#ifndef LIST_IMPLEMENTATIONS_H
#define LIST_IMPLEMENTATIONS_H

#include <stddef.h> // For size_t

/* Singly Linked List */
typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* createNode(int data);
void insertSingly(Node **head, int data);
void deleteSingly(Node **head, int data);
void printSingly(Node *head);

/* Doubly Linked List */
typedef struct DoublyNode {
    int data;
    struct DoublyNode *prev;
    struct DoublyNode *next;
} DoublyNode;

DoublyNode* createDoublyNode(int data);
void insertDoubly(DoublyNode **head, int data);
void deleteDoubly(DoublyNode **head, int data);
void printDoubly(DoublyNode *head);

/* Circular Buffer */
typedef struct CircularBuffer {
    int *buffer;
    int head;
    int tail;
    int size;
    int count;
} CircularBuffer;

CircularBuffer* createCircularBuffer(int size);
void insertCircular(CircularBuffer *cb, int data);
int deleteCircular(CircularBuffer *cb);
void printCircular(CircularBuffer *cb);
void destroyCircularBuffer(CircularBuffer *cb);

#endif // LIST_IMPLEMENTATIONS_H
