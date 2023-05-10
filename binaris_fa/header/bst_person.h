//
// Created by Lenovo on 08/05/2023.
//

#ifndef BINARIS_FA_BST_PERSON_H
#define BINARIS_FA_BST_PERSON_H

#include <stdio.h>
#include <stdlib.h>

#include <constants.h>

typedef enum {
    fiu, lany
} Gender;

typedef struct Date {
    int year, month, day;
} Date;

typedef struct Information {
    char *name;
    Date date;
    Gender gender;
} Information;

typedef struct NodePerson {
    Information information;
    struct NodePerson *left, *right;
} NodePerson;

//create a new node
NodePerson *createNewNodePerson(Information newData);

//insert on the left of the node
NodePerson *insertLeftPerson(NodePerson *root, Information newData);

//insert on the right of the node
NodePerson *insertRightPerson(NodePerson *root, Information newData);

//preorder traversal
void preorderTraversalPerson(NodePerson *root);

//inorder traversal
void inorderTraversalPerson(NodePerson *root);

//postorder traversal
void postorderTraversalPerson(NodePerson *root);

//destroy binary tree
void destroyBinaryTreePerson(NodePerson **root);

//insert a node
NodePerson *insertPerson(NodePerson *node, Information key);

//find the min number
NodePerson *minValueNodePerson(NodePerson *node);

//find the max number
NodePerson *maxValueNodePerson(NodePerson *node);

//deleting a node
NodePerson *deleteNodePerson(NodePerson *root, Information key);

#endif //BINARIS_FA_BST_PERSON_H
