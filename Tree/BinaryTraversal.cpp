/*
* 树的遍历
*/

#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <queue>
using namespace std;

typedef char DATA_TYPE;

typedef struct s_TreeNode
{
    struct s_TreeNode *left;
    struct s_TreeNode *right;
    DATA_TYPE data;
    int flag;
    s_TreeNode ()
    {
        left = right = NULL;
        flag = 0;
    }
} TreeNode;

TreeNode *addLeft(TreeNode *pNode, DATA_TYPE data)
{
    if (!pNode)
        return NULL;
    pNode->left = (TreeNode *)malloc(sizeof(TreeNode));
    if (!pNode->left)
        return NULL;
    pNode->left->data = data;
    return pNode->left;
}

TreeNode *addRight(TreeNode *pNode, DATA_TYPE data)
{
    if (!pNode)
        return NULL;
    pNode->right = (TreeNode *)malloc(sizeof(TreeNode));
    if (!pNode->right)
        return NULL;
    pNode->right->data = data;
    return pNode->right;
}

TreeNode *buildTree()
{
    TreeNode *pRoot = (TreeNode *)malloc(sizeof(TreeNode));
    if (!pRoot)
        return NULL;
    pRoot->data = 'a';

    TreeNode *tp_b = addLeft(pRoot, 'b');
    addRight(pRoot, 'c');
    TreeNode *tp_d = addLeft(tp_b, 'd');
    TreeNode *tp_f = addRight(tp_b, 'f');
    addRight(tp_d, 'e');
    addLeft(tp_f, 'g');
    return pRoot;
}

void r_preorder(TreeNode *pNode)
{
    if (!pNode)
        return;
    putchar(pNode->data);
    r_preorder(pNode->left);
    r_preorder(pNode->right);
}

void printStack(stack<TreeNode *> s)
{
    printf("stack: ");
    while (!s.empty())
    {
        putchar(s.top()->data);
        s.pop();
    }
    putchar('\n');
}

// 先序遍历
void preorder(TreeNode *pNode)
{
    stack<TreeNode *> s;
    s.push(pNode);
    TreeNode *tp;
    while (!s.empty())
    {
        tp = s.top();
        s.pop();
        putchar(tp->data);
        if (tp->right)
            s.push(tp->right);
        if (tp->left)
            s.push(tp->left);
    }
    putchar('\n');
}

// 中序遍历
void midorder(TreeNode *pNode)
{
    stack<TreeNode *> s;
    TreeNode *tp = pNode;
    while (!s.empty() || tp)
    {
        while (tp)
        {
            s.push(tp);
            tp = tp->left;
        }
        tp = s.top();
        s.pop();
        putchar(tp->data);
        tp = tp->right;
    }
    putchar('\n');
}

// 后序遍历，在数据结构中加入了 flag 表示访问到的次数
void postorder(TreeNode *pNode)
{
    stack<TreeNode *> s;
    s.push(pNode);
    TreeNode *tp;
    while (!s.empty())
    {
        tp = s.top();
        s.pop();
        if (tp->flag)
            putchar(tp->data);
        else
        {
            tp->flag = 1;
            s.push(tp);
            if (tp->right)
                s.push(tp->right);
            if (tp->left)
                s.push(tp->left);
        }
    }
    putchar('\n');
}

// 广度优先遍历
void levelorder(TreeNode *pNode)
{
    queue<TreeNode *> q;
    q.push(pNode);
    TreeNode *tp;
    while (!q.empty())
    {
        tp = q.front();
        q.pop();
        putchar(tp->data);
        if (tp->left)
            q.push(tp->left);
        if (tp->right)
            q.push(tp->right);
    }
    putchar('\n');
}

int main()
{
    TreeNode *tree = buildTree();
    preorder(tree);
    midorder(tree);
    postorder(tree);
    levelorder(tree);

    return 0;
}
