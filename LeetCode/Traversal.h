/**
Reference : 
	1. http://www.javabeat.net/binary-search-tree-traversal-java/
	2. http://wenku.baidu.com/view/defd6bf4f61fb7360b4c653e.html
Data Structure: Stack
	To traversal a tree, we use a stack as auxiliary data structure and put the result in a vector.
	Via the push() and pop() to get the right order.



*/
#ifndef TRAVERSAL_H
#define TRAVERSAL_H
#include<vector>
#include<stack>
#include<queue>
#include<iostream>
using namespace std;
struct TreeNode {
	int val;
	TreeNode * left;
	TreeNode * right;
	TreeNode(){};
	TreeNode(int x) : val(x), left(nullptr), right(nullptr){};
};
TreeNode* createTree(vector<int>& vec);
void insertTreeNode(const TreeNode* root, int val);
vector<int> postorderTraversal(const TreeNode* root);
vector<int> preorderTraversal(const TreeNode* root);
vector<int> inorderTraversal(const TreeNode* root);
vector<vector<int>> levelorderTraversal( const TreeNode* root);
vector<vector<int>> levelorderBottom(const TreeNode* root);
vector<vector<int>> zigzagLevelOrder(const TreeNode *root);
bool isSymmetric(const TreeNode* root);

void print( vector<int> &vec);
void print(vector<vector<int>> & vecvec);

#endif