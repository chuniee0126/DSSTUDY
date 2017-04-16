#include "BinTree.h"

#include <stdio.h>

int main(void) {
	TreeNode *A = MakeBT(NULL, 'A', NULL);
	TreeNode *B = MakeBT(NULL, 'B', NULL);
	TreeNode *C = MakeBT(A, 'C', B);
	TreeNode *D = MakeBT(NULL, 'D', NULL);
	TreeNode *E = MakeBT(C, 'E', D);

	printf("=== Inorder traversal: \n");
	Inorder(E, 1);
	printf("\n");

	printf("=== Preorder traversal: \n");
	Preorder(E, 1);
	printf("\n");

	printf("=== Postorder traversal: \n");
	Postorder(E, 1);
	printf("\n");

	printf("=== Deleting tree: \n");
	FreeBT(E, 1);
	printf("\n");

	system("PAUSE");

	return 0;
}