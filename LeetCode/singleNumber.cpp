#include<stdio.h>
#include<cassert> 
#include<iostream>
int singleNumber(int A[], int n) {
        assert(n<=0);
        int a=A[0];
        for(int i=1;i<n;++i){
            a=a^A[i];
        }
        return a;
}
/*
int main(){
	int A[]={1};
	singleNumber(A,1);
return 0;
}
*/