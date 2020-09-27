#include <stdio.h>
#include <stdlib.h>
#define MaxLen 255 //预定义最大串长为255
typedef struct
{                    //静态数组实现(定长顺序存储)
    char ch[MaxLen]; //每个分量存储一个字符
    int length;      //串的实际长度
} SString;

/**
 * @description:  求模式串T的next数组
 * @param {type} 
 * @return {type} 
 */
void GetNext(SString T, int next[])
{
    int i = 1, j = 0;
    next[1] = 0;
    while (i < T.length)
    {
        if (j == 0 || T.ch[i] == T.ch[j])
        {
            ++i;
            ++j;
            next[i] = j;
        }
        else
            j = next[j];
    }
}

/**
 * @description:  KMP算法
 * @param {type} 
 * @return {type} 
 */
int IndexKMP(SString S, SString T)
{
    int i = 1, j = 1;
    int next[T.length + 1];
    GetNext(T, next); //求模式串的next数组
    while (i <= S.length && j <= T.length)
    {
        if (j == 0 || S.ch[i] == T.ch[j])
        {
            ++i;
            ++j;
        }
        else
            j = next[j];
    }
    if (j > T.length)
        return i - T.length;
    else
        return 0;
}

/**
 * @description:  nextval数组
 * @param {type} 
 * @return {type} 
 */
void GetNextVal(SString T, int nextVal[])
{
    int i = 1, j = 0;
    nextVal[1] = 0;
    while (i < T.length)
    {
        if (j == 0 || T.ch[i] == T.ch[j])
        {
            ++i;
            ++j;
            if (T.ch[i] != T.ch[j])
                nextVal[i] = j;
            else
                nextVal[i] = nextVal[j];
        }
        else
            j = nextVal[j];
    }
}