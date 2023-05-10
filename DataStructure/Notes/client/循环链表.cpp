#include "bits/stdc++.h"

using namespace std;

typedef struct ListNode {
    int val;
    ListNode *next;
} ListNode, *ListLink;

// 初始化循环链表
// 最后一个结点的 next 指向头结点
ListLink InitListNode() {
    ListLink ls = new ListNode;
    ls->next = ls;

    return ls;
}

// 判断循环单链表是否为空
bool IsEmpty(ListLink ls) {
    return ls->next == ls;
}

// 判断结点 node 是否为尾结点
bool IsTail(ListLink ls, ListLink node) {
    return node->next == ls;
}

int main() {


    return 0;
}