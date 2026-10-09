// 练习：new / delete —— 手动借内存、还内存
#include <iostream>
using namespace std;

class Student {
public:
    Student(const string& name) {
        name_ = name;
        cout << "构造：学生[" << name_ << "] 入学" << endl;
    }
    ~Student() {
        cout << "析构：学生[" << name_ << "] 离场" << endl;
    }
    void show() const {
        cout << "我是 " << name_ << endl;
    }
private:
    string name_;
};

int main() {
    // 一、借一个整数
    int* p = new int(10);              // new 借一块内存存 10，把地址交给 p
    cout << "借来的整数 = " << *p << endl;   // *p 取出里面的值
    delete p;                          // 用完还回去，别忘！

    cout << "----------------" << endl;

    // 二、借一个 Student 对象
    Student* s = new Student("小明");  // 借一块内存放学生，构造函数自动跑
    s->show();                         // 用箭头 -> 访问它的成员函数
    delete s;                          // 还回去，析构函数自动跑

    cout << "----------------" << endl;

    // 三、忘了 delete 会怎样？—— 内存泄漏（借了不还）
    // 把下面这两行开头的 // 去掉，再跑一次：
    // Student* leak = new Student("泄漏哥");
    // 没写 delete，这个对象占的内存永远收不回，程序越大越卡

    return 0;
}
