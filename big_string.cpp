#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

Node<char>* create_list_from_string(const char* str) {
    if (!str || *str == '\0') {
        return NULL;
    }
    Node<char>* head = (Node<char>*)malloc(sizeof(Node<char>));
    head->data = *str;
    head->next = NULL;
    Node<char>* current = head;
    str++;
    while (*str != '\0') {
        current->next = (Node<char>*)malloc(sizeof(Node<char>));
        current = current->next;
        current->data = *str;
        current->next = NULL;
        str++;
    }
    return head;
}

void free_list(Node<char>* head) {
    while (head) {
        Node<char>* temp = head;
        head = head->next;
        free(temp);
    }
}

int
main(int argc, char *argv[])
{
  const char* big_string_literal = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
  const unsigned int len = strlen(big_string_literal);

  Node<char>* big_string_list = create_list_from_string(big_string_literal);

  if (argc != 2) {
    fprintf(stderr, "Usage: %s <index>\n", argv[0]);
    free_list(big_string_list);
    return 1;
  }

  int index = atoi(argv[1]);

  if (index >= 0 && index < len) {
    Node<char>* current = big_string_list;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }
    printf("%c\n", current->data);
  } else {
    fprintf(stderr, "Error: Index %d is out of bounds. Valid range is 0 to %u.\n", index, len - 1);
    free_list(big_string_list);
    return 1;
  }

  free_list(big_string_list);

  return 0;
}
