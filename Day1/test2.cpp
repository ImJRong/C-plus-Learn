// 练习 2：输入一个数，判断它是正数、负数还是零
// 练习点：if / else if / else 多分支判断

#include <iostream>
using namespace std;

int main() {
    double num;
    cin >> num;

    if (num > 0) {
        cout << "positive" << endl;
    } else if (num < 0) {
        cout << "negative" << endl;
    } else {
        cout << "zero" << endl;
    }

    return 0;
}
