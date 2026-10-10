#include<iostream>
#include<vector>
#include<stdexcept>
using namespace std;

class Stack{
    public:
    Stack(int cap){
        data_ =new int[cap];
        capacity_=cap;
        size_=0;
    }
    ~Stack(){
        delete data_;
    }

    void pushNum(int v){
        if(size_==capacity_)
            throw runtime_error("栈已满");
        else{
            data_[size_]=v;
            size_++;
        }
    }
    int popNum(){
        if(size_==0){
            throw runtime_error("栈已空"); 
        }
        else{
            size_--;
            return data_[size_];

        }
    }
    int peek(){
       if(size_==0){
            throw runtime_error("栈已空");
            return 1;    
        }
        else
            return data_[size_-1];
    }
    bool isEmpty(){
        return size_==0;
    }

    int size(){
        return size_;
    }

    private:
        int* data_;
        int capacity_;
        int size_;

};





int main(){
    Stack sta(3);
    sta.pushNum(1);
    sta.pushNum(2);
    sta.pushNum(3);
    try{sta.pushNum(4);}
        catch(const exception& e){
            cout<<"出错了,"<<e.what()<<endl;
        }

    cout<<sta.peek()<<endl;

    cout<<sta.popNum()<<endl;
    cout<<sta.popNum()<<endl;
    cout<<sta.popNum()<<endl;

    try{sta.popNum();}
        catch(const exception& e){
            cout<<"出错了,"<<e.what()<<endl;
        }


    return 0;
}