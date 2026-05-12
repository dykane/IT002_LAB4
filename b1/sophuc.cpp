#include <iostream>
#include "sophuc.h"

using namespace std;

SoPhuc::SoPhuc(double thuc, double ao) {
    iThuc = thuc;
    iAo = ao;
}

istream& operator>>(istream& is, SoPhuc& sp) {
    while(true){
        cout << "Nhap phan thuc: ";
        if (is >> sp.iThuc) break;
        else {
            cout << "Gia tri khong hop le! Nhap lai.\n";
            is.clear();
            is.ignore(1000, '\n');
        }
    }

    while(true) {
        cout << "Nhap phan ao: ";
        if (is >> sp.iAo) break;
        else {
            cout << "Gia tri khong hop le! Nhap lai.\n";
            is.clear();
            is.ignore(1000, '\n');
        }
    }
    return is;
}

ostream& operator<<(ostream& os, const SoPhuc& sp) {
    if (sp.iAo >= 0)
        os << sp.iThuc << " + " << sp.iAo << "i";
    else
        os << sp.iThuc << " - " << -sp.iAo << "i";
    return os;
}


SoPhuc operator+(const SoPhuc& a, const SoPhuc& b) {
    return SoPhuc(a.iThuc + b.iThuc, a.iAo + b.iAo);
}

SoPhuc operator-(const SoPhuc& a, const SoPhuc& b) {
    return SoPhuc(a.iThuc - b.iThuc, a.iAo - b.iAo);
}

SoPhuc operator*(const SoPhuc& a, const SoPhuc& b) {
    double thuc = a.iThuc * b.iThuc - a.iAo * b.iAo;
    double ao   = a.iThuc * b.iAo   + a.iAo * b.iThuc;
    return SoPhuc(thuc, ao);
}

SoPhuc operator/(const SoPhuc& a, const SoPhuc& b) {
    double mau = b.iThuc * b.iThuc + b.iAo * b.iAo;
    if (mau == 0) {
        // Có thể ném lỗi (exception) ở đây nếu cần thiết trong thực tế
        cout << "\n[Canh bao] Chia cho 0!";
        return SoPhuc(0, 0);
    }
    double thuc = (a.iThuc * b.iThuc + a.iAo * b.iAo) / mau;
    double ao   = (a.iAo * b.iThuc - a.iThuc * b.iAo) / mau;
    return SoPhuc(thuc, ao);
}

bool operator==(const SoPhuc& a, const SoPhuc& b) {
    return (a.iThuc == b.iThuc) && (a.iAo == b.iAo);
}

bool operator!=(const SoPhuc& a, const SoPhuc& b) {
    return !(a == b);
}
