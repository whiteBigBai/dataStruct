#include <stdio.h>
#include <stdlib.h>
#define MaxLen 255 //预定义最大串长为255
typedef struct
{                    //静态数组实现(定长顺序存储)
    char ch[MaxLen]; //每个分量存储一个字符
    int length;      //串的实际长度
} SString;

/**
 * @description:  KMP算法
 * @param {type} 
 * @return {type} 
 */
int IndexKMP(SString S, SString T, int next[])
{
    int i=1,j=1;
    while(i<=S.length&&j<=T.length){
        if(j==0||S.ch[i]==T.ch[j]){
            ++i;
            ++j;//比较后继字符
        }
        else
            j=next[j];//模式串向右移动
        
    }
    if(j>T.length)
        return i-T.length; //匹配成功
    else    
        return 0;
}
