// 练习：new 数组 —— 一次借一排，数量运行时才定
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "要存几个分数？";
    cin >> n;                        // n 是运行时才输入的

    int* scores = new int[n];        // 借一排 n 个 int，返回第一个的地址

    for (int i = 0; i < n; i++) {    // 像普通数组一样用下标读写
        cout << "第 " << i + 1 << " 个：";
        cin >> scores[i];
    }

    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += scores[i];
    }
    cout << "总分 = " << sum << "，平均 = " << sum / n << endl;

    delete[] scores;                 // 借了一排，用带方括号的 delete[] 还

    return 0;
}
