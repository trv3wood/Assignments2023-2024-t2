/*试写出你所能想到的所有形状(包括二维的和三维的)，生成一个形状层次类体系。生成的类体系以
shape 作为基类，并由此派生出 TwoDimShape 类和 ThreeDimShape
类。它们的派生类是不同的形状类。定义类体系中的每个类，并用main 函数进行测试。
注：题目中的形状包括：三角形、正方形、正方体、球。
输入
依次是：三角形的高和底、正方形的边长、正方体的边长、球的半径
输出
依次输出上述形状的面积和体积，示例输出如下：
样例输入 Copy
2 4
5.2
2.2
2.5
样例输出 Copy
Please enter the height and base of the triangle:
Area of Triangle is4
Please enter the side length of the square:
Area of Square is27.04
Please enter the side length of the cube:
Superficial area of Cube is10.648
Please enter the radius of the ball:
Superficial area of Ball is65.4167*/
#include <iostream>
class Shape {
protected:
    float m_area;

public:
    virtual float area() = 0;
    virtual void display() = 0;
};

class TwoDimShape : public Shape {
public:
    virtual float area() = 0;
    virtual void display() = 0;
};

class ThreeDimShape : public Shape {
public:
    virtual float area() = 0;
    virtual void display() = 0;
};

class Triangle : public TwoDimShape {
private:
    float height;
    float base;

public:
    Triangle(float h, float b) : height(h), base(b) {}
    float area() {
        m_area = 0.5 * height * base;
        return m_area;
    }
    void display() { std::cout << "Area of Triangle is"; }
};
class Square : public TwoDimShape {
private:
    float side;

public:
    Square(float s) : side(s) {}
    float area() {
        m_area = side * side;
        return m_area;
    }
    void display() { std::cout << "Area of Square is"; }
};
class Squarer : public ThreeDimShape {
private:
    float side;

public:
    Squarer(float s) : side(s) {}
    float area() {
        m_area = side * side * side;
        return m_area;
    }
    void display() { std::cout << "Superficial area of Cube is"; }
};
class Ball : public ThreeDimShape {
private:
    float radius;

public:
    Ball(float r) : radius(r) {}
    float area() {
        m_area = 4.0 / 3 * 3.14 * radius * radius * radius;
        return m_area;
    }
    void display() { std::cout << "Superficial area of Ball is"; }
};

int main() {
    float a, b, c, d, e;

    std::cout << "Please enter the height and base of the triangle:"
              << std::endl;

    std::cin >> a >> b;
    Triangle t(a, b);
    float area;
    area = t.area();
    t.display();
    std::cout << area << std::endl;

    std::cout << "Please enter the side length of the square:" << std::endl;
    std::cin >> c;
    Square s(c);
    area = s.area();
    s.display();
    std::cout << area << std::endl;

    std::cout << "Please enter the side length of the cube:" << std::endl;
    std::cin >> d;
    Squarer sr(d);
    area = sr.area();
    sr.display();
    std::cout << area << std::endl;

    std::cout << "Please enter the radius of the ball:" << std::endl;
    std::cin >> e;
    Ball br(e);
    area = br.area();
    br.display();
    std::cout << area << std::endl;

    return 0;
}