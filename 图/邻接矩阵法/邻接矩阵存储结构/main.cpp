#include <stdio.h>
#include <stdlib.h>

#define MaxVertexNum 100 //顶点数目的最大值

typedef struct
{
    char Vex[MaxVertexNum]; //顶点表
    int Edge[MaxVertexNum][MaxVertexNum];//邻接矩阵 ，边表
    int vexNum, arcNum; //图的当前顶点数和边数/弧数
} MGraph;

int main(int argc, char *argv[])
{
    return 0;
}
