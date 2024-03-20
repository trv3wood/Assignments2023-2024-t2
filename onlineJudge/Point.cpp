/*定义一个表示点的结构类型 Point 和一个由直线方程y=ax十b确定的直线类 Line。 结构类型 Point有两个成员x和y，分别表示点的横坐标和纵坐标。Line 类有两个数据成员a和b，分别表示直线方程中的系教。Line 类有一个成员函数 print 用于显示直线方程。友元函数 setPoint(Line &l1,Line &l2)用于求两条直线的交点。在 main 两数中，建立两个直线对象，分别调用 print 函数显示两条直线的方程，并调用函数 setPoint求这两条直线的交点。
输入
两条直线的斜率和截距
输出
两条直线的方程和交点

其中括号和逗号都是英文

样例输入 Copy
5 1
1 5
样例输出 Copy
y = 5x + 1
y = 1x + 5
(1,6)*/
#include <iostream>
#include <istream>
class Point {
public:
    double x, y;
    void print() {
        std::cout << '(' << x << ',' << y << ')' << '\n';
    }
};

class Line {
private:
    double k; //斜率
    double b; //截距
public:
    void print() {
        std::cout << "y = " << k << "x + " << b << '\n';
    }

    friend Point setPoint(Line& l1, Line& l2);
    friend std::istream& operator>>(std::istream& in, Line& line);
};

Point setPoint(Line& l1, Line& l2) {
    Point point;
    point.x = (l2.b - l1.b) / (l1.k - l2.k);
    point.y = l1.k * point.x + l1.b;
    return point;
}
std::istream& operator>>(std::istream& in, Line& line) {
    in >> line.k >> line.b;
    return in;
}

Line l1, l2;

int main() {
    std::cin >> l1 >> l2;
    l1.print();
    l2.print();
    setPoint(l1, l2).print();
}