/*
读入一段C++代码，删除全部注释内容，即删除以\/\*…\*\/相括的文本和以//开始到行末的文本，输出删除注释后的代码
input
一段包含注释的代码，注意输入数据的格式 输入STOP的时候，就停止输入的接收
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct index {
    int x, y;
    index(int x, int y) : x(x), y(y) {}
};

int main() {
    
    cout << "请输入要处理的字符串（包括注释），输入 \"STOP\" 停止输入：\n删除注释后的结果：" << endl;
    string s;
    vector<string> ss;

    while (getline(cin, s)) {  // 读入一行
        if (s == "STOP") { break; }
        ss.push_back(s);
    }

    int start = 0, end = 0;
    for (int i = 0; i < ss.size(); i++) {
        if (ss[i].find("//") != string::npos) {
            start = ss[i].find("//");
            ss[i].erase(start, ss[i].size() - start);// 删除从start开始到行尾的所有字符
        }
        if (ss[i].find("/*") != string::npos) {
            start = ss[i].find("/*");
            end = ss[i].find("*/");
            if (end != string::npos) {
                ss[i].erase(start, end - start + 2);
            } else {
                index temp(i, start);
                while (end == string::npos) {
                    i++;
                    end = ss[i].find("*/");
                }
                ss[temp.x].erase(temp.y, ss[temp.x].size() - temp.y);
                for (int j = temp.x + 1; j < i; j++) {
                    ss[j].erase(0, ss[j].size());
                }
                ss[i].erase(0, end + 2);
            }
        }
    }
    for (int i = 0; i < ss.size(); i++) {
        cout << ss[i] << endl;
    }
}