/*
test cases for binary tree in chapter 6
presented by xdxu@ustc.edu.cn
*/

#include <stdio.h>
#include <stdlib.h>
#include "btree.h"


// test cases
int main(void) {
	int arr[15] = {1, 2, 4, OUTLIER, 7, OUTLIER, OUTLIER, OUTLIER, 3, 5, OUTLIER, OUTLIER, 6, OUTLIER, OUTLIER};
	int list[15] = {OUTLIER, OUTLIER, OUTLIER, 7, 4, OUTLIER, 2, OUTLIER, OUTLIER, 5, OUTLIER, OUTLIER, 6, 3, 1};
	int pre[] = {1, 2, 4, 7, 3, 5, 6};
	int ind[] = {4, 7, 2, 1, 5, 3, 6};
	char postfix[] = "ga-bcd-*+ef/-";
	struct TreeNode *root, *bt, *node, *parent;
	int depth, numNodes, numLeaves;
	int i, j, n=0;
	SqStack *s;
	
	//case-1: basic operations
	printf("case-1: basic operations...\n");
	root = createTree(arr, 15, &n);
	depth = getTreeDepth(root);
	numNodes = getNumTreeNodes(root);
	printf("the tree has %d nodes and a depth of %d.\n", numNodes, depth);
	numLeaves = getTreeLeaves(root);
	printf("the tree has %d leaves.\n", numLeaves);
	printf("preorder sequence: ");
	preorder(root);
	printf("\n");

	printf("inorder sequence: ");
	inorder(root);
	printf("\n");

	printf("postorder sequence: ");
	postorder(root);
	printf("\n");
	
	printf("layerorder sequence: ");
	layerorder(root);
	printf("\n");	
	
	printf("display a horizonal-view tree: \n");
	showHorizonView(root);
	printf("\n");
	
	//case-2: some applications
	printf("\ncase-2: some applications...\n");
	printf("the route from root to each leaf:\n");
	s = createStack(15);
	printRoute(root, s);
	destroyStack(&s);
	
	printf("copy a tree:\n");
	copyBTree(root, &bt);
	preorder(bt);
	
	printf("\nfind the node's parent:\n");
	node = searchTreeNode(bt, 1);
	if (node!=NULL) {
		parent = getParent(bt, node);
		if (parent!=NULL)
			printf("the node's parent has value %d.\n", parent->data);
		else
			printf("the node has no parent.\n");
	} else printf("the node does not exist in the tree.\n");
	destroyTree(&bt);
	
	//case-3: others
	printf("\ncse-3: others...\n");
	printf("create a tree via postorder sequence:\n");
	n = 0;
	bt = createTreeByPostSeq(list, 15, &n);
	preorder(bt);
	destroyTree(&bt);
	
	printf("\ncreate a tree via two sequences:\n");
	bt = create(pre, ind, 0, 6, 0, 6);
	preorder(bt);
	destroyTree(&bt);
	
	printf("\ncreate a tree via postfix expression:\n");
	bt = buildExpreTree(postfix);
	preorder(bt);
	destroyTree(&bt);
    return 0;
}