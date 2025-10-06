#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int countWordsInFile(const string &filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Cannot open file: " << filename << endl;
        return 0;
    }

    int count = 0;
    string word;
    // ใช้ stringstream เพื่ออ่านเป็นคำ ๆ 
    while (file >> word) {
        count++;
    }

    return count;
}

int main() {
    string filename;
    cout << "Enter file name:\n";
    cin >> filename;

    int totalWords = countWordsInFile(filename);
    cout << "Total number of words in '" << filename << "' : " << totalWords << " words" << endl;

    return 0;
}
