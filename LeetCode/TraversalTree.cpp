#include "Traversal.h"
vector<int> postorderTraversal(TreeNode* root) {
	vector<int> result;
	const TreeNode* p = root;  // The current visiting node; 
	const TreeNode* q;			// The previous visited node;
	stack<const TreeNode*> s;
	do{
		/*
		* Firstly, put the left sub tree into the stack
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