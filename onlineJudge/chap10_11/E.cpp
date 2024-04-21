/*
 * 建立某单位职工通讯录的二进制数据文件，文件中的每个记录均包括:职工编号、姓名、电话号码邮政编码和通信地址。
 * 输入
 * 职工编号、姓名、电话号码邮政编码和通信地址
 * 输出
 * 通讯录的二进制文件内容
 */
#include <bitset>
#include <iostream>
#include <istream>
#include <ostream>
#include <string>
#include <vector>

#define bitV std::vector<std::bitset<8>>
#define bit8 std::bitset<8>

class Employee {
public:
    int id;
    std::string name;
    std::string phone;
    std::string postcode;
    std::string address;
    friend std::ostream& operator<<(std::ostream& os, const Employee& employee);
    static bitV toBitV(const std::string& str) {
        bitV res;
        for (const auto& c : str) {
            res.push_back(bit8(c));
        }
        return res;
    }
};

std::ostream& operator<<(std::ostream& os, const Employee& employee) {
    bitV id = Employee::toBitV(std::to_string(employee.id));
    bitV name = Employee::toBitV(employee.name);
    bitV phone = Employee::toBitV(employee.phone);
    bitV postcode = Employee::toBitV(employee.postcode);
    bitV address = Employee::toBitV(employee.address);
    os << "编号：";
    for (const auto& b : id) {
        os << b << ' ';
    }
    os << '\n';
    os << "姓名：";
    for (const auto& b : name) {
        os << b << ' ';
    }
    os << '\n';
    os << "电话号码：";
    for (const auto& b : phone) {
        os << b << ' ';
    }
    os << '\n';
    os << "邮政编码：";
    for (const auto& b : postcode) {
        os << b << ' ';
    }
    os << '\n';
    os << "通信地址：";
    for (const auto& b : address) {
        os << b << ' ';
    }
    return os;
}

int main() {
    std::cout << "请输入职工人数：";
    int n;
    std::cin >> n;
    std::vector<Employee> employees(n);
    // std::cin.ignore(); // Ignore newline character after reading n
    for (int i = 0; i < n; ++i) {
        std::cout << "请输入第" << i + 1 << "个职工的编号：";
        std::cin >> employees[i].id;
        std::cin.ignore(); // Ignore newline character after reading id
        std::cout << "请输入第" << i + 1 << "个职工的姓名：";
        std::getline(std::cin, employees[i].name);
        std::cout << "请输入第" << i + 1 << "个职工的电话号码：";
        std::getline(std::cin, employees[i].phone);
        std::cout << "请输入第" << i + 1 << "个职工的邮政编码：";
        std::getline(std::cin, employees[i].postcode);
        std::cout << "请输入第" << i + 1 << "个职工的通信地址：";
        std::getline(std::cin, employees[i].address);
        std::cout << "第" << i + 1 << "个职工的信息（二进制格式）：\n";
        std::cout << employees[i];
        std::cout << "\n\n";
    }
    return 0;
}
