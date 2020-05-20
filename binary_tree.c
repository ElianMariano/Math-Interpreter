#include "binary_tree.h"
#include <string.h>

void set_empty_left_child(struct Node p, char token[20]){
    struct Node *l;
    strcpy(l->token, token);
    l->left = NULL;
    l->right = NULL;

    p.left = l;
}

void set_empty_right_child(struct Node p, char token[20]){
    struct Node *r;
    strcpy(r->token, token);
    r->left = NULL;
    r->right = NULL;

    p.right = r;
}

struct Node* get_left_child(struct Node p){
    return p.left;
}

struct Node* get_right_child(struct Node p){
    return p.right;
}