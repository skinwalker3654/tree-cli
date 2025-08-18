#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tree.h"

int main(void) {
    char input[100];
    char command[10];
    int value;

    Node *root = NULL;
    while(1) {
        printf("Prompt@~> ");
        if(fgets(input,sizeof(input),stdin)==NULL) {
            printf("Error: Input failure\n");
            continue;
        }

        input[strcspn(input,"\n")] = 0;
        int parsed = sscanf(input,"%s %d",command,&value);

        if(strcmp(command,"add")==0) {  //add
            if(parser(parsed,2)==1) {
                insert_node(&root,value);
                continue;
            }
        } else if(strcmp(command,"del")==0) { //del
            if(parser(parsed,2)==1) {
                delete_node(&root,value);
                continue; 
            }
        } else if(strcmp(command,"find")==0) { //find
            if(parser(parsed,2)==1) {
                search_node(root,value); 
                printf("\n");
                continue;
            }
        } else if(strcmp(command,"inorder")==0) { //inorder
            if(parser(parsed,1)==1) {
                inorder(root);
                printf("\n");
                continue; 
            }
        } else if(strcmp(command,"preorder")==0) { //preorder
            if(parser(parsed,1)==1) {
                preorder(root);
                printf("\n");
                continue; 
            }
        } else if(strcmp(command,"postorder")==0) { //postorder
            if(parser(parsed,1)==1) {
                postorder(root);
                printf("\n");
                continue; 
            }
        } else if(strcmp(command,"help")==0) { //help
            if(parser(parsed,1)==1) {
                help_command();
                continue; 
            }
        } else if(strcmp(command,"cls")==0) { //cls
            if(parser(parsed,1)==1) {
                system("clear");
                continue; 
            }
        } else if(strcmp(command,"exit")==0) { //exit
            if(parser(parsed,1)==1) {
                printf("Exiting...\n");
                free_tree(root);
                return 0; 
            }
        } else {
            printf("Error: Invalid command '%s'\n",command);
            printf("Enter 'help' for more info\n");
            continue;
        }
    }

    free_tree(root);
    return 0;
}
