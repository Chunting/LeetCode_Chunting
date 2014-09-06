#include< stdio.h >
#include< iostream >
#define N 3;

using namespace std;

int climbStairs ( int& n) {
	if ( n == 0 )
		return 0;
	if ( n == 1 )
		return 1;
	if ( n ==2 )
		return 2;

	int* ways = new int[ n+1 ]; // Pay attention that it should be new int[n+1], not new int(n+1) !!
	memset( ways, 0, (n+1)*sizeof( int ));
	ways[1] = 1;
	ways[2] = 2;
	for ( int i =3; i < n+1; ++i ){
		ways[i] = ways[i-1] + ways[i-2];
	}
	return ways[n];
}
/******************************************
int main () {
	int n = 10;
	int ways = climbStairs( n );
	cout<< "ways: " <<ways << endl;
	system( "pause");
	return 0;
}
*******************************************/