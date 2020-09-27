#include <stdio.h>
#include <stdlib.h>
#define MaxLen 255 //预定义最大串长为255
typedef struct
{                    //静态数组实现(定长顺序存储)
    char ch[MaxLen]; //每个分量存储一个字符
    int length;      //串的实际长度
} SString;


int Index(SString S,SString T){
    int k=1; //起始位置
    int i=k,j=1;
    while(i<=S.length&&j<=T.length){
        if(S.ch[i]==T.ch[j]){
            ++i;
            ++j;//继续比较后继字符
        }
        else{
            k++;//检查下一个子串
            i=k;
            j=1;
        }

    }
    if(j>T.length)
        return k;
    else 
        return 0;

}

//较好的情况：每个子串第一个字符就与模式串不匹配
    //若模式串长度为m,主串长度为n，则
    //匹配成功的最好时间复杂度为 O(m)
    //匹配失败的最好时间复杂度：O(n-m+1)=O(n-m)=O(n)