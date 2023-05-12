#include "bits/stdc++.h"

using namespace std;

#define MaxSize 10
typedef struct {
    int data[MaxSize];  // 使用静态数组存放栈中元素
    int top;  // 栈顶指针
} SqStack;

// 初始化栈
SqStack InitStack() {
    SqStack Stk;
    Stk.top = -1;  // 初始化栈顶指针

    return Stk;
}

// 新元素进栈
void Push(SqStack &Stk, int x) {
    if (Stk.top == MaxSize - 1) {
        cout << "栈满" << endl;
        return ;
    }

    // 更新栈顶指针，插入元素
    Stk.top ++;
    Stk.data[Stk.top] = x;
}

// 栈顶出栈
void Pop(SqStack &Stk, int &x) {
    if (Stk.top == -1) {
        cout << "空栈" << endl;
        return ;
    }

    // 返回栈顶值，并更新栈顶
    // 并不是真的将元素删除，而是更新栈顶指针
    x = Stk.data[Stk.top];
    Stk.top --;
}

// 返回栈顶元素
void GetTop(SqStack Stk, int &x) {
    if (Stk.top == -1) {
        cout << "空栈" << endl;
        return ;
    }

    x =  Stk.data[Stk.top];
}

int main() {
    SqStack Stk = InitStack();  // 声明一个栈

    return 0;
}