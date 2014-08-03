#include "Traversal.h"
int main() {
	/*
	vector<int> vec;
	for (int i = 1; i < 8; ++i){
		vec.push_back(i);
	}
	
	root = createTree(vec);
	*/
	TreeNode *root = new TreeNode(4);
	TreeNode * t1 = new TreeNode(1);
	TreeNode* t2 = new TreeNode(2);
	TreeNode* t3 = new TreeNode(3);
	TreeNode * t4 = new TreeNode(5);
	TreeNode* t5 = new TreeNode(5);
	TreeNode* t6 = new TreeNode(6);
	root->left = t2;
	root->right = t6;
	t2->left = t1;
	t2->right = t3;
	t6->left = t5;
	/* Print in preorder */
	vector<int> prevec = preorderTraversal(root);
	cout << "**********Print in preorder **************" << endl;
	print(prevec);
	vector<int> invec = inorderTraversal(root);
	cout << "**********Print in inorder **************" << endl;
	print(invec);
	vector<int> postvec = postorderTraversal(root);
	cout << "**********Print in postorder **************" << endl;
	print(postvec);

	system("pause");
	return 0;
}