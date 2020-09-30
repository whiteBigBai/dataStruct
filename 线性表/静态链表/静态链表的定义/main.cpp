#include <stdio.h>
#include <stdlib.h>
#define MaxSize 10 //静态链表的最大长度
typedef int ElemType;
struct Node //静态链表结构类型的定义
{
    ElemType data; //存储数据元素
    int next; //下一个数组元素的下标
};

int	main(int argc, char *argv[])
{
    struct Node a[MaxSize]; //数组a为静态链表

    return 0;
}
