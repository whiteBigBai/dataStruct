#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

typedef struct CSNode
{
    ElemType data;
    int level;
    struct CSNode *firstchild, *nextsibling;

} CSNode, *CSTree;

#define CREATE(pos, c, l)                       \
    {                                           \
        pos = (CSNode *)malloc(sizeof(CSNode)); \
        pos->data = c;                          \
        pos->level = l;                         \
        pos->firstchild = NULL;                 \
        pos->nextsibling = NULL;                \
        return pos;                             \
    }

CSTree InitTree()
{
    CSTree tree;
    CREATE(tree, '\0', 0);
}

CSTree Insert(CSTree tree, char data, int level)
{
    if (tree->level == level - 1)
    {
        CREATE(tree->firstchild, data, level);
    }
    if (tree->level == level)
    {
        CREATE(tree->nextsibling, data, level);
    }
    return NULL;
}

void printTree(CSTree tree)
{
    CSNode *p;
    if (tree == NULL)
    {
        return;
    }
    if (tree->firstchild != NULL)
    {
        for (p = tree->firstchild; p != NULL; p = p->nextsibling)
        {
            printf("(%c,%c) ", tree->data, p->data);
        }
    }

    if (tree->nextsibling != NULL)
    {
        printTree(tree->nextsibling);
    }
    if (tree->firstchild != NULL)
    {
        printTree(tree->firstchild);
    }
}

int main(int argc, char **argv)
{
    CSTree T = InitTree(), temp1, temp2, temp3, temp4, temp5;
    temp1 = Insert(T, 'A', 1);
    temp2 = Insert(temp1, 'B', 2);
    temp3 = Insert(temp2, 'C', 2);
    Insert(temp3, 'D', 2);
    Insert(temp2, 'E', 3);
    temp5 = Insert(temp3, 'F', 3);
    Insert(temp5, 'G', 3);
    Insert(temp5, 'H', 4);
    printf("树的各条边分别是：\n");
    printTree(T->firstchild);
}