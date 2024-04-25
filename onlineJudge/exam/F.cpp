/*在大学期间，学生的学分由实践学分和课程学分组成，担任校级组织、院级组织、班级的学生干部可以增加一定的实践学分。
设计一个层次类实现计算学生的总学分并显示。首先定义一个Student的抽象类，提供有共同操作界面的纯虚函数，由此类派生出SchoolStuLeader类、FacultiesStuLeader类、ClassStuLeader类和RegStudent类。
每一种类中学分计算方式如下：
校级组织学生干部：实践学分 = （任职时长（天数） * 0.01 + 2）/ 5
院级组织学生干部：实践学分 = （任职时长（天数） * 0.01 + 1）/ 5
班级学生干部：实践学分 = （任职时长（天数） * 0.01 + 0.8）/ 5
无任职学生：实践学分 = 课外实践时长（小时） * 0.005
总学分 = 实践学分（其中任职时长和实践时长均键盘输入） + 课程学分（键盘输入）
已知某个学生数据，包括学号、姓名、实践学分、课程学分。设计函数求该学生的总学分并显示，设计一个disp显示该学生的信息和总学分。定义以上所有类，在第二层类中提供全部函数的实现。在测试函数中使用基类指针实现不同派生类对象的操作。*/
#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;
class Student {
protected:
    string name;
    int id;
    int days;
    int course;
    double prac;
    double TotalCredit;
public:
    Student(int i, const string& na, int d, int c): id(i), name(na), days(d), course(c) {}
    virtual void calculateCredits() {}
    virtual void getTotalCredit() {}
    virtual void disp() {}
};
class SchoolStuLeader : public Student {
public:
    SchoolStuLeader(int i, const string& na, int d, int c): Student(i, na, d, c) {}
    // 实践学分 = （任职时长（天数） * 0.01 + 2）/ 5
    void calculateCredits() override {
        prac = (days * 0.01 + 2) / 5;
    }
    void getTotalCredit() override {
        TotalCredit = prac + course;
    }
    void disp() override {
        std::cout << "校级学生干部：" << '\n';
        cout << "学号：" << id << "，姓名：" << name << '\n';
        cout << "总学分：" << TotalCredit << '\n';
    }
};
class FacultiesStuLeader : public Student {
public:
    FacultiesStuLeader(int i, const string& na, int d, int c): Student(i, na, d, c) {}
    void calculateCredits() override {
        prac = (days * 0.01 + 1) / 5;
    }
    void getTotalCredit() override {
        TotalCredit = prac + course;
    }
    void disp() override {
        std::cout << "院级学生干部：" << '\n';
        cout << "学号：" << id << "，姓名：" << name << '\n';
        cout << "总学分：" << TotalCredit << '\n';
    }

};
class ClassStuLeader : public Student {
public:
    ClassStuLeader(int i, const string& na, int d, int c): Student(i, na, d, c) {}

    void calculateCredits() override {
        prac = (days * 0.01 + 0.8) / 5;
    }
    void getTotalCredit() override {
        TotalCredit = prac + course;
    }
    void disp() override {
        std::cout << "班级学生干部：" << '\n';
        cout << "学号：" << id << "，姓名：" << name << '\n';
        cout << "总学分：" << TotalCredit << '\n';
    }
};
class RegStudent : public Student {
private:
    int hours;
public:
    RegStudent(int i, const string& na, int h, int c): Student(i, na, 0, c), hours(h) {}

    void calculateCredits() override {
        prac = hours * 0.005;
    }
    void getTotalCredit() override {
        TotalCredit = prac + course;
    }
    void disp() override {
        std::cout << "普通学生：" << '\n';
        cout << "学号：" << id << "，姓名：" << name << '\n';
        cout << "总学分：" << TotalCredit << '\n';
    }
};
int main() {
    Student* student;
    cout << "请输入校级学生干部的信息，包括学号，名字，任职天数，课程学分："
         << endl;
    int id;
    string n;
    double days;
    double course;
    cin >> id >> n >> days >> course;
    student = new SchoolStuLeader(id, n, days, course);
    student->calculateCredits();  // 计算所获得的实践学分
    student->getTotalCredit();    // 计算总学分
    student->disp();              // 显示信息

    cout << "请输入院级学生干部的信息，包括学号，名字，任职天数，课程学分："
         << endl;
    cin >> id >> n >> days >> course;
    student = new FacultiesStuLeader(id, n, days, course);
    student->calculateCredits();
    student->getTotalCredit();
    student->disp();

    cout << "请输入班级学生干部的信息，包括学号，名字，任职天数，课程学分："
         << endl;
    cin >> id >> n >> days >> course;
    student = new ClassStuLeader(id, n, days, course);
    student->calculateCredits();
    student->getTotalCredit();
    student->disp();

    cout << "请输入非学生干部的信息，包括学号，名字，课外实践时长，课程学分："
         << endl;
    double hours;
    cin >> id >> n >> hours >> course;

    student = new RegStudent(id, n, hours, course);
    student->calculateCredits();
    student->getTotalCredit();
    student->disp();

    return 0;
}