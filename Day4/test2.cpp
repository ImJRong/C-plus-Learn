// Day4-2 IoU 交并比（NMS 去重的核心：算两个框的重叠程度）
#include<iostream>
using namespace std;

struct Box {
    double x, y;   // 左上角坐标
    double w, h;   // 宽、高
};

double iou(const Box& a, const Box& b){
    auto inw=min(a.x+a.w, b.x+b.w) - max(a.x, b.x);
    auto inh=min(a.y+a.h, b.y+b.h) - max(a.y, b.y);
    if(inw<=0||inh<=0)
        return 0;
    else{
        auto ia=inw*inh;
        auto iaa=a.w*a.h;
        auto iba=b.w*b.h;
        auto iou=ia/(iaa+iba-ia);
        return iou;
    }

}


int main(){
    Box a1 = {0, 0, 10, 10},  b1 = {5, 5, 10, 10};      // 预期 0.1429
    Box a2 = {0, 0, 10, 10},  b2 = {20, 20, 10, 10};    // 预期 0
    Box a3 = {0, 0, 20, 20},  b3 = {5, 5, 10, 10};      // 预期 0.25

    printf("%.4f\n", iou(a1,b1));
    printf("%.4f\n", iou(a2,b2));
    printf("%.4f\n", iou(a3,b3));

    return 0;
}