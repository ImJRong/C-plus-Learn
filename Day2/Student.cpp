#include "Student.h"
#include <iostream>
using namespace std;

Student::Student(const string& name, int age) {
    name_ = name;
    age_  = age;
}

void Student::show() const {
    cout << name_ << " " << age_ << endl;
}
