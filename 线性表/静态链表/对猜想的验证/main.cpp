#include <stdio.h>
#include <stdlib.h>
#define MaxSize 10 //静态链表的最大长度

struct Node
{
    int data;
    int next;
};

typedef struct
{
    int data;
    int next;
} SLinkList[MaxSize];

int	main(int argc, char *argv[])
{
     struct Node x;
    printf("%d",sizeof(x));
    struct Node a[MaxSize];
    printf("%d",sizeof(a));
    SLinkList s;
    printf("%d",sizeof(s));
    return 0;
}

