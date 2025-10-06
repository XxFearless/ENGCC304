#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int findMin(const vector<int>& arr) {
    int minVal = arr[0];
    for (int v : arr) {
        if (v < minVal)
            minVal = v;
    }
    return minVal;
}

int findMax(const vector<int>& arr) {
    int maxVal = arr[0];
    for (int v : arr) {
        if (v > maxVal)
            maxVal = v;
    }
    return maxVal;
}

int main() {
    string line;
    cout << "Enter value:\n";
    getline(cin, line);

    stringstream ss(line);
    vector<int> arr;
    int num;
    while (ss >> num) {
        arr.push_back(num);
    }

    // แสดง Index
    cout << "Index:  ";
    for (size_t i = 0; i < arr.size(); i++) {
        cout << i << "  ";
    }
    cout << "\n";

    // แสดง Array
    cout << "Array: ";
    for (int v : arr) {
        cout << v << " ";
    }
    cout << "\n\n";

    // หาค่า Min Max
    cout << "Min : " << findMin(arr) << "\n";
    cout << "Max : " << findMax(arr) << "\n";

    return 0;
}
