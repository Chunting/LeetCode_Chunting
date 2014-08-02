#include "Traversal.h"
int main() {
	vector<int> vec;
	for (int i = 1; i < 8; ++i){
		vec.push_back(i);
	}
	TreeNode *root = nullptr;
	root = createTree(vec);
	vector<int> prevec = preorderTraversal(root);
	print(prevec);

	return 0;
}