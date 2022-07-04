#include<iostream>
#include<math.h>
using namespace std;
class Treenode {
public:
	int val;
	Treenode *left; 
	Treenode *right;
	Treenode(int root=NULL) {
		this->val = root;
		this->left = NULL;
		this->right = NULL;
	}
};
int max_depth(Treenode *node) {
	if (node==NULL) return 0;
	else {
		return max(max_depth(node->left), max_depth(node->right))+1;
	}
}
//int main() {
//	int n,root,child;
//	cin >> n;
//	/*Treenode *p= new Treenode[25];*/
//	Treenode p[25];
//	for (int i = 1; i <=n; i++)
//	{
//		p[i].val = i;
//	}
//	while (cin >>root>>child) {
//		if (!p[root].left) p[root].left = &p[child];
//		else p[root].right = &p[child];
//	}
//	cout << max_depth(&p[1]);
//	return 0;
//}