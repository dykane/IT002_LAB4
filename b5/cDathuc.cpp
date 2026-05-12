    #include "cDaThuc.h"
#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

double cDaThuc::nhapSo(string prompt) {
    double val;
    while (true) {
        cout << prompt;
        if (cin >> val) return val;
        cout << "=> LOI: Vui long chi nhap so!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int cDaThuc::nhapBac(string prompt) {
    int val;
    while (true) {
        val = (int)nhapSo(prompt);
        if (val >= 0) return val;
        cout << "=> LOI: Bac cua da thuc phai >= 0!\n";
    }
}

cDaThuc::cDaThuc() {
    n = 0;
    heSo = new double[1];
    heSo[0] = 0;
}

cDaThuc::cDaThuc(int bac) {
    n = bac;
    heSo = new double[n + 1];
    for (int i = 0; i <= n; i++) {
        heSo[i] = 0;
    }
}

// Copy Constructor
cDaThuc::cDaThuc(const cDaThuc& other) {
    n = other.n;
    heSo = new double[n + 1];
    for (int i = 0; i <= n; i++) {
        heSo[i] = other.heSo[i];
    }
}

// Destructor
cDaThuc::~cDaThuc() {
    if (heSo != nullptr) {
        delete[] heSo;
        heSo = nullptr;
    }
}

// Toán tử gán
cDaThuc& cDaThuc::operator=(const cDaThuc& other) {
    if (this != &other) { // Tránh tự gán (A = A)
        delete[] heSo;    // Xóa vùng nhớ cũ
        n = other.n;
        heSo = new double[n + 1]; // Cấp phát vùng nhớ mới
        for (int i = 0; i <= n; i++) {
            heSo[i] = other.heSo[i];
        }
    }
    return *this;
}

void cDaThuc::nhap() {
    n = nhapBac("Nhap bac cua da thuc (n): ");

    delete[] heSo;
    heSo = new double[n + 1];

    cout << "Nhap cac he so:\n";
    for (int i = n; i >= 0; i--) {
        heSo[i] = nhapSo("  + He so cua x^" + to_string(i) + " : ");
    }
}

void cDaThuc::xuat() const {
    bool isFirst = true;
    bool isAllZero = true;

    for (int i = n; i >= 0; i--) {
        if (heSo[i] == 0) continue;
        isAllZero = false;

        if (!isFirst) {
            if (heSo[i] > 0) cout << " + ";
            else cout << " - ";
        } else {
            if (heSo[i] < 0) cout << "-";
        }

        double val = abs(heSo[i]);
        if (val != 1 || i == 0) {
            cout << val;
        }

        if (i > 1) cout << "x^" << i;
        else if (i == 1) cout << "x";

        isFirst = false;
    }

    if (isAllZero) cout << "0";
    cout << "\n";
}

double cDaThuc::tinhGiaTri(double x) const {
    double result = 0;
    for (int i = 0; i <= n; i++) {
        result += heSo[i] * pow(x, i);
    }
    return result;
}

cDaThuc cDaThuc::operator+(const cDaThuc& dt2) const {
    int maxBac = (n > dt2.n) ? n : dt2.n;
    cDaThuc ketQua(maxBac);

    for (int i = 0; i <= maxBac; i++) {
        double heSo1 = (i <= n) ? heSo[i] : 0;
        double heSo2 = (i <= dt2.n) ? dt2.heSo[i] : 0;
        ketQua.heSo[i] = heSo1 + heSo2;
    }
    return ketQua;
}

cDaThuc cDaThuc::operator-(const cDaThuc& dt2) const {
    int maxBac = (n > dt2.n) ? n : dt2.n;
    cDaThuc ketQua(maxBac);

    for (int i = 0; i <= maxBac; i++) {
        double heSo1 = (i <= n) ? heSo[i] : 0;
        double heSo2 = (i <= dt2.n) ? dt2.heSo[i] : 0;
        ketQua.heSo[i] = heSo1 - heSo2;
    }
    return ketQua;
}
