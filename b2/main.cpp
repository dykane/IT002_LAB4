#include <iostream>
#include "phanso.h"

using namespace std;

int main() {
    Phanso a, b;

    cout << "Nhap phan so a (dang a/b): ";
    cin >> a;
    cout << "Nhap phan so b (dang a/b): ";
    cin >> b;
    cout << "\nPhan so a: " << a;
    cout << "\nPhan so b: " << b;
    cout << "\nTong (a + b):   " << (a + b);
    cout << "\nHieu (a - b):   " << (a - b);
    cout << "\nTich (a * b):   " << (a * b);
    cout << "\nThuong (a / b): " << (a / b);
    if (a == b) cout << "\na bang b";
    else if (a > b) cout << "\na lon hon b";
    else cout << "\na nho hon b";

    return 0;
}
