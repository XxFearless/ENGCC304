#include <iostream>
using namespace std;

int main() {
    int arr[] = {15, 7, 25, 3, 73, 32, 45};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Old Series : ";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i != n - 1) cout << ", ";
    }
    cout << endl;

    // จัดเรียงจากน้อยไปมาก (bubble sort)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    cout << "New Series : ";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i != n - 1) cout << ", ";
    }
    cout << endl;

    // หาตำแหน่งของเลข 32 (นับ index เริ่ม 0)
    int pos = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 32) {
            pos = i; // ได้ index
            break;
        }
    }

    // แสดงตำแหน่ง (โจทย์นับจาก 0 หรือ 1?)
    // จากโจทย์ Output: Pos of 32 : 4
    // ซึ่งนับ index เริ่มจาก 0 → ตรงตาม i เลย
    cout << "Pos of 32 : " << pos << endl;

    return 0;
}
