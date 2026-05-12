#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
#include "ctime.h"

using namespace std;

// Hàm xóa màn hình đa nền tảng
void clearScreen() {
#if defined(_WIN32)
    system("cls");
#else
    system("clear");
#endif
}

int main() {
    CTime t;

    cout << "\n===== KHOI TAO DONG HO =====\n";
    cin >> t;

    cout << "\n===== TEST CAC PHEP TOAN =====\n";
    cout << "Thoi gian ban dau    : " << t << "\n";
    CTime temp = t;
    cout << "Sau khi --t : " << (--temp) << "\n";
    cout << "Sau khi ++t : " << (++temp) << "\n";
    temp = t;
    cout << "Sau khi t++ : " << (temp++) << "\n";
    cout << "Gia tri sau t++      : " << temp << "\n";

    cout << "\n\nNhan Enter de bat dau chay dong ho thuc te (Ctrl+C de dung)...\n";
    cin.ignore();
    cin.get();

    clearScreen();

    // Vòng lặp đồng hồ chạy thực tế
    while (true) {
        // ANSI escape codes:
        // \033[s      : Lưu vị trí con trỏ hiện tại
        // \033[H      : Di chuyển con trỏ đến góc trên bên trái (Home position)
        // \033[2J     : Xóa toàn bộ màn hình
        // \033[1;1H   : Di chuyển con trỏ đến dòng 1, cột 1
        // \033[1;70H  : Di chuyển con trỏ đến dòng 1, cột 70 (góc phải)
        // \033[u      : Khôi phục lại vị trí con trỏ

        // In thời gian ở góc trên bên phải, sau đó khôi phục vị trí con trỏ
        cout << "\033[s\033[1;70H"     // Lưu vị trí, di chuyển đến góc phải
             << "[ " << t << " ]"      // In thời gian
             << "\033[u"               // Khôi phục vị trí
             << std::flush;

        // Cho luồng ngủ 1 giây
        this_thread::sleep_for(chrono::seconds(1));

        // Tăng thời gian thêm 1 giây (sử dụng toán tử ++)
        t++;
    }

    return 0;
}
