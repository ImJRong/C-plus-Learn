#include<iostream>
using namespace std;

void reverseArray(int* arr, int n){
    int* x=arr;
    int* y=arr+n-1;
    while(1){
        if(x==y)
            break;
        int tem=0;
        tem=*x;
        *x=*y;
        *y=tem;
        x++;
        y--;
}


}
int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n=sizeof(arr)/sizeof(arr[0]);
    reverseArray(arr,n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}