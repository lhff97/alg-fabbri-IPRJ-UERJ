#include <iostream>
#include <stdlib.h>
#include "list.h"

Node<int>* create_sorted_list_from_array(const int arr[], int size) {
    if (size == 0) {
        return NULL;
    }
    Node<int>* head = (Node<int>*)malloc(sizeof(Node<int>));
    head->data = arr[0];
    head->next = NULL;
    Node<int>* current = head;
    for (int i = 1; i < size; ++i) {
        current->next = (Node<int>*)malloc(sizeof(Node<int>));
        current = current->next;
        current->data = arr[i];
        current->next = NULL;
    }
    return head;
}

void free_list(Node<int>* head) {
    while (head) {
        Node<int>* temp = head;
        head = head->next;
        free(temp);
    }
}

Node<int>* get_middle(Node<int>* head) {
    if (!head) {
        return head;
    }
    Node<int>* slow = head;
    Node<int>* fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node<int>* binary_search_list(Node<int>* head, int target) {
    Node<int>* start = head;
    Node<int>* end = NULL;

    do {
        Node<int>* mid = get_middle(start);

        if (!mid) {
            return NULL;
        }

        if (mid->data == target) {
            return mid;
        }
        if (mid->data < target) {
            start = mid->next;
        } else {
            Node<int>* current = start;
            if (current == mid) {
                return NULL;
            }
            while(current->next != mid) {
                current = current->next;
            }
            end = current;
            end->next = NULL;
        }
    } while (end != NULL && end->next != start);

    return NULL;
}

int main(int argc, char *argv[]) {
    const int sorted_array[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    const int arr_size = sizeof(sorted_array) / sizeof(sorted_array[0]);

    Node<int>* head = create_sorted_list_from_array(sorted_array, arr_size);

    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <number_to_search>" << std::endl;
        std::cerr << "Searching in list: ";
        for (Node<int>* current = head; current; current = current->next) {
            std::cerr << current->data << " ";
        }
        std::cerr << std::endl;
        free_list(head);
        return 1;
    }

    int target = std::stoi(argv[1]);

    Node<int>* result_node = binary_search_list(head, target);

    if (result_node != NULL) {
        int index = 0;
        Node<int>* current = head;
        while(current != result_node) {
            current = current->next;
            index++;
        }
        std::cout << "Element " << target << " found at index: " << index << std::endl;
    } else {
        std::cout << "Element " << target << " not found in the list." << std::endl;
    }

    free_list(head);

    return 0;
}