// 练习 5：输入 n，计算 1 + 2 + ... + n 的总和
// 练习点：函数 + 循环累加

#include <iostream>
using namespace std;

int sumTo(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;               // 等价于 sum = sum + i
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    cout << sumTo(n) << endl;
    return 0;
}
