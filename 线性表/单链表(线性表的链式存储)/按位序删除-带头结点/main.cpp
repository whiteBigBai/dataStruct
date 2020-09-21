#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;

typedef struct LNode
{
    ElemType data;
    struct LNode *next;

} LNode, *LinkList;

bool ListDelete(LinkList &L, int i, ElemType &e)
{
    if (i == 1)
        return false;
    LNode *p;  //指针p指向当前扫描到的结点
    int j = 0; //当前p指向的是第几个结点
    p = L;     //L指向头结点,头结点是第0个结点（不存放数据）
    while (p != NULL && j < i - 1)
    { //循环找到第i-1个结点
        p = p->next;
        j++;
    }
    if(p==NULL) //i值不合法
        return false;
    if(p->next==NULL)//第i-1个结点之后已无其他结点
        return false;
    LNode *q=p->next;//令q指向被删除结点
    e=q->data;//用e返回元素的值
    p->next=q->next;//将*q结点从链中断开
    free(q);
    return true;
}

int	main(int argc, char *argv[])
{
    return 0;
}
