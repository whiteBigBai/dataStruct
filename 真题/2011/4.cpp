#include <stdio.h>
#include <stdlib.h>
typedef struct BiTNode //二叉树的节点结构
{
    char data;                       //此处用char  因为数据设用字母
    struct BiTNode *lchild, *rchild; //左右孩子指针
}BiTNode, BiTree;

void CreateBiTree(BiTree *&T); //创建二叉树
void PreOrderT(BiTree *T);       //先序遍历
void InOrderT(BiTree *T);        //中序遍历
void PostOrder(BiTree *T);       //后序遍历

void CreateBiTree(BiTree *&T)
{
    char ch;
    scanf("%c", &ch);
    if (ch == '#')
        T=NULL;
    else{
		T = (BiTree *)malloc(sizeof(BiTree));
		T->data = ch;                        //给节点的数据域赋值
		CreateBiTree(T->lchild); //递归创建左子树
		CreateBiTree(T->rchild); //递归创建右子树
	}
    return;
}
void PreOrderT(BiTree *T)
{
    if (T) //如果该树节点存在
    {
        printf("%c", T->data); //先序遍历
        PreOrderT(T->lchild);
        PreOrderT(T->rchild);
    }
}
void InOrderT(BiTree *T)
{
    if (T) //如果该树节点存在
    {
        InOrderT(T->lchild); //中序遍历
        printf("%c", T->data);
        InOrderT(T->rchild);
    }
}
void PostOrder(BiTree *T)
{
    if (T) //如果该树节点存在
    {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        printf("%c", T->data);
    }
}

//度为0的结点数目

void LeafCount_0(BiTree *T,int &count){
	if(T!=NULL){
		LeafCount_0(T->lchild,count);
		LeafCount_0(T->rchild,count);
		if(T->lchild==NULL&&T->rchild==NULL){
			count++;
		}
	}
}



//度为1的结点数目

void LeafCount_1(BiTree *T,int &count){
	if(T!=NULL){
		LeafCount_1(T->lchild,count);
		LeafCount_1(T->rchild,count);
		if((T->lchild==NULL&&T->rchild!=NULL)||
			(T->lchild!=NULL&&T->rchild==NULL)){
			count++;
		}
	}
}


int main(int argc, char **argv)
{
    //AB#D##C##
    //AB#CD###E#F##
    //AB#D##CE###
    BiTree *T=NULL; //先定义一个树节点指针，指向第一个树节点，也就是根节点
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
    
    int  count_0=0;
    int  count_1=0;
    LeafCount_0(T,count_0);
    printf("LeafCount_0 : %d\n",count_0);
    LeafCount_1(T,count_1);
    printf("LeafCount_1 : %d\n",count_1);
    return 0;
}
