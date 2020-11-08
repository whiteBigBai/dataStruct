#include <iostream>
using namespace std;

typedef struct TreeNode {
	char data;
	struct TreeNode *fch;
	struct TreeNode *nsib;
} Tree;

void printTree(TreeNode *T) {
	TreeNode *p;
	if (T == NULL)
		return;
	if (T->fch != NULL) {
		for (p = T->fch; p != NULL; p = p->nsib)
			printf("%c%c  ", T->data, p->data);
	}
	if (T->nsib != NULL)
		printTree(T->nsib);

	if (T->fch != NULL)
		printTree(T->fch);
}

void CreateTree(TreeNode *&T) {

	char data;
	cin >> data;
	if (data == '#')
		T = NULL;
	else {
		T = new TreeNode;
		T->data = data;
		CreateTree(T->fch);
		CreateTree(T->nsib);
	}
}
int main(int argc, char **argv) {
	//A B E # # C G # # D # # #
	cout << "请输入二叉树的序列:" << endl;
	Tree *T;
	CreateTree(T);
	printTree(T);
	return 0;
}