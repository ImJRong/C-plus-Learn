// 练习：指针遍历数组找最大值
#include<iostream>
using namespace std;

int maxInArray(int* arr, int n){
    int max = *arr;
    for(int i=0;i<n;i++){
        if(max<*arr)
        max=*arr;

        arr++;
    }

    return max;
}

int main(){
    int arr[] = {34, 7, 89, 12, 56, 90, 23, 78, 45, 3};
    cout<<maxInArray(arr,sizeof(arr)/sizeof(arr[0]))<<endl;
    return 0;
}