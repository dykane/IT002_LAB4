    #ifndef CDATHUC_H
#define CDATHUC_H

#include <string>

class cDaThuc {
private:
    int n;          // Bậc của đa thức
    double* heSo;   // Mảng động lưu hệ số, heSo[i] là hệ số của x^i

    // Các hàm hỗ trợ bẫy lỗi nhập liệu
    double nhapSo(std::string prompt);
    int nhapBac(std::string prompt);

public:
    // Các hàm thiết lập & hủy
    cDaThuc();                          // Mặc định bậc 0
    cDaThuc(int bac);                   // Khởi tạo với bậc chỉ định
    cDaThuc(const cDaThuc& other);      // Copy Constructor
    ~cDaThuc();                         // Destructor

    // Toán tử gán (Bắt buộc khi có cấp phát động)
    cDaThuc& operator=(const cDaThuc& other);

    // Các phương thức chính (Thêm const cho các hàm không sửa đổi đối tượng)
    void nhap();
    void xuat() const;
    double tinhGiaTri(double x) const;

    // Nạp chồng toán tử thay thế cho cong() và tru()
    cDaThuc operator+(const cDaThuc& dt2) const;
    cDaThuc operator-(const cDaThuc& dt2) const;
};

#endif
