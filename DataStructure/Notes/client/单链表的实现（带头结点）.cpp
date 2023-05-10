#include "bits/stdc++.h"

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
void ListNodeInsert2Head(ListLink &ls, int i) {
    ListLink node = new ListNode;  // 新建链表指针
    node->val = i;  // 赋值
    node->next = ls->next;  // 将新建的 node 的下一个节点指向 ls 的下一个节点
    ls->next = node;  // 将 ls 的下一个节点指向 ndoe
}

// 按位序插入到指定位置
void ListNodeInsert(ListLink &ls, int i, int e) {
    if (i < 1) {cout << "i < 1" << endl; return ;}  // 必须大于等于位序 1

    ListLink node = ls;  // 创建一个结点来搜索
    int idx = 0;  // 初始化搜索下标

    // 直到 idx = i - 1 或结点不存在才停止
    while (node != NULL and idx < i - 1) {
        node = node->next;
        idx ++;
    }

    // 特判一下 node 是否已经不存在（i大于链表长度）
    if (node == NULL) {cout << "i > ls.length" << endl; return ;}

    // 插入结点
    ListLink p = new ListNode;
    p->val = e;
    p->next = node->next;
    node->next = p;
}

// 指定结点的后插操作
void ListNodeInsert2Next(ListLink node, int e) {
    if (node == NULL) {cout << "ls == NULL" << endl; return ;}

    // 新建结点，插入到 node 结点后面
    ListLink p = new ListNode;
    p->val = e;
    p->next = node->next;
    node->next = p;
}

// 指定结点的前插操作
// 传入头指针和指定的结点
void ListNodeInsert2Prior(ListLink ls, ListLink node, int e) {
    if (node == NULL) {cout << "ls == NULL" << endl; return ;}

    ListLink p = new ListNode;
    // 先将 p 插到 node 后面
    // 然后把 node.val 给 p.val
    // 最后再 node.vel = e
    p->next = node->next;
    node->next = p;
    p->val = node->val;
    node->val = e;
}

// 按位序删除，并返回删除的结点的值
void ListNodeDelete(ListLink &ls, int i, int &e) {
    if (i < 1) {cout << "i < 1" << endl; return ;}

    // node 为被删除结点的前一个结点
    ListLink node = ls;
    int idx = 0;
    while (node != NULL and idx < i - 1) {
        node = node->next;
        idx ++;
    }

    if (node == NULL or node->next == NULL) {
        cout << "结点不存在" << endl;
        return ;
    }

    // p 为被删除的结点
    ListLink p = node->next;
    node->next = p->next;

    // 返回被删除节点值，并释放空间
    e = p->val;
    delete p;
}

// 指定结点的删除
void ListNodeDeleteNode(ListLink node) {
    if (node == NULL) {cout << "node = NULL" << endl; return ;}
    if (node->next == NULL) {cout << "node 是最后一个结点，需要从前往后遍历删除" << endl; return ;}

    // 将 node.next 的值给 node
    // 然后将 node.next 删除
    node->val = node->next->val;
    node->next = node->next->next;
}

// 按位查找元素，返回第 i 个结点
// 和插入与删除不同，可以返回头结点，所以 i 的判定为 0
ListLink GetNode(ListLink ls, int i) {
    if (i < 0) {cout << "i < 0" << endl; return NULL;}

    ListLink node = ls;
    int idx = 0;
    while (node != NULL and idx < i) {
        node = node->next;
        idx ++;
    }

    return node;
}


// 在链表中查找元素，并返回该元素的结点
ListLink LocateNode(ListLink ls, int e) {
    ListLink node = ls->next;

    while (node != NULL and node->val != e) node = node->next; 

    return node;
}

// 返回单链表的长度
int ListNodeLength(ListLink ls) {
    int len = 0;
    ListLink node = ls->next;
    while (node != NULL) {
        node = node->next;
        len ++;
    }

    return len;
}

int main() {
    ListLink ls = InitListNode();

    for (int i = 1; i < 3; i ++) {
        ListNodeInsert2Head(ls, i);
    }

    for (ListLink p = ls->next; p != NULL; p = p->next) {
        cout << p->val << endl;
    }

    ListLink node = ls->next->next;
    ListNodeDeleteNode(node);

    cout << "---------------" << endl;
    for (ListLink p = ls->next; p != NULL; p = p->next) {
        cout << p->val << endl;
    }

    cout << "链表长度：" << ListNodeLength(ls) << endl;

    return 0;
}