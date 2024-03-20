/*设计实现一个简易学生成绩管理程序，设学生信息包括学号（long）、姓名(20个字符)、性别（char），修读的科目有英语(int)、中文(int)、数学(int)。程序的一次运行结果如下图所示。请补充类的设计。（注：1.请勿修改已提供的代码；2. 补充完整后的代码和运行结果需提交到课程中心）
请按 以下顺序输入学生信息：
学号	姓名	性别	英语	语文	数学
1001 张三 男 80 90 70
1002 李四 女 85 95 75
1003 王五 男 90 85 80
1004 赵六 女 95 90 85
1005 孙七 男 100 95 90
*/

#include<cstring>
#include<iostream>

using namespace std;

class Student //学生类的定义

{
  long ID; //学号
  char Name[20];
  char gender;
  int English, Chinese, Math;
  int total;
public:
  Student() { }
  Student(long id, char *name, char g, int e, int c, int m) //构造函数
  {
    ID = id;
  }
 //重载提取运算符
  friend istream & operator >> (istream & in, Student & s)
  {
    in >> s.ID >> s.Name >> s.gender >> s.English >> s.Chinese >> s.Math;
    s.total = s.English + s.Chinese + s.Math;
    return in;
  }
  //重载插入运算符
  friend ostream & operator << (ostream & out, Student & s)
  {
    out << s.ID << "\t" << s.Name << "\t" << s.gender << "\t" << s.English << "\t" << s.Chinese << "\t" << s.Math << "\t" << s.total;
    return out;
  }
  //重载比较运算符
  bool operator > (Student & s)
  {
    return total > s.total;
  }
};

void  SelectSort(Student *st, int n)  //选择排序

{

int i,j,t;

Student  temp;

for(i=0;i<n-1;i++)

{

t=i;

for (j=i+1;j<n;j++)

if (st[j]>st[t])  //隐式调用类型转换函数

t=j;   

if(t!=i)

{

temp=st[i];

st[i]=st[t];

st[t]=temp;

}

}

return;

}

int main()

{
Student stu[5];

int i;

cout<<"请按以下顺序输入学生信息：\n学号\t姓名\t性别\t英语\t语文\t数学"<<endl;

for(i=0;i<5;i++)

cin>>stu[i];   // 调用重载的提取运算符

cout<<"\n按总分降序排列：\n学号\t姓名\t性别\t英语\t语文\t数学\t总分\n";

SelectSort(stu,5);

for(i=0;i<5;i++)

cout<<stu[i]<<endl;   //调用重载的插入运算符

return 0;

}