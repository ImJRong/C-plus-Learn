// 练习：动态数组类 MyArray —— 构造/析构/深拷贝/下标重载
#include <iostream>
using namespace std;

class MyArray {
public:
    // ① 构造：借 n 个 int
    MyArray(int n) {
        size_ = n;
        data_ = new int[n];
    }

    // ② 析构：还内存
    ~MyArray() {
        delete[] data_;
    }

    // ③ 拷贝构造：深拷贝（新借一块，逐个复制）
    MyArray(const MyArray& other) {
        size_ = other.size_;
        data_ = new int[size_];
        for (int i = 0; i < size_; i++)
            data_[i] = other.data_[i];
    }

    // ④ 拷贝赋值：深拷贝（先清旧的，防自赋值，再借新的）
    MyArray& operator=(const MyArray& other) {
        if (this != &other) {
            delete[] data_;
            size_ = other.size_;
            data_ = new int[size_];
            for (int i = 0; i < size_; i++)
                data_[i] = other.data_[i];
        }
        return *this;
    }

    // ⑤ 下标重载：返回引用，才能读也能写
    int& operator[](int i) {
        return data_[i];
    }

    // ⑥ 返回元素个数
    int size() const {
        return size_;
    }

private:
    int* data_;
    int  size_;
};

int main() {
    // 用 {1,2,3,4,5} 初始化 a
    MyArray a(5);
    for (int i = 0; i < a.size(); i++)
        a[i] = i + 1;

    // ① 拷贝构造：深拷贝，改 b 不影响 a
    MyArray b = a;
    b[0] = 999;
    cout << "a[0] = " << a[0] << "（应为 1）" << endl;
    cout << "b[0] = " << b[0] << "（应为 999）" << endl;

    // ② 拷贝赋值：c 原来是 3 个，赋值后变成 a 的内容
    MyArray c(3);
    c[0] = 10; c[1] = 20; c[2] = 30;
    c = a;
    cout << "赋值后 c: ";
    for (int i = 0; i < c.size(); i++)
        cout << c[i] << " ";
    cout << "（应为 1 2 3 4 5）" << endl;

    // ③ 连续赋值
    MyArray d(2);
    d[0] = 7; d[1] = 8;
    MyArray e(2), f(2);
    e = f = d;
    cout << "连续赋值后 e: " << e[0] << " " << e[1] << "（应为 7 8）" << endl;

    return 0;
}
