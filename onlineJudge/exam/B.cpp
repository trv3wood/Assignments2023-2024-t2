/*对于之前题目：影片管理的类进行修改：

1.提供一个多态的成员函数input，用于读取输入Film、DirectoCut和ForeignFilm的具体信息，输入的具体信息详见样例输入。

2.根据输入的信息动态的创建Film类层次对象。(在read_input 函数中实现)

3.将Film类层次中的input函数设计为虚函数，使其具有多态性，动态创建的对象通过input函数可以从我们的输入中得到正确数据。

4.将Film类层次中的output函数设计为虚函数，使其具有多态性，动态创建的对象通过output函数可以将信息正确的输出。*/
#include <bits/stdc++.h>

#include <ctime>
#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Film {
protected:
    string title;
    string director;
    int time;
    int quality;

public:
    void store_title(string t) { title = t; }
    void store_director(string d) { director = d; }
    void store_time(int t) { time = t; }
    void store_quality(int q) { quality = q; }
    virtual void output() {
        cout << "Title: " << title << '\n';
        cout << "Director: " << director << '\n';
        cout << "Time: " << time << " mins\n";
        cout << "Quality: ";
        for (int i = 0; i < quality; i++) cout << "*";
        cout << '\n';
    }
    virtual void input() {
        cout << "Input title:\n"; 
        getline(cin, title);
        cout << "Input director:\n";
        getline(cin, director);
        cout << "Input time:\n"; 
        cin >> time;
        cout << "Input quality:\n";
        cin >> quality; 
    }
};
class DirectorCut : public Film {
private:
    int rev_time;
    string changes;

public:
    void store_rev_time(int r) { rev_time = r; }
    void store_changes(string c) { changes = c; }
    void output() override {
        Film::output();
        cout << "Revised time: " << rev_time << " mins\n";
        cout << "Changes: " << changes << '\n';
    }
    void input() override {
        Film::input();
        cout << "Input rev_time:\n";
        cin >> rev_time;
        cout << "Input changes:\n";
        cin.ignore();
        getline(cin, changes);
    }
};
class ForeignFilm : public Film {
private:
    string language;

public:
    void store_language(string l) { language = l; }
    void output() override {
        Film::output();
        cout << "Language: " << language << '\n';
    }
    void input() override {
        Film::input();
        cout << "Input language:\n";
        cin >> language;
    }
};

Film* read_input(string class_name) {
    Film* film;
    if (class_name == "Film") {
        film = new Film;
        film->input();
    } else if (class_name == "DirectorCut") {
        film = new DirectorCut;
        film->input();
    } else if (class_name == "ForeignFilm") {
        film = new ForeignFilm;
        film->input();
    }
    return film;
}
int main() {
    int n = 5;
    Film* films[n];
    for (int i = 0; i < n; i++) {
        cout << "Input class name:" << endl;
        string class_name;
        cin >> class_name;
        cin.ignore();  // 可以去除输入流中的换行符
        films[i] = read_input(class_name);
        cout << class_name << "--" << endl;
        films[i]->output();
        cout << endl;
    }
    return 0;
}