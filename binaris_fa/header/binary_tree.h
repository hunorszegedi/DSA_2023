//
// Created by Lenovo on 08/05/2023.
//

#ifndef BINARIS_FA_BINARY_TREE_H
#define BINARIS_FA_BINARY_TREE_H

#include <stdio.h>
#include <stdlib.h>

#include <constants.h>
typedef struct Node{
    int info;
    struct Node *left, *right;
}Node;
//create a new node
Node *createNewNode(int newData);
//insert on the left of the node
Node *insertLeft(Node *root, int newData);
//insert on the right of the node
Node *insertRight(Node *root, int newData);
//preorder traversal
void preorderTraversal(Node *root);
//inorder traversal
void inorderTraversal(Node *root);
//postorder traversal
void postorderTraversal(Node *root);
//destroy binary tree
void destroyBinaryTree(Node **root);
#endif //BINARIS_FA_BINARY_TREE_H
