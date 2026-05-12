#ifndef CDATE_H_INCLUDED
#define CDATE_H_INCLUDED
#include <iostream>

class CDate {
private:
    int iNgay, iThang, iNam;
    bool namnhuan(int y) const;
    int songay() const;
    long getAbsoluteDays() const; // Hàm tính tổng số ngày từ năm 0 để trừ 2 ngày

public:
    // Constructor mặc định
    CDate(int d = 1, int m = 1, int y = 2000);

    // Kiểm tra ngày hợp lệ
    bool KiemTraHopLe() const;

    // Nạp chồng các toán tử tăng/giảm số ngày
    CDate operator+(int days);
    CDate operator-(int days);

    CDate& operator++();    // Tiền tố (++date)
    CDate operator++(int);  // Hậu tố (date++)
    CDate& operator--();    // Tiền tố (--date)
    CDate operator--(int);  // Hậu tố (date--)

    // Nạp chồng toán tử trừ 2 ngày cho nhau (trả về số ngày chênh lệch)
    long operator-(const CDate& other) const;

    // Nạp chồng toán tử nhập / xuất
    friend std::istream& operator>>(std::istream& is, CDate& d);
    friend std::ostream& operator<<(std::ostream& os, const CDate& d);
};

#endif
