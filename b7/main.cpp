#include <iostream>
#include <limits>
#include "CMatrix.h"

using namespace std;

// Hàm bẫy lỗi độc lập cho mảng vector trong main
double nhapSo(string prompt) {
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
    cout << "=== 1. TICH HAI MA TRAN ===\n";
    CMatrix matA, matB;
    cout << "[Nhap Ma tran A]\n"; matA.nhap();
    cout << "\n[Nhap Ma tran B]\n"; matB.nhap();

    cout << "\n=> Ma tran Ket qua (A * B):\n";
    CMatrix tichAB = matA * matB;
    tichAB.xuat();

    cout << "\n=====================================\n";

    cout << "=== 2. TICH MA TRAN VA VECTOR ===\n";
    CMatrix matC;
    cout << "[Nhap Ma tran C]\n";
    matC.nhap();

    // Khởi tạo vector là một mảng động.
    // Theo nguyên tắc toán học, số chiều vector phải bằng số cột của ma trận
    int soChieuV = matC.getCols();
    if (soChieuV > 0) {
        double* vecV = new double[soChieuV];

        cout << "\n[Nhap Vector V (" << soChieuV << " chieu)]\n";
        for (int i = 0; i < soChieuV; i++) {
            vecV[i] = nhapSo("  + Thanh phan thu " + to_string(i + 1) + ": ");
        }

        // Thực hiện phép nhân
        double* tichCV = matC * vecV;

        // In kết quả
        cout << "\n=> Vector Ket qua (C * V):\n(";
        int soChieuKetQua = matC.getRows(); // Kích thước vector kết quả = số dòng ma trận
        for (int i = 0; i < soChieuKetQua; i++) {
            cout << tichCV[i];
            if (i < soChieuKetQua - 1) cout << ", ";
        }
        cout << ")\n";

        // QUAN TRỌNG: Giải phóng bộ nhớ của các mảng động
        delete[] vecV;
        delete[] tichCV;
    }

    return 0;
}
