#include< stdio.h >
#include< iostream >
using namespace std;
int jump(int A[], int n) {
        if( n == 0 || n == 1 )
            return 0;
        if( n ==2 || A[0] >= n-1 )
            return 1;
        int* dp = new int[n];
        memset( dp, 0, n*sizeof(int));
        for( int i = 0; i < n; ++i ) {
            int maxj = A[i];
            if( maxj + i + 1 >= n ) {
                return dp[i] + 1 ;
            }
            for( int j = i + 1; j < maxj + i + 1; ++j ) {
                if( dp[j] == 0 ) {
                    dp[j] = dp[i] + 1;
                }
            }
        }
        return dp[n-1];
    }
/*
int main() {
	int A[250000];
	for( int i = 0; i < 250000; ++i ) {
		A[i] = i;
	}
	int minj = jump(A,250000);
	cout<< minj <<endl;

return 0;
}
*/