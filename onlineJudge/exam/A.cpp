/*构造一个类层次结构，用来对影片的制作进行跟踪管理，这些影片包括一些特殊的影片，如外国影片、导演的影片剪辑(directors cut, 表示因剪辑而产生的不同影片版本)。由于所有的影片都具有标题、导演、时间和等级(0星到4星)等共同属性，需要设计一个基类Film，该类包含所有影片共同的属性及存取这些属性的成员函数，同时需要专门设计一个输出信息的成员函数。
从基类Film派生出一个DirectorCut类，并为其添加一些数据成员用来存储影片修订时间、影片变更内容等信息，再添加一些成员函数以对这些新增数据成员进行访问，同时DirectorCut类也设计一个用来输出信息的成员函数。
从基类Film派生出一个ForeignFilm类，并为其添加数据成员来存储影片的不同语言版本，再添加一些成员函数以对这些新增数据成员进行访问，同时ForeignFilm类也设计一个用来输出信息的成员函数。
我们给出类Film的四个私有数据成员定义：
数据成员	数据类型	目的
title	string	影片标题
director	string	导演姓名
time	int	影片播放时间(精确到分钟)
quality	int	影片等级: 0-4
提示：例如store_title函数具有一个const string&类型的参数设置数据成员title，此外还有一个参数类型const char*的重载版本，同样可以设置数据成员title。*/
#include <bits/stdc++.h>
using namespace std;
class Film {
private:
    string title;
    string director;
    int time;
    int quality;
public:
    void store_title(const string& t) {
        title = t;
    }
    void store_director(const string& d) {
        director = d;
    }
    void store_time(int t) {
        time = t;
    }
    void store_quality(int q) {
        quality = q;
    }
    void output() {
        cout << "Title: " << title << '\n';
        cout << "Director: " << director << '\n';
        cout << "Time: " << time << " mins\n";
        cout << "Quality: ";
        for (int i = 0; i < quality; i++) {
            cout << '*';
        }
        cout << '\n';
    }
};
class DirectorCut: public Film {
private:
    int rev_time;
    string changes;
public:
    void store_rev_time(int r) { rev_time = r; }
    void store_changes(const string& c) { changes = c; }
    void output() {
        static_cast<Film*>(this)->output();
        cout << "Revised time: " << rev_time << " mins\n";
        cout << "Changes: " << changes << '\n';
    }
};
class ForeignFilm : public Film {
private:
    string language;
public:
    void store_language(const string& l) { language = l; }
    void output() {
        static_cast<Film*>(this)->output();
        cout << "Language: " << language << '\n';
    }
};
int main() {
    string title, director, changes, language;
    int time, quality, rev_time;
    Film f;
    getline(cin, title);
    f.store_title(title);
    getline(cin, director);
    f.store_director(director);
    cin >> time;
    f.store_time(time);
    cin >> quality;
    f.store_quality(quality);
    cout << "Film--" << endl;
    f.output();
    cout << endl;
    cin.ignore();

    DirectorCut d;
    getline(cin, title);
    d.store_title(title);
    getline(cin, director);
    d.store_director(director);
    cin >> time;
    d.store_time(time);
    cin >> quality;
    d.store_quality(quality);
    cin >> rev_time;
    d.store_rev_time(rev_time);  // 修订时间
    cin.ignore();
    getline(cin, changes);
    d.store_changes(changes);  // 影片变更内容
    cout << "DirectorCut--" << endl;
    d.output();
    cout << endl;

    ForeignFilm ff;
    getline(cin, title);
    ff.store_title(title);
    getline(cin, director);
    ff.store_director(director);
    cin >> time;
    ff.store_time(time);
    cin >> quality;
    ff.store_quality(quality);
    cin.ignore();
    getline(cin, language);
    ff.store_language(language);
    cout << "ForeignFilm--" << endl;
    ff.output();
    cout << endl;

    return 0;
}