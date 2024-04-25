/*
假设你正在编写一个数学库，你需要设计一个基类Number，表示所有数值，包括整数和实数。请定义Number类，并添加两个子类Integer和Real，分别表示整数和实数。
每个Number都可以进行基本的算术运算，包括加、减、乘、除，以及求幂，成员函数包括：
请使用继承和多态来实现这些运算
*/
#include <bits/stdc++.h>
using namespace std;

class Number {
public:
    virtual Number* add(Number* other) = 0; 
    virtual Number* subtract(Number* other) = 0;
    virtual Number* multiply(Number* other) = 0;
    virtual Number* divide(Number* other) = 0;
    virtual Number* power(Number* other) = 0;
    virtual void print() {}
};
class Integer : public Number {
private: 
    int i;
public:
    Integer(int a): i(a) {}
    Number * add(Number *other) override {
        int res = i + dynamic_cast<Integer*>(other)->i;
        Number* resP = new Integer(res);
        return resP;
    }
    Number * subtract(Number *other) override {
        int res = i - dynamic_cast<Integer*>(other)->i;
        Number* resP = new Integer(res);
        return resP;
    }
    Number * multiply(Number *other) override {
        int res = i * dynamic_cast<Integer*>(other)->i;
        Number* resP = new Integer(res);
        return resP;
    }
    Number * divide(Number *other) override {
        int res = i / dynamic_cast<Integer*>(other)->i;
        Number* resP = new Integer(res);
        return resP;
    }
    Number * power(Number *other) override {
        int res = pow(i, dynamic_cast<Integer*>(other)->i);
        Number* resP = new Integer(res);
        return resP;
    }
    void print() override {
        cout << i << '\n';
    }
};
class Real : public Number {
private:
    double rl;
public:
    Real(double r): rl(r) {}
    Number * add(Number *other) override {
        double res = rl + dynamic_cast<Real*>(other)->rl;
        Number* resP = new Real(res);
        return resP;
    }
    Number * subtract(Number *other) override {
        double res = rl - dynamic_cast<Real*>(other)->rl;
        Number* resP = new Real(res);
        return resP;
    }
    Number * multiply(Number *other) override {
        double res = rl * dynamic_cast<Real*>(other)->rl;
        Number* resP = new Real(res);
        return resP;
    }
    Number * divide(Number *other) override {
        double res = rl / dynamic_cast<Real*>(other)->rl;
        Number* resP = new Real(res);
        return resP;
    }
    Number * power(Number *other) override {
        double res = pow(rl, dynamic_cast<Real*>(other)->rl);
        Number* resP = new Real(res);
        return resP;
    }
    void print() override {
        std::cout << rl << '\n';
    }
};

int main() {
    int a, b;
    double c, d;
    while (cin >> a >> b >> c >> d) {
        if (a == b && c == d && a == 0 && c == 0) break;

        Integer* i1 = new Integer(a);
        Integer* i2 = new Integer(b);
        Real* r1 = new Real(c);
        Real* r2 = new Real(d);

        // 测试整数的算术运算
        Number* result = i1->add(i2);
        result->print();
        result = i1->subtract(i2);
        result->print();
        result = i1->multiply(i2);
        result->print();
        result = i1->divide(i2);
        result->print();
        result = i1->power(i2);
        result->print();

        // 测试实数的算术运算
        result = r1->add(r2);
        result->print();
        result = r1->subtract(r2);
        result->print();
        result = r1->multiply(r2);
        result->print();
        result = r1->divide(r2);
        result->print();
        result = r1->power(r2);
        result->print();
    }

    return 0;
}