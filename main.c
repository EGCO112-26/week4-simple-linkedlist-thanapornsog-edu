#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

void insert(nodePtr *head, int id, char *name);
void print_list(nodePtr head);
void delete_list(nodePtr *head);

int main(int argc, char **argv) {
    nodePtr head = NULL;
    int i;

    if (argc == 1) return 0;
    if (argc < 3 || (argc % 2) == 0) return 0;

    for (i = 1; i < argc; i += 2) {
        int id = atoi(argv[i]);
        char *name = argv[i + 1];
        insert(&head, id, name);
    }

    print_list(head);

    delete_list(&head);
    head = NULL;

    return 0;
}

void insert(nodePtr *head, int id, char *name) {
    nodePtr new_node = (nodePtr)malloc(sizeof(struct std_node));
    if (new_node == NULL) return;

    new_node->id = id;
    strncpy(new_node->name, name, sizeof(new_node->name));
    new_node->name[sizeof(new_node->name) - 1] = '\0';
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    nodePtr current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = new_node;
}

void print_list(nodePtr head) {
    nodePtr tmp = head;
    while (tmp != NULL) {
        printf("%d %s\n", tmp->id, tmp->name);
        tmp = tmp->next;
    }
}

void delete_list(nodePtr *head) {
    nodePtr tmp;
    while (*head != NULL) {
        tmp = *head;
        *head = (*head)->next;
        free(tmp);
    }
}
