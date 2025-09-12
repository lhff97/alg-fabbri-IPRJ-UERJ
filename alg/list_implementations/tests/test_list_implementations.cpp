#include "gtest/gtest.h"
extern "C" {
#include "../../list_implementations.h"
}
#include <string>
#include <vector>

// --- Singly Linked List Tests ---

TEST(SinglyLinkedListTest, InsertAndPrint) {
    Node *head = NULL;
    insertSingly(&head, 10);
    insertSingly(&head, 20);
    insertSingly(&head, 30);
    printSingly(head);
    while (head != NULL) {
        Node *temp = head;
        head = head->next;
        free(temp);
    }
}

TEST(SinglyLinkedListTest, DeleteHead) {
    Node *head = NULL;
    insertSingly(&head, 10);
    insertSingly(&head, 20);
    deleteSingly(&head, 20);
    ASSERT_NE(head, nullptr);
    ASSERT_EQ(head->data, 10);
    ASSERT_EQ(head->next, nullptr);
    free(head);
}

TEST(SinglyLinkedListTest, DeleteMiddle) {
    Node *head = NULL;
    insertSingly(&head, 10);
    insertSingly(&head, 20);
    insertSingly(&head, 30);
    deleteSingly(&head, 20);
    ASSERT_NE(head, nullptr);
    ASSERT_EQ(head->data, 30);
    ASSERT_NE(head->next, nullptr);
    ASSERT_EQ(head->next->data, 10);
    ASSERT_EQ(head->next->next, nullptr);
    while (head != NULL) {
        Node *temp = head;
        head = head->next;
        free(temp);
    }
}

TEST(SinglyLinkedListTest, DeleteTail) {
    Node *head = NULL;
    insertSingly(&head, 10);
    insertSingly(&head, 20);
    insertSingly(&head, 30);
    deleteSingly(&head, 10);
    ASSERT_NE(head, nullptr);
    ASSERT_EQ(head->data, 30);
    ASSERT_NE(head->next, nullptr);
    ASSERT_EQ(head->next->data, 20);
    ASSERT_EQ(head->next->next, nullptr);
    while (head != NULL) {
        Node *temp = head;
        head = head->next;
        free(temp);
    }
}

TEST(SinglyLinkedListTest, DeleteNonExistent) {
    Node *head = NULL;
    insertSingly(&head, 10);
    deleteSingly(&head, 99);
    ASSERT_NE(head, nullptr);
    ASSERT_EQ(head->data, 10);
    free(head);
}

TEST(SinglyLinkedListTest, DeleteFromEmpty) {
    Node *head = NULL;
    deleteSingly(&head, 10);
    ASSERT_EQ(head, nullptr);
}

// --- Doubly Linked List Tests ---

TEST(DoublyLinkedListTest, InsertAndPrint) {
    DoublyNode *head = NULL;
    insertDoubly(&head, 10);
    insertDoubly(&head, 20);
    insertDoubly(&head, 30);
    printDoubly(head);
    while (head != NULL) {
        DoublyNode *temp = head;
        head = head->next;
        free(temp);
    }
}

TEST(DoublyLinkedListTest, DeleteHead) {
    DoublyNode *head = NULL;
    insertDoubly(&head, 10);
    insertDoubly(&head, 20);
    deleteDoubly(&head, 20);
    ASSERT_NE(head, nullptr);
    ASSERT_EQ(head->data, 10);
    ASSERT_EQ(head->prev, nullptr);
    ASSERT_EQ(head->next, nullptr);
    free(head);
}

TEST(DoublyLinkedListTest, DeleteMiddle) {
    DoublyNode *head = NULL;
    insertDoubly(&head, 10);
    insertDoubly(&head, 20);
    insertDoubly(&head, 30);
    deleteDoubly(&head, 20);
    ASSERT_NE(head, nullptr);
    ASSERT_EQ(head->data, 30);
    ASSERT_EQ(head->prev, nullptr);
    ASSERT_NE(head->next, nullptr);
    ASSERT_EQ(head->next->data, 10);
    ASSERT_EQ(head->next->prev, head);
    ASSERT_EQ(head->next->next, nullptr);
    while (head != NULL) {
        DoublyNode *temp = head;
        head = head->next;
        free(temp);
    }
}

TEST(DoublyLinkedListTest, DeleteTail) {
    DoublyNode *head = NULL;
    insertDoubly(&head, 10);
    insertDoubly(&head, 20);
    insertDoubly(&head, 30);
    deleteDoubly(&head, 10);
    ASSERT_NE(head, nullptr);
    ASSERT_EQ(head->data, 30);
    ASSERT_EQ(head->prev, nullptr);
    ASSERT_NE(head->next, nullptr);
    ASSERT_EQ(head->next->data, 20);
    ASSERT_EQ(head->next->prev, head);
    ASSERT_EQ(head->next->next, nullptr);
    while (head != NULL) {
        DoublyNode *temp = head;
        head = head->next;
        free(temp);
    }
}

TEST(DoublyLinkedListTest, DeleteNonExistent) {
    DoublyNode *head = NULL;
    insertDoubly(&head, 10);
    deleteDoubly(&head, 99);
    ASSERT_NE(head, nullptr);
    ASSERT_EQ(head->data, 10);
    free(head);
}

TEST(DoublyLinkedListTest, DeleteFromEmpty) {
    DoublyNode *head = NULL;
    deleteDoubly(&head, 10);
    ASSERT_EQ(head, nullptr);
}

// --- Circular Buffer Tests ---

TEST(CircularBufferTest, CreateAndDestroy) {
    CircularBuffer *cb = createCircularBuffer(5);
    ASSERT_NE(cb, nullptr);
    ASSERT_NE(cb->buffer, nullptr);
    ASSERT_EQ(cb->size, 5);
    ASSERT_EQ(cb->count, 0);
    destroyCircularBuffer(cb);
}

TEST(CircularBufferTest, InsertUntilFull) {
    CircularBuffer *cb = createCircularBuffer(3);
    insertCircular(cb, 10);
    insertCircular(cb, 20);
    insertCircular(cb, 30);
    ASSERT_EQ(cb->count, 3);
    printCircular(cb);
    insertCircular(cb, 40);
    ASSERT_EQ(cb->count, 3);
    destroyCircularBuffer(cb);
}

TEST(CircularBufferTest, DeleteUntilEmpty) {
    CircularBuffer *cb = createCircularBuffer(3);
    insertCircular(cb, 10);
    insertCircular(cb, 20);
    ASSERT_EQ(deleteCircular(cb), 10);
    ASSERT_EQ(cb->count, 1);
    ASSERT_EQ(deleteCircular(cb), 20);
    ASSERT_EQ(cb->count, 0);
    deleteCircular(cb);
    ASSERT_EQ(cb->count, 0);
    destroyCircularBuffer(cb);
}

TEST(CircularBufferTest, Circularity) {
    CircularBuffer *cb = createCircularBuffer(3);
    insertCircular(cb, 10);
    insertCircular(cb, 20);
    insertCircular(cb, 30);
    ASSERT_EQ(deleteCircular(cb), 10);
    insertCircular(cb, 40);
    printCircular(cb);
    ASSERT_EQ(cb->count, 3);
    ASSERT_EQ(deleteCircular(cb), 20);
    ASSERT_EQ(deleteCircular(cb), 30);
    ASSERT_EQ(deleteCircular(cb), 40);
    ASSERT_EQ(cb->count, 0);
    destroyCircularBuffer(cb);
}
