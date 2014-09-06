/***********************************************************
Remove Element 
Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Comment: If you need to chose exactly one action form given set of actions, depending on some conditions, the natural and
		 most clear choice is either swith ( don't forget to break after each branch ) or combination of if and else.
		 So pay attention that only one action will be performed in the branch.

	@Author Chun-Ting
	@Date: 06/15/2014
	@Version 1.0
	@Accept https://oj.leetcode.com/problems/remove-element/

************************************************************/

#include < stdio.h >
#include < iostream >
using namespace std;
int removeElement(int A[], int n, int elem) {
	int count = 0;
	for ( int i = 0; i < n; ++i ) {
		if( A[i] == elem ) {
			count++;
		} else if ( count > 0 ){
			A[ i-count] = A[i];
		}
	}
	return n - count;
}
/**
int main() {
	int A[4] = { 1,2,2,3 };
	int newlenth = 0;
	newlenth = removeElement( A, 4, 2 );
	for ( int i = 0; i< 3; ++i ) {
		cout<< A[i] <<"   " ;
	}
		cout << endl;
		cout <<"new length: "<< newlenth <<endl;
	system( "pause");
	return 0;
}
*/