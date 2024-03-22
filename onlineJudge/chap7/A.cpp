#include <climits>
#include <iostream>
#include <ostream>
class Integer {
private:
    int num;
public:
    Integer() {};
    Integer(int n): num(n) {}
    Integer operator+(const Integer& other) const {
        return Integer(this->num + other.num);
    }
    Integer operator-(const Integer& other) const {
        return Integer(this->num - other.num);
    }
    Integer operator*(const Integer& other) const {
        return Integer(this->num * other.num);
    }
    Integer operator/(const Integer& other) const {
        return Integer(this->num / other.num);
    }
    friend std::istream& operator>>(std::istream& in, Integer& i) {
        in >> i.num;
        return in;
    }
    friend std::ostream& operator<<(std::ostream& out, Integer i) {
        if (i.num > SHRT_MAX || i.num < SHRT_MIN) out << "Data Overflow!";
        else out << i.num;
        return out;
    }
};
int main() {
    char op;
    Integer i1, i2;
    while (std::cin >> i1 >> i2 >> op) {
        switch (op) {
            case '+':
                std::cout << (i1 + i2) << std::endl;
                break;
            case '-':
                std::cout << (i1 - i2) << std::endl;
                break;
            case '*':
                std::cout << (i1 * i2) << std::endl;
                break;
            case '/':
                std::cout << (i1 / i2) << std::endl;
                break;
            default:
                break;
        }
    }
}