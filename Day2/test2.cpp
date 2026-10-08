#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name_;
    int    age_;

public:
    // 构造函数：名字和类名相同，无返回值
    Student(const string& n, int a) {
        name_ = n;
        age_  = a;
    }

    void show() {
        cout << name_ << " " << age_ << endl;
    }
};

int main() {
    Student s1("张佳荣", 20);   // 创建对象时，自动调用构造函数
    s1.show();                // 张三 20

    return 0;
}

