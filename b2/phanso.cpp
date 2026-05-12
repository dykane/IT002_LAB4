#include "phanso.h"
#include <cmath>

// Hàm thiết lập
Phanso::Phanso(long long tu, long long mau) {
    if (mau == 0) mau = 1; // Tránh lỗi mẫu bằng 0
    Itu = tu;
    Imau = mau;
    Rutgon();
}

// Hàm tìm UCLN
long long Phanso::ucln(long long a, long long b) {
    a = std::abs(a);
    b = std::abs(b);
    while (b != 0) {
        long long t = a % b;
        a = b;
        b = t;
    }
    return a;
}

// Hàm rút gọn phân số
void Phanso::Rutgon() {
    if (Itu == 0) {
        Imau = 1;
        return;
    }
    long long common = ucln(Itu, Imau);
    Itu /= common;
    Imau /= common;
    if (Imau < 0) {
        Itu = -Itu;
        Imau = -Imau;
    }
}

// Toán tử nhập >>
std::istream& operator>>(std::istream& is, Phanso& ps) {
    char c;
    while (true) {
        if (is >> ps.Itu >> c >> ps.Imau && c == '/' && ps.Imau != 0) {
            ps.Rutgon();
            break;
        } else {
            std::cout << "Nhap sai! Vui long nhap theo dang tu/mau (vi du 1/2): ";
            is.clear();
            is.ignore(1000, '\n');
        }
    }
    return is;
}

// Toán tử xuất <<
std::ostream& operator<<(std::ostream& os, const Phanso& ps) {
    if (ps.Itu == 0) os << 0;
    else if (ps.Imau == 1) os << ps.Itu;
    else os << ps.Itu << "/" << ps.Imau;
    return os;
}

// Toán tử cộng +
Phanso operator+(const Phanso& a, const Phanso& b) {
    return Phanso(a.Itu * b.Imau + b.Itu * a.Imau, a.Imau * b.Imau);
}

// Toán tử trừ -
Phanso operator-(const Phanso& a, const Phanso& b) {
    return Phanso(a.Itu * b.Imau - b.Itu * a.Imau, a.Imau * b.Imau);
}

// Toán tử nhân *
Phanso operator*(const Phanso& a, const Phanso& b) {
    return Phanso(a.Itu * b.Itu, a.Imau * b.Imau);
}

// Toán tử chia /
Phanso operator/(const Phanso& a, const Phanso& b) {
    return Phanso(a.Itu * b.Imau, a.Imau * b.Itu);
}

// Toán tử so sánh bằng ==
bool operator==(const Phanso& a, const Phanso& b) {
    return (a.Itu == b.Itu && a.Imau == b.Imau);
}

// Toán tử so sánh lớn hơn >
bool operator>(const Phanso& a, const Phanso& b) {
    return (double)a.Itu * b.Imau > (double)b.Itu * a.Imau;
}

// Toán tử so sánh bé hơn <
bool operator<(const Phanso& a, const Phanso& b) {
    return (double)a.Itu * b.Imau < (double)b.Itu * a.Imau;
}
