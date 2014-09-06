#include< stdio.h >
#include< iostream >
using namespace std;
void mergeArray ( int A[], int m, int B[], int n ) {
	 int sA = m;
        int sB = n;
        while ( sA>0 && sB>0 ) {
            if( A[sA-1] > B[sB-1] ) {
                A[sA+sB-1] = A[sA-1];
                sA--;
            } else {
                A[sA+sB-1] = B[sB-1];
                sB--;
            }
        }
        if( sA == 0) {
            for ( int i = 0; i < sB; ++i ) {
                A[i] = B[i];
            }
        }
}
