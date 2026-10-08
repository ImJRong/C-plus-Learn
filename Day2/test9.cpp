#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Student {
    string name;
    double score;
};

int main() {
    vector<Student> students;     // 装 Student 的动态数组

    // 逐个加入
    students.push_back({"张伟", 88.5});
    students.push_back({"李娜", 95.0});
    students.push_back({"王强", 76.0});

    for (int i = 0; i < students.size(); i++) {
        cout << students[i].name << " " << students[i].score << endl;
    }

    return 0;
}
