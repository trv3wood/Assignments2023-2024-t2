#include <iostream>
using namespace std;
class RMB {
private:
    int yuan;
    int jiao;
    int fen;
    bool mark;

public:
    RMB(int y = 0, int j = 0, int f = 0, bool m = false)
        : yuan(y), jiao(j), fen(f), mark(m) {}
    RMB(double c) {
        int y, j, f;
        if (c < 0) {
            mark = true;
            c = -c;
        } else {
            mark = false;
        }
        yuan = c;
        jiao = c * 10 - yuan * 10;
        fen = c * 100 - yuan * 100 - jiao * 10;
    }
    RMB operator-(RMB A) {
        RMB temp;
        temp.yuan = yuan - A.yuan;
        temp.jiao = jiao - A.jiao;
        temp.fen = fen - A.fen;
        return temp;
    }
    RMB operator*(RMB A) {
        RMB temp;
        temp.yuan = yuan * A.yuan;
        temp.jiao = jiao * A.jiao;
        temp.fen = fen * A.fen;
        return temp;
    }
    RMB operator+(double c) {
        int y, j, f;
        y = c;
        j = c * 10 - y * 10;
        f = c * 100 - y * 100 - j * 10;
        RMB temp;
        temp.yuan = yuan + y;
        temp.jiao = jiao + j;
        temp.fen = fen + f;
        return temp;
    }
    double operator*(int c) {
        double tem;
        tem = yuan + 0.1 * jiao + 0.01 * fen;
        tem = tem * c;
        return tem;
    }
    double operator*(double c) {
        double tem;
        tem = yuan + 0.1 * jiao + 0.01 * fen;
        tem *= c;
        return tem;
    }
    operator double() const {
        return mark ? (-yuan + jiao * 0.1 + fen * 0.01)
                    : (yuan + jiao * 0.1 + fen * 0.01);
    }

    friend ostream& operator<<(ostream& output, const RMB& A);
    friend istream& operator>>(istream& input, RMB& A);
};

ostream& operator<<(ostream& output, const RMB& A) {
    output << A.yuan << "Y" << A.jiao << "J" << A.fen << "F" << endl;
    return output;
}
istream& operator>>(istream& input, RMB& A) {
    input >> A.yuan >> A.jiao >> A.fen;
    return input;
}

int main() {
    RMB a, b;
    double c;
    while (cin >> a) {
        // cout <<"b:\n";
        cin >> b;
        // cout <<"c:\n";
        cin >> c;
        cout << "a = " << a << "b = " << b << "c = " << RMB(c);
        cout << "a + c = " << RMB(a + c);
        cout << "a - b = " << RMB(a - b);
        cout << "b * 2 = " << RMB(b * 2);
        cout << "a * 0.5 = " << RMB(a * 0.5);
    }
    return 0;
}
