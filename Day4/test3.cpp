// 练习：map 统计单词词频
#include <iostream>
#include <map>
#include <string>
#include <sstream>
using namespace std;

int main() {
    string s = "the cat the dog the bird cat";

    map<string, int> m;          // 键：单词，值：出现次数

    istringstream iss(s);        // 把字符串当成输入流，自动按空格切词
    string word;
    while (iss >> word) {        // 每轮读出一个单词
        m[word]++;               // 该单词计数 +1（map 里没有会自动创建，初值 0）
    }

    // 用迭代器遍历：map 的每个元素是一对 (键, 值)
    for (auto it = m.begin(); it != m.end(); it++) {
        cout << it->first << ": " << it->second << endl;   // first=键 second=值
    }

    return 0;
}
