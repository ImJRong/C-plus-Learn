// 练习：vector 常用操作
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // ① 创建 + 添加
    vector<int> v;
    v.push_back(10);   // 尾部添加
    v.push_back(20);
    v.push_back(30);

    // ② 访问
    cout << "v[0] = " << v[0] << endl;          // 下标
    cout << "首个 = " << v.front() << endl;      // 第一个
    cout << "末尾 = " << v.back() << endl;       // 最后一个

    // ③ 大小
    cout << "个数 = " << v.size() << endl;       // 元素个数（注意：int 不写 & 也行，这里返回个数）

    // ④ 遍历（两种写法）
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;

    for (int x : v)          // 范围 for：逐个取出，x 是副本
        cout << x << " ";
    cout << endl;

    // ⑤ 删除末尾
    v.pop_back();
    cout << "删除后个数 = " << v.size() << endl;

    // ⑥ 清空
    v.clear();
    cout << "清空后个数 = " << v.size() << endl;

    return 0;
}
