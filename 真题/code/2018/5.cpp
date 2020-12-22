#include <stdio.h>
#include <stdlib.h>

bool isComplete(BiTree T)
{
    InitQueue(Q);
    if (!T)
    {
        return true;
    }
    EnQueue(Q, T);
    while (!IsEmpty(Q))
    {
        DeQueue(Q, p);
        if (p)
        {
            EnQueue(Q, p->lchild);
            EnQueue(Q, p->rchild);
        }
        else
        {
            while (!IsEmpty(Q))
            {
                DeQueue(Q, p);
                if (p)
                {
                    return false;
                }
            }
        }
    }
    return true;
}