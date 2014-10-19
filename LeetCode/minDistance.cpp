/*************************************************************************
Edit Distance Total Accepted: 14300 Total Submissions: 56571 My Submissions
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character

Link: https://oj.leetcode.com/problems/edit-distance/

@ By Chunting
@@ 2014.09.07

**************************************************************************/
#include<iostream>
using namespace std;
int minDistance(const string &word1, const string &word2) {
	const size_t n = word1.size();
	const size_t m = word2.size();
	int **f = new int*[n + 1];
	for (int i = 0; i < n + 1; ++i)
		f[i] = new int[m + 1];
	for (int i = 0; i <= n; ++i)
		f[i][0] = i;
	for (int j = 0; j <= m; ++j)
		f[0][j] = j;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (word1[i - 1] == word2[j - 1])
				f[i][j] = f[i - 1][j - 1];
			else {
				int min = f[i - 1][j] < f[i][j - 1] ? f[i - 1][j] : f[i][j - 1];
				f[i][j] = 1 + (min < f[i - 1][j - 1] ? min : f[i - 1][j - 1]);
			}
		}
	}
	return f[n][m];
}
int main() {
	const string word1 = "a";
	const string word2 = "b";
	cout << minDistance(word1, word2) << endl;
	return 0;
}