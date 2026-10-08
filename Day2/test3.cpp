#include<iostream>
using namespace std;
void swap(int* a, int* b){
    int tem;
    tem=*a;
    *a=*b;
    *b=tem;
}
int main(){
    int a=10 ,b=20;
    cout<<a<<endl<<b<<endl;
    swap(&a,&b);
    cout<<a<<endl<<b<<endl;
    return 0;
}
