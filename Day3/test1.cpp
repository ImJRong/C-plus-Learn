// 练习：析构函数 —— 对象销毁时自动调用的"善后函数"
#include <iostream>
using namespace std;

class Student {
public:
    Student(const string& name) {          // 构造函数：创建对象时自动跑
        name_ = name;
        cout << "构造函数：学生[" << name_ << "] 入学了" << endl;
    }

    ~Student() {                    // 析构函数：销毁对象时自动跑（类名前加 ~）
        cout << "析构函数：学生[" << name_ << "] 离场了" << endl;
    }

private:
    string name_;
};

void makeOne() {
    Student temp("临时学生");       // 这个对象只活在这一对大括号里
}                                   // ← 走到这里，temp 销毁，析构函数自动跑

int main() {
    cout << "===== 开始 =====" << endl;

    Student a("小明");              // a 的生存期 = 整个 main

    makeOne();                      // 进去造一个"临时学生"，函数结束它就没

    cout << "===== 结束 =====" << endl;
    // 走到这里，a 销毁，析构函数自动跑（最后一条输出）
    return 0;
}
