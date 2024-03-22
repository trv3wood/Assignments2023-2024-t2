/*定义一个类 nauticalmile_kilometer，它包含两个数据成员 kilometer（千米）和 meter（米）；还包含 一个构造函数对数据成员进行初始化；成员函数 print，用于输出数据成员 kilometer 和 meter 的值；类型转换函数operator double，实现把千米和米转换为海里（1 海里=1.852 千米）的功能。编写 main 函数，测试类 nauticalmile_kilometer。

输入
输入kilometer和meter。

输出
输出对应的海里(结果保留4位小数)。

必须使用的关键字
class 
样例输入 Copy
123 456
100 50
样例输出 Copy
67.0000
54.0227
提示
多组输入*/
#include <iomanip>
#include <iostream>
class nauticalmile_kilometer {
public:
    nauticalmile_kilometer(double k, double m) : kilometer(k), meter(m) {}
    void print() {
        std::cout << kilometer << " " << meter << std::endl;
    }
    operator double() {
        return (kilometer + meter / 1000) / 1.852;
    }
private:
    double kilometer;
    double meter;
};

int main() {
    double k, m;
    while (std::cin >> k >> m) {
        nauticalmile_kilometer n(k, m);
        // 固定输出4位小数
        std::cout << std::fixed << std::setprecision(4) << (double)n << std::endl;
    }
    return 0;
}