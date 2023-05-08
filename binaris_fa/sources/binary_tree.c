//
// Created by Lenovo on 08/05/2023.
//

#include "binary_tree.h"
#include "bst.h"


Node *createNewNode(int newData) {
    Node *newItem = (Node *) calloc(1, sizeof(Node));
    if (!newItem) {
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
    newItem->info = newData;
    newItem->left = newItem->right = NULL;
    return newItem;
}

Node *insertLeft(Node *root, int newData) {
    root->left = createNewNode(newData);
    return root->left;
}

Node *insertRight(Node *root, int newData) {
    root->right = createNewNode(newData);
    return root->right;
}

void preorderTraversal(Node *root) {
    if (root == NULL) return;
    printf("%i ", root->info);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void inorderTraversal(Node *root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%i ", root->info);
    inorderTraversal(root->right);
}


void postorderTraversal(Node *root) {
    if (root == NULL) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%i ", root->info);
}
