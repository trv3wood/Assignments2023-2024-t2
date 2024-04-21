/*定义:类模板 T_Counter实现基本数据类型的+、-、*、=、>>、<< 运算；类模板
 * T_Vector，实现向量运算；类模板T_Matrix，实现矩阵运算。*/
#include <bits/stdc++.h>
#include <vector>
using namespace std;

# define tp template <class T>

tp class T_Counter {
private:
    T value;

public:
    T_Counter() { value = 0; }

    T_Counter operator+(const T_Counter &counter) {
        T_Counter temp;
        temp.value = value + counter.value;
        return temp;
    }

    T_Counter operator-(const T_Counter &counter) {
        T_Counter temp;
        temp.value = value - counter.value;
        return temp;
    }

    T_Counter operator*(const T_Counter &counter) {
        T_Counter temp;
        temp.value = value * counter.value;
        return temp;
    }

    T_Counter &operator=(const T_Counter &counter) {
        value = counter.value;
        return *this;
    }

    friend istream &operator>>(istream &in, T_Counter &counter) {
        in >> counter.value;
        return in;
    }

    friend ostream &operator<<(ostream &out, const T_Counter &counter) {
        out << counter.value;
        return out;
    }
};

tp class T_Vector: public std::vector<T> {
public:
    T_Vector operator+(const T_Vector &v) {
        T_Vector res;
        for (int i = 0; i < this->size(); i++) {
            res.push_back(this->at(i) + v.at(i));
        }
        return res;
    }

    T_Vector operator-(const T_Vector &v) {
        T_Vector res;
        for (int i = 0; i < this->size(); i++) {
            res.push_back(this->at(i) - v.at(i));
        }
        return res;
    }

    T operator*(const T_Vector &v) {
        T res = 0;
        for (int i = 0; i < this->size(); i++) {
            res += this->at(i) * v.at(i);
        }
        return res;
    }

    friend istream &operator>>(istream &in, T_Vector &v) {
        T temp;
        while (in >> temp) {
            v.push_back(temp);
            if (in.get() == '\n') break;
        }
        return in;
    }

    friend ostream &operator<<(ostream &out, const T_Vector &v) {
        for (int i = 0; i < v.size(); i++) {
            out << v.at(i) << " ";
        }
        return out;
    }
};

tp class Vector {
protected:
    T m_size;
    T* vec;

public:
    Vector() {}
    Vector(int size, T initVal) : m_size(size), vec(new T[size]) {
        for (int i = 0; i < size; i++) {
            vec[i] = initVal;
        }
    }

    T& operator[](int idx) { return vec[idx]; }
    Vector operator+(const Vector& o) {
        Vector res(m_size, 0);
        for (int i = 0; i < m_size; i++) {
            res.vec[i] = vec[i] + o.vec[i];
        }
        return res;
    }
    Vector operator-(const Vector& o) {
        Vector res(m_size, 0);
        for (int i = 0; i < m_size; i++) {
            res.vec[i] = vec[i] - o.vec[i];
        }
        return res;
    }
    T operator*(const Vector& o) {
        T res = 0;
        for (int i = 0; i < m_size; i++) {
            res += vec[i] * o.vec[i];
        }
        return res;
    }
    friend std::istream& operator>>(std::istream& is, Vector& v) {
        for (int i = 0; i < v.m_size; i++) {
            is >> v.vec[i];
        }
        return is;
    }
    friend std::ostream& operator<<(std::ostream& os, const Vector& v) {
        for (int i = 0; i < v.m_size; i++) {
            os << v.vec[i] << " ";
        }
        return os;
    }
};

tp class Matrix : public Vector<T> {
    T m_row;
    T m_col;

public:
    friend std::ostream& operator<<(std::ostream& os, const Matrix& m) {
        for (T i = 0; i < m.m_row; i++) {
            for (T j = 0; j < m.m_col; j++) {
                os << m.vec[i * m.m_col + j] << " ";
            }
            os << std::endl;
        }
        return os;
    }
    friend std::istream& operator>>(std::istream& is, Matrix& m) {
        is >> m.m_row >> m.m_col;
        m.m_size = m.m_row * m.m_col;
        m.vec = new T[m.m_size];
        for (T i = 0; i < m.m_row; i++) {
            for (T j = 0; j < m.m_col; j++) {
                is >> m.vec[i * m.m_col + j];
            }
        }
        return is;
    }

    Matrix() {}
    Matrix(int row, int col, T initVal = 1) : m_row(row), m_col(col), Vector<T>(row * col, initVal) {}
    Matrix operator*(const Matrix& o) {
        Matrix res(m_row, o.m_col, 0);
        for (T i = 0; i < m_row; i++) {
            for (T j = 0; j < o.m_col; j++) {
                for (T k = 0; k < m_col; k++) {
                    res[i * o.m_col + j] +=
                        this->vec[i * m_col + k] * o.vec[k * o.m_col + j];
                }
            }
        }
        return res;
    }
    Matrix operator+(const Matrix& o) {
        Matrix res(m_row, m_col);
        for (T i = 0; i < m_row; i++) {
            for (T j = 0; j < m_col; j++) {
                res[i * m_col + j] = this->vec[i * m_col + j] + o.vec[i * m_col + j];
            }
        }
        return res;
    }
    Matrix operator-(const Matrix& o) {
        Matrix res(m_row, m_col);
        for (T i = 0; i < m_row; i++) {
            for (T j = 0; j < m_col; j++) {
                res[i * m_col + j] = this->vec[i * m_col + j] - o.vec[i * m_col + j];
            }
        }
        return res;
    }
};

int main() {
    cout << "请输入两个整数：" << endl;
    T_Counter<int> int_counter1, int_counter2;
    cin >> int_counter1 >> int_counter2;
    cout << "整数加法结果：" << int_counter1 + int_counter2 << endl;
    cout << "整数减法结果：" << int_counter1 - int_counter2 << endl;
    cout << "整数乘法结果：" << int_counter1 * int_counter2 << endl;

    cout << "请输入两个双精度浮点数：" << endl;
    T_Counter<double> double_counter1, double_counter2;
    cin >> double_counter1 >> double_counter2;
    cout << "双精度浮点数加法结果：" << double_counter1 + double_counter2
         << endl;
    cout << "双精度浮点数减法结果：" << double_counter1 - double_counter2
         << endl;
    cout << "双精度浮点数乘法结果：" << double_counter1 * double_counter2
         << endl;

    cout << "请输入第一个个向量（空格分隔）：" << endl;
    T_Vector<int> int_vector1, int_vector2;
    cin >> int_vector1;
    cout << "请输入第二个个向量（空格分隔）：" << endl;
    cin >> int_vector2;
    cout << "向量加法结果：" << int_vector1 + int_vector2 << endl;
    cout << "向量减法结果：" << int_vector1 - int_vector2 << endl;
    cout << "向量点乘结果：" << int_vector1 * int_vector2 << endl;

    cout << "请输入第一个矩阵（注意第一行先输入矩阵的行和列，然后再输入矩阵，每"
            "行空格分隔，回车换行）："
         << endl;
    Matrix<int> int_matrix1, int_matrix2;
    cin >> int_matrix1;
    cout << "请输入第二个矩阵（每行空格分隔，回车换行）：" << endl;
    cin >> int_matrix2;
    cout << "矩阵加法结果：" << endl << int_matrix1 + int_matrix2 << endl;
    cout << "矩阵减法结果：" << endl << int_matrix1 - int_matrix2 << endl;
    cout << "矩阵乘法结果：" << endl << int_matrix1 * int_matrix2 << endl;

    return 0;
}