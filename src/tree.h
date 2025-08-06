#ifndef TREE_H
#define TREE_H

struct Node {
    int data;
    struct Node *left;
    struct Node *right; 
};

void insert_node(struct Node **root,int value);
void delete_node(struct Node **root,int value);
void search_node(struct Node *root,int value);
void inorder(struct Node *root);
void preorder(struct Node *root);
void postorder(struct Node *root);
void free_tree(struct Node *root);
void help_command(void);
int parser(int persed,int n);

#endif
