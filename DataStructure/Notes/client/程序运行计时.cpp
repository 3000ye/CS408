#include "bits/stdc++.h"
#include "time.h"  // 时间库
#include <ctime>

using namespace std;

clock_t start, stop;  // 初始化时间节点

int main() {

    start = clock();
    //  程序开始
    //  如果程序运行时间太短，可以多重复几次
    //  cout << "Hello World!" << endl;
    //  程序结束
    stop = clock();

    double duration = ((double)(stop - start)) / CLOCKS_PER_SEC;
    cout << duration << endl;

    return 0;
}