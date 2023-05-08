#include "bits/stdc++.h"

using namespace std;

#define MaxSize 10  // 定义最大长度
typedef struct {
    int data[MaxSize];  // 用静态数组存放数据元素
    int length;  // 顺序表的当前长度
} SqList;  // 顺序表的类型定义


// 基本操作：初始化顺序表
void InitList(SqList &ls) {
    for (int i = 0; i < MaxSize; i ++) {
        ls.data[i] = 0;  // 将所有数据元素设置为默认初始值
    }

    ls.length = 0;  // 顺序表初始长度为 0
}

// 基本操作：插入元素
void ListInsert(SqList &ls, int i, int e) {
    if (ls.length == MaxSize) {
        cout << "表已满！" << endl;
        return ;
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

    ls.length ++;  // 更新长度
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
    SqList ls;  // 声明一个顺序表
    InitList(ls);  // 初始化顺序表

    for (int i = 1; i <= 8; i ++) ListInsert(ls, i, i);

    for (int i = 0; i < ls.length; i ++) {
        cout << ls.data[i] << endl;
    }

    cout << GetElem(ls, 4) << endl;
    cout << LocateElem(ls, 6) << endl;
    cout << LocateElem(ls, 20) << endl;


    return 0;
}