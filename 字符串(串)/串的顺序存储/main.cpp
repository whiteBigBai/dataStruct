#include <stdio.h>
#include <stdlib.h>
#define MaxLen 255 //预定义最大串长为255
typedef struct
{                    //静态数组实现(定长顺序存储)
    char ch[MaxLen]; //每个分量存储一个字符 0下标不存储元素
    int length;      //串的实际长度
} SString;

typedef struct
{               //动态数组实现 (堆分配存储)
    char *ch;   //按串长分配存储区,ch指向串的基地址
    int length; //串的长度
} HString;

/**
 * @description:  动态数组实现串的初始化
 * @param {type} 
 * @return {type} 
 */
void InitHString(HString &S)
{
    S.ch = (char *)malloc(MaxLen * sizeof(char));
    S.length = 0;
}

/**
 * @description: 求子串 
 * @param {type} 
 * @return {type} 
 */
bool SubString(SString &Sub, SString S, int pos, int len)
{
    //字串范围越界
    if (pos + len - 1 > S.length)
        return false;
    for (int i = pos; i < pos + len; i++)
        Sub.ch[i - pos + 1] = S.ch[i];
    Sub.length = len;
    return true;
}

/**
 * @description: 比较操作
 * @param {type} 
 * @return {type} 
 */
int StrCompare(SString S, SString T)
{
    for (int i = 1; i <= S.length && i <= T.length; i++)
    {
        if (S.ch[i] != T.ch[i])
            return S.ch[i] - T.ch[i];
    }
    //扫描过的所有字符都相同 则长度长的串更大
    return S.length - T.length;
}

int Index(SString S, SString Sub)
{
    int i = 1, m = S.length, n = Sub.length;
    SString temp;//用于暂存子串
    while(i<=m-n+1){
        SubString(temp,S,i,n);
        if(StrCompare(temp,Sub)!=0)
            ++i;
        else
            return i;//返回子串在主串中的位置
    }
    return 0;//S中不存在与Sub相等的子串
}
