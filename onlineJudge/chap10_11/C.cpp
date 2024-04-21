/*以表格形式输出:当x=1°,2°…,10°时，sinx、cosx和 tanx的值。要求:输出时，数据的宽度为10，左对齐，保留小数点后5位。*/

#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
int main() {
    std::cout << std::fixed << std::setw(10) << std::left << "x sin(x) cos(x) tan(x)" << std::endl;
    for (int i = 1; i <= 10; i++) {
        double x = i;
        double sinx = sin(x / 180 * M_PI);
        double cosx = cos(x / 180 * M_PI);
        double tanx = tan(x / 180 * M_PI);
        std::cout << std::setw(3) << std::left << i  << ": " << std::fixed << std::setprecision(5) << std::setw(10) << std::left << sinx << std::setw(10) << std::left << cosx << std::setw(10) << std::left << tanx << std::endl;
    }
    return 0;

}