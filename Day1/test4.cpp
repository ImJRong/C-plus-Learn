// 练习 4：写一个函数，返回三个数中的最大值
// 练习点：函数返回多个参数中的最大值（擂台法）

#include <iostream>
using namespace std;

// 擂台法：先假设 a 最大，再让 b、c 依次上来挑战
int maxOf3(int a, int b, int c) {
    int max = a;
    if (max < b) max = b;
    if (max < c) max = c;
    return max;
}

int main() {
    int a, b, c;
    cout << "please input 3 integers: " << endl;
    cin >> a >> b >> c;

    cout << maxOf3(a, b, c) << endl;

    return 0;
}
