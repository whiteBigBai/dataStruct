#include <stdio.h>
#include <stdlib.h>
typedef struct StringNode //存储密度低：每个字符1B 每个指针4B
{
    char ch; //每个结点存1个字符
    struct StringNode *next;
} StringNode, *String;

typedef struct StringNode1
{

    char ch[4];//每个结点存多个字符
    struct StringNode1 *next;
} StringNode1, *String1;