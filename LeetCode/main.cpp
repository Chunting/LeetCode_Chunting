#include "Traversal.h"
int main_test() {
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
	TreeNode* t3 = new TreeNode(5);
	TreeNode * t4 = new TreeNode(1);
	TreeNode* t5 = new TreeNode(5);
	TreeNode* t6 = new TreeNode(2);
	root->left = t2;
	root->right = t6;
	t2->left = t1;
	t2->right = t3;
	t6->left = t5;
	t6->right = t4;
	/* Print in preorder */
	cout << endl << "**********Print in preorder **************" << endl;
	vector<int> prevec = preorderTraversal(root);
	print(prevec);

	cout << endl<<"**********Print in inorder **************" << endl;
	vector<int> invec = inorderTraversal(root);
	print(invec);

	cout << endl << "**********Print in postorder **************" << endl;
	vector<int> postvec = postorderTraversal(root);
	print(postvec);
	cout << endl << "**********Print in leveltorder **************" << endl;
	vector< vector<int> > levelvec = levelorderTraversal(root);
	cout << endl << "**********Print in leveltorder from bottom-up **************" << endl;
	vector< vector<int> > levelvecbottom = levelorderBottom(root);
	print(levelvecbottom);
	cout << endl << "**********Print in zigzag-leveltorder  **************" << endl;
	vector< vector<int> > zigzagvec = zigzagLevelOrder(root);
	print(zigzagvec);
	cout << endl << "********** is Symmetric Tree  **************" << endl;
	bool isSym = isSymmetric(root);
	cout << isSym << endl;
	system("pause");
	return 0;
}