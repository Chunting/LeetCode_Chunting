#include <stdio.h>
#include <iostream>
using namespace std;
struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}

};
bool isSameTree(TreeNode *p, TreeNode *q) {
        if(!p&&!q) return true;
		bool lb,lr;
		if(p&&!q) return false;
		if(!p&&q) return false;
		if(p&&q){
			if(p->val!=q->val) return false;
			else{
				lb=isSameTree(p->left,q->left);
				lr=isSameTree(p->right,q->right);
				return lb&&lr;
			}
		}
		return true;
        
    }
/*
int main(){
	TreeNode *t1=new TreeNode(12);
	TreeNode *t2=new TreeNode(12);
	TreeNode *t3=new TreeNode(1);
	TreeNode *t4=new TreeNode(1);
	TreeNode *t5=new TreeNode(10);
	TreeNode *t6=new TreeNode(-12);
	
	t1->left=t3;
	t1->right=t5;
	t2->left=t4;
	t2->right=t6;
	
	
	bool b;
	
b=isSameTree(t1,t2);
cout<<b<<endl;
system("pause");
return 0;
}
*/