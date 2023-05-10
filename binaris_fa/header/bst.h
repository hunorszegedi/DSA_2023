//
// Created by Lenovo on 08/05/2023.
//

#ifndef BINARIS_FA_BST_H
#define BINARIS_FA_BST_H

#include <stdio.h>
#include <stdlib.h>
#include <constants.h>
#include "binary_tree.h"


//insert a node
Node *insert(Node *node, int key);

//find the min number
Node *minValueNode(Node *node);

//find the max number
Node *maxValueNode(Node *node);

//deleting a node
Node *deleteNode(Node *root, int key);

#endif //BINARIS_FA_BST_H
