//
// Created by Lenovo on 08/05/2023.
//

#include "bst.h"


Node *insert(Node *node, int key) {
    if (node == NULL) {
        node = createNewNode(key);
    } else if (key < node->info) {
        node->left = insert(node->left, key);
    } else if (key > node->info) {
        node->right = insert(node->right, key);
    }
    return node;
}


Node *minValueNode(Node *node) {
    Node *temp = node;
    while (temp != NULL && temp->left != NULL) {
        temp = temp->left;
    }
    return temp;
}

Node *maxValueNode(Node *node) {
    Node *temp = node;
    while (temp != NULL && temp->right != NULL) {
        temp = temp->right;
    }
    return temp;
}

Node *deleteNode(Node *root, int key) {
    if (root == NULL) {
        return NULL;
    }
    if (root->info < key) {
        root->right = deleteNode(root->right, key);
    } else if (root->info > key) {
        root->left = deleteNode(root->left, key);
    } else {
        //node to be deleted
        //level -- egyszeruen nincs tovabbi leszarmazottja //nincs jobb //nincs bal
        if (root->right == NULL && root->left == NULL) {
            free(root);
            return NULL;
        } else if (root->right == NULL) {
            //a bal lesz helyette a csomopont
            Node *temp = root->left;
            free(root);
            return temp;
        } else if (root->left == NULL) {
            Node *temp = root->right;
            free(root);
            return temp;
        }

        //van jobb es van bal
//        Node *temp = minValueNode(root->right);
        Node *temp = maxValueNode(root->left);
        root->info = temp->info;
//        deleteNode(root->right, temp->info);
        deleteNode(root->left, temp->info);

    }
    return root;
}
