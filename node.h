#ifndef NODE_H
#define NODE_H

struct std_node {
    int id;
    char name[50];
    struct std_node *next;
};

typedef struct std_node* nodePtr;

#endif
