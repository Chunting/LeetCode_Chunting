/* 
Substring with Concatenation of All Words
You are given a string, S, and a list of words, L, that are all of the same length. 
Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once 
and without any intervening characters.

For example, given:
S: "barfoothefoobarman"
L: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).

Leetcode: https://oj.leetcode.com/problems/substring-with-concatenation-of-all-words/
The difference between map and hash_map: http://blog.sina.com.cn/s/blog_54cae6d70100gem2.html
*/
#include<vector>
#include<iostream>
#include<string>
#include<stdio.h>
#include<map>
#include<hash_map>
using namespace std;

vector<int> findSubstring(string S, vector<string> &L) {
	vector<int> res;
	if (S.empty() || S.size() < 1 || L.size() < 1 || L.empty()) {
		return res;
	}
	hash_map<string, int > toFind;
	hash_map<string, int> Find;

	int arr_len = L.size();
	int str_len = L[0].length();
	int s_len = S.length();
	for (int i = 0; i < arr_len; ++i) {
		if (toFind.find(L[i]) == toFind.end()) {
			toFind[L[i]] = 1;
		}
		else {
			toFind[L[i]] ++ ;
		}
	}
	for (int i = 0; i < s_len - arr_len*str_len + 1; ++i) {
		Find.clear();
		int j = 0;
		for (j = 0; j < arr_len; ++j)
		{
			int k = i + j*str_len;
			string substr = S.substr(k, str_len);
			if (toFind.find(substr) == toFind.end()) 
				break;
			if (Find.find(substr) == Find.end()) {
				Find[substr] = 1;
			}
			else {
				Find[substr] ++;
			}
			if (Find[substr] > toFind[substr])
				break;
		}
		if (j == arr_len)
			res.push_back(i);
	}
	return res;
}