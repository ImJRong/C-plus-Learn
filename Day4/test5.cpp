// Day4-5 班级成绩册：class + vector + 排序 + 引用传参 + const
#include<iostream>
#include<string>
#include<vector>
#include<cstdio>          // printf 需要这个头文件
using namespace std;

class Student{
    private:
    string name_;
    double score_;

    public:
    Student(const string& name, double score){   // 必须是 const 引用，否则 {"张三",85.5} 传不进来
        name_  = name;
        score_ = score;
    }
    string nameGetter() const {      // 末尾加 const，const 对象才能调用
        return name_;
    }
    double scoreGetter() const {
        return score_;
    }
};



void sortByScore(vector<Student>& v){
    for(int i=0;i<(int)v.size();i++)
        for(int j=i+1;j<(int)v.size();j++)
            if(v[i].scoreGetter()<v[j].scoreGetter()){
                Student tem=v[i];
                v[i]=v[j];
                v[j]=tem;
            }
}                                    // ← 这个 } 是关 sortByScore 的，你原来漏了

double average(const vector<Student>& v){
    double sum=0;
    for(int i=0;i<(int)v.size();i++)
        sum+=v[i].scoreGetter();
    return sum/v.size();
}

const Student& topStudent(const vector<Student>& v){
    int maxIndex=0;
    for(int i=1;i<(int)v.size();i++){
        if(v[i].scoreGetter()>v[maxIndex].scoreGetter())
            maxIndex=i;
    }
    return v[maxIndex];
}

void printGradeCount(const vector<Student>& v){
    int a=0, b=0, c=0, d=0;          // 不能写成 int a=b=c=d=0;
    for(int i=0; i<(int)v.size();i++){
        if(v[i].scoreGetter()>=90)
            a++;
        else if(v[i].scoreGetter()>=80)
            b++;
        else if(v[i].scoreGetter()>=60)
            c++;                     // 这里漏了分号
        else
            d++;
    }
    printf("优：%d 人，良：%d 人，及格：%d 人，不及格：%d 人\n",a,b,c,d);
}

int main(){
    vector<Student> v = {
        {"张三", 85.5}, {"李四", 92.0}, {"王五", 78.5},
        {"赵六", 95.5}, {"钱七", 88.0}, {"孙八", 73.0},
        {"周九", 91.5}, {"吴十", 66.5}
    };

    // ① 排序并打印
    cout << "=== 排序后（分数从高到低）===" << endl;
    sortByScore(v);
    for(size_t i=0;i<v.size();i++)
        cout << v[i].nameGetter() << "\t" << v[i].scoreGetter() << endl;

    // ② 平均分
    cout << "\n平均分：" << average(v) << endl;

    // ③ 最高分的学生（用返回的引用）
    const Student& top = topStudent(v);
    cout << "最高分：" << top.nameGetter() << "  " << top.scoreGetter() << endl;

    // ④ 分档统计
    cout << endl;
    printGradeCount(v);

    return 0;
}
