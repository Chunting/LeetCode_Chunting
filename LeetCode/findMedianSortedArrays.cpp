/**************************************************************************
There are two sorted arrays A and B of size m and n respectively. 
Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

	@Author Chun-Ting
	@Date: 06/01/2014
	@Version 1.0
	@Accept https://oj.leetcode.com/problems/median-of-two-sorted-arrays/

***************************************************************************/


#include< stdio.h >
#include< iostream>
using namespace std;


/** Find the k-th value **/
double findKthSortedArrays ( int A[], int m, int B[], int n, int k ) {
	if ( m > n )
		return findKthSortedArrays( B, n, A, m, k );
	if ( m == 0 )
		return B[k-1];
	if ( k == 1 )
		return A[0] < B[0] ? A[0] : B[0]; 
	int med = m < k/2 ? m : k/2 ;
	bool flag =false;
	// If k is odd, then med++
	if ( k%2 !=0 && med !=m ){
		med = med + 1;
		flag = true;
	}
	if ( A[med-1] == B[med-1] )
		return A[med-1];
	if ( A[med-1] < B[med-1] ) {
		// if med has been changed, it should be recoveried.
		if ( flag )
			med--;
		return findKthSortedArrays(	A+med , m-med, B, n, k-med ); 
	} else {
			if ( flag )
			med--;
		return findKthSortedArrays(	A , m, B+med, n-med, k-med ); 
	}
}

double findMedianSortedArrays(int A[], int m, int B[], int n) {
	double ans1 = findKthSortedArrays( A, m, B, n, (m+n)/2+1 );
	double ans2;
	if ( (m+n)%2==0 ) {
		ans2 = findKthSortedArrays ( A, m, B, n, (m+n)/2 );
		return (ans1+ans2)/2;
	}
	return ans1;    
}
/**
int main () {
	int A[] = {1,3};
	int B[] = {1,3,11,12};
	double ans = 0;
	ans = findMedianSortedArrays( A, 2, B, 2 );
	cout<< ans <<endl;
	return 0;
}
**/