
#include <stdio.h>
#include <stdlib.h>

#include "tree_bi.h"

void initBiTree(BiNodePtr *root){
    *root = malloc(sizeof(BiNode));
    (*root)->data.id = 1;
    (*root)->data.val = 0;
    (*root)->parent = NULL;
    (*root)->left = NULL;
    (*root)->right = NULL;
}

BiNodePtr getParent(BiNodePtr root, Data data) {
    BiNodePtr p=root;
    BiNodePtr l;

    return  p;
}

void traverseBiTree_LDR(BiNodePtr root) {
    if (root == NULL) return;
    traverseBiTree_LDR(root->left);
    printf("id: %d, val: %d\n", root->data.id, root->data.val);
    traverseBiTree_LDR(root->right);
}

void traverseBiTree_DLR(BiNodePtr root) {
    if(root==NULL) return;
    printf("id: %d, val: %d\n", root->data.id, root->data.val);
    traverseBiTree_DLR(root->left);
    traverseBiTree_DLR(root->right);
}

void traverseBiTree_LRD(BiNodePtr root) {
    if(root==NULL) return;
    traverseBiTree_LRD(root->left);
    traverseBiTree_LRD(root->right);
    printf("id: %d, val: %d\n", root->data.id, root->data.val);
}

void traverseBiTree_LR(BiNodePtr root) {

}
