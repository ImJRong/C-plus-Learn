// 练习 8：两数之和 —— 找出所有相加等于 target 的数对及其下标
// 练习点：双层循环枚举所有组合

#include <iostream>
using namespace std;

int main() {
    int num[] = {
        3, 11, 7, 25, 4, 18, 9, 30, 13, 6,
        22, 15, 8, 27, 1, 19, 12, 35, 5, 16,
        20, 10, 28, 2, 14, 31, 24, 17, 21, 23
    };
    int target = 40;
    int size = sizeof(num) / sizeof(num[0]);
    int count = 0;

    // j 从 i+1 开始，避免重复组合和自己配自己
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (num[i] + num[j] == target) {
                cout << "index: " << i << " and " << j << endl;
                cout << num[i] << " + " << num[j] << " = " << target << endl;
                count++;
            }
        }
    }
    cout << "---------- Total: " << count << " groups. ----------" << endl;

    return 0;
}
