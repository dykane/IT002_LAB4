#ifndef PHANSO_H_INCLUDED
#define PHANSO_H_INCLUDED

#include <iostream>

class Phanso {
private:
    long long Itu, Imau;

    // Hàm tiện ích nội bộ
    long long ucln(long long a, long long b);
    void Rutgon();

public:
    // Hàm thiết lập duy nhất: mặc định là 0/1, cho phép chuyển đổi số nguyên thành phân số
    Phanso(long long tu = 0, long long mau = 1);

    // Nạp chồng toán tử nhập/xuất (friend function để truy cập private members)
    friend std::istream& operator>>(std::istream& is, Phanso& ps);
    friend std::ostream& operator<<(std::ostream& os, const Phanso& ps);

    // Nạp chồng toán tử số học
    friend Phanso operator+(const Phanso& a, const Phanso& b);
    friend Phanso operator-(const Phanso& a, const Phanso& b);
    friend Phanso operator*(const Phanso& a, const Phanso& b);
    friend Phanso operator/(const Phanso& a, const Phanso& b);

    // Nạp chồng toán tử so sánh
    friend bool operator==(const Phanso& a, const Phanso& b);
    friend bool operator>(const Phanso& a, const Phanso& b);
    friend bool operator<(const Phanso& a, const Phanso& b);
};

#endif
