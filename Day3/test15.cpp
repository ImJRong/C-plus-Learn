#include<iostream>
#include<vector>
using namespace std;

struct Box {
    double x, y;      // 左上角坐标
    double w, h;      // 宽、高
    double conf;      // 置信度，0~1，越大越可信
};

int main(){
    vector<Box> boxes = {
    {10,  10,  50, 80, 0.65},
    {100, 20,  40, 60, 0.90},
    {200, 30,  70, 90, 0.45},
    {50,  100, 30, 40, 0.30},
    {150, 60,  60, 70, 0.75},
    {80,  150, 45, 55, 0.88},
    {220, 90,  35, 65, 0.52},
    {30,  200, 55, 45, 0.95},
    {170, 220, 40, 50, 0.38},
    {90,  40,  65, 75, 0.71},
    {250, 140, 30, 45, 0.61},
    {120, 250, 50, 60, 0.83}
};
    for(int i=0;i<boxes.size();i++){
        for(int j=i+1;j<boxes.size();j++){
            if(boxes[i].conf<boxes[j].conf){
                Box tem=boxes[i];
                boxes[i]=boxes[j];
                boxes[j]=tem;
            }
        }
    }

    vector<Box> newboxes;
    for(int i=0;i<boxes.size();i++){
        if(boxes[i].conf>0.5)
            newboxes.push_back(boxes[i]);
    }

    for(int i=0;i<newboxes.size();i++)
        //cout<<"("<<newboxes[i].x<<", "<<newboxes[i].y<<", "<<newboxes[i].w<<", "<<newboxes[i].h<<") conf= "<<newboxes[i].conf<<endl;
        printf("(%.0f, %.0f, %.0f, %.0f) conf=%.2f\n", newboxes[i].x, newboxes[i].y, newboxes[i].w, newboxes[i].h, newboxes[i].conf);


    return 0;
}