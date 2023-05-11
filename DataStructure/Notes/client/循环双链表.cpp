#include "bits/stdc++.h"

using namespace std;

typedef struct DListNode {
    int val;
    DListNode *prior, *next;
} DListNode, *DListLink;

// 初始化循环链表
// 头结点的 prior 和 next 都是头结点本身
DListLink InitDListNode() {
    DListLink ls = new DListNode;
    ls->prior = ls;
    ls->next = ls;

    return ls;
}

// 判断循环双链表是否为空
bool IsEmpty(DListLink ls) {
    return ls->next == ls;
}

// 判断结点 node 是否为表尾结点
bool IsTail(DListLink ls, DListLink node) {
    return node->next == ls;
}

// 在 node 结点之后插入 p 结点
void DListNodeInsertNext(DListLink node, DListLink p) {
    p->next = node->next;
    node->next->prior = p;
    p->prior = node;
    node->next = p;
}

// 删除 node 结点的后继结点
void DListNodeDeleteNext(DListLink node) {
    node->next = node->next->next;
    node->next->next->prior = node;
}

int main() {


    return 0;
}