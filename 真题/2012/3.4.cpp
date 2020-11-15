#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct ThreadNode
{
    ElemType Data;
    struct ThreadNode *Lc, *Rc;
    int Ltag, Rtag;

} ThreadNode, *ThreadTree;

ThreadNode *InPre(ThreadNode *p)
{
    ThreadNode *pre, *q;
    if (p->Ltag == 1)
        pre = p->Lc;
    else
    {
        for (q = p->Lc; q->Rtag == 0; q = q->Rc)
        pre = q;
    }
    return pre;
}

int main(int argc, char const *argv[])
{

    return 0;
}
