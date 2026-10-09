// 练习：智能指针 —— 自动管内存，不用手写 delete
#include <iostream>
#include <memory>   // 智能指针头文件
using namespace std;

class Student {
public:
    Student(string name) {
        name_ = name;
        cout << "构造：" << name_ << endl;
    }
    ~Student() {
        cout << "析构：" << name_ << endl;
    }
    void show() { cout << "我是 " << name_ << endl; }
private:
    string name_;
};

int main() {
    cout << "== 一、unique_ptr：独占，只有一个主人 ==" << endl;
    {
        unique_ptr<Student> p = make_unique<Student>("小明");
        p->show();                    // 用 -> 访问，跟普通指针一样
        // 不用写 delete！出了这个大括号，自动析构
    }
    cout << "（上面 p 出了作用域，自动析构了）" << endl;

    cout << "\n== 二、shared_ptr：共享，多个主人，全用完才释放 ==" << endl;
    {
        shared_ptr<Student> s1 = make_shared<Student>("小红");
        {
            shared_ptr<Student> s2 = s1;   // s2 也指向同一个，计数 +1
            cout << "引用计数 = " << s1.use_count() << endl;  // 2
        }
        // 这里 s2 出了作用域，但 s1 还在，不释放
        cout << "引用计数 = " << s1.use_count() << endl;      // 1
    }
    // 这里 s1 也出了作用域，计数归 0，才释放
    cout << "（全部引用都没了，才析构）" << endl;

    return 0;
}
