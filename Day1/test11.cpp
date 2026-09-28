//最大子数组和
#include<iostream>
using namespace std;
int main(){
    int num[] = {
        -2, 1, -3, 4, -1, 2, 1, -5, 4,
        6, -3, 8, -9, 2, 5, -1, 7, -4,
        -6, 3, 10, -2, 4, -8, 5, 1, -3, 6
    };
    int size=sizeof(num)/sizeof(num[0]);
    int best=0,cur=0;

    for(int i=0;i<size;i++){
        cur+=num[i];
        if(cur>best)
            best=cur;
        if(cur<0)
            cur=0;
    }
    cout<<best<<endl;


    return 0;
}