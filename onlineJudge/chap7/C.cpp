/*假设有向量 X = ( x1, x2,…, xn)和 Y = ( y1, y2,…, yn )，它们之间的加、减和乘法分别定义为：

X + Y = ( x1 + y1, x2 + y2,…, xn + yn )

X - Y = ( x1 - y1, x2 - y2,…, xn - yn )

X * Y = x1 * y1 + x2 * y2 +…+ xn * yn

编写程序定义向量类 Vector，重载运算符+、-、*和=，实现向量之间的加、减、乘、赋值运算；重载 运算符>>、<<实现向量的输入、输出功能。注意检测运算的合法性。 

输入
分别输入向量X、Y的长度，以及X、Y的各个数据元素。

输出
输出X和Y的向量形式、X+Y、X-Y、X*Y的结果。

必须使用的关键字
class 
样例输入 Copy
4
1 1 1 1
4
2 2 2 2
3
2 1 0
2
1 1
样例输出 Copy
X=(1,1,1,1)
Y=(2,2,2,2)
X+Y=(3,3,3,3)
X-Y=(-1,-1,-1,-1)
X*Y=8
error
提示
 多组测试数据*/
#include <iostream>
#include <string>
class Vector {
private:
    int* vec;
    int size;
public:
    int length() const { return size; }
    Vector() {}
    Vector(int size_): vec(nullptr), size(size_) {}
    friend std::istream& operator>>(std::istream& in, Vector& v) {
        in >> v.size;
        int* nums = new int[v.size];
        for (int i = 0; i < v.size; i++) {
            in >> nums[i];
        }
        v.vec = nums;
        return in;
    }
    friend std::ostream& operator<<(std::ostream& out, const Vector& v) {
        if (v.vec == nullptr) {
            out << "error";
            return out;
        }
        out << '(';
        for (int i = 0; i < v.size; i++) {
            out << v.vec[i];
            if (i != v.size - 1) {
                out << ",";
            }
        }
        out << ")";
        return out;
    }
    Vector operator+(const Vector& other) {
        Vector result(size);
        if (size != other.size) {
            result.vec = nullptr;
            return result;
        }
        int* res = new int[size];
        for (int i = 0; i < size; i++) {
            res[i] = this->vec[i] + other.vec[i];
        }
        result.vec = res;
        return result;
    }
    Vector operator-(const Vector& other) {
        Vector result(size);
        if (size != other.size) {
            result.vec = nullptr;
            return result;
        }
        int* res = new int[size];
        for (int i = 0; i < size; i++) {
            res[i] = this->vec[i] - other.vec[i];
        }
        result.vec = res;
        return result;
    }
    std::string operator*(const Vector& other) {
        if (size != other.size) {
            return "error";
        }
        int res = 0;
        for (int i = 0; i < size; i++) {
            res += this->vec[i] * other.vec[i];
        }
        return std::to_string(res);
    }
};

int main() {
    Vector X, Y;
    while (std::cin >> X >> Y) {
        if (X.length() != Y.length() || X.length() == 0 || Y.length() == 0) {
            std::cout << "error" << std::endl;
            continue;
        }
        std::cout << "X=" << X << std::endl;
        std::cout << "Y=" << Y << std::endl;
        std::cout << "X+Y=" << X + Y << std::endl;
        std::cout << "X-Y=" << X - Y << std::endl;
        std::cout << "X*Y=" << X * Y << std::endl;
    }
}