#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

// 2. Function Prototypes
void insert(nodePtr *head, int id, char *name);
void print_list(nodePtr head);
void delete_list(nodePtr head);

int main(int argc, char **argv) {
	nodePtr head = NULL;
	int i;

	// Check for input
	if (argc < 3) {
		printf("Usage: %s <ID> <Name> <ID> <Name> ...\n", argv[0]);
		return 1;
	}

	// Loop through argv in pairs (ID, Name)
	for (i = 1; i < argc; i += 2) {
		if (i + 1 < argc) {
			int id = atoi(argv[i]);
			char *name = argv[i + 1];
			insert(&head, id, name);
		}
	}

	// Print all linked list
	print_list(head);

	// Delete all linked list (Free memory)
	delete_list(head);
	head = NULL;

	return 0;
}

/* --- Functions Implementation --- */

// Insert (sorted by ID ascending)
void insert(nodePtr *head, int id, char *name) {
	nodePtr new_node = (nodePtr)malloc(sizeof(struct std_node));
	if (!new_node) return;
	new_node->id = id;
	strncpy(new_node->name, name, sizeof(new_node->name)-1);
	new_node->name[sizeof(new_node->name)-1] = '\0';
	new_node->next = NULL;

	nodePtr current;

	// Insert at head
	if (*head == NULL || (*head)->id > id) {
		new_node->next = *head;
		*head = new_node;
	} else {
		// Insert in middle or end
		current = *head;
		while (current->next != NULL && current->next->id < id) {
			current = current->next;
		}
		new_node->next = current->next;
		current->next = new_node;
	}
}

// Print
void print_list(nodePtr head) {
	nodePtr tmp = head;
	while (tmp != NULL) {
		printf("%d %s\n", tmp->id, tmp->name);
		tmp = tmp->next;
	}
}

// Delete (free)
void delete_list(nodePtr head) {
	nodePtr tmp;
	while (head != NULL) {
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
