#include "bits/stdc++.h"

using namespace std;

typedef struct ListNode {
    int val;
    ListNode * next;
} ListNode, * ListLink;

// 初始化链表
// 没有头结点，ls 为第一个结点，初始为 NULL
ListLink InitListNode() {
    ListLink ls = NULL;

    return ls;
}

// 判断链表是否为空
bool IsEmpty(ListLink ls) {
    return ls == NULL;
}

// 按位序插入
void ListNodeInsert(ListLink &ls, int i, int e) {
    if (i < 1) {cout << "i < 1" << endl; return ;}

    if (i == 1) {
        ListLink p = new ListNode;
        p->val = e;
        p->next = ls;
        ls = p;
    }
    else {
        ListLink node = ls;
        int idx = 1;

        while (node != NULL and idx < i - 1) {
            node = node->next;
            idx ++;
        }

        if (node == NULL) {cout << "i > ls.length" << endl; return ;}

        ListLink s = new ListNode;
        s->val = e;
        s->next = node->next;
        node->next = s;
    }
}

int main() {
    ListLink ls = InitListNode();

    for (int i = 1; i < 8; i ++) {
        ListNodeInsert(ls, 1, i);
    }

    for (ListLink p = ls; p != NULL; p = p->next) {
        cout << p->val << endl;
    }

    return 0;
}