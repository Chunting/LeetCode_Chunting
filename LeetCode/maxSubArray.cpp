/*********************************************************************************************
Maximum Subarray Total Accepted: 24037 Total Submissions: 71190 My Submissions
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.

click to show more practice.

More practice:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

Link: https://oj.leetcode.com/problems/maximum-subarray/

Use the dynimic programming method.

@ By Chunting
@@2014.09.06
*********************************************************************************************/
#include <iostream>
using namespace std;
int maxSubArray( int A[], int n ) {
	int maxNum = A[0];
	int s = A[0];
	for ( int i=1; i<n; ++i ) {
		s = s>=0? s+A[i] : A[i];
		if ( s>maxNum )
			maxNum = s;
	}
	return maxNum;
}