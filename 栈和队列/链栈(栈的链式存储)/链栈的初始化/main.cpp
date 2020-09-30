#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct LinkNode{
    ElemType data;
    struct LinkNode  *next;
}*LiStack;