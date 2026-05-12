#ifndef CVECTOR_H
#define CVECTOR_H

#include <string>

class CVector {
private:
    int n;          // Số chiều của vector
    double* v;      // Mảng động lưu các thành phần (tọa độ)

    // Các hàm private hỗ trợ nhập liệu tuyệt đối an toàn
    double nhapSoAnToan(std::string prompt);
    int nhapKichThuocAnToan(std::string prompt);

public:
    // Các hàm thiết lập & hủy (Rule of Three)
    CVector();                                // Constructor mặc định (0 chiều)
    CVector(int soChieu);                     // Constructor với số chiều
    CVector(const CVector& other);            // Copy Constructor
    ~CVector();                               // Destructor

    CVector& operator=(const CVector& other); // Toán tử gán

    // Hàm I/O
    void nhap();
    void xuat() const;

    // Nạp chồng các phép toán vector cơ bản
    CVector operator+(const CVector& other) const; // Cộng 2 vector
    CVector operator-(const CVector& other) const; // Trừ 2 vector
    double operator*(const CVector& other) const;  // Tích vô hướng
    CVector operator*(double k) const;             // Nhân vector với một số thực (vô hướng)
};

#endif
