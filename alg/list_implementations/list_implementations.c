#include "list_implementations.h"
#include <stdio.h>
#include <stdlib.h>

Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("Failed to allocate memory for Node");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertSingly(Node **head, int data) {
    Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
    printf("Inserted %d into singly linked list.\n", data);
}

void deleteSingly(Node **head, int data) {
    Node *current = *head;
    Node *prev = NULL;

    while (current != NULL && current->data != data) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Data %d not found in singly linked list.\n", data);
        return;
    }

    if (prev == NULL) {
        *head = current->next;
    } else {
        prev->next = current->next;
    }
    printf("Deleted %d from singly linked list.\n", data);
    free(current);
}

void printSingly(Node *head) {
    Node *current = head;
    printf("Singly Linked List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

DoublyNode* createDoublyNode(int data) {
    DoublyNode *newNode = (DoublyNode*)malloc(sizeof(DoublyNode));
    if (newNode == NULL) {
        perror("Failed to allocate memory for DoublyNode");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertDoubly(DoublyNode **head, int data) {
    DoublyNode *newNode = createDoublyNode(data);
    newNode->next = *head;
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    *head = newNode;
    printf("Inserted %d into doubly linked list.\n", data);
}

void deleteDoubly(DoublyNode **head, int data) {
    DoublyNode *current = *head;

    while (current != NULL && current->data != data) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Data %d not found in doubly linked list.\n", data);
        return;
    }

    if (current->prev == NULL) {
        *head = current->next;
    } else {
        current->prev->next = current->next;
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
    }
    printf("Deleted %d from doubly linked list.\n", data);
    free(current);
}

void printDoubly(DoublyNode *head) {
    DoublyNode *current = head;
    printf("Doubly Linked List: ");
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

CircularBuffer* createCircularBuffer(int size) {
    CircularBuffer *cb = (CircularBuffer*)malloc(sizeof(CircularBuffer));
    if (cb == NULL) {
        perror("Failed to allocate memory for CircularBuffer");
        exit(EXIT_FAILURE);
    }
    cb->buffer = (int*)malloc(sizeof(int) * size);
    if (cb->buffer == NULL) {
        perror("Failed to allocate memory for CircularBuffer buffer");
        free(cb);
        exit(EXIT_FAILURE);
    }
    cb->head = 0;
    cb->tail = 0;
    cb->size = size;
    cb->count = 0;
    printf("Circular Buffer created with size %d.\n", size);
    return cb;
}

void insertCircular(CircularBuffer *cb, int data) {
    if (cb->count == cb->size) {
        printf("Circular Buffer is full. Cannot insert %d.\n", data);
        return;
    }
    cb->buffer[cb->tail] = data;
    cb->tail = (cb->tail + 1) % cb->size;
    cb->count++;
    printf("Inserted %d into circular buffer.\n", data);
}

int deleteCircular(CircularBuffer *cb) {
    if (cb->count == 0) {
        printf("Circular Buffer is empty. Cannot delete.\n");
        return -1;
    }
    int data = cb->buffer[cb->head];
    cb->head = (cb->head + 1) % cb->size;
    cb->count--;
    printf("Deleted %d from circular buffer.\n", data);
    return data;
}

void printCircular(CircularBuffer *cb) {
    printf("Circular Buffer: ");
    if (cb->count == 0) {
        printf("Empty\n");
        return;
    }
    int i = cb->head;
    int printed_count = 0;
    while (printed_count < cb->count) {
        printf("%d ", cb->buffer[i]);
        i = (i + 1) % cb->size;
        printed_count++;
    }
    printf("\n");
}

void destroyCircularBuffer(CircularBuffer *cb) {
    if (cb) {
        free(cb->buffer);
        free(cb);
        printf("Circular Buffer destroyed.\n");
    }
}
