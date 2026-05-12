#include "CVector.h"
#include <iostream>
#include <limits>

using namespace std;

// --- CÁC HÀM BẪY LỖI NHẬP LIỆU ---
double CVector::nhapSoAnToan(string prompt) {
    double val;
    while (true) {
        cout << prompt;
        if (cin >> val) return val;
        cout << "=> LOI: Du lieu khong hop le. Vui long chi nhap so!\n";
        cin.clear(); // Xóa cờ lỗi của cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Loại bỏ các ký tự thừa trong buffer
    }
}

int CVector::nhapKichThuocAnToan(string prompt) {
    int val;
    while (true) {
        val = (int)nhapSoAnToan(prompt);
        if (val > 0) return val;
        cout << "=> LOI: So chieu cua vector phai > 0!\n";
    }
}

// --- THIẾT LẬP & HỦY ---
CVector::CVector() : n(0), v(nullptr) {}

CVector::CVector(int soChieu) : n(soChieu) {
    v = new double[n];
    for (int i = 0; i < n; i++) v[i] = 0;
}

CVector::CVector(const CVector& other) : n(other.n) {
    v = new double[n];
    for (int i = 0; i < n; i++) v[i] = other.v[i];
}

CVector::~CVector() {
    if (v != nullptr) {
        delete[] v;
        v = nullptr;
    }
}

CVector& CVector::operator=(const CVector& other) {
    if (this != &other) {
        delete[] v; // Xóa vùng nhớ cũ
        n = other.n;
        v = new double[n];
        for (int i = 0; i < n; i++) v[i] = other.v[i];
    }
    return *this;
}

// --- NHẬP XUẤT ---
void CVector::nhap() {
    n = nhapKichThuocAnToan("Nhap so chieu cua vector (n): ");

    delete[] v;
    v = new double[n];

    cout << "Nhap cac thanh phan cua vector:\n";
    for (int i = 0; i < n; i++) {
        v[i] = nhapSoAnToan("  + Thanh phan thu " + to_string(i + 1) + ": ");
    }
}

void CVector::xuat() const {
    if (n == 0) {
        cout << "(empty)\n";
        return;
    }
    cout << "(";
    for (int i = 0; i < n; i++) {
        cout << v[i];
        if (i < n - 1) cout << ", ";
    }
    cout << ")\n";
}

// --- PHÉP TOÁN ---
CVector CVector::operator+(const CVector& other) const {
    if (n != other.n) {
        cout << "=> LOI: Khong the cong hai vector khac so chieu!\n";
        return CVector(); // Trả về vector rỗng nếu lỗi
    }
    CVector ketQua(n);
    for (int i = 0; i < n; i++) ketQua.v[i] = v[i] + other.v[i];
    return ketQua;
}

CVector CVector::operator-(const CVector& other) const {
    if (n != other.n) {
        cout << "=> LOI: Khong the tru hai vector khac so chieu!\n";
        return CVector();
    }
    CVector ketQua(n);
    for (int i = 0; i < n; i++) ketQua.v[i] = v[i] - other.v[i];
    return ketQua;
}

double CVector::operator*(const CVector& other) const {
    if (n != other.n) {
        cout << "=> LOI: Khong the tinh tich vo huong hai vector khac so chieu!\n";
        return 0;
    }
    double ketQua = 0;
    for (int i = 0; i < n; i++) ketQua += v[i] * other.v[i];
    return ketQua;
}

CVector CVector::operator*(double k) const {
    CVector ketQua(n);
    for (int i = 0; i < n; i++) ketQua.v[i] = v[i] * k;
    return ketQua;
}
