// 练习：迭代器 iterator —— 容器里的"指针"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30, 40, 50};

    // ① 迭代器就是指向容器元素的"指针"
    auto it = v.begin();                    // 指向第一个元素（10）

    cout << "第一个元素 = " << *it << endl;   // 用 * 取值，跟指针一样

    // ② 用 ++ 往后移
    it++;                              // 移到第二个
    cout << "第二个元素 = " << *it << endl;

    it += 2;                           // 往后跳两个，到第四个
    cout << "第四个元素 = " << *it << endl;

    // ③ 遍历：从 begin 到 end
    for (auto it2 = v.begin(); it2 != v.end(); it2++) {
        cout << *it2 << " ";
    }
    cout << endl;

    // ④ end() 是"末尾之后"，不是最后一个元素
    cout << "最后元素 = " << *(v.end() - 1) << endl;   // end()-1 才是最后一个

    return 0;
}
