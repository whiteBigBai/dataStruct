#include <stdio.h>
#include <stdlib.h>

//求顶点u到到其他顶点的最短路径
void BFS_MIN_Distance(Graph G, int u)
{
    //d[i]表示从u到i节点的最短路径
    for (int i = 0; i < G.vexNum; i++)
    {
        d[i] =∞;      //初始化路径长度
        path[i] = -1; //最短路径从哪个顶点过来
    }
    d[u] = 0;
    visited[u] = true;
    EnQueue(Q, u);
    while (!isEmpty(Q))
    {                  //BFS算法主过程
        DeQueue(Q, u); //对头元素u出队
        for (w = FirstNeighbor(G, u); w >= 0; w = NextNeighbor(G, u, w))
            if (!visited[w])
            {                      //w位u的尚未访问的邻接顶点
                d[w] = d[u] + 1;   //路径长度加1
                path[w] = u;       //最短路径应从u到w
                visited[w] = true; //设已访问标记
                EnQueue(Q, w);     //顶点w入队
            }
    }
}