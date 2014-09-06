/**************************************************************************************************************************
Triangle Total Accepted: 17192 Total Submissions: 64244 My Submissions
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

Link: https://oj.leetcode.com/problems/triangle/
C++Vector”√∑® : http://blog.csdn.net/pandy1110/article/details/5963908

@ By Chunting
@ @ 2014.09.06
************************************************************************************************************************/
#include <vector>
#include<iostream>
using namespace std;
int minimumTotal(vector<vector<int>> &triangle) {
        vector<int> s;
        int rows = triangle.size();
        if ( rows <2 )
            return triangle[0][0];
        for ( int j = 0; j<triangle[rows-1].size(); ++j ) {
			/* For the sake of performance, the operator [] does not check whether the index is a valid one. 
			Similar to a C-style array, using an invalid index will mostly buy you an access violation.
			Before use the operator[], the element should exist.
			So s[j] = triangle[rows-1][j], will not be accepted.
			*/
			s.push_back( triangle[rows-1][j]) ;
        }
        for ( int i = rows-2; i>=0; --i ) {
            for ( int j=0; j<triangle[i].size(); ++j ) {
                if ( s[j]>s[j+1])
                    s[j] = s[j+1] + triangle[i][j];
                    else 
                        s[j] += triangle[i][j];
            }
        }
        return s[0];
 }
