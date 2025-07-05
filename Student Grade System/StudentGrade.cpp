#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student{
private:
    string studentName;
    vector<double>marks;
    double avg;
    char grade;

public:
    void inputData(){
        cout << "\nEnter the name of the student: " << "\n";
        cin.ignore();
        getline(cin, studentName);

        int num_of_subjects;
        cout << "Enter the number of subjects: " << "\n";
        cin >> num_of_subjects;

        marks.resize(num_of_subjects);

        cout << "Enter the marks for " << num_of_subjects << " subjects: " << "\n";
        for(int i=0; i< num_of_subjects; i++){
            cout << "Subject " << i+1 << ": ";
            cin >> marks[i];
        }

        calculateAvg();
        assignGrade();
    }

    void calculateAvg(){
        double sum = 0;
        for (double mark : marks){
            sum += mark;
        }
        avg = marks.empty() ? 0 : sum / marks.size();
    }

    void assignGrade(){
        if (avg >= 90){
            grade = 'A';
        } else if (avg >= 80){
            grade = 'B';
        } else if (avg >= 70){
            grade = 'C';
        } else if (avg >= 60){
            grade = 'D';
        } else if (avg >= 50){
            grade = 'E';
        } else if (avg >= 40){
            grade = 'F';
        } else {
            grade = 'X';
        }
    }

    void displayData() const{
        cout << "Name: " << studentName << "\n";
        cout << "Marks: ";
        for (double mark : marks){
            cout << mark << " ";
        }
        cout << "Average: " << avg << "\n";
        cout << "Grade: " << grade << "\n";
    }
};

int main(){
    cout << "\nHello Students and welcome to the Student Grading Application" << "\n";
    cout << "In this app, you can find out what grade you are going to get" << "\n";

    int numofstudents;

    cout << "Enter the number of students: " << "\n";
    cin >> numofstudents;

    vector<Student> students(numofstudents);

    for (int i = 0; i< numofstudents; i++){
        cout << "\n--- Student " << i+1 << " ---";
        students[i].inputData();
    }

    cout << "\n---- Student Report -----" << "\n";
    for (int i = 0; i< numofstudents; i++){
        students[i].displayData();
    }

    return 0;
}