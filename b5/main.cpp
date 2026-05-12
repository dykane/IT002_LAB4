#include <iostream>
#include <limits>
#include "cDaThuc.h"

using namespace std;

double nhapX(string prompt) {
    double val;
    while (true) {
        cout << prompt;
        if (cin >> val) return val;
        cout << "=> LOI: Vui long chi nhap so!\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

int main() {
    cDaThuc dtA;
    cout << "[1] Nhap Da Thuc A:\n";
    dtA.nhap();

    cDaThuc dtB;
    cout << "\n[2] Nhap Da Thuc B:\n";
    dtB.nhap();

    cout << "\nDa thuc A(x) = "; dtA.xuat();
    cout << "Da thuc B(x) = "; dtB.xuat();

    cout << "\n[3] Tinh gia tri cua da thuc A khi biet x:\n";
    double x = nhapX("Nhap gia tri x: ");
    cout << "=> A(" << x << ") = " << dtA.tinhGiaTri(x) << "\n";

    // 4. Cộng đa thức (Sử dụng toán tử + đã nạp chồng)
    cout << "\n[4] Cong hai da thuc (A + B):\n";
    cDaThuc Tong = dtA + dtB;
    cout << "=> Tong(x) = ";
    Tong.xuat();

    // 5. Trừ đa thức (Sử dụng toán tử - đã nạp chồng)
    cout << "\n[5] Tru hai da thuc (A - B):\n";
    cDaThuc Hieu = dtA - dtB;
    cout << "=> Hieu(x) = ";
    Hieu.xuat();

    return 0;
}
