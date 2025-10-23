#include <iostream>
#include <iomanip>
using namespace std;

struct Subject{
    string name;
    int credit;
    double mark;
    char grade;
};

struct Student{
    string name;
    Subject subjects[5];
    int age, subjectCount;
    double cpa;
};

char calculateGrade(double mark){
    if(mark >= 80){
        return 'A';
    }
    else if(mark >= 70){
        return 'B';
    }
    else if(mark >= 60){
        return 'C';
    }
    else if(mark >= 50){
        return 'D';
    }
    else if(mark >= 40){
        return 'E';
    }
    else{
        return 'F';
    }
}

double calculateCPA(Student &student){
    double totalPoints = 0;
    int totalCredits = 0;

    for(int i = 0; i < student.subjectCount; i++){
        int points = 0;

        switch(student.subjects[i].grade){
            case 'A':{
                points = 4;
                break;
            }
            case 'B':{
                points = 3;
                break;
            }
            case 'C':{
                points = 2;
                break;
            }
            case 'D':{
                points = 1;
                break;
            }
            default:{
                points = 0;
                break;
            }
        }
        totalPoints += points * student.subjects[i].credit;
        totalCredits += student.subjects[i].credit;
    }
    if(totalCredits == 0){ return 0; }
    return totalPoints / totalCredits;
}

void displayStudentInfo(Student &student){
    cout << "Student Name: " << student.name << endl;
    cout << "Age: " << student.age << endl;
    cout << "Subjects: " << endl;
    for(int i = 0; i < student.subjectCount; i++){
        cout << (i + 1) << ". " << student.subjects[i].name 
        << ", Credit: " << student.subjects[i].credit 
        << ", Mark: " << student.subjects[i].mark << ", Grade: " 
        << student.subjects[i].grade << endl;
    }
    cout << "CPA: " << fixed << setprecision(2) << student.cpa << endl;
}

int main(){
    int studentIndex;
    int studentCount = 0;
    char choice;
    Student students[10];

    cout << "Enter the number of students (max 10): ";
    cin >> studentCount;

    while(studentCount <= 0 || studentCount > 10){
        cout << "ERROR: Number of students must be between 1 to 10." << endl;
        cout << "Enter again: ";
        cin >> studentCount;
    }

    for(int i = 0; i < studentCount; i++){
        cout << "Enter student " << (i + 1) << " name: ";
        cin.ignore();
        getline(cin, students[i].name);

        cout << "Enter student " << (i + 1) << " age: ";
        cin >> students[i].age;

        students[i].subjectCount = 0;
        students[i].cpa = 0;
    }
        cout << "Student info added succesfully." << endl;

    do{
        cout << "-----------------------------" << endl;
        cout << "Pls enter your choice." << endl;
        cout << "1. Add subject info" << endl;
        cout << "2. Display student info" << endl;
        cout << "3. Exit" << endl;
        cout << "Your choice: ";
        cin >> choice;

        switch(choice){
            case 1:{
                cout << "Enter student number (1 to " << studentCount << "): ";
                cin >> studentIndex;

                while(studentIndex < 1 || studentIndex > studentCount){
                    cout << "ERROR: Invalid student number. Pls enter only number 1 to "
                    << studentCount << "." << endl;
                    cout << "Enter again: ";
                    cin >> studentIndex;
                }

                Student &student = students[studentIndex - 1];

                if(student.subjectCount >= 5){
                    cout << "This student has maximum subjects." << endl;
                    break;
                }

                Subject &subject = student.subjects[student.subjectCount];

                cout << "Enter subject name: ";
                cin >> subject.name;

                cout << "Enter subject credit: ";
                cin >> subject.credit;

                do{
                    cout << "Enter subject mark: ";
                    cin >> subject.mark;
                } while(subject.mark < 0 || subject.mark > 100);

                students[studentIndex - 1].subjects[student.subjectCount].mark = subject.mark;
                students[studentIndex - 1].subjects[student.subjectCount].grade 
                = calculateGrade(subject.mark);
                student.subjectCount++;
                student.cpa = calculateCPA(student);

                cout << "Subject added succesfully." << endl;
                break;
            }

            case 2:{
                do{
                    cout << "Enter student number to display info (1 to"
                    << studentCount << "): ";
                    cin >> studentIndex;

                    if(studentIndex < 1 || studentIndex > studentCount){
                        cout << "ERROR: Invalid student number. Pls enter only number 1 to"
                        << studentCount << "): " << endl;
                    }
                    
                }while(studentIndex < 1 || studentIndex > studentCount);

                displayStudentInfo(students[studentIndex - 1]);
                break;
            }
        }

    }while(choice != 3);

    return 0;
}