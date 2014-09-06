/******************************************************************
Longest Consecutive Sequence 
Given an unsorted array of integers, find the length of the longest consecutive elements sequence. 

For example,
 Given [100, 4, 200, 1, 3, 2],
 The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4. 

Your algorithm should run in O(n) complexity. 


*******************************************************************/

#include< stdio.h >
#include< iostream >
#include< vector >
#include< algorithm >
using namespace std;
bool compareVec( const int& a, const int& b) {
	return a < b ;
}
int longestConsecutive(vector<int> &num) {
	int size = num.size();
    if( size < 2 )
		return size;
    sort( num.begin(), num.end(), compareVec );
    int len = 1;
    int flag = 1;
    for( int i = 1; i < size; ++i ) {
		if( num[i] - num[i-1] == 1 ) {
			flag++;   
        } else {
			if( flag > len ) {
				len = flag;
            }
            flag = 1;
        }
	}
    if( flag > len ) {
		len = flag;
    }
    return len;
}
