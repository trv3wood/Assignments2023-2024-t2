#include <bits/stdc++.h>
using namespace std;
class Student {
private:
    string name;
    double hw, midterm, final;
    int id;
    double hw_, mid_, final_;
public:
    Student(int i, const string& n, double h, double mid, double fi)
        : name(n), hw(h), midterm(mid), final(fi), id(i) {}
    void couscore() const {
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
    void operator*() {
        hw_ = hw * 0.2;
        mid_ = midterm * 0.3;
        final_ = final * 0.5;
    }
    friend ostream& operator<<(ostream& out, const Student& s) {
        out << "学生姓名: " << s.name << '\n';
        out << "学生学号: " << s.id << '\n';
        out << "平时作业成绩加权: " << s.hw_ << '\n';
        out << "期中考试成绩加权: " << s.mid_ << '\n';
        out << "期末考试成绩加权: " << s.final_ << '\n';
        s.couscore();
        return out;
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

        // 调用重载的乘法运算符进行加权成绩的计算
        student.operator*();

        cout << "学生信息及成绩单：" << endl;
        cout << student << endl;

        cout << "是否继续输入学生信息？(y/n): ";
        cin >> continue_input;
    }

    return 0;
}