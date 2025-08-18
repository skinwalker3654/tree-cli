#ifndef TREE_H
#define TREE_H

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right; 
} Node;

void insert_node(Node **root,int value);
void delete_node(Node **root,int value);
void search_node(Node *root,int value);
void inorder(Node *root);
void preorder(Node *root);
void postorder(Node *root);
void free_tree(Node *root);
void help_command(void);
int parser(int parsed,int n);

#endif
