// 练习：vector 存点，找离原点最远的点
#include<iostream>
#include<vector>
using namespace std;

struct Point{
    int x,y;
};

int main(){
vector<Point> point={
    {3, 4}, {1, 1}, {5, 12}, {6, 8}, {2, 2}
};
    int n=point.size();
    int maxIndex = 0;
    for(int i=1;i<n;i++){
        if(point[i].x*point[i].x+point[i].y*point[i].y>point[maxIndex].x*point[maxIndex].x+point[maxIndex].y*point[maxIndex].y)
            maxIndex=i;
    }
    cout<<"("<<point[maxIndex].x<<","<<point[maxIndex].y<<")"<<endl;
    return 0;
}