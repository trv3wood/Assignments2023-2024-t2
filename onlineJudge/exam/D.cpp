/*编写一个程序，已知某个学生数据，包括学号、姓名、平时作业成绩、期中考试成绩、期末考试成绩。设计成员函数求该学生的总成绩并显示，设计一个
disp 函数显示该学生的信息及成绩单。 已给出了 main () 函数。成员函数
couscore的功能是求某学生的总成绩并显示，disp
函数功能是显示学生的姓名、学号和成绩单。 要求按照 main () 函数及对应的输出完成
Student 类的设计，要求 Student
类中包含学号、姓名、平时作业成绩、期中考试成绩、期末考试成绩等数据成员，包含总成绩的静态数据成员，另外包含构造函数（参数为学号、姓名、平时作业成绩、期中考试成绩、期末考试成绩）、计算总成绩的成员函数
(couscore) 以及显示成绩的成员函数 (disp)。 注：总成绩 = 平时作业成绩 * 20% +
期中考试成绩 * 30% + 期末考试成绩*50%*/
#include <bits/stdc++.h>

#include <iostream>
#include <string>

using namespace std;
class Student {
private:
    string name;
    double hw, midterm, final;
    int id;

public:
    Student(int i, const string& n, double h, double mid, double fi)
        : name(n), hw(h), midterm(mid), final(fi), id(i) {}
    void couscore() {
        double total = hw * 0.2 + midterm * 0.3 + final * 0.5;
        cout << "总成绩: " << total << '\n';
    }
    void disp() {
        cout << "学生姓名: " << name << '\n';
        cout << "学生学号: " << id << '\n';
        cout << "平时作业成绩: " << hw << '\n';
        cout << "期中考试成绩: " << midterm << '\n';
        cout << "期末考试成绩: " << final << "\n\n";
    }
};
int main() {
    int id;
    string name;
    double hw, midterm, final;
    char continue_input = 'y';  // 控制是否继续输入的标志

    while (continue_input == 'y') {
        cout << "请输入学生学号: ";
        cin >> id;
        cout << "请输入学生姓名: ";
        cin >> name;
        cout << "请输入平时作业成绩: ";
        cin >> hw;
        cout << "请输入期中考试成绩: ";
        cin >> midterm;
        cout << "请输入期末考试成绩: ";
        cin >> final;

        Student student(id, name, hw, midterm, final);
        student.couscore();
        student.disp();

        cout << "是否继续输入学生信息？(y/n): ";
        cin >> continue_input;
    }

    return 0;
}