#include "CMatrix.h"
#include <iostream>
#include <limits>

using namespace std;

// --- BẪY LỖI ---
double CMatrix::nhapSoAnToan(string prompt) {
    double val;
    while (true) {
        cout << prompt;
        if (cin >> val) return val;
        cout << "=> LOI: Vui long chi nhap so!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int CMatrix::nhapKichThuocAnToan(string prompt) {
    int val;
    while (true) {
        val = (int)nhapSoAnToan(prompt);
        if (val > 0) return val;
        cout << "=> LOI: Kich thuoc ma tran phai > 0!\n";
    }
}

// --- THIẾT LẬP & HỦY ---
CMatrix::CMatrix() : rows(0), cols(0), data(nullptr) {}

CMatrix::CMatrix(int r, int c) : rows(r), cols(c) {
    data = new double*[rows];
    for (int i = 0; i < rows; i++) {
        data[i] = new double[cols](); // Khởi tạo toàn bộ bằng 0
    }
}

CMatrix::CMatrix(const CMatrix& other) : rows(other.rows), cols(other.cols) {
    data = new double*[rows];
    for (int i = 0; i < rows; i++) {
        data[i] = new double[cols];
        for (int j = 0; j < cols; j++) {
            data[i][j] = other.data[i][j];
        }
    }
}

CMatrix::~CMatrix() {
    if (data != nullptr) {
        for (int i = 0; i < rows; i++) delete[] data[i];
        delete[] data;
        data = nullptr;
    }
}

CMatrix& CMatrix::operator=(const CMatrix& other) {
    if (this != &other) {
        if (data != nullptr) {
            for (int i = 0; i < rows; i++) delete[] data[i];
            delete[] data;
        }
        rows = other.rows;
        cols = other.cols;
        data = new double*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new double[cols];
            for (int j = 0; j < cols; j++) {
                data[i][j] = other.data[i][j];
            }
        }
    }
    return *this;
}

// --- NHẬP XUẤT ---
void CMatrix::nhap() {
    rows = nhapKichThuocAnToan("Nhap so dong: ");
    cols = nhapKichThuocAnToan("Nhap so cot: ");

    if (data != nullptr) {
        for (int i = 0; i < rows; i++) delete[] data[i];
        delete[] data;
    }

    data = new double*[rows];
    cout << "Nhap cac phan tu cua ma tran:\n";
    for (int i = 0; i < rows; i++) {
        data[i] = new double[cols];
        for (int j = 0; j < cols; j++) {
            data[i][j] = nhapSoAnToan("  + A[" + to_string(i) + "][" + to_string(j) + "] = ");
        }
    }
}

void CMatrix::xuat() const {
    if (rows == 0 || cols == 0) {
        cout << "(empty)\n";
        return;
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << data[i][j] << "\t";
        }
        cout << "\n";
    }
}

// --- PHÉP TOÁN ---
CMatrix CMatrix::operator+(const CMatrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        cout << "=> LOI: Khong the cong hai ma tran khac kich thuoc!\n";
        return CMatrix();
    }
    CMatrix ketQua(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            ketQua.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return ketQua;
}

CMatrix CMatrix::operator-(const CMatrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        cout << "=> LOI: Khong the tru hai ma tran khac kich thuoc!\n";
        return CMatrix();
    }
    CMatrix ketQua(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            ketQua.data[i][j] = data[i][j] - other.data[i][j];
        }
    }
    return ketQua;
}

CMatrix CMatrix::operator*(const CMatrix& other) const {
    if (cols != other.rows) {
        cout << "=> LOI: So cot cua ma tran A phai bang so dong cua ma tran B!\n";
        return CMatrix();
    }
    CMatrix ketQua(rows, other.cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < other.cols; j++) {
            ketQua.data[i][j] = 0;
            for (int k = 0; k < cols; k++) {
                ketQua.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }
    return ketQua;
}

// Nhân ma trận với Vector (Mảng 1 chiều)
double* CMatrix::operator*(const double* v) const {
    if (v == nullptr) return nullptr;

    // Vector kết quả có kích thước bằng số dòng của ma trận
    double* ketQua = new double[rows];
    for (int i = 0; i < rows; i++) {
        double sum = 0;
        for (int j = 0; j < cols; j++) {
            // cols của ma trận = số chiều của vector (kích thước mảng v)
            sum += data[i][j] * v[j];
        }
        ketQua[i] = sum;
    }
    return ketQua; // CHÚ Ý: Hàm main() phải có trách nhiệm delete[] mảng này
}
