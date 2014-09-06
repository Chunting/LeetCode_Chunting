#include<stdio.h>
#include<iostream>
#include<set>
#include<string>
#include<vector>
using namespace std;
bool wordBreak ( string s, set<string> &dict ) {
	if ( s.empty() || dict.empty() )
		return false;
	int n = s.size();
	vector <bool> flag ( n+1, false );
	flag[0] = true;
	for ( int i=1; i<=n; ++i ) {
		if( flag[ i-1 ] ) {
			int index =  i-1;
			for ( int j=i; j<=n; ++j ) {
				string temp = s.substr( index, j-index );
				cout<< temp <<endl;
				if ( dict.count( temp ) > 0 ) {
					flag[ j ] = true;
				}
			}
		}
		
		
	}
return flag [n];
}
/*
int main() {
	string s = "aaaaaaa";
	set<string> dict;
	dict.insert( "aaa" );
	dict.insert( "aaaa" );
	//dict.insert( "gs" );
	bool ok;
	ok = wordBreak ( s, dict );
	cout << ok <<endl;
	system( "pause ");

return 0;
}
*/