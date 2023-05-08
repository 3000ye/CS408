#include "bits/stdc++.h"
#include <cstddef>

using namespace std;

typedef struct {
    int num;
    int people;
} Customer;

int main() {
    Customer a, b;

    a.num = 1, b.num = 1;
    a.people = 2, b.people = 2;

    if (a.num == b.num and a.people == b.people) {
        cout << "a = b" << endl;
    }
    else cout << "a != b" << endl;

    // 注意，不能直接判断是否相等
    // if (a == b) cout << "a = b" << endl;
    // else cout << "a != b" << endl;

    return 0;
}