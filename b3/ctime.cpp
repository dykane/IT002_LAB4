#include "ctime.h"
#include <iomanip>

// --------------------------------------------------
// Hàm chuẩn hóa thời gian
// --------------------------------------------------
void CTime::Normalize() {
    // Chuyển toàn bộ thời gian thành tổng số giây
    long long totalSeconds = (long long)hour * 3600 + minute * 60 + second;

    // Xử lý trường hợp giây âm hoặc vượt quá 24h (86400 giây/ngày)
    totalSeconds = ((totalSeconds % 86400) + 86400) % 86400;

    // Chuyển ngược lại thành giờ, phút, giây
    hour = totalSeconds / 3600;
    minute = (totalSeconds % 3600) / 60;
    second = totalSeconds % 60;
}

// --------------------------------------------------
// Constructor
// --------------------------------------------------
CTime::CTime(int h, int m, int s) {
    hour = h;
    minute = m;
    second = s;
    Normalize();
}

// --------------------------------------------------
// Toán tử nhập (>>)
// --------------------------------------------------
std::istream& operator>>(std::istream& is, CTime& t) {
    int h, m, s;
    char c1, c2;

    while (true) {
        std::cout << "Nhap thoi gian (HH:MM:SS, vd: 14:30:00): ";

        if (is >> h >> c1 >> m >> c2 >> s) {
            if (c1 == ':' && c2 == ':' && h >= 0 && h < 24 && m >= 0 && m < 60 && s >= 0 && s < 60) {
                t.hour = h;
                t.minute = m;
                t.second = s;
                break;
            }
        }

        std::cout << "Sai dinh dang hoac thoi gian khong thuc te!\n";
        is.clear();
        is.ignore(10000, '\n');
    }

    return is;
}

// --------------------------------------------------
// Toán tử xuất (<<)
// --------------------------------------------------
std::ostream& operator<<(std::ostream& os, const CTime& t) {
    os << std::setfill('0')
       << std::setw(2) << t.hour << ":"
       << std::setw(2) << t.minute << ":"
       << std::setw(2) << t.second;
    return os;
}

// --------------------------------------------------
// Toán tử cộng: CTime + int (thêm số giây)
// --------------------------------------------------
CTime operator+(const CTime& t, int s) {
    CTime result = t;
    result.second += s;
    result.Normalize();
    return result;
}

// --------------------------------------------------
// Toán tử trừ: CTime - int (bớt số giây)
// --------------------------------------------------
CTime operator-(const CTime& t, int s) {
    CTime result = t;
    result.second -= s;
    result.Normalize();
    return result;
}

// --------------------------------------------------
// Toán tử tiền tố ++ (++t)
// --------------------------------------------------
CTime& CTime::operator++() {
    second++;
    Normalize();
    return *this;
}

// --------------------------------------------------
// Toán tử hậu tố ++ (t++)
// --------------------------------------------------
CTime CTime::operator++(int) {
    CTime temp = *this;
    second++;
    Normalize();
    return temp;
}

// --------------------------------------------------
// Toán tử tiền tố -- (--t)
// --------------------------------------------------
CTime& CTime::operator--() {
    second--;
    Normalize();
    return *this;
}

// --------------------------------------------------
// Toán tử hậu tố -- (t--)
// --------------------------------------------------
CTime CTime::operator--(int) {
    CTime temp = *this;
    second--;
    Normalize();
    return temp;
}
