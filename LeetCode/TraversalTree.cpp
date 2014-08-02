#include "Traversal.h"
TreeNode* createTree(vector<int>& vec){
	if (vec.empty())
		return nullptr;
	TreeNode* root = new TreeNode(vec[0]);
	for (vector<int>::iterator it = vec.begin() +1; it != vec.end(); ++it) {
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
vector<int> postorderTraversal(TreeNode* root) {
	vector<int> result;
	const TreeNode* p = root;  // The current visiting node; 
	const TreeNode* q;			// The last visited node;
	stack<const TreeNode*> s;
	do{
		/*
		* Firstly, find the left leaf and push all the nodes in the path into stack;
		* Secondly, take the top element of the stack( which is the left leaf node ), determine if (1) it has right child, 
		* and whether (2) the right child has been visited?
		* If it has right child which is not been visited, then push the right sub tree into stack.
		* If not, visite and print the node.
		*/
		while( p != nullptr ) {
			s.push(p);
			p = p -> left;
		}
		q = nullptr;
		while( !s.empty() ) {
			p = s.top();
			s.pop();
			if( p -> right == q || p ->right == nullptr ){
				result.push_back( p -> val );
				q = p;
			} else {
				s.push( p );
				p = p ->right;
				break;
			}
		}
	} while( !s.empty() ) ;
	return result;
}
vector<int> preorderTraversal( TreeNode* root ) {
	vector<int> result;
	const TreeNode* p = root;
	stack< const TreeNode* > s;
	if( p != nullptr ) 
		s.push( p );
	while( !s.empty() ) {
		p = s.top();
		s.pop();
		result.push_back( p->val );
		if( p -> right != nullptr ) {
			s.push( p -> right );
		}
		if( p -> left != nullptr ) {
			s.push( p -> left );
		}
	}
	return result;
}
vector<int> inorderTraversal( TreeNode* root ) {
	vector<int> result;
	const TreeNode* p = root;
	stack< const TreeNode* > s;
	while( !s.empty() || p != nullptr ) {
		if( p != nullptr ) {
			s.push( p );
			p = p -> left;
		} else {
			p = s.top();
			s.pop();
			result.push_back( p -> val );
			p = p -> right;
		}
	}
	return result;
}
void print(vector<int> &vec) {
	for (vector<int>::iterator it = vec.begin(); it < vec.end(); ++it) {
		cout << *it << endl;
	}

}