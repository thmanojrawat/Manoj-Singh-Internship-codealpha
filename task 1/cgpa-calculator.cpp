#include <iostream>
using namespace std;

int main() {
    int numSubjects;
    float totalGradePoints = 0, totalCredits = 0;
    
    cout << "Enter the number of subjects: ";
    cin >> numSubjects;

    for (int i = 1; i <= numSubjects; i++) {
        float gradePoint, credits;

        cout << "Enter the grade point for subject " << i << ": ";
        cin >> gradePoint;

        cout << "Enter the credit hours for subject " << i << ": ";
        cin >> credits;

        totalGradePoints += gradePoint * credits;
        totalCredits += credits;
    }

    float cgpa = totalGradePoints / totalCredits;
    cout << "Your CGPA is: " << cgpa << endl;

    return 0;
}