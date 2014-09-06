#include <stdio.h>
#include <iostream>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode ( int x ) : val( x ), left( NULL ), right( NULL ){}
};
int sumNumbers ( TreeNode* root );
int getCurSum ( TreeNode* root, int pre, int sum );
int sumNumbers ( TreeNode* root ) {
	if ( root == NULL )
		return 0;
	int pre = 0;
	int path = 0;
	int sum = getCurSum( root, pre, path );
	return sum;
	
}

int getCurSum ( TreeNode* cur, int pre, int sum ) {
	if ( cur == NULL )
		return sum;
	if ( cur -> left == NULL && cur ->right == NULL ) {
		sum += pre*10 + cur -> val;
		return sum;
	}
	pre = pre*10 + cur -> val;
	sum = getCurSum( cur -> left, pre, sum );
	sum = getCurSum( cur -> right, pre, sum );
	return sum;
}
/*
int main () {
	TreeNode* t1 = new TreeNode ( 0 );
	TreeNode* t2 = new TreeNode ( 1 );
	//TreeNode* t3 = new TreeNode ( 3 );
	t1 -> left = t2;
	//t1 -> right = t3;
	int sum = sumNumbers( t1 );
	cout<<sum<<endl;

}
*/