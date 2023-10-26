#include <iostream>
using namespace std;

int main() {
	int n_students=3, n_subjects=5;
	int marks[n_students][n_subjects];
	string students[n_students];
	
	for (int i=0; i<n_students; i++) {
		cout << "Name of Student: ";
		cin >> students[i];
		cout << "Enter Marks in " << n_subjects << " Subjects: ";
		for (int j=0, a; j<n_subjects; j++) cin >> marks[i][j];
	}

	for (int i=0; i<n_students; i++) {
		int total_marks = 0;
		for (int j=0; j<n_subjects; j++) {
			total_marks += marks[i][j];
		}

		cout << "Total of " << students[i] << " = " << total_marks << endl;
	}

	for (int i=0; i<n_subjects; i++) {
		float average = 0;
		for (int j=0; j<n_students; j++) {
			average += (float) marks[j][i];
		}

		average /= (float) n_students;
		cout << "Average of Subject " << i << " = " << average << endl;
	}
}
