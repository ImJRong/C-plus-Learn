// 练习：指针排序（全程指针，不用下标）
#include<iostream>
using namespace std;

void sortArray(int* arr, int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int tem;
            if(*(arr+i)>*(arr+j)){
                tem=*(arr+i);
                *(arr+i)=*(arr+j);
                *(arr+j)=tem;
            }
        }
    }


};
int main(){
    int arr[] = {5, 2, 9, 1, 7, 3};
    int n=sizeof(arr)/sizeof(arr[0]);
    sortArray(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}