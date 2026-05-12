#ifndef SOPHUC_H_INCLUDED
#define SOPHUC_H_INCLUDED

#include <iostream>
using namespace std;

class SoPhuc {
private:
    double iThuc, iAo;
public:
    // Phương thức thiết lập duy nhất:
    // Vừa là constructor mặc định (0, 0), vừa ép kiểu số thực thành số phức (x, 0), vừa khởi tạo số phức (x, y)
    SoPhuc(double thuc = 0, double ao = 0);

    // Nạp chồng toán tử nhập >> và xuất <<
    friend istream& operator>>(istream& is, SoPhuc& sp);
    friend ostream& operator<<(ostream& os, const SoPhuc& sp);

    // Nạp chồng các phép toán số học +, -, *, /
    friend SoPhuc operator+(const SoPhuc& a, const SoPhuc& b);
    friend SoPhuc operator-(const SoPhuc& a, const SoPhuc& b);
    friend SoPhuc operator*(const SoPhuc& a, const SoPhuc& b);
    friend SoPhuc operator/(const SoPhuc& a, const SoPhuc& b);

    // Nạp chồng toán tử so sánh ==, !=
    friend bool operator==(const SoPhuc& a, const SoPhuc& b);
    friend bool operator!=(const SoPhuc& a, const SoPhuc& b);
};

#endif
