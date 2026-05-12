#include <iostream>
#include "CVector.h"

using namespace std;

// Hàm bẫy lỗi độc lập cho main()
double nhapHeSoAnToan(string prompt) {
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
    CVector v1, v2;

    cout << "--- NHAP VECTOR A ---\n";
    v1.nhap();

    cout << "\n--- NHAP VECTOR B ---\n";
    v2.nhap();

    cout << "\nVector A = "; v1.xuat();
    cout << "Vector B = "; v2.xuat();

    cout << "\n--- CAC PHEP TOAN ---\n";

    CVector tong = v1 + v2;
    cout << "1. A + B = "; tong.xuat();

    CVector hieu = v1 - v2;
    cout << "2. A - B = "; hieu.xuat();

    double tichVoHuong = v1 * v2;
    cout << "3. Tich vo huong A * B = " << tichVoHuong << "\n";

    double k = nhapHeSoAnToan("\nNhap mot so thuc k de nhan voi Vector A: ");
    CVector tichVoHuongVoiSo = v1 * k;
    cout << "4. k * A = "; tichVoHuongVoiSo.xuat();

    return 0;
}
