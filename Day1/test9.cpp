// 练习 9：移动零 —— 把所有 0 挪到数组末尾，非零数保持原相对顺序
// 练习点：双下标法（k 记录下一个非零数该放的位置）

#include <iostream>
using namespace std;

int main() {
    int num[] = {
        0, 5, 0, 0, 12, 7, 0, 33, 0, 8,
        41, 0, 0, 19, 0, 61, 2, 0, 74, 0,
        96, 0, 50, 0, 0, 13, 0, 27, 0, 6
    };
    int size = sizeof(num) / sizeof(num[0]);

    // 第一趟：把非零数依次搬到前面
    int k = 0;                      // k 是下一个非零数该放的下标
    for (int i = 0; i < size; i++) {
        if (num[i] != 0) {
            num[k] = num[i];
            k++;
        }
    }

    // 第二趟：k 之后的位置全部填 0
    for (; k < size; k++) {
        num[k] = 0;
    }

    for (int i = 0; i < size; i++) {
        cout << num[i] << " ";
    }
    cout << endl;

    return 0;
}
