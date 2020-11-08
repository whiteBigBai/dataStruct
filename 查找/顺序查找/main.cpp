#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;

typedef struct
{                   //查找表的数据结构(顺序表)
    ElemType *elem; //元素存储空间基址，建表时按实际长度分配,0号单元留空
    int TableLen;   //表的长度
} SSTable;

//顺序查找

int Search_Seq(SSTable ST, ElemType key)
{
    int i;
    for (i = 0; i < ST.TableLen && ST.elem[i] != key; ++i)
        //查找成功，则返回元素下标；查找失败，则返回-1
        return i == ST.TableLen ? -1 : i;
}

int Search_Seq1(SSTable ST, ElemType key)
{
    ST.elem[0] = key;                                 //"哨兵"
    for (int i = ST.TableLen; ST.elem[i] != key; --i) //从后往前找
        return i;                                     //若表中不存在关键字位key的元素，将查找到i位0时退出for循环  
                                                      //查找成功 返回元素下标 查找失败 返回0
}