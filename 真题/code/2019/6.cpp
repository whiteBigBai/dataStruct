#include <stdio.h>
#include <stdlib.h>

void FindPath(AGraph *G, int u, int v, int path[], int d)

{

    int w, i;

    ArcNode *p;

    d++;

    path[d] = u;

    visited[u] = 1; //路径长度增1

    if (u == v)

    {

        for (i = 0; i <= d; i++)

            printf("%2d", path[i]);

        printf("\n");
    }

    p = G->adjlist[u].firstarc; //p指向v的第一个相邻点

    while (p != NULL)

    {

        w = p->adjvex;

        if (visited[w] == 0) //若w顶点未访问，递归访问它

            FindPath(G, w, v, path, d);

        p = p->nextarc; //p指向v的下一个邻接点
    }

    visited[u] = 0; //恢复环境，使该顶点可重新使用
}