#include "Traversal.h"
TreeNode* createTree(vector<int>& vec){
	if (vec.empty())
		return nullptr;
	TreeNode* root = new TreeNode(vec[0]);
	for (vector<int>::iterator it = vec.begin() + 1; it != vec.end(); ++it) {
		insertTreeNode(root, *it);
	}
	return root;

}
void insertTreeNode(TreeNode* root, int val) {
	if (root == nullptr)
		root = new TreeNode(val);
	else {
		if (root->val >= val){
			insertTreeNode(root->left, val);
			/*
			if ( root -> left != nullptr)
			insertTreeNode(root->left, val);
			else {
			root->left = new TreeNode(val);
			}
			*/
		}
		else{
			insertTreeNode(root->right, val);
		}
	}


}
/*
* Firstly, find the left leaf and push all the nodes in the path into stack;
* Secondly, take the top element of the stack( which is the left leaf node ), determine if (1) it has right child,
* and whether (2) the right child has been visited?
* If it has right child which is not been visited, then push the right sub tree into stack.
* If not, visite and print the node.
*/
vector<int> postorderTraversal(TreeNode* root) {
	vector<int> result;
	const TreeNode* p = root;  // The current visiting node; 
	const TreeNode* q;			// The last visited node;
	stack<const TreeNode*> s;
	do{
		while (p != nullptr) {
			s.push(p);
			p = p->left;
		}
		q = nullptr;
		while (!s.empty()) {
			p = s.top();
			s.pop();
			if (p->right == q || p->right == nullptr){
				result.push_back(p->val);
				q = p;
			}
			else {
				s.push(p);
				p = p->right;
				break;
			}
		}
	} while (!s.empty());
	return result;
}
vector<int> preorderTraversal(TreeNode* root) {
	vector<int> result;
	const TreeNode* p = root;
	stack< const TreeNode* > s;
	if (p != nullptr)
		s.push(p);
	while (!s.empty()) {
		p = s.top();
		s.pop();
		result.push_back(p->val);
		if (p->right != nullptr) {
			s.push(p->right);
		}
		if (p->left != nullptr) {
			s.push(p->left);
		}
	}
	return result;
}
vector<int> inorderTraversal(TreeNode* root) {
	vector<int> result;
	const TreeNode* p = root;
	stack< const TreeNode* > s;
	while (!s.empty() || p != nullptr) {
		if (p != nullptr) {
			s.push(p);
			p = p->left;
		}
		else {
			p = s.top();
			s.pop();
			result.push_back(p->val);
			p = p->right;
		}
	}
	return result;
}
/*
* For each level, set a flag nullptr to indiquer this level has been visisted.
*			 4			--> nullptr
*		   /   \
*		  2     6		--> nullptr
*		 / \   /  
*       1   3  5		--> nullptr
* Here we use a queue as auxiliary data structure, at the end of each level, push an nullptr into queue;
* So when meet with an nullptr, we should put it into the result and clear the level.
*/
vector<vector<int> > levelorderTraversal(TreeNode* root) {
	vector< vector<int>> result;
	if (root == nullptr)
		result;

	vector<int> level;
	TreeNode* p;
	queue< TreeNode*> q;
	q.push(root);
	q.push(nullptr);

	while (!q.empty()){
		p = q.front();
		q.pop();
		if (p != nullptr){
			level.push_back(p->val);
			if (p->left != nullptr)
				q.push(p->left);
			if (p->right != nullptr)
				q.push(p->right);
		}
		else {
			/*	If level is empty, that's to say the lowest level has been visited.
			*/
			if (!level.empty()) {
				q.push(nullptr);
				result.push_back(level);
				print(level);
				level.clear();
			}
		}
	}
	return result;

}
void print(vector<int> &vec) {
	for (vector<int>::iterator it = vec.begin(); it < vec.end(); ++it) {
		cout << *it << "	";
	}
	cout << endl;

}
