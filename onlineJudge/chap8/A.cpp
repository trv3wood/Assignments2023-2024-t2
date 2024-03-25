/*����ĳ���۹�˾��һ��Ա��������Ա�������۾����¹��ʵļ���취��:
һ��Ա����н=�������ʣ�
����Ա����н=��������+���۶�*����ʣ�
���۾�����н=��������+ְ����+���۶�*����ʡ�
��д���򣬶���һ����ʾһ��Ա���Ļ��� Employee��������������ʾԱ��������Ϣ�����ݳ�Ա:���number������ name �ͻ������� basicSalary��
�� Employee ��������ʾ����Ա���� Salesman �࣬Salesman ��������������ݳ�Ա:���۶� sales �;�̬���ݳ�Ա�����commrate��
���� Salesman ��������ʾ���۾���� Salcsmanager �ࡣSalesmanager ����������ݳ�Ա;ְ����JobSalary��
Ϊ��Щ�ඨ���ʼ�����ݵĹ��캯��,�Լ���������input�����㹤�� pay ����������� print �ĳ�Ա������
��һ��Ա���Ļ���������2000Ԫ�����۾����ְ������3000Ԫ�������=5/1000����main �������������ɸ���ͬ���͵�Ա����Ϣ���������ṹ��
����main�ĺ������£�
int main() {
    salesman obj1;
    obj1.pay();
    obj1.print();
 
    salesmanager obj2;
    obj2.pay();
    obj2.print();
 
    return 0;
}
����
����Ա���ı�š����������۶�Լ����۾���ı�š����������۶�
���
���������š����������ʣ�����ͼ��

ע����Ӣ�ķ���

�������� Copy
1
��
5000
2
Nian
8000
������� Copy
���
����:
�±������۶�:
����Ա:�� ���:1 ���¹���:2025
���:
����:
nian���²������۶�:
���۾���:nian ���:2 ���¹���:8040*/
#include <iostream>
#include <string>
class Employee {
protected:
    long number;
    std::string name;
    static double basicSalary;
};
double Employee::basicSalary = 2000.0;

class Salesman: public Employee {
protected:
    double sales;
    static double commrate;
    double monthlyPay;
public:
    void pay() {
        std::cout << "���:";
        std::cin >> number;
        std::cout << "����:";
        std::cin >> name;
        std::cout << name << "�������۶�:"; 
        std::cin >> sales;
        monthlyPay = Employee::basicSalary + sales * commrate;
    }
    void print() {
        std::cout << "����Ա:" << name << " ���:" << number << " ���¹���:" << monthlyPay << '\n';
    }
};
double Salesman::commrate = 0.005;

class SalesManager: public Salesman {
private:
    static double jobSalary;
public:
    void pay() {
        std::cout << "���:";
        std::cin >> number;
        std::cout << "����:";
        std::cin >> name;
        std::cout << name << "���²������۶�:"; 
        std::cin >> sales;
        monthlyPay = Employee::basicSalary + sales * commrate + jobSalary * 2;
    }
    void print() {
        std::cout << "���۾���:" << name << " ���:" << number << " ���¹���:" << monthlyPay << '\n';
    }
};
double SalesManager::jobSalary = 3000.0;

int main() {
    Salesman obj1;
    obj1.pay();
    obj1.print();
 
    SalesManager obj2;
    obj2.pay();
    obj2.print();
 
    return 0;
}