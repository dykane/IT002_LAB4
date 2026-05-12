#include <iostream>
#include <iomanip> // Để format tiền tệ
#include "CDate.h"

using namespace std;

int main() {
    CDate d1;
    cout << "Nhap mot ngay bat ky (dd/mm/yyyy): ";
    cin >> d1;

    cout << "Ngay ban vua nhap: " << d1 << endl;
    cout << "Ngay hom sau (++): " << ++(CDate(d1)) << endl;
    cout << "Ngay hom truoc (--): " << --(CDate(d1)) << endl;

    double tienGoc, laiSuatNam;
    CDate ngayGoi, ngayRut;

    cout << "Nhap so tien gui (VNd): ";
    cin >> tienGoc;

    cout << "Nhap lai suat theo nam (%/nam): ";
    cin >> laiSuatNam;

    cout << "Nhap ngay bat dau gui (dd/mm/yyyy): ";
    cin >> ngayGoi;

    cout << "Nhap ngay rut tien (dd/mm/yyyy): ";
    cin >> ngayRut;

    // Sử dụng toán tử '-' để tính số ngày thực tế gửi
    long soNgayGoi = ngayRut - ngayGoi;

    if (soNgayGoi < 0) {
        cout << "Loi: Ngay rut tien phai sau ngay goi tien!\n";
    } else {
        // Công thức: Tiền lãi = Gốc * (Lãi suất năm / 365) * Số ngày thực gửi
        double tienLai = tienGoc * (laiSuatNam / 100.0) * (soNgayGoi / 365.0);
        double tongTien = tienGoc + tienLai;

        cout << "\n--- CHI TIET GIAO DICH ---\n";
        cout << "- So ngay thuc goi: " << soNgayGoi << " ngay\n";
        cout << fixed << setprecision(0); // Không in số thập phân cho tiền VNĐ
        cout << "- Tien lai sinh ra: " << tienLai << " VND\n";
        cout << "- Tong tien nhan duoc: " << tongTien << " VND\n";
    }

    return 0;
}
