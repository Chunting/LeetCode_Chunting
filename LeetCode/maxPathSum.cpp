/****************************************************************
Binary Tree Maximum Path Sum      Total Accepted: 22260 Total Submissions: 110364 
Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.

Link: https://oj.leetcode.com/problems/binary-tree-maximum-path-sum/
By Chunting
2014-10-19
*****************************************************************/
#include<iostream>
#include<climits>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(): val(0), left( NULL ), right( NULL ) {}
	TreeNode( int x ): val( x ), left( NULL ), right( NULL ) {}
};
int max( int a, int b ) {
	return a > b ? a : b;
}
void solve( TreeNode* root, int& sum, int& path ) {
	if ( root == NULL ) {
		sum = INT_MIN/10;
		path = INT_MIN/10;
		return ;
	} else {
		int lsum = INT_MIN/10, lpath = INT_MIN/10;
		if( root->left != NULL ) {
			solve( root->left, lsum, lpath );
		}
		int rsum = INT_MIN/10, rpath = INT_MIN/10;
		if( root->right, rsum, rpath ) {
			solve( root->right, rsum, rpath );
		}
		path = max( root->val, max( lpath, rpath ) + root->val );
		sum = max( max( lsum, rsum ), lpath + rpath + root->val ); //If use lpath = rpath =INT_MIN, a problem will show up here.
		sum = max( sum, path );
	}
}
int maxPathSum(TreeNode *root) {
	if ( root == NULL ) {
		return INT_MIN/10;
	}
	int sum = INT_MIN/10;
	int path = INT_MIN/10;
	solve( root, sum, path );
	return sum;
}
