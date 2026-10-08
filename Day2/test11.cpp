// 练习：vector + while 循环求平均值
#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> nums;
    int x;
    double sum=0;
    while(1){
        cin>>x;
        if(x!=0){
            nums.push_back(x);
            sum+=x;
        }
        else
            break;
    }
    double avg = sum/nums.size();
    cout<<avg;
    return 0;
}