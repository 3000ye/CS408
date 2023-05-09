#include "bits/stdc++.h"
#include <cstddef>

using namespace std;

// ListNode: 链表结点，强调结点
// ListLink: 链表结点中的指针，强调单链表
// 声明链表时，两种方法均可：ListNode *ls, ListLink ls
typedef struct ListNode {  // 定义单链表结点类型
    int val;  // 每个节点存放的数据
    ListNode *next;  // 指针指向下一个节点
} ListNode, *ListLink;

// 初始化链表
// ls 为链表头结点，它的值无所谓，只关心它的下一个节点
ListLink InitListNode() {
    ListLink ls = new ListNode;
    ls->next = NULL;

    return ls;
}

// 判断链表是否为空
bool IsEmpty(ListLink ls) {
    return ls->next == NULL;
}

// 在链表头部插入
// 头结点始终是 ls，而链表的头部就是 ls 的下一个节点
void ListNodeInsert2Head(ListLink ls, int i) {
    ListLink node = new ListNode;  // 新建链表指针
    node->val = i;  // 赋值
    node->next = ls->next;  // 将新建的 node 的下一个节点指向 ls 的下一个节点
    ls->next = node;  // 将 ls 的下一个节点指向 ndoe
}

// 按位序插入到指定为止
void ListNodeInsert(ListLink ls, int i, int e) {
    if (i < 1) return ;

    ListLink node = ls;
    int idx = 0;

    while (node != NULL and idx < i - 1) {
        node = node->next;
        idx ++;
    }

    ListLink s = new ListNode;
    s->val = e;
    s->next = node->next;
    node->next = s;
}


// 在链表中查找元素，并返回该元素的结点
ListLink GetNode(ListLink ls, int x) {
    ListLink node = ls->next;

    while (node != NULL) {
        if (node->val == x) return node;

        node = node->next;
    }

    return NULL;
}


int main() {
    ListLink ls = InitListNode();

    for (int i = 1; i < 8; i ++) {
        ListNodeInsert2Head(ls, i);
    }

    for (ListLink p = ls->next; p != NULL; p = p->next) {
        cout << p->val << endl;
    }

    ListNodeInsert(ls, 3, 8);

    for (ListLink p = ls->next; p != NULL; p = p->next) {
        cout << p->val << endl;
    }

    return 0;
}