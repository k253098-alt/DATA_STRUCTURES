#include <iostream>
using namespace std;

int main() {

    int patientIDs[] = {101, 205, 101, 309, 405, 101, 205};
    int n = sizeof(patientIDs) / sizeof(patientIDs[0]);

    int target;
    cout << "Enter patient ID to search: ";
    cin >> target;

    int count = 0;
    int firstIndex = -1;
    int lastIndex = -1;

    for (int i = 0; i < n; i++) {

        if (patientIDs[i] == target) {

            count++;

            if (firstIndex == -1) {
                firstIndex = i;
            }

            lastIndex = i;
        }
    }

    if (count == 0) {
        cout << "Patient ID " << target << " does not exist." << endl;
    }
    else {
        cout << "Patient ID found." << endl;
        cout << "Number of occurrences: " << count << endl;
        cout << "First occurrence index: " << firstIndex << endl;
        cout << "Last occurrence index: " << lastIndex << endl;

        if (count > 1) {
            cout << "All occurrence indexes: ";

            for (int i = 0; i < n; i++) {
                if (patientIDs[i] == target) {
                    cout << i << " ";
                }
            }

            cout << endl;
        }
    }

    return 0;
}