#include< stdio.h >
#include< iostream >
using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode ( int x ): val( x ), next ( NULL ) {}
};
void printList( struct ListNode* head );
ListNode* swapPairs ( ListNode* head ) {
	  if ( head == NULL || head -> next == NULL ) {
            return head;
        }
        ListNode* cur = head;
        ListNode* curnext = head -> next;
        ListNode* newhead =  curnext;
        
        while ( curnext != NULL ) {
			ListNode* temp = cur;
            cur = curnext -> next;
            curnext -> next = temp;
            temp -> next = cur;
            if ( cur != NULL ) {
                curnext = cur -> next;
				if ( curnext != NULL )
					temp -> next = curnext;
            } else {
                break;
            }
        }
        return newhead;
}
void printList(ListNode* head){
	ListNode* cur=head;
	while(cur){
		cout<<cur->val<<endl;
		cur = cur->next;
	}
}
/*
int main(){
	ListNode *n1 = new ListNode(1);
	ListNode *n2 = new ListNode(2);
	ListNode *n3 = new ListNode(3);
 
	ListNode *n4 = new ListNode(4);
	ListNode *n5 = new ListNode(5);
	ListNode *n6 = new ListNode(6);
 
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	//printList(n1);
	n1 = swapPairs (n1);
	cout<<"***************"<<endl;
	printList(n1);
}
*/
