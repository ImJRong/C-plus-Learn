#include<iostream>
using namespace std;
struct Point{
    int x,y;
};
void move(Point* p, int dx, int dy){
    p->x+=dx;
    p->y+=dy;
}
int main(){
    Point A{3,4};
    cout<<A.x<<endl<<A.y<<endl;
    move(&A,2,1);
    cout<<A.x<<endl<<A.y<<endl;
    return 0;
}