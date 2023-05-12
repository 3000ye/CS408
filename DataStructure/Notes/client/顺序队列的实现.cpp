#include "bits/stdc++.h"

using namespace std;

// 顺序队列定义
#define MaxSize 10
typedef struct {
    int data[MaxSize];
    int head, tail;  // 头尾指针
} SqQueue;

// 初始化队列
SqQueue InitQueue() {
    SqQueue Que;
    Que.head = 0, Que.tail = 0;

    return Que;
}

// 判断队列是否为空
bool IsEmpty(SqQueue Que) {
    return Que.head == Que.tail;
}

// 入队操作
void PushQueue(SqQueue &Que, int x) {
    if ((Que.tail + MaxSize - Que.head) % MaxSize == 0) {
        cout << "队列已满" << endl;
        return ;
    }

    Que.data[Que.tail] = x;
    Que.tail ++;
}

int main() {


    return 0;
}