// 练习 7：数组去重，每个数只打印一次
// 练习点：双层循环 + flag 标志位

#include <iostream>
using namespace std;

int main() {
    int num[] = {1, 1, 3, 4, 4, 8, 9, 9, 10, 2, 3, 3, 6, 5, 5, 4, 7, 7, 6};
    int size = sizeof(num) / sizeof(num[0]);

    for (int i = 0; i < size; i++) {
        int flag = 0;               // 每轮开始先假设"这个数没出现过"

        // 回头检查前面有没有出现过相同的数
        for (int j = 0; j < i; j++) {
            if (num[i] == num[j]) {
                flag = 1;           // 出现过，插上旗子
            }
        }

        if (flag == 0) {            // 没出现过才打印
            cout << num[i] << endl;
        }
    }
    return 0;
}
