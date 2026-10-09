// 练习：引用 —— 给变量起外号，通过外号改本人
#include <iostream>
using namespace std;

// 用引用实现交换：x、y 是 a、b 的外号，改外号 = 改本人
void swapRef(int& x, int& y) {
    int t = x;
    x = y;
    y = t;
}

// 用指针实现交换（test3 你写过这种）
void swapPtr(int* x, int* y) {
    int t = *x;
    *x = *y;
    *y = t;
}

int main() {
    int a = 3, b = 8;

    // 方式一：引用。调用时直接写变量名，不用加 & 也不用加 *
    swapRef(a, b);
    cout << "引用版交换后: a=" << a << " b=" << b << endl;

    // 方式二：指针。调用时要传地址 &a，函数里要用 * 取值
    swapPtr(&a, &b);
    cout << "指针版交换后: a=" << a << " b=" << b << endl;

    return 0;
}
