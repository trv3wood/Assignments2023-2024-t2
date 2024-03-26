/*使用 Integer类，定义派生类 Vector 类:
class Integer
{//…
protected
int n;
};
class Vector:public Integer{//…
protected :
int *v:
};
其中，数据成员v用于建立向量，n为向量长度。要求:类的成员函数可以实现向量的基本运算。
给出main函数如下：
*/
#include <iostream>
#include <vector>
using namespace std;

class Vector : public std::vector<int> {
private:
    int length;

public:
    Vector(int len, const int value = 1)
        : length(len), std::vector<int>(len, value) {}
    friend std::ostream& operator<<(std::ostream& out, const Vector& v) {
        for (const int& i : v) {
            out << i << ' ';
        }
        return out;
    }
    Vector operator+(const Vector& b) const {
        Vector res{length, 0};
        for (int i = 0; i < length; i++) {
            res[i] = *(this->begin() + i) + b[i];
        }
        return res;
    }

    Vector operator-(const Vector& b) const {
        Vector res{length, 0};
        for (int i = 0; i < length; i++) {
            res[i] = *(this->begin() + i) - b[i];
        }
        return res;
    }

    Vector operator*(const Vector& b) const {
        Vector res{length, 0};
        for (int i = 0; i < length; i++) {
            res[i] = *(this->begin() + i) * b[i];
        }
        return res;
    }

    Vector operator/(const Vector& b) const {
        Vector res{length, 0};
        for (int i = 0; i < length; i++) {
            res[i] = *(this->begin() + i) / b[i];
        }
        return res;
    }
};
int main() {
    int length;
    cin >> length;
    Vector v1(length);
    Vector v2(length);
    cout << v1 << endl;
    cout << v2 << endl;

    Vector v = v1 + v2;
    cout << "sum:" << endl;
    cout << v << endl;

    v = v1 - v2;
    cout << "differenct:" << endl;
    cout << v << endl;

    v = v1 * v2;
    cout << "product:" << endl;
    cout << v << endl;

    v = v1 / v2;
    cout << "quotient:" << endl;
    cout << v << endl;

    return 0;
}