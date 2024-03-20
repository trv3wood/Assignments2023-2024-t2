/*定义一个Box（盒子）类，在该类定义中包括以下数据成员和成员函数。
数据成员：length（长)、width（宽）和height （高）。
成员函数：构造函数 Box，设置盒子的长、宽和高三个初始数据；成员函数setBox 对数据成员置值；成员函数 volume 计算盒子的体积。
在main函数中，要求创建 Box对象，输入长、宽、高，输出盒子的体积。
输入
盒子的长宽高
输出
盒子的体积，具体格式样例如下

样例输入 Copy
1 5 3
4 5 5
3 4 2
样例输出 Copy
15
100
24*/
#include <iostream>
class Box {
private:
    int length;
    int width;
    int height;
public:
    Box(): length(0), width(0), height(0) {}
    void setBox(int length_, int width_, int height_) {
        length = length_; width = width_; height = height_;
    }
    int volume() {
        return length * width * height;
    }
};

int main() {
    Box box;
    int l, w, h;
    while (std::cin >> l >> w >> h) {
        box.setBox(l, w, h);
        std::cout << box.volume() << '\n';
    }
}