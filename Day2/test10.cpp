#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1 = "hello";
    string s2 = "world";

    cout << s1 + " " + s2 << endl;    // 拼接：hello world

    cout << s1.length() << endl;      // 5 —— 长度

    cout << s1[0] << endl;            // h —— 下标取字符

    s1 += " cpp";                     // 追加
    cout << s1 << endl;               // hello cpp

    if (s1 == "hello cpp") {          // 直接 == 比较
        cout << "相等" << endl;
    }

    return 0;
}
