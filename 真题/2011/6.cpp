#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100

typedef struct BiTNode //二叉树的节点结构
{
	char data;						 //此处用char  因为数据设用字母
	struct BiTNode *lchild, *rchild; //左右孩子指针
} BiTNode, *BiTree;

typedef struct SeqQueue
{
	BiTree data[MaxSize];
	int front, rear;
} SeqQueue;

void InitQueue(SeqQueue &Q)
{
	Q.front = Q.rear = 0; //初始时，队头和队尾指针都指向0
}

bool EnQueue(SeqQueue &Q, BiTree e)
{
	if ((Q.rear + 1) % MaxSize == Q.front) //队列满报错
		return false;
	Q.data[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MaxSize; //队尾指针加1取模
	return true;
}

/**
 * @description:  出队操作
 * @param {type} 
 * @return {type} 
 */
bool DeQueue(SeqQueue &Q, BiTree &e)
{
	if (Q.front == Q.rear) //队空，报错
		return false;
	e = Q.data[Q.front];
	Q.front = (Q.front + 1) % MaxSize;
	return true;
}

bool IsEmpty(SeqQueue Q)
{
	if (Q.rear == Q.front) //队空条件
		return true;
	else
		return false;
}

//二叉树的层次遍历
void LevelOrder(BiTree T)
{
	SeqQueue Q;
	BiTree p;
	InitQueue(Q);  //初始化辅助队列
	EnQueue(Q, T); //根结点入队
	while (!IsEmpty(Q))
	{						   //队列不为空则循环
		DeQueue(Q, p);		   //队头出队
		printf("%c", p->data); //访问出队结点
		if (p->lchild != NULL)
			EnQueue(Q, p->lchild);
		if (p->rchild != NULL)
			EnQueue(Q, p->rchild);
	}
}

void CreateBiTree(BiTree &T)
{
	char ch;
	scanf("%c", &ch);
	if (ch == '#')
		T = NULL;
	else
	{
		T = (BiTree)malloc(sizeof(BiTree));
		T->data = ch;			 //给节点的数据域赋值
		CreateBiTree(T->lchild); //递归创建左子树
		CreateBiTree(T->rchild); //递归创建右子树
	}
	return;
}

void PreOrderT(BiTree T)
{
	if (T) //如果该树节点存在
	{
		printf("%c", T->data); //先序遍历
		PreOrderT(T->lchild);
		PreOrderT(T->rchild);
	}
}
void InOrderT(BiTree T)
{
	if (T) //如果该树节点存在
	{
		InOrderT(T->lchild); //中序遍历
		printf("%c", T->data);
		InOrderT(T->rchild);
	}
}
void PostOrder(BiTree T)
{
	if (T) //如果该树节点存在
	{
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		printf("%c", T->data);
	}
}

int main(int argc, char **argv)
{
	//AB#D##C##
	//AB#CD###E#F##
	//AB#D##CE###
	BiTree T = NULL; //先定义一个树节点指针，指向第一个树节点，也就是根节点
	printf("请输入二叉树的数据，并以#为空节点\n");
	CreateBiTree(T);
	printf("该树的先序遍历结果为：");
	PreOrderT(T);
	printf("\n");
	printf("该树的中序遍历结果为：");
	InOrderT(T);
	printf("\n");
	printf("该树的后序遍历结果为：");
	PostOrder(T);
	printf("\n");
	LevelOrder(T);
	return 0;
}
