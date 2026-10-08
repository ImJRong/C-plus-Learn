#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
public:
    Student(const std::string& name, int age);
    void show() const;

private:
    std::string name_;
    int age_;
};

#endif
