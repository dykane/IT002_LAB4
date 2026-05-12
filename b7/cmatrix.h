#ifndef CMATRIX_H
#define CMATRIX_H

#include <string>

class CMatrix {
private:
    int rows;       // Số dòng
    int cols;       // Số cột
    double** data;  // Mảng 2 chiều động

    // Hàm bẫy lỗi
    double nhapSoAnToan(std::string prompt);
    int nhapKichThuocAnToan(std::string prompt);

public:
    CMatrix();
    CMatrix(int r, int c);
    CMatrix(const CMatrix& other);
    ~CMatrix();

    CMatrix& operator=(const CMatrix& other);

    // Getter để hàm main biết kích thước ma trận mà tạo vector tương ứng
    int getRows() const { return rows; }
    int getCols() const { return cols; }

    void nhap();
    void xuat() const;

    // Các phép toán ma trận
    CMatrix operator+(const CMatrix& other) const;
    CMatrix operator-(const CMatrix& other) const;
    CMatrix operator*(const CMatrix& other) const;

    // Tích của ma trận và vector (vector là mảng 1 chiều double*)
    double* operator*(const double* v) const;
};

#endif
