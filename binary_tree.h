#ifndef BINARY_TREE_H
#define BINARY_TREE_H

struct Node{
    char token[20];
    struct Node *left;
    struct Node *right;
};

// Sets an empty left child
void set_empty_left_child(struct Node p, char token[20]);

// Sets an empty right child
void set_empty_right_child(struct Node p, char token[20]);

// Gets the left child
struct Node* get_left_child(struct Node p);

// Gets the right child
struct Node* get_right_child(struct Node p);

#endif