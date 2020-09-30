#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10
typedef struct
{
    char data[MaxSize];
    int top;
} SqStack;

//初始化栈
void InitStack(SqStack &S);
//判断栈是否为空
bool StackEmpty(SqStack S);
//进栈操作
bool Push(SqStack &S, char e);
//出栈操作
bool Pop(SqStack &S, char &e);

/**
 * @description: 匹配括号
 * @param {type} 
 * @return {type} 
 */
bool bracketCheck(char str[], int length)
{
    SqStack S;
    InitStack(S);
    for (int i = 0; i < length; i++)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
            Push(S, str[i]); //扫描到左括号，入栈
        }
        else
        {
            if (StackEmpty(S)) //扫描到右括号，且当前栈空，匹配失败
                return false;
            char topElem;
            Pop(S, topElem); //栈顶元素出栈
            if (str[i] == '(' && topElem != ')')
                return false;
            if (str[i] == '[' && topElem != ']')
                return false;
            if (str[i] == '{' && topElem != '}')
                return false;
        }
    }
    return StackEmpty(S);
}