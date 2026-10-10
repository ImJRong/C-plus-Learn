// 练习：异常处理 try / throw / catch
#include <iostream>
#include <stdexcept>     // runtime_error 定义在这个头文件
using namespace std;

double divide(double a, double b) {
    if (b == 0) {
        throw runtime_error("除数不能为0");   // 抛出异常，函数立即终止，不返回
    }
    return a / b;
}

int main() {
    // 情况1：正常调用
    try {
        cout << "10 / 2 = " << divide(10, 2) << endl;
    } catch (const exception& e) {
        cout << "出错了：" << e.what() << endl;
    }

    // 情况2：除零，会抛异常
    try {
        cout << "10 / 0 = " << divide(10, 0) << endl;   // 这行不会执行完
    } catch (const exception& e) {
        cout << "出错了：" << e.what() << endl;          // 跳到这来处理
    }

    return 0;
}
