/*为第7章综合练习的程序设计第1题和第2题中的 Integer 类和 Real
类定义一个派生类IntReal。 class IntReal : public Integer, public Real;
使其可以进行+、-、*、/、=的左、右操作数类型不同的相容运算，并符合原有运算类型转换的语义规则。
给出main函数如下：
输入
四个数字，分别是两个整数，两个实数
输出
两个整数的和、差、积、商，两个实数的和、差、积、商。
示例如下：


注意之间的空格间隔

样例输入 Copy
5 4 4.5 5.6
样例输出 Copy
Sum:9 (Integer), 10.1 (Real)
Difference:1 (Integer), -1.1 (Real)
Product:20 (Integer), 25.2 (Real)
Quotient:1 (Integer), 0.803571 (Real)*/

#include <iostream>
class Integer {
public:
    Integer(int i) : i(i) {}
    operator int() const { return i; }

protected:
    int i;
};
class Real {
public:
    Real(double r) : r(r) {}
    operator double() const { return r; }

protected:
    double r;
};
class IntReal : public Integer, public Real {
public:
    IntReal(int i, double r) : Integer(i), Real(r) {}

    IntReal operator+(const IntReal& rhs) const {
        return IntReal(i + rhs.i, r + rhs.r);
    }
    IntReal operator-(const IntReal& rhs) const {
        return IntReal(i - rhs.i, r - rhs.r);
    }
    IntReal operator*(const IntReal& rhs) const {
        return IntReal(i * rhs.i, r * rhs.r);
    }
    IntReal operator/(const IntReal& rhs) const {
        return IntReal(i / rhs.i, r / rhs.r);
    }
    operator int() const { return i; }
    operator double() const { return r; }
};

int main() {
    int m, n;
    double x, y;
    std::cin >> m >> n >> x >> y;
    IntReal a(m, x);
    IntReal b(n, y);

    IntReal sum = a + b;
    IntReal difference = a - b;
    IntReal product = a * b;
    IntReal quotient = a / b;

    std::cout << "Sum:" << int(sum) << " (Integer), " << double(sum)
              << " (Real)" << std::endl;
    std::cout << "Difference:" << int(difference) << " (Integer), "
              << double(difference) << " (Real)" << std::endl;
    std::cout << "Product:" << int(product) << " (Integer), " << double(product)
              << " (Real)" << std::endl;
    std::cout << "Quotient:" << int(quotient) << " (Integer), "
              << double(quotient) << " (Real)" << std::endl;

    return 0;
}