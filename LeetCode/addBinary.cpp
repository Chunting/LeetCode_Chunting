/****************************************************************
Add Binary 
Given two binary strings, return their sum (also a binary string). 

For example,
 a = "11"
 b = "1"
 Return "100". 




*****************************************************************/
#include< stdio.h >
#include< iostream >
#include< string >
using namespace std;
string addBinary(string a, string b) {
	if( a.empty() )
		return b;
	if( b.empty() )
		return a;
	int alen = a.length();
	int blen = b.length();
	int flag = 0;
	string c;
	while( alen > 0 && blen > 0 ) {
		int num = (int)( a[alen-1] - '0' ) + (int)( b[blen-1] - '0' ) + flag;
		flag = num/2;
		c = ( char )( num%2 +'0' ) + c;
		alen --;
		blen --;
	}
	while( alen > 0) {
		int num = a[alen-1] - '0' + flag;
		flag = num/2;
		c = (char)(num%2 + '0' ) + c;
		alen --;
	}
	while( blen > 0 ) {
		int num = b[blen-1] - '0' + flag;
		flag = num/2;
		c = (char)(num%2 + '0' ) + c;
		blen --;
	}
	if( flag != 0 )
		c = (char)( flag + '0' ) + c;
	return c;
}
/**
int main() {
	string a = "111";
	string b = "10";
	string c = addBinary( a, b );
	cout<< c << endl;
	system("pause");
	return 0;
}
**/