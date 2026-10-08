// 最大子数组和：找连续一段，使其元素之和最大
// 练习点：动态规划入门（Kadane 算法），只需一次遍历，时间复杂度 O(n)

#include <iostream>
using namespace std;

int main() {
    int num[] = {
        -2, 1, -3, 4, -1, 2, 1, -5, 4,
        6, -3, 8, -9, 2, 5, -1, 7, -4,
        -6, 3, 10, -2, 4, -8, 5, 1, -3, 6
    };
    int size = sizeof(num) / sizeof(num[0]);

    int best = 0;               // 历史最大和
    int cur = 0;                // 当前这一段的和

    for (int i = 0; i < size; i++) {
        cur += num[i];          // 把当前数接进这一段

        if (cur > best) {       // 刷新历史纪录
            best = cur;
        }
        if (cur < 0) {          // 当前段变成负数，对后续任何数都是拖累
            cur = 0;            // 直接丢弃，从下一个数重新开始一段
        }
    }

    cout << best << endl;       

    return 0;
}
