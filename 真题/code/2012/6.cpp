#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX_NUM 100 //最多顶点个数
typedef char VertexData;
typedef struct ArcNode
{
    int adjvex;              //该弧指向顶点的位置
    struct ArcNode *nextarc; //指向下一条弧的指针
} ArcNode;

typedef struct VertexNode
{
    VertexData data;   //顶点数据
    ArcNode *firstarc; //指向该顶点第一条弧的指针
} VertexNode;

typedef struct
{
    VertexNode vertex[MAX_VERTEX_NUM];
    int vexnum, arcnum; //图的顶点数和弧数
} AdjList;              //基于邻接表的图
