/*
 *设计实现一个简易学生成绩管理程序，设学生信息包括学号（long）、姓名(20个字符)、性别（char），修读的科目有英语(int)、中文(int)、数学(int)。请补充Student类的设计，使程序运行能得到以下输出结果。
 *图略
 */
#include<iostream>
#include <cstring>
using namespace std;
class Student {
private:
    long ID;
    char name[20];
    char gender;
    int english;
    int chinese;
    int maths;
public:
    Student(long id, const char* name_, char gender_, int english_, int chinese_, int maths_): ID(id), gender(gender_), english(english_), chinese(chinese_), maths(maths_) {
        strcpy(name, name_);
    }
    Student(const Student& other) {
        *this = other;
    }
    Student(): ID(0), name("noname"), gender(' '), english(0), chinese(0), maths(0) {}
    void show() {
        std::cout << "学号：" << ID << "\t姓名：" << name << "\t性别：" << gender << "\t英语：" << english << "\t语文：" << chinese << "\t数学：" << maths << std::endl;
    }
};

int main() {

Student std_1(1001,"Li Hua",'F',91,71,81);

Student std_2(1002,"HeXiao",'M',92,72,82);

Student std_3=std_1;Student std_4;

std_1.show();

std_2.show();

std_3.show();

std_4.show();

return 0;

}