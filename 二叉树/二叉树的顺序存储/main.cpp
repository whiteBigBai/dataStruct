#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100

struct ElemType
{
    int value;
};

struct TreeNode
{
    ElemType value; //结点中的数据元素
    bool isEmpty;   //结点是否为空
};

//定义一个长度为MaxSize的数组t，按照从上至下,从左至右的顺序
//依次存储完全二叉树中的各个结点 0下标不存储元素
TreeNode t[MaxSize];



void InitTree(TreeNode t[])
{
    for (int i = 0; i < MaxSize; i++)
    {
        t[i].isEmpty = true;
    }
}

int main(int argc, char *argv[])
{

    return 0;
}
