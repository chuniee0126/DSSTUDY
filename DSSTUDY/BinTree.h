#ifndef __BinTree__
#define __BinTree__

typedef struct tTreeNode {
	char data;
	struct tTreeNode *left, *right;
} TreeNode;

TreeNode* MakeBT(TreeNode *left, char data, TreeNode *right);
void FreeBT(TreeNode *root, int level);

void Inorder(TreeNode *root, int level);	// inorder traversal
void Preorder(TreeNode *root, int level);	// preorder traversal
void Postorder(TreeNode *root, int level);	// postorder traversal
void PrintTab(int level);

#endif // !__BinTree__
