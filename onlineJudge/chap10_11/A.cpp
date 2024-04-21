/*建立结点，包括一个任意类型的数据域和一个指针域的单向链表类模板。在 main 函数中使用该类模板建立数据域为整型的单向链表，并把链表中的数据显示出来。
设计好类以后，请使用以下main函数测试：*/
#include <bits/stdc++.h>
using namespace std;

# define tp template<class T>

tp
class List {
private: 
    T m_data;
    List<T>* m_next;
public:
    List<T>(const T& data): m_data(data), m_next(nullptr) {}
    const List<T>* append(List<T>* toAppend) {
        toAppend->m_next = this;
        return this;
    }
    const T& getData() { return m_data; }
    List<T>* getNext() { return m_next; }
};

int main() {
    int idata, n, fdata;
    cout << "输入结点的个数：";
    cin >> n;
    cout << "输入第一个结点的数据域：";
    cin >> fdata;
    List<int> headnode(fdata);
    List<int>* last = &headnode;
 
    for (int i = 1; i < n; i++) {
        cout << "输入第" << i + 1 << "个结点的数据域：";
        cin >> idata;
        List<int>* p = new List<int>(idata);
        p->append(last);
        last = p;
    }
 
    cout << "链表已经建立！" << endl;
    cout << "链表中的数据为：" << endl;
 
    List<int>* p = &headnode;
    while (p != nullptr) {
        cout << p->getData() << endl;
        p = p->getNext();
    }
 
    return 0;
}