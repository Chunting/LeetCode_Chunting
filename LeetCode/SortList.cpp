/*********************************************************

Given an input string, reverse the string word by word. 

For example,
 Given s = "the sky is blue",
 return "blue is sky the". 
 
 @Author Chun-Ting
 @Date: 5/25/2014
 @Version 1.0
 @Accept 5/26/2014
 @https://oj.leetcode.com/problems/reverse-words-in-a-string/

 *********************************************************/
#include<string>
#include<vector>
#include<iostream>
#include<stdio.h>
using namespace std;
struct ListNode{
int val;
ListNode* next;
ListNode(int x):val(x),next(NULL){}

};
ListNode *sortList(ListNode *head) {
      if(!head)
		return NULL;
	int k=0;
	ListNode *p=head;
	while(p){
		k++;
		p=p->next;
	}	
	if(k==1)
		return head;
	p=head;
	int l=k/2;
	ListNode* q=head;
	ListNode* t=NULL;
	for(int i=0;i<l&&q;++i){
		if(i==l-1)
			t=q;
		q=q->next;
	}
	if(t)
		t->next=NULL;
	p=sortList(p);
	q=sortList(q);
	ListNode* hd=NULL;
	ListNode* pp=NULL;
	while(q&&p){
		if(p->val<=q->val){
			if(!hd)
				hd=pp=p;
			else{
				if(!hd->next)
					hd->next=pp;
				pp->next=p;
				pp=p;
			}
				p=p->next;
		}else{
			if(!hd)
				hd=pp=q;
			else{
				if(!hd->next)
					hd->next=pp;
				pp->next=q;
				pp=q;
			}				
			q=q->next;
		}
		
	}
	if(p){
		pp->next=p;
	}
	if(q){
		pp->next=q;
	}
	/*
	ListNode* tem=hd;
	while(tem){
		cout<<tem->val<<endl;
		tem=tem->next;
			}
	*/
	return hd;

	
}
/*
int main(){
	ListNode *head=new ListNode(1);
	ListNode *p1=new ListNode(2);
	head->next=p1;
	p1->next=NULL;
	sortList(head);

system("pause");
return 0;
}
*/