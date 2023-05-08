#include "bits/stdc++.h"

using namespace std;

#define InitSize 10
typedef struct {
    int *data;  // 指示动态分配数组的指针
    int MaxSize;  // 顺序表的最大容量
    int length;  // 顺序表的当前长度
} SqList;

// 基本操作：初始化顺序表
void InitList(SqList &ls) {
    ls.data = new int[InitSize];  // 动态分配存储空间
    ls.length = 0;  // 初始长度为 0
    ls.MaxSize = InitSize;  // 初始最大容量
}

// 顺序表扩容
void IncreaseSize(SqList &ls, int len) {
    int *newList = new int[ls.MaxSize + len];  // 新建一个数组

    // 将顺序表中元素存进新数据
    memcpy(newList, ls.data, ls.length * sizeof(int));
    delete [] ls.data;  // 释放原数组

    ls.data = newList;  // 更新顺序表数组
    ls.MaxSize += len;  // 更新顺序表容量
}

// 基本操作：插入元素
void ListInsert(SqList &ls, int i, int e) {
    if (ls.length == ls.MaxSize) {
        IncreaseSize(ls, 10);  // 扩容
    }
    
    if (i <= ls.length) {
        // 将第 i 个元素及之后所有元素后移一位
        for (int j = ls.length; j >= i; j --) {
            ls.data[j] = ls.data[j - 1];
        }

        ls.data[i - 1] = e;  // 插入元素 e
    }
    else {  // 如果长度小于插入坐标，则直接在最后插入
        ls.data[ls.length] = e;
    }

    ls.length ++;
}

// 基本操作：删除元素
void ListDelete(SqList &ls, int i, int &e) {
    if (i >= ls.length) {
        cout << "错误！超出顺序表长度！" << endl;
        return ;
    }

    e = ls.data[i - 1];  // 记录被删除元素的值
    // 删除元素后面的元素往前移动
    for (int j = i; j < ls.length; j ++) {
        ls.data[j - 1] = ls.data[j];
    }

    ls.length --;  // 长度减 1
}

// 基本操作：按位查找
int GetElem(SqList ls, int i) {
    return ls.data[i - 1];
}

// 基本操作：按值查找
int LocateElem(SqList ls, int e) {
    for (int i = 0, l = ls.length; i < l; i ++) {
        if (ls.data[i] == e) return i + 1;
    }

    return -1;  // 元素不存在，返回 -1
}

int main() {
    SqList ls;
    InitList(ls);

    for (int i = 1; i <= 8; i ++) ListInsert(ls, 1, i);

    for (int i = 0; i < ls.length; i ++) cout << ls.data[i] << endl;

    
    cout << GetElem(ls, 4) << endl;
    cout << LocateElem(ls, 6) << endl;
    cout << LocateElem(ls, 20) << endl;

    return 0;
}