// 练习：类的定义与封装
// 数据成员私有，通过公有成员函数访问（setter / getter 模式）

#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name_;       // 私有成员：外部不能直接访问
    int    age_;

public:
    // 设置名字
    void setName(const string& n) {      //应用，省复制
        name_ = n;
    }

    // 设置年龄
    void setAge(int a) {
        age_ = a;
    }

    // 打印信息
    void show() {
        cout << name_ << " " << age_ << endl;
    }
};

int main() {
    Student s1;
    s1.setName("张佳荣");
    s1.setAge(22);
    s1.show();          // 输出：张佳荣 22

    return 0;
}
