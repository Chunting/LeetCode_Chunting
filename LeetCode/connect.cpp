/************************************************************
Populating Next Right Pointers in Each Node 
Given a binary tree 
    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }

Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note: 
?You may only use constant extra space.
?You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).


For example,
 Given the following perfect binary tree,

         1
       /  \
      2    3
     / \  / \
    4  5  6  7

After calling your function, the tree should look like:

         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL

	@Author Chun-Ting
	@Date: 06/11/2014
	@Version 1.0
	@Accept https://oj.leetcode.com/problems/populating-next-right-pointers-in-each-node/

*************************************************************/




#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

struct TreeLinkNode {
	int val;
	TreeLinkNode* left;
	TreeLinkNode* right;
	TreeLinkNode* next;
	TreeLinkNode ( int x ): val( x ), left( NULL ), right( NULL ), next( NULL ) {}
};

void connect ( TreeLinkNode* root ) {
	if ( root == NULL )
		return ;
	queue< TreeLinkNode* > Tqueue;
	Tqueue.push( root );
	Tqueue.push( NULL );
	while ( true ) {
		TreeLinkNode* cur = Tqueue.front();
		Tqueue.pop();
		if ( Tqueue.empty() ) {
			if ( cur == NULL )
				break;
			else {
				cur -> next = NULL;
		}
		TreeLinkNode* curnext = Tqueue.front();
		if ( cur != NULL ) {
			cur -> next = curnext;
			if ( cur -> left != NULL )
				Tqueue.push( cur -> left );
			if ( cur -> right != NULL )
				Tqueue.push ( cur -> right );
		} else {
			Tqueue.push ( NULL );
		}


	}


}