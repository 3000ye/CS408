#include "bits/stdc++.h"

using namespace std;

void NoChange(int x) {
    x = 1024;
    cout << "NoChange函数内部: x = " << x << endl;
}

void Change(int & x) {
    x = 2048;
    cout << "Change函数内部: x = " << x << endl;
}

int main() {
    int x = 1;
    cout << "调用前: x = " << x << endl;

    NoChange(x);

    cout << "NoChange调用后: x = " << x << endl;

    Change(x);

    cout << "Change调用后: x = " << x << endl;

    return 0;
}