/****************************************************************************
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
 Given binary tree {1,#,2,3},

   1
    \
     2
    /
   3

return [1,2,3]. 

Note: Recursive solution is trivial, could you do it iteratively?

	@Author Chun-Ting
	@Date: 5/28/2014
	@Version 1.0
	@Accept https://oj.leetcode.com/problems/binary-tree-preorder-traversal/
*****************************************************************************/
#include<stdio.h>
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<cmath>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode ( int x ): val(x), left(NULL), right(NULL){}
};
void printVector ( vector<int> vec );
void printTree ( TreeNode* head );

/*********************************************
Stack is a good tool to traverse a tree.
As for the preorderTraversal, the order is always root->right->left, with the properties of stack, you can use
top() to get stack top and continue for the left child.

***********************************************/
vector<int> preorderTraversal( TreeNode *root ) {
    vector<int> preorder;
	stack< TreeNode* > treestack;
	if ( !root ) {
		return preorder;
	}
	treestack.push( root );
	while ( treestack.size() > 0 ) {
		TreeNode* temp = treestack.top();
		treestack.pop();
		if ( temp->right ) {
			treestack.push( temp->right );
		}
		if ( temp->left ) {
			treestack.push( temp->left );
		}
		preorder.push_back( temp->val );
	}
       return preorder;
}
/************************
In the postorderTraversal, there are two stacks, one is to store the TreeNode,
and the other is to mark if its left and right children are traversed, if so, the bool value is true, otherwise is false;
If the flag is true, it's time to pop it from the stack and push the value into the vector, what's more, 
don't forget to pop the bool flag.


**************************/
vector<int> postorderTraversal( TreeNode *root ) {
	vector<int> vec;
	if ( !root ) 
		return vec;
	stack<TreeNode*> pstack;
	stack<bool> bstack; 
	pstack.push ( root );
	bstack.push ( false );
	while ( pstack.size() > 0 ) {
		TreeNode* temp = pstack.top();		
		bool btemp = bstack.top();
		if ( btemp ) {
			vec.push_back ( temp->val );
			pstack.pop();
			bstack.pop();
			continue;
		}
		bstack.pop();
		bstack.push(true);
		if( temp->right ) {
			pstack.push( temp->right );
			bstack.push( false );
		}
		if ( temp->left ) {
			pstack.push( temp->left );
			bstack.push( false );	
		}
		if( !temp->right && !temp->left ) {
			vec.push_back ( temp->val );
			pstack.pop();
			bstack.pop();
			//bstack.push ( true );
		}
	}
	return vec;
}
vector<int> inorderTraversal(TreeNode *root) {
	vector<int> vec;
	if ( !root )
		return vec;
	stack<TreeNode*> instack;
	instack.push ( root );
	while ( instack.size() ) {
		TreeNode* temp=instack.top();
		instack.pop();
		if ( temp->right ) {
			instack.push( temp->right );
		}
		vec.push_back( temp->val );
		if ( temp->left ) {
			instack.push( temp->left );
		}
		
	}
	return vec;
}

int getdepth( TreeNode* root ){
	if ( !root ) 
		return 0;
	int depth = 1;
	TreeNode * temp = root->left;
	if ( root->left )
		depth = getdepth( root->left ) + 1;
	if ( root->right )
		depth =  getdepth( root->right ) + 1;
	return depth;
}
vector<vector<int> > levelOrder(TreeNode *root) {
	vector< int > level;
	vector< vector< int> > vec;
	if ( !root )
		return vec;
	queue< TreeNode* > levelnode;
	levelnode.push ( root );
	levelnode.push ( NULL );
	while ( true ) {
			TreeNode *temp = levelnode.front();
			levelnode.pop();
			if ( !temp ) {			
				vec.push_back ( level );
				level.clear();
				if ( levelnode.empty() )
					break;
				levelnode.push( NULL );
			}else {
				level.push_back( temp->val );
				if ( temp->left ) {
					levelnode.push( temp->left );
				} 
				if ( temp->right ) {
					levelnode.push( temp->right );
				}
			}

	}
	
	return vec;
}

void printTree (TreeNode* root) {
	if ( root ){
		cout<<root->val<<endl;
		printTree( root->left );
		printTree( root->right );
	}
}
void printVector ( vector<int> vec ) {
	int size = vec.size();
	if ( size>0 ) {
		for ( int i=0; i<size; ++i) {
			cout<< vec.at(i)<<endl;
		}
	}
}
/*
int main() {
	TreeNode* root = new TreeNode(1);
	TreeNode* t1 = root;
	TreeNode* t2 = new TreeNode(2);
	TreeNode* t3 = new TreeNode(3);
	TreeNode* t4 = new TreeNode(4);
	TreeNode* t5 = new TreeNode(5);
	for (int i = 0; i < 50; ++i) {
		TreeNode* temp = new TreeNode( i );
		t1->left = temp;
		t1 = temp;
	}
	//t1->right = t3;
	//t1->left = t2;
	//t2->left = t3;
	//t3->left = t4;
	//t4->left = t5;
	printTree ( root );
	cout<<"*********************"<<endl;
	vector<int> arr;
	vector< vector<int> > vecarr;
	//arr = preorderTraversal( t1 );
	//arr = postorderTraversal ( t1 );
	//arr = inorderTraversal ( t1 );
	vecarr = levelOrder( root );
	int size = vecarr.size();
	for ( int i=0; i<size; ++i ) {
		
		if ( !vecarr[i].empty() ) {
			cout<<"+++++++++"<<endl;
			printVector ( vecarr[i] );
		}
		
		

	}
	system( "pause" );
	return 0;

}

*/
