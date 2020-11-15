#include <stdio.h>
#include <stdlib.h>

Link *StrIndex(LinkString *s, LinkString *t)
{

    Link *sp, *tp, *start;
    if (t->len == 0)
    {
        return s->head->Next;
    }
    start = s->head->Next;
    sp = start;
    tp = t->head->Next;
    while (sp != NULL && tp != NULL)
    {
        if (sp->data == tp->data)
        {
            sp = sp->Next;
            tp = tp->Next;
        }
        else
        {
            start = start->Next;
            sp = start;
            tp = t->head->Next;
        }
    }
    if (tp == NULL)
    {
        return start;
    }
    else
    {
        return NULL;
    }
}

int main(int argc, char const *argv[])
{

    return 0;
}
