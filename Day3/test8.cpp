// 练习：动态数组类 MyArray —— 你来补全
#include <iostream>
using namespace std;

class MyArray {
public:
    // ① 构造：借 n 个 int（你来写）
    MyArray(int n){
        size_=n;
        data_=new int[size_];
    }

    // ② 析构：还内存（你来写）
    ~MyArray(){
        delete[] data_;
    }

    // ③ 拷贝构造：深拷贝（你来写）
    MyArray(const MyArray& other){
        size_=other.size_;
        data_=new int[other.size_];
        for(int i=0;i<other.size_;i++)
            data_[i]=other.data_[i];

    }

    // ④ 拷贝赋值：深拷贝 + 防自赋值（你来写）
    MyArray& operator=(MyArray& other){
        if(this!=&other){
            delete[] data_;
            size_=other.size_;
            data_=new int[other.size_];
            for(int i=0;i<other.size_;i++)
                data_[i]=other.data_[i];
        }
        return *this;

    }

    // ⑤ 下标重载：返回引用，能读能写（你来写）
    int& operator[](int n){
        return data_[n];
    }

    // ⑥ 返回元素个数（你来写）
    int size(){
        return size_;
    }

    // ⑦ 追加：在末尾新增一个元素（你来写）
    //    提示：需要新借一块 size_+1 的数组，把旧的复制过去，再放进新元素，最后删旧的
    MyArray& append(int n){
       int* tem=new int[size_+1];
       for(int i=0;i<size_;i++)
            tem[i]=data_[i];
        tem[size_]=n;
        delete[] data_;
        size_+=1;
        data_=tem;
        return *this;

    }

    // ⑧ 打印所有元素（你来写）
    MyArray& print(){
        for(int i=0;i<size_;i++)
            cout<<data_[i]<<" ";
        cout<<endl;
        return *this;
    }

private:
    int* data_;
    int  size_;
};

int main() {
    MyArray a(5);
    for (int i = 0; i < a.size(); i++)
        a[i] = i + 1;            // 1 2 3 4 5

    // 拷贝构造测试
    MyArray b = a;
    b[0] = 100;//下标重载

    // 拷贝赋值测试
    MyArray c(3);
    c = a;

    // 追加测试
    a.append(99).append(520);                // 追加后应为 1 2 3 4 5 99 520

    a.print();
    b.print();
    c.print();

    return 0;
}
