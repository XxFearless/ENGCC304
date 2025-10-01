#include <iostream>
#include <cmath> // สำหรับ pow()
using namespace std;

// ฟังก์ชันตรวจสอบ Armstrong number
bool isArmstrong(int num) {
    int original = num;
    int count = 0;

    // นับจำนวนหลัก
    int temp = num;
    while (temp != 0) {
        temp /= 10;
        count++;
    }

    // คำนวณผลรวมของแต่ละหลักยกกำลัง count
    int sum = 0;
    temp = num;
    while (temp != 0) {
        int digit = temp % 10;
        sum += pow(digit, count);
        temp /= 10;
    }

    return sum == original;
}

int main() {
    int number;
    cout << "Enter Number: ";
    cin >> number;

    if (isArmstrong(number)) {
        cout << "Pass." << endl;
    } else {
        cout << "Not Pass." << endl;
    }

    return 0;
}
