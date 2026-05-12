#ifndef CTIME_H_INCLUDED
#define CTIME_H_INCLUDED

#include <iostream>
#include <iomanip>

class CTime {
private:
    int hour;    // Giờ (0-23)
    int minute;  // Phút (0-59)
    int second;  // Giây (0-59)

    // Hàm tiện ích để chuẩn hóa thời gian
    void Normalize();

public:
    // Constructor
    CTime(int h = 0, int m = 0, int s = 0);

    // Toán tử nhập/xuất
    friend std::istream& operator>>(std::istream& is, CTime& t);
    friend std::ostream& operator<<(std::ostream& os, const CTime& t);

    // Toán tử số học: cộng/trừ thêm số giây
    friend CTime operator+(const CTime& t, int s);
    friend CTime operator-(const CTime& t, int s);

    // Toán tử tiền tố ++, --
    CTime& operator++();    // ++t
    CTime& operator--();    // --t

    // Toán tử hậu tố ++, --
    CTime operator++(int);  // t++
    CTime operator--(int);  // t--
};

#endif
