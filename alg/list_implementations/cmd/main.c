#include <stdio.h>
#include <stdlib.h>
#include "../list_implementations.h"

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    int choice_list, choice_op, data, buffer_size;

    Node *singly_head = NULL;
    DoublyNode *doubly_head = NULL;
    CircularBuffer *cb = NULL;

    do {
        printf("\nChoose List Type:\n");
        printf("1. Singly Linked List (Encadeada)\n");
        printf("2. Doubly Linked List (Duplamente Encadeada)\n");
        printf("3. Circular Buffer\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice_list) != 1) {
            printf("Invalid input. Please enter a number.\n");
            clear_input_buffer();
            continue;
        }
        clear_input_buffer();

        switch (choice_list) {
            case 1: // Singly Linked List
                do {
                    printf("\nSingly Linked List Operations:\n");
                    printf("i. Insert (Inserir)\n");
                    printf("d. Delete (Deletar)\n");
                    printf("p. Print\n");
                    printf("b. Back to main menu\n");
                    printf("Enter your choice: ");
                    char op_char;
                    if (scanf(" %c", &op_char) != 1) {
                        printf("Invalid input. Please enter a character.\n");
                        clear_input_buffer();
                        continue;
                    }
                    clear_input_buffer();

                    switch (op_char) {
                        case 'i':
                            printf("Enter data to insert: ");
                            if (scanf("%d", &data) != 1) {
                                printf("Invalid input. Please enter a number.\n");
                                clear_input_buffer();
                                continue;
                            }
                            clear_input_buffer();
                            insertSingly(&singly_head, data);
                            break;
                        case 'd':
                            printf("Enter data to delete: ");
                            if (scanf("%d", &data) != 1) {
                                printf("Invalid input. Please enter a number.\n");
                                clear_input_buffer();
                                continue;
                            }
                            clear_input_buffer();
                            deleteSingly(&singly_head, data);
                            break;
                        case 'p':
                            printSingly(singly_head);
                            break;
                        case 'b':
                            break;
                        default:
                            printf("Invalid option. Please try again.\n");
                    }
                } while (choice_op != 'b');
                break;

            case 2: // Doubly Linked List
                do {
                    printf("\nDoubly Linked List Operations:\n");
                    printf("i. Insert (Inserir)\n");
                    printf("d. Delete (Deletar)\n");
                    printf("p. Print\n");
                    printf("b. Back to main menu\n");
                    printf("Enter your choice: ");
                    char op_char;
                    if (scanf(" %c", &op_char) != 1) {
                        printf("Invalid input. Please enter a character.\n");
                        clear_input_buffer();
                        continue;
                    }
                    clear_input_buffer();

                    switch (op_char) {
                        case 'i':
                            printf("Enter data to insert: ");
                            if (scanf("%d", &data) != 1) {
                                printf("Invalid input. Please enter a number.\n");
                                clear_input_buffer();
                                continue;
                            }
                            clear_input_buffer();
                            insertDoubly(&doubly_head, data);
                            break;
                        case 'd':
                            printf("Enter data to delete: ");
                            if (scanf("%d", &data) != 1) {
                                printf("Invalid input. Please enter a number.\n");
                                clear_input_buffer();
                                continue;
                            }
                            clear_input_buffer();
                            deleteDoubly(&doubly_head, data);
                            break;
                        case 'p':
                            printDoubly(doubly_head);
                            break;
                        case 'b':
                            break;
                        default:
                            printf("Invalid option. Please try again.\n");
                    }
                } while (choice_op != 'b');
                break;

            case 3: // Circular Buffer
                if (cb == NULL) {
                    printf("Enter size for Circular Buffer: ");
                    if (scanf("%d", &buffer_size) != 1 || buffer_size <= 0) {
                        printf("Invalid input. Please enter a positive number.\n");
                        clear_input_buffer();
                        break;
                    }
                    clear_input_buffer();
                    cb = createCircularBuffer(buffer_size);
                }
                do {
                    printf("\nCircular Buffer Operations:\n");
                    printf("i. Insert (Inserir)\n");
                    printf("d. Delete (Deletar)\n");
                    printf("p. Print\n");
                    printf("b. Back to main menu\n");
                    printf("Enter your choice: ");
                    char op_char;
                    if (scanf(" %c", &op_char) != 1) {
                        printf("Invalid input. Please enter a character.\n");
                        clear_input_buffer();
                        continue;
                    }
                    clear_input_buffer();

                    switch (op_char) {
                        case 'i':
                            printf("Enter data to insert: ");
                            if (scanf("%d", &data) != 1) {
                                printf("Invalid input. Please enter a number.\n");
                                clear_input_buffer();
                                continue;
                            }
                            clear_input_buffer();
                            insertCircular(cb, data);
                            break;
                        case 'd':
                            deleteCircular(cb);
                            break;
                        case 'p':
                            printCircular(cb);
                            break;
                        case 'b':
                            break;
                        default:
                            printf("Invalid option. Please try again.\n");
                    }
                } while (choice_op != 'b');
                break;

            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice_list != 0);

    Node *current_singly = singly_head;
    while (current_singly != NULL) {
        Node *temp = current_singly;
        current_singly = current_singly->next;
        free(temp);
    }

    DoublyNode *current_doubly = doubly_head;
    while (current_doubly != NULL) {
        DoublyNode *temp = current_doubly;
        current_doubly = current_doubly->next;
        free(temp);
    }

    destroyCircularBuffer(cb);

    return 0;
}
