#include "CDate.h"

using namespace std;

// Constructor
CDate::CDate(int d, int m, int y) : iNgay(d), iThang(m), iNam(y) {}

bool CDate::namnhuan(int y) const {
    return (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0));
}

int CDate::songay() const {
    switch(iThang) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return namnhuan(iNam) ? 29 : 28;
        default:
            return 0;
    }
}

bool CDate::KiemTraHopLe() const {
    if(iThang < 1 || iThang > 12 || iNam < 0) return false;
    if(iNgay < 1 || iNgay > songay()) return false;
    return true;
}

// Toán tử tăng 1 ngày (++date)
CDate& CDate::operator++() {
    iNgay++;
    if(iNgay > songay()) {
        iNgay = 1;
        iThang++;
        if(iThang > 12) {
            iThang = 1;
            iNam++;
        }
    }
    return *this;
}

// Toán tử tăng 1 ngày (date++)
CDate CDate::operator++(int) {
    CDate temp = *this;
    ++(*this);
    return temp;
}

// Toán tử giảm 1 ngày (--date)
CDate& CDate::operator--() {
    iNgay--;
    if(iNgay == 0) {
        iThang--;
        if(iThang == 0) {
            iThang = 12;
            iNam--;
        }
        iNgay = songay();
    }
    return *this;
}

// Toán tử giảm 1 ngày (date--)
CDate CDate::operator--(int) {
    CDate temp = *this;
    --(*this);
    return temp;
}

// Cộng thêm n ngày
CDate CDate::operator+(int days) {
    CDate result = *this;
    if (days >= 0) {
        for(int i = 0; i < days; i++) ++result;
    } else {
        for(int i = 0; i < -days; i++) --result;
    }
    return result;
}

// Trừ đi n ngày
CDate CDate::operator-(int days) {
    return *this + (-days); // Trừ đi n ngày chính là cộng thêm -n ngày
}

// Tính tổng số ngày từ năm 0 (Dùng để tính khoảng cách 2 ngày)
long CDate::getAbsoluteDays() const {
    const int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    long n = iNam * 365 + iNgay;
    for (int i = 0; i < iThang - 1; i++) {
        n += monthDays[i];
    }
    // Cộng thêm các ngày của năm nhuận
    int years = iNam;
    if (iThang <= 2) years--;
    n += (years / 4 - years / 100 + years / 400);
    return n;
}

// Toán tử trừ 2 ngày để lấy số ngày chênh lệch
long CDate::operator-(const CDate& other) const {
    return this->getAbsoluteDays() - other.getAbsoluteDays();
}

// Toán tử nhập (>>), bao gồm cả vòng lặp bắt lỗi như code cũ của bạn
istream& operator>>(istream& is, CDate& d) {
    char c1, c2;
    while(true){
        if(is >> d.iNgay >> c1 >> d.iThang >> c2 >> d.iNam && c1=='/' && c2=='/'){
            if(d.KiemTraHopLe()){
                break;
            } else {
                cout << "Ngay khong hop le hoac khong ton tai! Vui long nhap lai: ";
            }
        } else {
            cout << "Nhap dung dinh dang dd/mm/yyyy (vd: 11/02/2000): ";
            is.clear();
            is.ignore(1000,'\n');
        }
    }
    return is;
}

// Toán tử xuất (<<)
ostream& operator<<(ostream& os, const CDate& d) {
    os << (d.iNgay < 10 ? "0" : "") << d.iNgay << "/"
       << (d.iThang < 10 ? "0" : "") << d.iThang << "/"
       << d.iNam;
    return os;
}
