/*定义人民币类 RMB，包含：
私有数据成员：
int yuan（元）、int jiao（角）、int fen（分）、bool mark（标志，表示正、负数）
成员函数：
用（元，角，分，标志）构造 RMB 对象   
用 double 数据构造 RMB 对象   
类型转换，把 RMB 对象转换为 double 值
友元函数： 
重载<<，以“元角分”形式输出 RMB 对象值   
重载>>，以“元角分”形式输入 RMB 对象值
以下是main 函数(仅提供参考)的测试和运行显示。请补充 RMB 类的定义。*/
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <ostream>
#include <sstream>
#include <string>
class RMB {
private:
    int yuan, jiao, fen;
    bool mark = true;
    void normalize() {
        jiao += fen / 10;
        fen = fen % 10;
        yuan += jiao / 10;
        jiao = jiao % 10;
    }
public:
    RMB() {}
    RMB(int y, int j, int f, bool m): yuan(y), jiao(j), fen(f), mark(m) {}
    RMB(double amount)  {
        mark = amount >= 0;
        amount = std::abs(amount);
        yuan = static_cast<int>(amount);
        amount = (amount - yuan) * 10;
        jiao = static_cast<int>(amount);
        amount = (amount - jiao) * 10;
        fen = static_cast<int>(std::round(amount));
        normalize();
    }
    explicit operator double() const {
        return yuan + 0.1 * jiao + 0.01 * fen;
    }
    friend std::ostream& operator<<(std::ostream& out, const RMB& rmb) {
        if (!rmb.mark) {
            out << '-';
        }
        out << rmb.yuan << 'Y' << rmb.jiao << 'J' << rmb.fen << 'F' << '\n';
        return out;
    }
   
    friend std::istream& operator>>(std::istream& in, RMB& rmb) {
        std::string str;
        in >> str;
        if (str.find('.') != std::string::npos) {
            rmb.yuan = std::stoi(str.substr(0, str.find('.')));
            rmb.jiao = str[str.find('.') + 1] - '0';
            rmb.fen = str[str.find('.') + 2] - '0';
        } else {
            std::stringstream ss(str);
            ss >> rmb.yuan;
            in >> rmb.jiao >> rmb.fen;
        }
        return in;
    }
    RMB operator+(const RMB& other) const {
        return RMB(double(*this) + double(other));
    }
    RMB operator-(const RMB& other) const {
        return RMB(double(*this) - double(other));
    }
    RMB operator*(double n) const {
        return RMB(double(*this) * n);
    }
};
//int main() {
    //RMB test;
    //std::cin >> test;
    //std::cout << test << '\n';
//}
int main(){ 
    RMB a, b; 
    double c; 
    while(std::cin >> a) {  
        //std::cout <<"b:\n"; 
        std::cin >> b; 
        //std::cout <<"c:\n"; 
        std::cin >> c;
        std::cout << "a = "<< a << "b = " << b << "c = " << RMB(c); 
        std::cout << "a + c = " << RMB(a + c); 
        std::cout << "a - b = " << RMB(a - b);  
        std::cout << "b * 2 = " << RMB(b * 2);  
        std::cout << "a * 0.5 = " << RMB(a * 0.5) ;
    }       
    return 0;
}