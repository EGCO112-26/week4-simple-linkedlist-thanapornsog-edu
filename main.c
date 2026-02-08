#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char id[100];
    char name[100];
    struct Node* next;
} Node;

Node* createNode(const char* id, const char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->id, id);
    strcpy(newNode->name, name);
    newNode->next = NULL;
    return newNode;
}

void insert(Node** head, const char* id, const char* name) {
    Node* newNode = createNode(id, name);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%s %s\n", current->id, current->name);
        current = current->next;
    }
}

int main(int argc, char* argv[]) {
    Node* head = NULL;
    
    // Process arguments in pairs (skip argv[0] which is the program name)
    for (int i = 1; i < argc; i += 2) {
        if (i + 1 < argc) {
            insert(&head, argv[i], argv[i + 1]);
        }
    }
    
    printList(head);
    
    return 0;
}    while (*head != NULL) {
        tmp = *head;
        *head = (*head)->next;
        free(tmp);
    }
}    while (*head != NULL) {
        tmp = *head;
        *head = (*head)->next;
        free(tmp);
    }
}    nodePtr new_node = (nodePtr)malloc(sizeof(struct std_node));
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
}    nodePtr new_node = (nodePtr)malloc(sizeof(struct std_node));
    if (new_node == NULL) return;

    new_node->id = id;
    strncpy(new_node->name, name, sizeof(new_node->name));
    new_node->name[sizeof(new_node->name) - 1] = '\0';
    new_node->next = NULL;

    if (*head == NULL || (*head)->id > id) {
        new_node->next = *head;
        *head = new_node;
        return;
    }

    nodePtr current = *head;

    while (current->next != NULL && current->next->id < id) {
        current = current->next;
    }

    new_node->next = current->next;
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
