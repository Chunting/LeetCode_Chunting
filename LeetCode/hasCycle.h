#include<stdio.h>
#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode ( int x ): val (x), next (NULL){}
};
bool hasCycle(ListNode *head) {
	 if ( !head )
		return false;
	ListNode* first = head;
	ListNode* second = head->next;
	while ( first && second ) {
		if ( first == second )
			return true;
		first = first->next;
		if ( !second->next || !second->next->next )
		    return false;
		second = second->next->next;
	}
	return false;    
}

int main() {
	ListNode * 


}