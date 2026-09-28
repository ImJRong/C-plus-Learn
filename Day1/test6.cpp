// 练习 6：把数组中的数从小到大排序
// 练习点：双层循环 + 元素交换

#include <iostream>
using namespace std;

int main() {
    int num[8] = {3, 8, 1, 9, 4, 7, 2, 6};
    int size = sizeof(num) / sizeof(num[0]);

    // 外层为位置 i 找正确的数，内层从 i+1 开始逐个比较
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (num[i] > num[j]) {
                // 交换两个元素，需要临时变量中转
                int tem = num[j];
                num[j] = num[i];
                num[i] = tem;
            }
        }
    }

    for (int i = 0; i < size; i++) {
        cout << num[i] << endl;
    }
    return 0;
}
