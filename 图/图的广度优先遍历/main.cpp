#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX_NUM 100

bool visited[MAX_VERTEX_NUM]; //访问标记数组 初始都为false

void BFSTraverse(Graph G)
{ //对图G进行广度优先遍历
    for (int i = 0; i < G.vexNum; i++)
        visited[i] = false;            //访问标记数组初始化
    InitQueue(Q);                      //初始化辅助队列Q
    for (int i = 0; i < G.vexNum; ++i) //从0号顶点开始遍历
        if (!visited[i])               //对每个连通分量调用一次BFS
            BFS(G, i);                 //vi未访问过,从vi开始BFS
}

/*
 * 广度优先遍历
 */
void BFS(Graph G, int v)
{

    visit(v);          //访问初始顶点
    visited[v] = true; //对v做已访问标记
    EnQueue(Q, v);     //顶点v入队列Q
    while (!isEmpty(Q))
    {
        DeQueue(v); //顶点v出队列
        for (w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w))
        {
            //检测v所有邻接点
            if (!visited[w])
            {                      //w为v的尚未访问的邻接顶点
                visit(w);          //访问顶点w
                visited[w] = true; //对w做已访问标记
                EnQueue(Q, w);     //顶点w入队列
            }
        }
    }
}