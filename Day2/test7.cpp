#include<iostream>
using namespace std;
class Counter{
    private:
        int count_;
    public:
        Counter(int n){
            count_=n;
        }
        void increment(){
            count_++;
        }
        int* get(){
            return &count_;
        }

};
int main(){
Counter c(0);        // count_ 现在是 0
cout << *(c.get())<<endl;
*(c.get()) = 100;    // 通过 get() 返回的引用，直接把 count_ 改成 100
cout << *(c.get())<<endl;
c.increment();    // count_ 加 1，变 101
cout << *(c.get())<<endl;  // 打印 101



}