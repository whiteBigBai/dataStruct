#include <iostream>
typedef int ElemType;

typedef struct LNode
{
    ElemType data;
    struct LNode *next;

} LNode, *LinkList;

bool ListInsert(LinkList &L, int i, ElemType e)
{
    if (i < 1)
        return false;
    LNode *p;  //指针p指向当前扫描到的结点
    int j = 0; //当前p指向的是第几个结点
    p = L;     //将p指向头结点（L指向头结点,头结点是第0个结点，不存储数据）
    while (p != NULL && j < i - 1)
    { //循环找到第i-1个节点
        p = p->next;
        j++;
    }
    if (p == NULL) //i值不合法
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next; //将s的next指向p的next
    p->next = s;       //把p和s连起来
    return true;
}

int main()
{
    return 0;
}