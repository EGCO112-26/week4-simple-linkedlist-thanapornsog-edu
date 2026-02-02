//
//  node.h
//  simple linkedlist
//
//  Created by Mingmanas Sivaraksa on 4/2/2566 BE.
//
#ifndef stdnode_h
#define stdnode_h

#include <string.h> 

struct node {
    int value;
    struct node *next;
};

struct std_node {
    int id;
    char name[30];
    struct std_node *next;
};

typedef struct node Node;
typedef Node* NodePtr;
typedef struct std_node StdNode;
typedef StdNode* nodePtr;

#endif /* node_h */