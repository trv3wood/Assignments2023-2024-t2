/*使用课本中244页第5题定义的 Vector 类，定义它的派生类
Matrix，实现矩阵的基本运算 给出main函数如下： 输入
四个数字，分别是两个矩阵的行数和列数
输出
示例如下：

注意之间的空格和换行

样例输入 Copy
3 3 3 3
样例输出 Copy
矩阵 A:
1 1 1
1 1 1
1 1 1

矩阵 B:
1 1 1
1 1 1
1 1 1

矩阵 C = A * B:
3 3 3
3 3 3
3 3 3

矩阵 C = A + B:
2 2 2
2 2 2
2 2 2

矩阵 C = A - B:
0 0 0
0 0 0
0 0 0*/
#include <iostream>
class Vector {
protected:
    int m_size;
    int* vec;

public:
    Vector() {}
    Vector(int size, int initVal) : m_size(size), vec(new int[size]) {
        for (int i = 0; i < size; i++) {
            vec[i] = initVal;
        }
    }

    int& operator[](int idx) { return vec[idx]; }
};
class Matrix : public Vector {
    int m_row;
    int m_col;

public:
    friend std::ostream& operator<<(std::ostream& os, const Matrix& m) {
        for (int i = 0; i < m.m_row; i++) {
            for (int j = 0; j < m.m_col; j++) {
                os << m.vec[i * m.m_col + j] << " ";
            }
            os << std::endl;
        }
        return os;
    }

    Matrix(int row, int col, int initVal = 1) : m_row(row), m_col(col), Vector(row * col, initVal) {}
    Matrix operator*(const Matrix& o) {
        Matrix res(m_row, o.m_col, 0);
        for (int i = 0; i < m_row; i++) {
            for (int j = 0; j < o.m_col; j++) {
                for (int k = 0; k < m_col; k++) {
                    res[i * o.m_col + j] +=
                        vec[i * m_col + k] * o.vec[k * o.m_col + j];
                }
            }
        }
        return res;
    }
    Matrix operator+(const Matrix& o) {
        Matrix res(m_row, m_col);
        for (int i = 0; i < m_row; i++) {
            for (int j = 0; j < m_col; j++) {
                res[i * m_col + j] = vec[i * m_col + j] + o.vec[i * m_col + j];
            }
        }
        return res;
    }
    Matrix operator-(const Matrix& o) {
        Matrix res(m_row, m_col);
        for (int i = 0; i < m_row; i++) {
            for (int j = 0; j < m_col; j++) {
                res[i * m_col + j] = vec[i * m_col + j] - o.vec[i * m_col + j];
            }
        }
        return res;
    }
};
int main() {
    int row1, col1, row2, col2;
        std::cin >> row1 >> col1 >> row2 >> col2;
        Matrix A(row1, col1);
        Matrix B(row2, col2);

        std::cout << "矩阵 A:" << std::endl;
        std::cout << A << std::endl;

        std::cout << "矩阵 B:" << std::endl;
        std::cout << B << std::endl;

        Matrix C = A * B;
        std::cout << "矩阵 C = A * B:" << std::endl;
        std::cout << C << std::endl;

        Matrix D = A + B;
        std::cout << "矩阵 C = A + B:" << std::endl;
        std::cout << D << std::endl;

        Matrix E = A - B;
        std::cout << "矩阵 C = A - B:" << std::endl;
        std::cout << E << std::endl;

    return 0;
}