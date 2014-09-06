/********************************************************************
Sort a linked list using insertion sort.

	@Author Chun-Ting
	@Date: 5/28/2014
	@Version 1.0
	@Accept https://oj.leetcode.com/problems/insertion-sort-list/

*********************************************************************/


#include <stdio.h>
#include <iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x): val(x),next(NULL){}
};

/** This method is to return the node just before the insert point.  **/
ListNode* FindListPos ( ListNode* head, ListNode* nodePos ) {
	ListNode* h=head;
	if ( !h ) 
		return h;
	while ( h->next && h->next->val <= nodePos->val ){
		h=h->next;
	}
	return h;
}
ListNode* InsertListNode ( ListNode* head, ListNode* node ){
	ListNode* htemp = head;
	if ( !node )
		return node;
	if ( !htemp || htemp->val > node->val ) {
		ListNode* temp = new ListNode( node->val );
		temp->next = htemp;
		htemp = temp;
	} else {
		ListNode* temp = FindListPos( htemp, node );
		ListNode* newtemp=new ListNode(node->val);
		ListNode* tempnext = temp->next;
		temp->next = newtemp;
		newtemp->next = tempnext;
	}
	return htemp;
}
ListNode* insertSortList(ListNode *head){
	if (!head||!head->next)
		return head;
	ListNode * newhead=new ListNode(head->val);
	ListNode* cur = head->next;
	while( cur ) {
		newhead = InsertListNode( newhead, cur );
		cur = cur->next;
	}
	return newhead;
}
/*
void printList(ListNode* head){
	ListNode* cur=head;
	while(cur){
		cout<<cur->val<<endl;
		cur = cur->next;
	}
}


int main(){
	ListNode *n1 = new ListNode(2);
	ListNode *n2 = new ListNode(3);
	ListNode *n3 = new ListNode(4);
 
	ListNode *n4 = new ListNode(3);
	ListNode *n5 = new ListNode(4);
	ListNode *n6 = new ListNode(5);
 
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	printList(n1);
	n1 = insertSortList(n1);
	cout<<"***************"<<endl;
	printList(n1);

}
*/