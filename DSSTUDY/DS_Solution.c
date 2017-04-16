#include "BinTree.h"
#include <stdio.h>
#include <malloc.h>

TreeNode* MakeBT(TreeNode *left, char data, TreeNode *right) {
	TreeNode *temp = (TreeNode *)malloc(sizeof(TreeNode));

	temp->data = data;
	temp->left = left;
	temp->right = right;

	return temp;
}

void FreeBT(TreeNode *root, int level) {
	
	if (root) {
		FreeBT(root->left, level + 1);
		FreeBT(root->right, level + 1);
		PrintTab(level);
		printf("Deleting %c, %d\n", root->data, level);
		free(root);
	}
}

void Inorder(TreeNode *root, int level) {
	int i;
	if (root) {
		Inorder(root->left, level + 1);
		PrintTab(level);
		printf("inorder(%c, %d)\n", root->data, level);
		Inorder(root->right, level + 1);
	}
	else {
		PrintTab(level);
		printf("inorder(NULL, %d)\n", level);
	}
}

void Preorder(TreeNode *root, int level) {
	int i;
	if (root) {
		PrintTab(level);
		printf("inorder(%c, %d)\n", root->data, level);
		Preorder(root->left, level + 1);
		Preorder(root->right, level + 1);
	}
	else {
		PrintTab(level);
		printf("inorder(NULL, %d)\n", level);
	}
}

void Postorder(TreeNode *root, int level) {
	int i;
	if (root) {
		Postorder(root->left, level + 1);
		Postorder(root->right, level + 1);
		PrintTab(level);
		printf("inorder(%c, %d)\n", root->data, level);
	}
	else {
		PrintTab(level);
		printf("inorder(NULL, %d)\n", level);
	}
}

void PrintTab(int level) {
	int i = 0;
	for (i = 0; i < level; i++)
		putchar('\t');
}
