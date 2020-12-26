#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <iostream>
using namespace std;

typedef struct node
{
	struct node *fch;
	char data;
	struct node *nsib;
	int level;
} NODE;

typedef NODE *TREE;

#define SET(pos, c, l)						\
{                                       	\
		pos = (NODE *)malloc(sizeof(NODE)); \
		pos->data = c;                      \
		pos->level = l;                     \
		pos->fch = NULL;                    \
		pos->nsib = NULL;                   \
		return pos;                         \
}

void Display(TREE tree);

TREE InitTree()
{
	TREE tree;
	SET(tree, '\0', 0);
}

TREE Insert(TREE tree, char data, int level)
{
	assert(tree);
	if (tree->level == level - 1)
	{
		SET(tree->fch, data, level);
	}
	if (tree->level == level)
	{
		SET(tree->nsib, data, level);
	}
	return NULL;
}

int main()
{
	TREE T = InitTree(), temp1, temp2, temp3, temp4;
	temp1 = Insert(T, 'A', 1);
	temp2 = Insert(temp1, 'B', 2);
	temp3 = Insert(temp2, 'C', 2);
	Insert(temp3, 'D', 2);
	temp4 = Insert(temp2, 'E', 3);
	Insert(temp4, 'F', 3);
	Insert(temp3, 'G', 3);
	cout << "树的各条边分别是：" << endl;
	Display(T->fch);
	cout << endl;
}

void Display(TREE tree)
{
	NODE *p;
	if (tree == NULL)
	{
		return;
	}
	if (tree->fch != NULL)
	{
		for (p = tree->fch; p != NULL; p = p->nsib)
		{
			printf("%c%c,", tree->data, p->data);
		}
	}

	if (tree->nsib != NULL)
	{
		Display(tree->nsib);
	}
	if (tree->fch != NULL)
	{
		Display(tree->fch);
	}
}