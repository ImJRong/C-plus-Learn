// Day4-1 STL 算法练习：sort / max_element / min_element / find / count
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int> v = {5, 2, 9, 1, 7, 3, 9, 4, 8};
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    auto maxele=max_element(v.begin(),v.end());
    cout<<"max: "<<*maxele<<endl;

    auto minele=min_element(v.begin(),v.end());
    cout<<"min: "<<*minele<<endl;

    auto find7=find(v.begin(),v.end(),7);
    if(find7 != v.end())
        cout<<"element 7: "<<find7-v.begin()<<endl;
    else
        cout<<"element 7 is not exist";
    
    auto count9=0;
    for(int i=0;i<v.size();i++){
        if(v[i]==9)
            count9++;
    }
    cout<<"9的个数: "<<count9;

    


    return 0;
}