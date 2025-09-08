#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;

int main() {
    int choice;
    int guess, score, target;
    int lower, upper;

    srand(time(NULL)); // random ตามเวลา

    while (true) {
        cout << "Do you want to play game (1=play,-1=exit) :" << endl;
        if (!(cin >> choice)) {
            // ถ้า input ไม่ใช่ตัวเลข
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nPlease enter only 1 or -1.\n" << endl;
            continue;
        }

        if (choice == -1) {
            cout << "\nSee you again." << endl;
            break;
        } else if (choice == 1) {
            score = 100;
            target = rand() % 100 + 1;
            // target = 42;   // 🔹 uncomment ตรงนี้ถ้าต้องการ Fix ค่า test case

            lower = 1;
            upper = 100;

            cout << "\n(Score=100)\n" << endl;

            while (true) {
                cout << "Guess the winning number (" << lower << "-" << upper << ") :" << endl;
                if (!(cin >> guess)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "\nPlease enter only number between " 
                         << lower << " and " << upper << ".\n" << endl;
                    continue;
                }

                if (guess == target) {
                    cout << "\nThat is correct! The winning number is " << target << "." << endl;
                    cout << "\nScore this game: " << score << "\n" << endl;
                    break;
                } else {
                    score -= 10;
                    if (score < 0) score = 0;

                    if (guess < target) {
                        cout << "\nSorry, the winning number is HIGHER than " << guess 
                             << ". (Score=" << score << ")\n" << endl;
                        if (guess + 1 > lower) lower = guess + 1;
                    } else {
                        cout << "\nSorry, the winning number is LOWER than " << guess 
                             << ". (Score=" << score << ")\n" << endl;
                        if (guess - 1 < upper) upper = guess - 1;
                    }
                }
            }
        } else {
            cout << "\nPlease enter only 1 or -1.\n" << endl;
        }
    }

    return 0;
}
