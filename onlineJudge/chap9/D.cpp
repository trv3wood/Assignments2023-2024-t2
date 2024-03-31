/*改写第8章习题中程序设计第2题的程序，把 Shape
类定义为抽象类，提供有共同操作界面的纯虚函数。TwoDimShape 类和 ThreeDimShape
类仍然是抽象类，只有第三层具体类才提供全部函数的实现。在测试函数中使用基类指针实现不同派生类对象的操作。
最后通过以下形式的main函数测试代码：

输出
main函数中的四种形状中，二维图形的面积，三维图像的面积和体积，如下：

必须使用的关键字
class
样例输出 Copy
Circle
Radius: 3
Area: 28.26
Rectangle
Length: 5, Width: 6
Area: 30
Ball
Radius: 2
Surface Area: 50.24
Volume: 33.4933
Rectangular
Length: 7, Width: 8, Height: 9
Surface Area: 382
Volume: 504
提示
注意圆周率使用3.14*/
#include <iostream>
class Shape {
public:
    virtual void show_name() = 0;
    virtual void calculate() = 0;
    virtual void show_area() = 0;
    virtual void show_volume() {}
    virtual ~Shape() {}
};

class TwoDimShape : public Shape {
protected:
    float m_area;
};

class ThreeDimShape : public TwoDimShape {
protected:
    float m_volume;
};

class Circle : public TwoDimShape {
protected:
    float radius;

public:
    Circle(float r) : radius(r) {}
    void show_name() override {
        std::cout << "Circle\n"
                  << "Radius: " << radius << std::endl;
    }
    void calculate() override { m_area = 3.14 * radius * radius; }
    void show_area() override { std::cout << "Area: " << m_area << std::endl; }
};
class Rectangle : public TwoDimShape {
protected:
    float length;
    float width;

public:
    Rectangle(float l, float w) : length(l), width(w) {}
    void show_name() override {
        std::cout << "Rectangle" << "\nLength: " << length
                  << ", Width: " << width << std::endl;
    }
    void calculate() override { m_area = length * width; }
    void show_area() override { std::cout << "Area: " << m_area << std::endl; }
};
class Rectangular : public Rectangle {
protected:
    float height;
    float m_volume;

public:
    Rectangular(float l, float w, float h) : Rectangle(l, w), height(h) {}
    void show_name() override {
        std::cout << "Rectangular" << "\nLength: " << length
                  << ", Width: " << width << ", Height: " << height
                  << std::endl;
    }
    void calculate() override {
        m_area = 2 * (length * width + width * height + height * length);
        m_volume = length * width * height;
    }
    void show_area() override {
        std::cout << "Surface Area: " << m_area << std::endl;
    }
    void show_volume() override {
        std::cout << "Volume: " << m_volume << std::endl;
    }
};
class Ball : public ThreeDimShape {
protected:
    float radius;

public:
    Ball(float r) : radius(r) {}
    void show_name() override {
        std::cout << "Ball" << "\nRadius: " << radius << std::endl;
    }
    void calculate() override {
        m_area = 4 * 3.14 * radius * radius;
        m_volume = 4.0 / 3.0 * 3.14 * radius * radius * radius;
    }
    void show_area() override {
        std::cout << "Surface Area: " << m_area << std::endl;
    }
    void show_volume() override {
        std::cout << "Volume: " << m_volume << std::endl;
    }
};
int main() {
    Shape* c = new Circle(3);
    c->show_name();
    c->calculate();
    c->show_area();
    c->show_volume();
    delete c;

    Shape* s = new Rectangle(5, 6);
    s->show_name();
    s->calculate();
    s->show_area();
    s->show_volume();
    delete s;

    Shape* b = new Ball(2);
    b->show_name();
    b->calculate();
    b->show_area();
    b->show_volume();
    delete b;

    Shape* cu = new Rectangular(7, 8, 9);
    cu->show_name();
    cu->calculate();
    cu->show_area();
    cu->show_volume();
    delete cu;

    return 0;
}