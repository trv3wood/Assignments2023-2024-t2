/*为Complex类重载 == 、 !=
 * 、一元减(-)、>>操作符，复数的判等操作定义为：复数z1=a+bi等于z2=c+di，当且仅当a等于c且b等于d。复数求负的操作定义为：如果z=a+bi是一个复数,
 * -z为-a-bi。为Complex类重载右移操作符>>以输出数据。
 */
#include <istream>
#include <iostream>
#include <ostream>
using namespace std;
class Complex {
public:
    Complex(double real, double image): Real(real), Image(image) {}
    Complex(): Real(0.0), Image(0.0) {}
    // TODO: 重载 ==
    bool operator==(const Complex& o) {
        return (Real == o.Real) && (Image == o.Image);
    }
    // TODO: 重载 !=
    bool operator!=(const Complex& o) {
        return !operator==(o);
    }
    // TODO: 重载 -
    friend Complex operator-(const Complex& o) {
        Complex res = Complex(o);
        res.Real = -res.Real;
        res.Image = -res.Image;
        return res;
    }
    // TODO: 重载 >>
    friend std::istream& operator>>(std::istream& in, Complex& c) {
        in >> c.Real >> c.Image;
        return in;
    }
    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << '(' << c.Real << " + " << c.Image << "i)";
        return out;
    }

private:
    double Real, Image;
};
int main() {
    double r, i;
    cin >> r >> i;
    Complex c1(r, i);
    Complex c;
    c = -c1;
    cout << c << std::endl;
    cout << (c1 != c) << endl;
    cout << (c1 == c) << endl;
}