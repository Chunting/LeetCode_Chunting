/**
Reference : 
	1. http://www.javabeat.net/binary-search-tree-traversal-java/
	2. http://wenku.baidu.com/view/defd6bf4f61fb7360b4c653e.html



*/
#ifndef TRAVERSAL_H
#define TRAVERSAL_H
#include<vector>
#include<stack>
#include<iostream>
using namespace std;
struct TreeNode {
	int val;
	TreeNode * left;
	TreeNode * right;
	TreeNode(){};
	TreeNode(int x) : val(x), left(nullptr), right(nullptr){};
};
TreeNode* createTree(vector<int> vec);
void insertTreeNode(TreeNode* root, int val);
vector<int> postorderTraversal(TreeNode* root);
vector<int> preorderTraversal(TreeNode* root);
vector<int> inorderTraversal(TreeNode* root);
void print( vector<int> &vec);

#endif