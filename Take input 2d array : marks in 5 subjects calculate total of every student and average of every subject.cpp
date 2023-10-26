#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int numStudents = 3; // You can change this to the number of students you have.
    int numSubjects = 5; // You can change this to the number of subjects.

    int marks[numStudents][numSubjects];

    // Input marks for each student in each subject
    for (int i = 0; i < numStudents; i++) {
        cout << "Enter marks for Student " << i + 1 << ": ";
        for (int j = 0; j < numSubjects; j++) {
            cin >> marks[i][j];
        }
    }

    // Calculate total marks for each student and average marks for each subject
    int total[numStudents] = {0};
    double average[numSubjects] = {0};

    for (int i = 0; i < numStudents; i++) {
        for (int j = 0; j < numSubjects; j++) {
            total[i] += marks[i][j];
            average[j] += marks[i][j];
        }
    }

    // Calculate the averages
    for (int j = 0; j < numSubjects; j++) {
        average[j] /= numStudents;
    }

    // Display the results
    cout << "Total marks for each student: ";
    for (int i = 0; i < numStudents; i++) {
        cout << "Student " << i + 1 << ": " << total[i] << " ";
    }

    cout << "\nAverage marks for each subject: ";
    for (int j = 0; j < numSubjects; j++) {
        cout << "Subject " << j + 1 << ": " << fixed << setprecision(2) << average[j] << " ";
    }

    return 0;
}
