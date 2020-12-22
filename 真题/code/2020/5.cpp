#include <stdio.h>
#include <stdlib.h>
#define maxsize 100

typedef int VexType;
typedef struct ArcNode
{
    struct ArcNode *nextarc;
    int adjvex; //顶点编号
} ArcNode;

typedef struct
{
    ArcNode *firstarc;
    VexType data; //该边指向的结点的位置
} VNode;

typedef struct
{
    VNode AdjList[maxsize];
    int vexnum, arcnum;
} AGraph;

VexType locate(AGraph *G, VexType x)
{
    for (int i = 0; i < G->vexnum; i++)
        if (G->AdjList[i].data == x)
            return i;

    return -1;
}
AGraph *creat()
{
    AGraph *G = (AGraph *)malloc(sizeof(AGraph));
    printf("请输入顶点数目：");
    scanf("%d", &(G->vexnum));
    printf("请输入弧的数目：");
    scanf("%d", &(G->arcnum));

    int i, k;
    VexType vex;
    VexType v1, v2;
    for (i = 0; i < G->vexnum; i++)
    {
        printf("正在创建顶点表，请输入顶点信息：\n");
        scanf("%d", &vex);
        G->AdjList[i].data = vex;
        G->AdjList[i].firstarc = NULL;
    }

    for (k = 0; k < G->arcnum; k++)
    {
        printf("正在连接各个顶点，请输入弧的信息：\n");
        scanf("%d%d", &v1, &v2); //v1为弧尾，v2为弧头；
        int a = locate(G, v1);   //求顶点v1在顶点表中的编号
        int b = locate(G, v2);   //求顶点v2在顶点表中的编号

        //采用头插法建表
        ArcNode *p = (ArcNode *)malloc(sizeof(ArcNode));
        p->adjvex = b;
        p->nextarc = G->AdjList[a].firstarc;
        G->AdjList[a].firstarc = p;
    }
    return G;
}

int visit[maxsize];
void dfs(AGraph *G, int v0)
{ //采用深度优先遍历的方法对图进行打印，该图存储在邻接表中
    ArcNode *p;
    visit[v0] = 1;
    printf("检查待输入数组是否被标记为已访问：%d\n", visit[v0]);
    printf("%d\n", G->AdjList[v0].data);
    p = G->AdjList[v0].firstarc;
    while (p != NULL)
    {
        if (visit[p->adjvex] == 0)
            dfs(G, p->adjvex);
        p = p->nextarc;
    }
}

void print(AGraph *G)
{ //为避免要打印的图为非连通图，将深度优先遍历嵌套在for循环中
    for (int i = 0; i < G->vexnum; i++)
        visit[i] = 0; //初始化visit数组
    printf("\n");
    for (int i = 0; i < G->vexnum; i++)
        if (visit[i] == 0)
            dfs(G, i);
}

int main(int argc, char **argv)
{
    AGraph *G = creat();
    print(G);
}
