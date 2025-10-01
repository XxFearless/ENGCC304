#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string word;
    cout << "Enter word: ";
    getline(cin, word); // รับทั้งบรรทัด (จะได้ใช้กับวลีได้ด้วย)

    // แปลงให้เป็นตัวพิมพ์เล็กทั้งหมด
    string lowerWord = word;
    transform(lowerWord.begin(), lowerWord.end(), lowerWord.begin(), ::tolower);

    // เอาเฉพาะตัวอักษร (ถ้าอยากเช็คเฉพาะตัวอักษร)
    string filtered = "";
    for (char c : lowerWord) {
        if (isalnum(static_cast<unsigned char>(c))) { // ตัวอักษรหรือตัวเลข
            filtered += c;
        }
    }

    // ตรวจสอบ palindrome
    string reversed = filtered;
    reverse(reversed.begin(), reversed.end());

    if (filtered == reversed) {
        cout << "Pass." << endl;
    } else {
        cout << "Not Pass." << endl;
    }

    return 0;
}
