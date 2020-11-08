#include <stdio.h>
#include <stdlib.h>
#define MaxVertexNum 100 //顶点数目的最大值
typedef char VertexType;

//"边/弧"
typedef struct ArcNode{
    int adjvex;//边/弧指向哪个结点
    struct ArcNode *next;//指向下一条弧的指针
    //InfoType info ;边权值
}ArcNode;

//顶点
typedef struct VNode
{
    VertexType data; //顶点信息
    ArcNode *first;  //第一条边/弧
} VNode, AdjList[MaxVertexNum];

//用邻接表存储的图
typedef struct
{
    AdjList vertices;
    int vexNum, arcNum;
} ALGraph;