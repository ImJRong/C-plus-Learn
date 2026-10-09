// 练习：STL 算法 sort / find / max_element
#include <iostream>
#include <vector>
#include <algorithm>   // 算法头文件
using namespace std;

int main() {
    vector<int> v = {5, 2, 9, 1, 7, 3};

    // ① 排序：一行升序
    sort(v.begin(), v.end());
    for (int x : v) cout << x << " ";
    cout << endl;

    // ② 排序：降序（greater 表示"从大到小"）
    sort(v.begin(), v.end(), greater<int>());
    for (int x : v) cout << x << " ";
    cout << endl;

    // ③ 查找：find 返回迭代器，找不到返回 end()
    auto it = find(v.begin(), v.end(), 7);
    if (it != v.end())
        cout << "找到 7，下标 " << (it - v.begin()) << endl;
    else
        cout << "没找到 7" << endl;

    // ④ 最大值：max_element 返回指向最大元素的迭代器
    auto maxIt = max_element(v.begin(), v.end());
    cout << "最大值 = " << *maxIt << endl;

    return 0;
}
