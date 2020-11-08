#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MaxVertexNum 100 //顶点数目的最大值
#define INFINTIY INT_MAX //宏定义常量“无穷”

typedef char VertexType; //顶点的数据类型
typedef int EdgeType; //带权图中边上权值的数据类型
typedef struct
{
    VertexType Vex[MaxVertexNum]; //顶点  
    EdgeType Edge[MaxVertexNum][MaxVertexNum];//边的权
    int vexNum, arcNum; //图的当前顶点数和边数/弧数
} MGraph;

int main(int argc, char *argv[])
{
    printf("%d",INFINTIY);
    return 0;
}