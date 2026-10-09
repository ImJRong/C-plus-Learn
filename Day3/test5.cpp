// 练习：深拷贝 —— 自己写拷贝构造函数，避免浅拷贝崩溃
#include <iostream>
using namespace std;

class Buffer {
public:
    Buffer(int n) {                 // 普通构造：借一块内存
        size_ = n;
        data_ = new int[n];
        cout << "构造：借了内存 " << data_ << endl;
    }

    // 深拷贝：拷贝构造函数
    Buffer(const Buffer& other) {
        size_ = other.size_;
        data_ = new int[size_];                 // ① 新借一块，地址跟 other 不一样
        for (int i = 0; i < size_; i++) {
            data_[i] = other.data_[i];          // ② 内容逐个抄过去
        }
        cout << "拷贝构造（深拷贝）：新借内存 " << data_ << endl;
    }

    ~Buffer() {                     // 析构：还内存
        cout << "析构：还内存 " << data_ << endl;
        delete[] data_;
    }

    int* data_;
    int size_;
};

int main() {
    Buffer a(5);
    Buffer b(a);                   // 走深拷贝，b 有自己独立的内存

    cout << "a.data_ = " << a.data_ << endl;
    cout << "b.data_ = " << b.data_ << endl;
    // 现在两个地址不一样了，析构各还各的，不再崩

    return 0;
}
