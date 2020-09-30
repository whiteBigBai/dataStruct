#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct DNode
{
    ElemType data;
    struct DNode *prior, *next;
} DNode, *DLinkList;

/**
 * 遍历双链表
 **/
void TraversalList(DNode *p)
{
    //后向遍历
    while (p != NULL)
    {
        //对结点p做相应处理，如打印
        p = p->next;
    }
    //前向遍历
    while (p != NULL)
    {
        //对p结点做相应处理
        p = p->prior;
    }
    //前向遍历，跳过头结点
    while (p->prior != NULL)
    {
        //对p结点做相应处理
        p = p->prior;
    }
}

int	main(int argc, char *argv[])
{
    return 0;
}