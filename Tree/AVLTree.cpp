/*
* 平衡二叉树
*/

#include <stdio.h>
#include <stdlib.h>

typedef int DATA_TYPE;

typedef struct s_AVLTreeNode
{
    DATA_TYPE data;
    int height;
    struct s_AVLTreeNode *left;
    struct s_AVLTreeNode *right;
    s_AVLTreeNode()
    {
        left = right = NULL;
        height = 0;
    }
} TreeNode;

void preorder(TreeNode *pNode)
{
    if (!pNode)
        return;
    printf("%d(%d) ", pNode->data, pNode->height);
    preorder(pNode->left);
    preorder(pNode->right);
}

inline int Max(int a, int b)
{
    return a > b ? a : b;
}

inline int Min(int a, int b)
{
    return a < b ? a : b;
}

int height(TreeNode *pNode)
{
    if (!pNode)
        return -1;
    else
        return pNode->height;
}

inline void updateHeight(TreeNode *pNode)
{
    pNode->height = Max(height(pNode->left), height(pNode->right)) + 1;
}

// 左左旋转（即左子树的左边节点，单旋转）
TreeNode *rotateLL(TreeNode *pNode)
{
    TreeNode *pTop = pNode->left;
    pNode->left = pTop->right;
    pTop->right = pNode;

    updateHeight(pNode);
    updateHeight(pTop);

    return pTop;
}

// 右右旋转（单旋转）
TreeNode *rotateRR(TreeNode *pNode)
{
    TreeNode *pTop = pNode->right;
    pNode->right = pTop->left;
    pTop->left = pNode;

    updateHeight(pNode);
    updateHeight(pTop);

    return pTop;
}

TreeNode *rotateLR(TreeNode *pNode)
{
    pNode->left = rotateRR(pNode->left);
    return rotateLL(pNode);
}

TreeNode *rotateRL(TreeNode *pNode)
{
    pNode->right = rotateLL(pNode->right);
    return rotateRR(pNode);
}

void AVL_Insert(TreeNode *(&pNode), DATA_TYPE data)
{
    if (!pNode)
    {
        pNode = new TreeNode;
        pNode->data = data;
        return;
    }
    if (pNode->data > data)
    {
        AVL_Insert(pNode->left, data);
        if (2 == height(pNode->left) - height(pNode->right))
        {
            if (data < pNode->left->data)
                pNode = rotateLL(pNode);
            else
                pNode = rotateLR(pNode);
        }
    }
    else if (pNode->data < data)
    {
        AVL_Insert(pNode->right, data);
        if (2 == height(pNode->right) - height(pNode->left))
        {
            if (data > pNode->right->data)
                pNode = rotateRR(pNode);
            else
                pNode = rotateRL(pNode);
        }
    }
    updateHeight(pNode);
}

inline void parentConnect(TreeNode *parent, TreeNode *pNode, int leftFlag)
{
    if (parent)
    {
        if (leftFlag)
            parent->left = pNode;
        else
            parent->right = pNode;
    }
}

inline TreeNode *replaceNode(TreeNode *oldNode, DATA_TYPE data,
                             int leftFlag, TreeNode *parent)
{
    TreeNode *newNode = new TreeNode;
    newNode->data = data;
    parentConnect(parent, newNode, leftFlag);
    newNode->left = oldNode->left;
    newNode->right = oldNode->right;
    delete oldNode;
    return newNode;
}

int RightMinParent(TreeNode *(&parent), TreeNode *(&pNode), TreeNode *node)
{
    TreeNode *minNodeParent = node;
    TreeNode *minNode = node->right;
    int leftFlag = 0;
    while (minNode->left)
    {
        minNodeParent = minNode;
        minNode = minNode->left;
        leftFlag = 1;
    }
    parent = minNodeParent;
    pNode = minNode;
    return leftFlag;
}

// TODO：更新树的高度并旋转，检查在替换节点时是否会有错（当节点有左右子树）
/*
void ADL_DeleteOK(TreeNode *parent, TreeNode *(&pNode),
                  DATA_TYPE data, int leftFlag)
{
    if (!pNode)
        return;
    if (pNode->data < data)
        ADL_Delete(pNode, pNode->right, data, 0);
    else if (pNode->data > data)
        ADL_Delete(pNode, pNode->left, data, 0);
    else
    {
        if (pNode->left && pNode->right)
        {
            TreeNode *tp, *tpParent;
            int f = RightMinParent(tpParent, tp, pNode);
            pNode = replaceNode(pNode, tp->data, leftFlag, parent);
            ADL_Delete(tpParent, tp, tp->data, f);
        }
        else if (pNode->left)
        {
            parentConnect(parent, pNode->left, leftFlag);
            pNode = pNode->left;
            delete pNode;
        }
        else if (pNode->right)
        {
            parentConnect(parent, pNode->right, leftFlag);
            pNode = pNode->right;
            delete pNode;
        }
        else
            parentConnect(parent, NULL, leftFlag);
    }
}

void updateTree(TreeNode *pNode)
{
    updateTree(pNode->left);
    updateTree(pNode->right);
    if (height(pNode->left) - height(pNode->right) == 2)
    {

    }
}

void ADL_Delete(TreeNode *parent, TreeNode *(&pNode),
                DATA_TYPE data, int leftFlag)
{
    ADL_DeleteOK(parent, pNode, data, leftFlag);
    // updateTree(pNode);
}
*/

int main()
{
    TreeNode *tree = NULL;
    int data[] = {16, 3, 7, 11, 9, 26, 18, 14, 15};
    for (int i = 0; i < 9; i++)
    {
        AVL_Insert(tree, data[i]);
        preorder(tree);
        putchar('\n');
    }
    //ADL_Delete(NULL, tree, 11, 0);
    preorder(tree);
    putchar('\n');
    return 0;
}
