// 练习 1：输入两个整数，输出它们的和、差、积
// 练习点：函数定义与调用

#include <iostream>
using namespace std;

// 求和
int add(int a, int b) {
    return a + b;
}

// 求差
int sub(int a, int b) {
    return a - b;
}

// 求积
int times(int a, int b) {
    return a * b;
}

int main() {
    int a, b;
    cin >> a >> b;

    cout << add(a, b) << endl;
    cout << sub(a, b) << endl;
    cout << times(a, b) << endl;

    return 0;
}
