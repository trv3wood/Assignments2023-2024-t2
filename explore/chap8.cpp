/*设计实现一个简易学生成绩管理程序，学生信息包括学号（long）、姓名(20个字符)、性别（char），修读的科目有英语(int)、中文(int)、数学(int)。设学生分文科生和理科生，除了修读英语、中文和数学外，文科生还修读了历史(int)、地理(int)、政治(int)，理科生还要修读了物理(int)、化学(int)、生物(int)。请在第7章研讨的基础上，分别建立文科生类和理科生类，均由学生类派生。为两个派生类重载”>>”和”<<”运算符，并计算每个学生的总分和各门课程的平均分。程序的一次运行结果如下图所示。请补充类的设计。（注：请勿修改已提供的代码）
输入示例
ScienceStudent stu_ss[5];
1 zsan m 80 90 70 85 90 80
2 lisi f 85 95 75 90 85 75
3 wangwu m 90 80 85 80 85 90
4 zhaoliu f 95 85 90 95 80 85
5 sunqi m 75 85 95 75 90 85
ArtStudent stu_las[5];
6 zhangsa m 80 90 70 83 90 80
7 lis f 85 95 75 90 85 95
8 wanwu m 90 80 85 80 85 92
9 zhaliu f 95 85 90 95 83 85
10 suni m 75 85 95 75 80 85
*/
#include <cstring>
#include <iostream>
#include <istream>
#include <ostream>

using std::endl;

class Student {
public:
    Student(long n, const char *p, char s, int e, int m, int c);
    Student() {}
    static int totalMembers;
    static double totalChinese;
    static double totalMath;
    static double totalEnglish;
    static double getAvgCh() { return totalChinese / totalMembers; }
    static double getAvgMath() { return totalMath / totalMembers; }
    static double getAvgEn() { return totalEnglish / totalMembers; }

protected:
    long ID;
    char name[20];
    char gender;
    int english;
    int math;
    int chinese;
};
double Student::totalChinese = 0;
double Student::totalMath = 0;
double Student::totalEnglish = 0;
int Student::totalMembers = 0;

class LiberalArtStudent : public Student {
public:
    LiberalArtStudent(long n, const char *p, char s, int e, int m, int c, int h,
                      int g, int politics_);
    LiberalArtStudent() {}
    friend std::istream &operator>>(std::istream &input,
                                    LiberalArtStudent &student);
    friend std::ostream &operator<<(std::ostream &output,
                                    const LiberalArtStudent &student);
    static void get_average() {
        std::cout << "The average of History:" << averageHistory()
                  << "\tGeography" << averageGeography() << "\tPolitics"
                  << averagePolitics() << std::endl;
    }

protected:
    int history;
    int geography;
    int politics;
    int individualTotal;
    static double totalHistory;
    static double totalGeography;
    static double totalPolitics;
    static int totalMembers;
    static double averageHistory() { return totalHistory / totalMembers; }
    static double averageGeography() { return totalGeography / totalMembers; }
    static double averagePolitics() { return totalPolitics / totalMembers; }
};
double LiberalArtStudent::totalHistory = 0;
double LiberalArtStudent::totalGeography = 0;
double LiberalArtStudent::totalPolitics = 0;
int LiberalArtStudent::totalMembers = 0;

class ScienceStudent : public Student {
public:
    ScienceStudent(long n, const char *p, char s, int e, int m, int c, int ph,
                   int ch, int bi);
    ScienceStudent() {}
    friend std::istream &operator>>(std::istream &input,
                                    ScienceStudent &student);
    friend std::ostream &operator<<(std::ostream &output,
                                    const ScienceStudent &student);
    static double averagePhysics() {
        return totalPhysics / ScienceStudent::totalMembers;
    }
    static double averageChemistry() {
        return totalChemistry / ScienceStudent::totalMembers;
    }
    static double averageBiology() {
        return totalBiology / ScienceStudent::totalMembers;
    }
    static void get_average() {
        std::cout << "The average of Physics:" << averagePhysics()
                  << "\tChemistry:" << averageChemistry()
                  << "\tBiology:" << averageBiology() << std::endl;
    }

protected:
    int physics;
    int chemistry;
    int biology;
    int individualTotal;
    static double totalPhysics;
    static double totalChemistry;
    static double totalBiology;
    static int totalMembers;
};
double ScienceStudent::totalPhysics = 0;
double ScienceStudent::totalChemistry = 0;
double ScienceStudent::totalBiology = 0;
int ScienceStudent::totalMembers = 0;

int main() {
    ScienceStudent stu_ss[5];

    LiberalArtStudent stu_las[5];

    int i;

    std::cout << "请按以下顺序输入理科生信息：\n学号\t姓名\t性别\t英语\t语文\t"
                 "数学\t物理\t化学\t生物"
              << std::endl;

    for (i = 0; i < 5; i++) std::cin >> stu_ss[i];

    std::cout << "\n理科生成绩单：\n学号\t姓名\t性别\t英语\t语文\t数学\t物理\t"
                 "化学\t生物\t总分\n";

    for (i = 0; i < 5; i++) std::cout << stu_ss[i] << std::endl;

    std::cout << "请按以下顺序输入文科生信息：\n学号\t姓名\t性别\t英语\t语文\t"
                 "数学\t历史\t地理\t政治"
              << endl;

    for (i = 0; i < 5; i++) std::cin >> stu_las[i];

    std::cout << "\n文科生成绩单：\n学号\t姓名\t性别\t英语\t语文\t数学\t历史\t"
                 "地理\t政治\t总分\n";

    for (i = 0; i < 5; i++) std::cout << stu_las[i] << endl;

    std::cout << "The average of English:" << Student::getAvgEn()
              << "\tChinese:"

              << Student::getAvgCh() << "\tMath:" << Student::getAvgMath()
              << endl;

    ScienceStudent::get_average();

    LiberalArtStudent::get_average();

    return 0;
}
Student::Student(long n, const char *p, char s, int e, int m, int c)
    : ID(n), gender(s), english(e), math(m), chinese(c) {
    strcpy(name, p);
    Student::totalMembers++;
    Student::totalChinese += chinese;
    Student::totalMath += math;
    Student::totalEnglish += english;
}

LiberalArtStudent::LiberalArtStudent(long n, const char *p, char s, int e,
                                     int m, int c, int h, int g, int politics_)
    : Student(n, p, s, e, m, c), history(h), geography(g), politics(politics_) {
    LiberalArtStudent::totalHistory += history;
    LiberalArtStudent::totalGeography += geography;
    LiberalArtStudent::totalPolitics += politics;
    LiberalArtStudent::totalMembers++;
    individualTotal = english + math + chinese + history + geography + politics;
}

std::istream &operator>>(std::istream &input, LiberalArtStudent &student) {
    input >> student.ID >> student.name >> student.gender >> student.english >>
        student.chinese >> student.math >> student.history >>
        student.geography >> student.politics;
    student.individualTotal = student.english + student.math + student.chinese +
                              student.history + student.geography +
                              student.politics;

    Student::totalMembers++;
    Student::totalChinese += student.chinese;
    Student::totalMath += student.math;
    Student::totalEnglish += student.english;

    LiberalArtStudent::totalMembers++;
    LiberalArtStudent::totalHistory += student.history;
    LiberalArtStudent::totalGeography += student.geography;
    LiberalArtStudent::totalPolitics += student.politics;
    return input;
}

std::ostream &operator<<(std::ostream &output,
                         const LiberalArtStudent &student) {
    output << student.ID << '\t' << student.name << '\t' << student.gender
           << '\t' << student.english << '\t' << student.math << '\t'
           << student.chinese << '\t' << student.history << '\t'
           << student.geography << '\t' << student.politics << '\t'
           << student.individualTotal;
    return output;
}

ScienceStudent::ScienceStudent(long n, const char *p, char s, int e, int m,
                               int c, int ph, int ch, int bi)
    : Student(n, p, s, e, m, c), physics(ph), chemistry(ch), biology(bi) {
    ScienceStudent::totalPhysics += physics;
    ScienceStudent::totalChemistry += chemistry;
    ScienceStudent::totalBiology += biology;
    ScienceStudent::totalMembers++;
    individualTotal = english + math + chinese + physics + chemistry + biology;
}

std::istream &operator>>(std::istream &input, ScienceStudent &student) {
    input >> student.ID >> student.name >> student.gender >> student.english >>
        student.chinese >> student.math >> student.physics >>
        student.chemistry >> student.biology;
    student.individualTotal = student.english + student.math + student.chinese +
                              student.physics + student.chemistry +
                              student.biology;

    Student::totalMembers++;
    Student::totalChinese += student.chinese;
    Student::totalMath += student.math;
    Student::totalEnglish += student.english;

    ScienceStudent::totalMembers++;
    ScienceStudent::totalPhysics += student.physics;
    ScienceStudent::totalChemistry += student.chemistry;
    ScienceStudent::totalBiology += student.biology;
    return input;
}

std::ostream &operator<<(std::ostream &output, const ScienceStudent &student) {
    output << student.ID << '\t' << student.name << '\t' << student.gender
           << '\t' << student.english << '\t' << student.math << '\t'
           << student.chinese << '\t' << student.physics << '\t'
           << student.chemistry << '\t' << student.biology << '\t'
           << student.individualTotal;
    return output;
}
