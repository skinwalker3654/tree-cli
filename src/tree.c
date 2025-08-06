#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void insert_node(struct Node **root,int value) {
    if(*root == NULL) {
        struct Node *new_node = malloc(sizeof(struct Node));
        if(!new_node) {
            printf("Error: Memory Allocation failed\n");
            return;
        }

        new_node->data = value;
        new_node->left = NULL;
        new_node->right = NULL;

        *root = new_node;
        return;
    }

    struct Node *temp = *root;
    if(value < temp->data) {
        insert_node(&temp->left,value);
    } else if(value > temp->data) {
        insert_node(&temp->right,value);
    } else {
        printf("Error: Duplicate values\n");
        return;
    }
}

void delete_node(struct Node **root,int value) {
    if(*root == NULL) {
        printf("Error: Value %d not found\n",value);
        return;
    }

    struct Node *temp = *root;
    if(value < temp->data) {
        delete_node(&temp->left,value);
    } else if(value > temp->data) {
        delete_node(&temp->right,value);
    } else {
        if(temp->left == NULL) {
            struct Node *right_ch = temp->right;
            free(temp);
            *root = right_ch;
            return;
        } else if(temp->right == NULL) {
            struct Node *left_ch = temp->left;
            free(temp);
            *root = left_ch;
            return;
        } else {
            struct Node *min_right = temp->right;
            while(min_right->left != NULL) min_right = min_right->left;
            temp->data = min_right->data;
            delete_node(&temp->right,min_right->data);
            return;
        }
    }
}

void search_node(struct Node *root,int value) {
    if(root == NULL) {
        printf("Tree is empty\n");
        return;
    }

    struct Node *temp = root;
    printf("\nRoot: %d\n",root->data);
    while(temp != NULL) {
        if(value == temp->data) {
            printf("Value %d found\n",value);
            return;
        }

        if(value < temp->data) {
            temp = temp->left;
            if(temp != NULL)
                printf("-> Left(%d)\n",temp->data);
        } else {
            temp = temp->right;
            if(temp != NULL)
                printf("-> Right(%d)\n",temp->data);
        }
    }

    printf("Value %d not found\n",value);
}

void inorder(struct Node *root) {
    if(root != NULL) {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void preorder(struct Node *root) {
    if(root != NULL) {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node *root) {
    if(root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

void free_tree(struct Node *root) {
    if(root != NULL) {
        free_tree(root->left);
        free_tree(root->right);
        free(root);
    }
}

void help_command() {
    printf("\nCommands:\n");
    printf("   add   <value>  : add a value to the tree\n");
    printf("   del   <value>  : delete a value from the tree\n");
    printf("   find  <value>  : search a value in the tree\n");
    printf("   cls            : clear the screen\n");
    printf("   exit           : exit the program\n");
    printf("   help           : show this panel\n");
    printf("   inorder        : print nodes in inorder traversal\n");
    printf("   preorder       : print nodes in preorder traversal\n");
    printf("   postorder      : print nodes in postorder traversal\n\n");
}

int parser(int persed,int n) {
    if(persed == n) {return 1;}
    printf("Error: Invalid arguments passed\n");
    return 0;
}
