/*********************************************************

Given an input string, reverse the string word by word. 

For example,
 Given s = "the sky is blue",
 return "blue is sky the". 
 
 @Author Chun-Ting
 @Date: 5/24/2014
 @Version 1.0
 @Accept
 @https://oj.leetcode.com/problems/reverse-words-in-a-string/

 *********************************************************/
#include<string>
#include<vector>
#include<iostream>
using namespace std;

void reverseWords(string &s) {
        std::vector<std::string> result;
		std::string::size_type pos;
		string pattern=" ";
		if(!s.empty())   //make the format regular.
		    s+=pattern;
		int size=s.size();
		for(int i=0;i<size;++i)
		{
			pos=s.find(pattern,i);
			if(pos<size)
			{
				string s2=s.substr(i,pos-i);
				if(!s2.empty()){
				    result.push_back(s2);
				    i=pos+pattern.size()-1;
				}
			}
		}
		string news="";
		while(result.size()>0){
			news+=result.back()+pattern; //Once the size()>0, the new string will be always added a space at the end,it should be delete finally.
			result.pop_back();
		}
		if(news.size()>0) //Avoid from "a" to "a ";
		    news.resize(news.size()-1);
		s=news;
}
/*
int main(){
	string s=" ";
reverseWords(s);

system("pause");
return 0;
}
*/