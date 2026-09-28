// 练习 10：移除元素 —— 删除数组中所有等于 target 的数，剩余元素保持原顺序
// 练习点：双下标法

#include <iostream>
using namespace std;

int main() {
    int num[] = {3, 2, 2, 3, 5, 3, 7, 3, 9, 2, 3, 4, 3, 8, 3};
    int size = sizeof(num) / sizeof(num[0]);
    int target = 3;

    // 只保留不等于 target 的元素，依次搬到前面
    int k = 0;                      // k 是下一个有效元素该放的下标
    for (int i = 0; i < size; i++) {
        if (num[i] != target) {
            num[k] = num[i];
            k++;
        }
    }

    // k 就是剩余元素的个数
    for (int i = 0; i < k; i++) {
        cout << num[i] << " ";
    }
    cout << endl;

    return 0;
}
