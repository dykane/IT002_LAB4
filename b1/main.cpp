#include <iostream>
#include "sophuc.h"

using namespace std;

int main() {
    SoPhuc a, b;
    cout << "NHAP SO PHUC a: \n";
    cin >> a;
    cout << "NHAP SO PHUC b: \n";
    cin >> b;
    cout << "\nSo phuc a = " << a;
    cout << "\nSo phuc b = " << b << "\n";
    cout << "\nTong (a + b)  = " << (a + b);
    cout << "\nHieu (a - b)  = " << (a - b);
    cout << "\nTich (a * b)  = " << (a * b);
    cout << "\nThuong (a / b)= " << (a / b);
    if (a == b) cout << "\nKet qua: a giong b (a == b)";
    if (a != b) cout << "\nKet qua: a khac b (a != b)";
    return 0;
}
