/************************************************
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321 

click to show spoilers.

Have you thought about this? 
Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!

If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.

Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?

Throw an exception? Good, but what if throwing an exception is not an option? You would then have to re-design the function (ie, add an extra parameter).

	@Author Chun-Ting
	@Date: 5/26/2014
	@Version 1.0
	@Accept https://oj.leetcode.com/problems/reverse-integer/
************************************************/
#include<stdio.h>
#include<iostream>
using namespace std;
int reverse(int x) {
        if(x==0) return x;
        int a=0;
        int b=0;
      while(x!=0){  
            a=x%10;
            b=b*10+a;
            x=x/10;
      }
      return b;
    }
/*
int main(){
int a=0;
scanf("%d",&a);
a=reverse(a);
cout<<a<<endl;
system("pause");
return 0;
}
*/