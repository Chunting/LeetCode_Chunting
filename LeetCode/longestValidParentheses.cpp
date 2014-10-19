#include<iostream>
#include<stdio.h>
#include<stack>
using namespace std;
int longestValidParentheses(string s) {
	if (s.size() <= 1)
		return 0;
	stack<int> sleft;
	int maxlen = 0;
	int start = 0;
	int n = s.size();
	for (int i = 0; i<n; ++i) {
		if (s[i] == '(') {
			sleft.push(i);  //The key issus is the index of '('that should be pushed into the stack, because we may use that index
		}
		else if (s[i] == ')') {
			if (!sleft.empty()) {
				sleft.pop();
				if (sleft.empty()) {
					if (maxlen < i - start + 1) {
						maxlen = i - start + 1;
					}
				}
				else {
					if (maxlen < i - sleft.top()) {
						maxlen = i - sleft.top();
					}
				}
			}
			else {
				start = i + 1;
			}
		}
		else {
			return -1;
		}
	}
	return maxlen;
}