#include<vector>
#include<iostream>
#include<string>
#define MAXLEN 50
int dp[MAXLEN][MAXLEN];
using namespace std;
int LCS(string A, string B);
vector<char> Print(string A,string B);
vector<char> common;
int LCS(string A, string B) {
	int len_A = A.size();
	int len_B = B.size();
	int maxlen = 0;

	if ( len_A == 0 || len_B == 0 )
		return 0;
	//int **dp = new int[MAXLEN][MAXLEN];
	for ( int i = 0; i<len_A +1; ++i) {
		dp[i][0] = 0;
	}
	for ( int j=0; j<len_B+1; ++j) {
		dp[0][j] = 0;
	}
	for( int i=1; i<len_A+1; ++i) {
		for ( int j=1; j<len_B+1; ++j) {
		// Take care of this, it's i-1 and j-1, not i or j.
			if ( A[i-1] == B[j-1] ) {
				dp[i][j] = dp[i-1][j-1] + 1;
			} else if ( dp[i-1][j] > dp[i][j-1] ) {
				dp[i][j] = dp[i-1][j];
			} else {
				dp[i][j] = dp[i][j-1];
			}
		}
	}
	maxlen = dp[len_A][len_B];
	return maxlen;
}
vector<char> Print(string A, string B) {
	int apos = A.size();
	int bpos = B.size();
	int len = dp[apos][bpos];
	//vector<char> common;
	common.resize(len);
	while( apos&&bpos ) {
		if( dp[apos][bpos] == dp[apos-1][bpos-1] + 1 ) {
			common[--len] = A[--apos];
			--bpos;
		} else if ( dp[apos-1][bpos] >= dp[apos][bpos-1] ) {
			apos--;
		} else {
			bpos--;
		}
	}
	return common;
}
int main() {
	string A = "ABCBDABCAB";
	string B = "BDCABAAC";
	int lcs_len = LCS(A, B);
	cout << " max common len: " << lcs_len << endl;
	Print(A, B);
	for ( int k = 0; k<lcs_len; ++k ) {
		cout<<common[k]<<"  ";
	}	
	cout<<endl;
	system("pause");
	return 0;
}