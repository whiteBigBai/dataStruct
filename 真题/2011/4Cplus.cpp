#include <iostream>
using namespace std;
typedef struct TreeNode
{
    char data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode,Tree;

void CreateTree(TreeNode *&T) //先序法创建二叉树
{

    char data;
    cin >> data;
    if (data == '#')
        T = NULL;
    else
    {
        T = new TreeNode;
        T->data = data;
        CreateTree(T->left);
        CreateTree(T->right);
    }
}

void PreorderTree(TreeNode *T) //前序遍历二叉树
{
    if (T == NULL)
        return;
    cout << T->data << " ";
    PreorderTree(T->left);
    PreorderTree(T->right);
}

void InorderTree(TreeNode *T) //中序遍历二叉树
{
    if (T == NULL)
        return;
    InorderTree(T->left);
    cout << T->data << " ";
    InorderTree(T->right);
}

void PostorderTree(TreeNode *T) //后序遍历二叉树
{
    if (T == NULL)
        return;
    PostorderTree(T->left);
    PostorderTree(T->right);
    cout << T->data << " ";
}

int main(int argc, char **argv)
{
    //AB#D##CE###
    cout << "请输入先序创建二叉树的序列:" << endl;
    Tree *T;
    CreateTree(T);
    cout << "前序遍历的结果为:";
    PreorderTree(T);
    cout << endl;
    cout << "中序遍历的结果为:";
    InorderTree(T);
    cout << endl;
    cout << "后序遍历的结果为:";
    PostorderTree(T);
    return 0;
}
