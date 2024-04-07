/*在第8章研讨题的基础上，
对学生成绩单按降序排序后输出，
排序规则为按总分排序、总分相同的按语文成绩排、语文成绩还相同的按数学成绩排、数学成绩也相同的按英语成绩排，
前面都相同的话，
就保持输入的顺序。输出信息包括学号、姓名、性别、英语、语文、数学以及每个学生六科的总分。
程序的一次运行结果如下图所示。请将程序补充完整。*/
/*
输入数据
1001    A       F       90      88      92      90      80      88
1002    B       M       92      90      88      88      90      80
1003    C       M       88      90      92      80      90      88
1004    D       M       90      95      93      99      88      90
1005    E       F       88      98      95      89      87      90

2001    AA      F       90      88      92      90      80      88
2002    BB      F       92      90      88      88      90      80
2003    CC      M       88      90      92      80      90      88
2004    DD      M       98      89      90      89      97      90
2005    EE      M       95      94      90      90      89      97
*/
#include <cstring>
#include <iostream>
#include <istream>
#include <ostream>

using namespace std;

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
        int getChinese() { return chinese; }
        int getMath() { return math; }
        int getEnglish() { return english; }
        virtual int get_total() const = 0;
        friend ostream &operator<<(ostream &output, const Student &student) {
            output << student.ID << '\t' << student.name << '\t' << student.gender
                << '\t' << student.english << '\t' << student.math << '\t'
                << student.chinese << '\t' << student.get_total();
            return output;
        }

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
    int get_total() const override { return individualTotal; }

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
    int get_total() const override { return individualTotal; }

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

void BubbleSort(Student **st, int n)

{
    int i, j;

    int work;

    for (i = 1; i < n; i++)

    {
        work = 0;

        for (j = 0; j < n - i; j++)

        {
            if (st[j]->get_total() < st[j + 1]->get_total())

            {
                swap(st[j], st[j + 1]);

                work = 1;

            }

            else

                if (st[j]->get_total() == st[j + 1]->get_total())

                    if (st[j]->getChinese() < st[j + 1]->getChinese())

                    {
                        swap(st[j], st[j + 1]);

                        work = 1;

                    }

                else

                    if (st[j]->getChinese() == st[j + 1]->getChinese())

                    if (st[j]->getMath() < st[j + 1]->getMath())

                    {
                        swap(st[j], st[j + 1]);

                        work = 1;

                    }

                    else

                        if (st[j]->getMath() == st[j + 1]->getMath())

                        if (st[j]->getEnglish() < st[j + 1]->getEnglish())

                        {
                            swap(st[j], st[j + 1]);

                            work = 1;
                        }
        }

        if (!work) break;
    }
}

int main()

{
    Student *stu[10];

    ScienceStudent stu_ss[5];

    LiberalArtStudent stu_las[5];

    int i;

    int j = 0;

    cout << "请按以下顺序输入理科生信息：\n学号\t姓名\t性别\t英语\t语文\t数学\t"
            "物理\t化学\t生物"
         << endl;

    for (i = 0; i < 5; i++)

    {
        cin >> stu_ss[i];

        stu[j] = &stu_ss[i];

        j++;
    }

    cout << "\n理科生成绩单：\n学号\t姓名\t性别\t英语\t语文\t数学\t物理\t化学\t"
            "生物\t总分\n";

    // SelectSort(stu_ss,5);

    for (i = 0; i < 5; i++) cout << stu_ss[i] << endl;

    cout << "请按以下顺序输入文科生信息：\n学号\t姓名\t性别\t英语\t语文\t数学\t"
            "历史\t地理\t政治"
         << endl;

    for (i = 0; i < 5; i++)

    {
        cin >> stu_las[i];

        stu[j] = &stu_las[i];

        j++;
    }

    cout << "\n文科生成绩单：\n学号\t姓名\t性别\t英语\t语文\t数学\t历史\t地理\t"
            "政治\t总分\n";

    for (i = 0; i < 5; i++) cout << stu_las[i] << endl;

    //        SelectSort(stu,10);

    BubbleSort(stu, 10);

    cout
        << "\n排序后的成绩单：\n学号\t姓名\t性别\t英语\t语文\t数学\t六科总分\n";

    for (i = 0; i < 10; i++) cout << *stu[i] << endl;

    cout << "The average of English:" << Student::getAvgEn()
         << "\tChinese:" << Student::getAvgCh()
         << "\tMath:" << Student::getAvgMath() << endl;

    ScienceStudent::get_average();

    LiberalArtStudent::get_average();

    return 0;
}