/*
* 数据结构之单链表
*/

#include <stdio.h>
#include <stdlib.h>

typedef int DATA_TYPE;

// 单链表的结点
typedef struct s_node
{
    DATA_TYPE data;
    struct s_node *next;
} node;

// 创造一个空的单链表，返回头节点指针
node *create()
{
    node *pHead = (node *)malloc(sizeof(node));
    if (!pHead)
        return NULL;
    pHead->next = NULL;
    return pHead;
}

// 销毁单链表
void destroy(node *(&pHead))
{
    if (!pHead)
        return;
    node *p = pHead->next;
    free(pHead);
    pHead = NULL;

    node *tp;
    while (p)
    {
        tp = p->next;
        free(p);
        p = tp;
    }
}

// 添加元素，采用头添加方式
void add(node *pHead, DATA_TYPE data)
{
    node *pNew = (node *)malloc(sizeof(node));
    if (!pNew)
        return;
    pNew->data = data;
    pNew->next = pHead->next;
    pHead->next = pNew;
}

// 找到第 index 个位置的节点，返回其指针，并修改fp为其前驱的指针
node *findNode(node *pHead, int index, node *(&fp))
{
    if (!pHead)
        return NULL;
    node *p = pHead->next;
    fp = pHead;
    int i = 1;
    while (p && i < index)
    {
        fp = p;
        p = p->next;
        i++;
    }
    return p;
}

// 只遍历一次得到中间节点并返回
node *getMid(node *pHead)
{
    if (!pHead)
        return NULL;
    node *p, *p2, *mid;
    mid = p = p2 = pHead->next;
    while (p2->next && p2->next->next)
    {
        p2 = p2->next->next;
        p = p->next;
        mid = p;
    }
    return mid;
}

// 删除第 index 个位置上的结点
void deleteNode(node *pHead, int index)
{
    if (!pHead)
        return;
    node *fp;
    node *p = findNode(pHead, index, fp);
    if (!p)
        return;
    fp->next = p->next;
    free(p);
}

// 在第 index 个位置插入值为 data 的结点
void insertNode(node *pHead, int index, DATA_TYPE data)
{
    if (!pHead)
        return;
    node *fp;
    node *p = findNode(pHead, index, fp);
    if (!p)
        return;
    node *np = (node *)malloc(sizeof(node));
    np->data = data;
    np->next = p;
    fp->next = np;
}

// 获取单链表的长度
int length(node *pHead)
{
    if (!pHead)
        return -1;
    int len = 0;
    node *p = pHead->next;
    while (p)
    {
        len++;
        p = p->next;
    }
    return len;
}

// 按序输出单链表
void printList(node *pHead)
{
    if (!pHead)
        return;
    node *p = pHead->next;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    putchar('\n');
}

// 逆置单链表
void reverseList(node *pHead)
{
    if (!pHead)
        return;
    node *p = pHead->next;
    node *fp = NULL, *tp;
    while (p)
    {
        tp = p->next;
        p->next = fp;
        fp = p;
        p = tp;
    }
    pHead->next = fp;
}

int main()
{
    node *listHead = create();
    if (!listHead)
        return 0;
    for (int i = 0; i < 10; i++)
        add(listHead, i);
    deleteNode(listHead, 5);
    insertNode(listHead, 5, 50);

    printf("Length = %d\n", length(listHead));
    printList(listHead);
    reverseList(listHead);
    printList(listHead);

    node *pMid;
    pMid = getMid(listHead);
    printf("Mid data is %d\n", pMid->data);
    add(listHead, 99);
    printList(listHead);
    pMid = getMid(listHead);
    printf("Mid data is %d\n", pMid->data);

    destroy(listHead);
    return 0;
}
