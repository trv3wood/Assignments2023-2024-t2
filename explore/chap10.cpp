#include <cstring>
#include <iostream>
#include <ostream>

using namespace std;

template <class T>
class Student {
public:
    Student() {}
    static T totalMembers;
    static T totalChinese;
    static T totalMath;
    static T totalEnglish;
    static T getAvgCh() { return totalChinese / totalMembers; }
    static T getAvgMath() { return totalMath / totalMembers; }
    static T getAvgEn() { return totalEnglish / totalMembers; }
    T getChinese() { return chinese; }
    T getMath() { return math; }
    T getEnglish() { return english; }
    virtual T get_total() const { return english + math + chinese; }
    virtual ostream &getOstream(ostream &out) const;
    virtual istream &getIstream(istream &in);
    template <class>
    friend ostream &operator<<(ostream &out, const Student<T> &stu);

protected:
    char name[20];
    char gender;
    T ID;
    T english;
    T math;
    T chinese;
};
template <class T>
T Student<T>::totalMath = 0;
template <class T>
T Student<T>::totalChinese = 0;
template <class T>
T Student<T>::totalEnglish = 0;
template <class T>
T Student<T>::totalMembers = 0;

template <class T>
ostream &Student<T>::getOstream(ostream &out) const {
    out << ID << '\t' << name << '\t' << gender << '\t' << english << '\t'
        << math << '\t' << chinese;
    return out;
}

template <class T>
ostream &operator<<(ostream &out, const Student<T> &stu) {
    return stu.getOstream(out);
}

template <class T>
istream &Student<T>::getIstream(istream &in) {
    in >> ID >> name >> gender >> english >> chinese >> math;
    Student<T>::totalMembers++;
    totalChinese += chinese;
    totalMath += math;
    totalEnglish += english;
    return in;
}

template <class T>
istream &operator>>(istream &in, Student<T> &stu) {
    return stu.getIstream(in);
}

template <class T>
class ScienceStudent : public Student<T> {
public:
    ScienceStudent() {}
    T get_total() const override {
        return this->english + this->math + this->chinese + physics +
               chemistry + biology;
    }
    template <class>
    friend ostream &operator<<(ostream &out, const ScienceStudent<T> &stu);
    template <class>
    friend istream &operator>>(istream &in, ScienceStudent<T> &stu);
    static void get_average();
    ostream &getOstream(ostream &out) const override;
    istream &getIstream(istream &in) override;

private:
    T physics;
    T chemistry;
    T biology;
    static T totalPhysics;
    static T totalChemistry;
    static T totalBiology;
    static int totalMembers;
};

template <class T>
T ScienceStudent<T>::totalPhysics = 0;
template <class T>
T ScienceStudent<T>::totalChemistry = 0;
template <class T>
T ScienceStudent<T>::totalBiology = 0;
template <>
int ScienceStudent<int>::totalMembers = 0;

template <class T>
void ScienceStudent<T>::get_average() {
    cout << "The average of Physics: " << totalPhysics / totalMembers << '\t'
         << "Chemistry: " << totalChemistry / totalMembers << '\t'
         << "Biology: " << totalBiology / totalMembers << endl;
}

template <class T>
ostream &ScienceStudent<T>::getOstream(ostream &out) const {
    Student<T>::getOstream(out);
    out << '\t' << physics << '\t' << chemistry << '\t' << biology << '\t'
        << get_total();
    return out;
}

template <class T>
ostream &operator<<(ostream &out, const ScienceStudent<T> &stu) {
    return stu.getOstream(out);
}

template <class T>
istream &ScienceStudent<T>::getIstream(istream &in) {
    Student<T>::getIstream(in);
    in >> physics >> chemistry >> biology;
    ScienceStudent<T>::totalBiology += biology;
    ScienceStudent<T>::totalChemistry += chemistry;
    ScienceStudent<T>::totalPhysics += physics;
    ScienceStudent<T>::totalMembers++;
    return in;
}

template <class T>
istream &operator>>(istream &in, ScienceStudent<T> &stu) {
    return stu.getIstream(in);
}

template <class T>
class LiberalArtsStudent : public Student<T> {
public:
    LiberalArtsStudent() {}
    T get_total() const override {
        return this->english + this->math + this->chinese + history +
               geography + politics;
    }
    template <class>
    friend ostream &operator<<(ostream &out, const LiberalArtsStudent<T> &stu);
    template <class>
    friend istream &operator>>(istream &in, LiberalArtsStudent<T> &stu);
    static void get_average();
    ostream &getOstream(ostream &out) const override;
    istream &getIstream(istream &in) override;

private:
    T history;
    T geography;
    T politics;
    static T totalHistory;
    static T totalGeography;
    static T totalPolitics;
    static int totalMembers;
};

template <class T>
T LiberalArtsStudent<T>::totalHistory = 0;
template <class T>
T LiberalArtsStudent<T>::totalGeography = 0;
template <class T>
T LiberalArtsStudent<T>::totalPolitics = 0;
template <class T>
int LiberalArtsStudent<T>::totalMembers = 0;

template <class T>
void LiberalArtsStudent<T>::get_average() {
    cout << "The average of History: "
         << LiberalArtsStudent::totalHistory / totalMembers << '\t'
         << "Geography: " << LiberalArtsStudent::totalGeography / totalMembers
         << '\t'
         << "Politics: " << LiberalArtsStudent::totalPolitics / totalMembers
         << endl;
}

template <class T>
ostream &LiberalArtsStudent<T>::getOstream(ostream &out) const {
    Student<T>::getOstream(out);
    out << '\t' << history << '\t' << geography << '\t' << politics << '\t'
        << get_total();
    return out;
}

template <class T>
ostream &operator<<(ostream &out, const LiberalArtsStudent<T> &stu) {
    return stu.getOstream(out);
}

template <class T>
istream &LiberalArtsStudent<T>::getIstream(istream &in) {
    Student<T>::getIstream(in);
    in >> history >> geography >> politics;
    LiberalArtsStudent<T>::totalHistory += history;
    LiberalArtsStudent<T>::totalGeography += geography;
    LiberalArtsStudent<T>::totalPolitics += politics;
    LiberalArtsStudent<T>::totalMembers++;
    return in;
}

template <class T>
istream &operator>>(istream &in, LiberalArtsStudent<T> &stu) {
    return stu.getIstream(in);
}

template <class T>
void ToSort(T *stu[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (stu[i]->get_total() < stu[j]->get_total()) {
                T *temp = stu[i];
                stu[i] = stu[j];
                stu[j] = temp;
            }
        }
    }
}
int main()

{
    Student<int> *stu[10];

    ScienceStudent<int> stu_ss[5];

    ScienceStudent<int> *stu_s[5];

    LiberalArtsStudent<int> stu_las[5];

    LiberalArtsStudent<int> *stu_la[5];

    int i;

    int j = 0;

    cout << "请按以下顺序输入理科生信息：\n学号\t姓名\t性别\t英语\t语文\t数学\t"
            "物理\t化学\t生物"
         << endl;

    for (i = 0; i < 5; i++)

    {
        cin >> stu_ss[i];

        stu[j] = &stu_ss[i];

        stu_s[i] = &stu_ss[i];

        j++;
    }

    cout << "\n理科生成绩按降序排列：\n学号\t姓名\t性别\t英语\t语文\t数学\t物理"
            "\t化学\t生物\t总分\n";

    ToSort(stu_s, 5);

    for (i = 0; i < 5; i++) cout << *stu_s[i] << endl;

    cout << "请按以下顺序输入文科生信息：\n学号\t姓名\t性别\t英语\t语文\t数学\t"
            "历史\t地理\t政治"
         << endl;

    for (i = 0; i < 5; i++)

    {
        cin >> stu_las[i];

        stu[j] = &stu_las[i];

        stu_la[i] = &stu_las[i];

        j++;
    }

    cout << "\n文科生成绩按降序排列：\n学号\t姓名\t性别\t英语\t语文\t数学\t历史"
            "\t地理\t政治\t总分\n";

    ToSort(stu_la, 5);

    for (i = 0; i < 5; i++) cout << *stu_la[i] << endl;

    ToSort(stu, 10);

    cout
        << "\n排序后的成绩单：\n学号\t姓名\t性别\t英语\t语文\t数学\t六科总分\n";

    for (i = 0; i < 10; i++) cout << *stu[i] << endl;

    cout << "The average of English:" << Student<int>::getAvgEn()
         << "\tChinese:" << Student<int>::getAvgCh()
         << "\tMath:" << Student<int>::getAvgMath() << endl;

    ScienceStudent<int>::get_average();

    LiberalArtsStudent<int>::get_average();

    return 0;
}