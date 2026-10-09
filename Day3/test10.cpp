// 练习：map 常用操作
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<string, int> score;

    // ① 存（键不存在会自动创建）
    score["张三"] = 88;
    score["李四"] = 92;
    score["王五"] = 78;

    // ② 查
    cout << "张三的分数 = " << score["张三"] << endl;

    // ③ 遍历（按键从小到大自动排序）
    for (auto& p : score) {          // p 是 pair，p.first 是键，p.second 是值
        cout << p.first << " -> " << p.second << endl;
    }

    // ④ 判断键是否存在（find 找不到返回 end()）
    if (score.find("赵六") != score.end())
        cout << "赵六存在" << endl;
    else
        cout << "赵六不存在" << endl;

    // ⑤ 删除
    score.erase("李四");

    // ⑥ 个数
    cout << "剩 " << score.size() << " 个人" << endl;

    return 0;
}
