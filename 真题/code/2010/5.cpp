#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OVERFLOW -2
#define OK 1
#define ERROR 0

typedef int Status;
typedef char TElemType;

/*
 * 存储结构
 */
typedef struct BiTNode
{
	TElemType data; //数据
	struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

/*
 * 创建二叉树,输入0表示创建空树
 */
Status CreateBiTree(BiTree *T)
{
	TElemType e;
	scanf("%c", &e);
	if (e == '.')
	{
		*T = NULL;
	}
	else
	{
		*T = (BiTree)malloc(sizeof(BiTNode));
		if (!T)
		{
			exit(OVERFLOW);
		}
		(*T)->data = e;
		CreateBiTree(&(*T)->lchild); //创建左子树
		CreateBiTree(&(*T)->rchild); //创建右子树
	}
	return OK;
}

void swap(BiTree b)
{
	BiTNode *temp = (BiTNode *)malloc(sizeof(BiTNode));
	if (b)
	{
		swap(b->lchild);
		swap(b->rchild);
		temp = b->lchild;
		b->lchild = b->rchild;
		b->rchild = temp;
	}
}

/*
 * 访问元素
 */
void visit(TElemType e)
{
	printf("%c ", e);
}

/*
 * 先序遍历二叉树
 */
void PreOrderTraverse(BiTree T)
{
	if (T)
	{
		visit(T->data);
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
}

/*
 * 中序遍历二叉树
 */
void InOrderTraverse(BiTree T)
{
	if (T)
	{
		InOrderTraverse(T->lchild);
		visit(T->data);
		InOrderTraverse(T->rchild);
	}
}

/*
 * 后序遍历二叉树
 */
void PostOrderTraverse(BiTree T)
{
	if (T)
	{
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		visit(T->data);
	}
}

int main(int argc, char **argv)
{
	//AB.D..CE...
	BiTree T;
	printf("创建树，输入.为空树：\n");
	CreateBiTree(&T);
	printf("先序遍历：");
	PreOrderTraverse(T);
	printf("\n中序遍历：");
	InOrderTraverse(T);
	printf("\n后序遍历：");
	PostOrderTraverse(T);
	printf("\n");
	return 0;
}
