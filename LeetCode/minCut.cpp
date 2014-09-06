/*****************************************************************************************************************
Palindrome Partitioning II Total Accepted: 14621 Total Submissions: 81085 My Submissions
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.

 s <- "abccdcba";
if p[i][j] = true
	f[i] <- min( n-i-1, f(j+1)+1 ); //because the substring s[i...j] is palindrome, so the minCut is s[j+1...n-1] plus 1;
if j-i<2 && s[i]=s[j]
	p[i][j] <- true;
if j-i>=2 && s[i] = s[j] && p[i+1][j-1]
	p[i][j] <- true



Link: https://oj.leetcode.com/problems/palindrome-partitioning-ii/
******************************************************************************************************************/
#include<iostream>
#include<vector>
using namespace std;
int minCut( string s ) {
	int len = s.size();
	vector<int> f; //represente the minCut from i to n-1;
	vector<vector<bool>> p(len, vector<bool>(len,false)); //representes if the substring ( from i to j ), is  palindrome.
	for( int i=0; i<=len; ++i ) {
		f.push_back( len-i-1 );
		//p[i][i] = true;
	}

	for (int i=len-1; i>=0; --i) {
		for (int j=i; j<len; ++j) {
			if (s[i] == s[j] && ( j-i<2 || p[i+1][j-1] )) {
				p[i][j] = true;
				f[i] = f[i] > f[j+1]+1 ? f[j+1]+1 : f[i];
			}
		}
	}
	return f[0];
}