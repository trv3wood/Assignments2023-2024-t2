/*请定义一个名为 MyString 的类，该类中包含一个 char* 类型的数据成员，该类支持
以下操作：
1.        实现类型转换函数 operator int () 和 operator double ()，分别将
MyString 类型转换为 int 类型和 double 类型。
2.        实现运算符重载 operator =，实现 MyString 类型之间的赋值操作。
3.        实现运算符重载 operator +，实现 MyString 类型的字符串拼接操作。
4.        实现运算符重载 operator == 和 operator !=，分别实现 MyString
类型的等于和不等于操作。
5.        实现运算符重载 operator []，实现 MyString 类型的下标操作符。
实现运算符重载 operator <<，实现将 MyString 对象的字符串输出到标准输出流。
*/
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
using namespace std;

class MyString {
public:
    string str;
    MyString() {}
    MyString(const char* s) : str(s) {}
    operator int() {
        stringstream ss;
        ss << str;
        int res;
        ss >> res;
        return res;
    }
    string operator+(const MyString& s) {
        // 内存泄漏
        char* res = new char[str.size() + s.str.size() + 1];
        strcpy(res, str.c_str());
        strcat(res, s.str.c_str());
        return res;
    }
    string operator=(string s) {
        str = s;
        return str;
    }
    bool operator==(string s) {
        return str == s;
    }
    bool operator!=(string s) {
        return str != s;
    }
    char operator[](int index) {
        if (index < 0 || index >= str.size()) {
            // 抛出异常
            const char* msg = "out of range";
            throw msg;
        }
        return str[index];
    }
};
int main() {
    char a[999], b[999];
    int index;
    while (cin >> a >> b >> index) {
        if (index == -1) break;

        MyString s1(a), s2(b), s3;
        int a_int = s1;
        cout << "a = " << a_int << endl;
        double b_double = s2;
        cout << "b = " << b_double << endl;

        s3 = s1 + s2;
        if (s1 != s2) {
            cout << "a is not equal to b" << endl;
        } else {
            cout << "a is equal to b" << endl;
        }

        if (s3 == s1 + s2) {
            cout << "a + b = " << s3 << endl;
        }

        try {
            cout << "a[" << index << "] = " << s1[index] << endl;
        } catch (const char* msg) {
            cerr << msg << endl;
        }
        try {
            cout << "b[" << index << "] = " << s2[index] << endl;
        } catch (const char* msg) {
            cerr << msg << endl;
        }
    }

    return 0;
}