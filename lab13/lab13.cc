#include <iostream>
using namespace std;

// ฟังก์ชันสลับค่าโดยไม่ใช้ตัวแปรพักค่า
void swapNumbers(int *a, int *b) {
    // ใช้หลักการบวก-ลบ แทนการใช้ตัวแปรพัก
    *a = *a + *b; // a เก็บผลรวม
    *b = *a - *b; // b = (a+b)-b = a
    *a = *a - *b; // a = (a+b)-a(เก่า)=b
}

int main() {
    int num1, num2;

    cout << "Enter num1 : ";
    cin >> num1;
    cout << "Enter num2 : ";
    cin >> num2;

    // ประกาศ pointer ให้ชี้ไปยัง num1, num2
    int *ptr1 = &num1;
    int *ptr2 = &num2;

    cout << "Before swap (num1 & num2) : " << num1 << ", " << num2 << endl;

    // เรียกใช้ฟังก์ชัน swapNumbers โดยส่ง pointer เข้าไป
    swapNumbers(ptr1, ptr2);

    cout << "After swap (num1 & num2) : " << num1 << ", " << num2 << endl;

    return 0;
}
