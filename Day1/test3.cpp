// 练习 3：打印 1 到 100 之间所有能被 7 整除的数
// 练习点：for 循环 + 取余运算 % 判断整除

#include <iostream>
using namespace std;

int main() {
    for (int i = 1; i <= 100; i++) {
        if (i % 7 == 0) {       // 余数为 0 说明能整除
            cout << i << endl;
        }
    }
    return 0;
}
