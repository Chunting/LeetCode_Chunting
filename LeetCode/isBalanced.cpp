#include <stdio.h>
#include <iostream>
using namespace std;
struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode (int x ): val(x), left(NULL), right(NULL) {}
};
int getHeight (TreeNode * root ) {
        if ( root == NULL)
            return 0;
        int hl = 1;
        int hr = 1;
        if ( root->left == NULL && root->right == NULL) {
            return 1;
        }
        TreeNode* temp = root;
        if ( temp->left !=NULL ) {
            hl = getHeight( temp->left ) + 1;   
        }
        if ( temp->right )
            hr = getHeight( temp->right ) + 1;
        return hl > hr ? hl:hr ; 
        
    }
    bool isBalanced(TreeNode *root) {
        if ( root == NULL )
            return true;
        if ( root->left == NULL && root->right == NULL )
            return true;
        int hl = 0;
        int hr = 0;
        TreeNode* temp = root;
        hl = getHeight( temp -> left );
        hr = getHeight ( temp -> right);
        int t = hl - hr;
        if ( t < 2 && t > -2 ) {
            return isBalanced (temp->left) && isBalanced ( temp->right);
        }
        return false;
    }