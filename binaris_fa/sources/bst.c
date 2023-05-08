//
// Created by Lenovo on 08/05/2023.
//

#include "bst.h"


Node *insert(Node *node, int key) {
    if (key < node->info) {
        insertLeft(node, key);
    }
    if(key > node->info){
        insertRight(node, key);
    }
}

Node *minValueNode(Node *node) {
    return NULL;
}

Node *maxValueNode(Node *node) {
    return NULL;
}

Node *deleteNode(Node *root, int key) {
    return NULL;
}
