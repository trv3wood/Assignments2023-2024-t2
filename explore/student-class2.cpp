/*
 * 设计实现一个简易学生成绩管理程序，设学生信息包括学号（long）、姓名(20个字符)、性别（char），修读的科目有英语(int)、中文(int)、数学(int)。
 * 运行结果：
 * 英语的平均分是：68.5
 * 中文的平均分是：53.5
 * 数学的平均分是：61
 */
#include <iostream>
#include <cstring>
class Student {
private:
    long ID;
    char name[20];
    char gender;
    int english;
    int chinese;
    int maths;
    void updateScore() {
        members++;
        total_zh += this->chinese;
        total_math += this->maths;
        total_en += this->english;
    }
public:
    Student(long id, const char* name_, char gender_, int english_, int chinese_, int maths_): ID(id), gender(gender_), english(english_), chinese(chinese_), maths(maths_) {
        strcpy(name, name_);
        updateScore();
    }
    Student(): ID(0), name("noname"), gender(' '), english(0), chinese(0), maths(0) {updateScore();}
    Student(const Student& other) {
        *this = other;
        updateScore();
    }

    static double avg_chi() {return total_zh / members;}
    static double avg_eng() {return total_en / members;}
    static double avg_math() {return total_math / members;}
private:
    static int members;
    static double total_zh;
    static double total_math;
    static double total_en;
};

int Student::members = 0;
double Student::total_zh= 0.0;
double Student::total_math= 0.0;
double Student::total_en= 0.0;

int main() {

    Student std_1(1001,"Li Hua",'F',91,71,81);

    Student std_2(1002,"HeXiao",'M',92,72,82);

    Student std_3=std_1, std_4;

    std::cout << "英语的平均分是：" << Student::avg_eng() << std::endl

            << "中文的平均分是：" << Student::avg_chi() << std::endl

            << "数学的平均分是：" << Student::avg_math() << std::endl;
    return 0;
}