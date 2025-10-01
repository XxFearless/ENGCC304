#include <iostream>
#include <iomanip>   // สำหรับ setprecision
#include <string>
#include <limits>    // สำหรับ numeric_limits
using namespace std;

struct Student {
    char Name[50];   // เผื่อชื่อยาวขึ้น
    char ID[10];     // เผื่อไอดียาวขึ้น
    float ScoreSub1;
    float ScoreSub2;
    float ScoreSub3;
    float ScoreSub4;
    float ScoreSub5;
} typedef S;

// ฟังก์ชันตัดเกรดตามคะแนน
string getGrade(float score) {
    if (score >= 80) return "A";
    else if (score >= 75) return "B+";
    else if (score >= 70) return "B";
    else if (score >= 65) return "C+";
    else if (score >= 60) return "C";
    else if (score >= 55) return "D+";
    else if (score >= 50) return "D";
    else return "F";
}

// ฟังก์ชันคำนวณคะแนนเฉลี่ย
float calcAverage(const S &st) {
    return (st.ScoreSub1 + st.ScoreSub2 + st.ScoreSub3 + st.ScoreSub4 + st.ScoreSub5) / 5.0f;
}

int main() {
    S students[3];

    cout << "Enter the details of 3 students :" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "\nStudent " << i + 1 << ":" << endl;

        // ล้างบัฟเฟอร์ก่อนรับชื่อครั้งแรก หรือหลังรับตัวเลข
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Name: " << endl;
        cin.getline(students[i].Name, 50);

        cout << "ID: " << endl;
        cin.getline(students[i].ID, 10);

        cout << "Scores in Subject 1: " << endl;
        cin >> students[i].ScoreSub1;
        cout << "Scores in Subject 2: " << endl;
        cin >> students[i].ScoreSub2;
        cout << "Scores in Subject 3: " << endl;
        cin >> students[i].ScoreSub3;
        cout << "Scores in Subject 4: " << endl;
        cin >> students[i].ScoreSub4;
        cout << "Scores in Subject 5: " << endl;
        cin >> students[i].ScoreSub5;
    }

    // แสดงผล
    for (int i = 0; i < 3; i++) {
        cout << "\nStudent " << i + 1 << ":" << endl;
        cout << "Name: " << students[i].Name << endl;
        cout << "ID: " << students[i].ID << endl;

        cout << "Scores: "
             << students[i].ScoreSub1 << " "
             << students[i].ScoreSub2 << " "
             << students[i].ScoreSub3 << " "
             << students[i].ScoreSub4 << " "
             << students[i].ScoreSub5 << endl;

        cout << "Grades: "
             << getGrade(students[i].ScoreSub1) << " "
             << getGrade(students[i].ScoreSub2) << " "
             << getGrade(students[i].ScoreSub3) << " "
             << getGrade(students[i].ScoreSub4) << " "
             << getGrade(students[i].ScoreSub5) << endl;

        float avg = calcAverage(students[i]);
        cout << fixed << setprecision(1); // ให้ทศนิยม 1 ตำแหน่ง
        cout << "Average Scores: " << avg << endl;
    }

    return 0;
}