// 练习：类 + 成员函数（area / isSquare）
#include<iostream>
using namespace std;
class Rectangle{
    private:
        double width_;
        double height_;

    public:
        Rectangle(double x,double y){
            width_=x;
            height_=y;
        }

        double area(){
            return width_*height_;
        }

        bool isSquare(){
            return (width_==height_);
        }

};

int main(){
    Rectangle rec1(3, 4);
    Rectangle rec2(5, 5);
    cout << "rec1 area: " << rec1.area() << endl;
    cout << "rec2 area: " << rec2.area() << endl;
    if (rec1.isSquare())
        cout << "rec1 是正方形" << endl;
    else
        cout << "rec1 不是正方形" << endl;

    if (rec2.isSquare())
        cout << "rec2 是正方形" << endl;
    else
        cout << "rec2 不是正方形" << endl;

    return 0;
}