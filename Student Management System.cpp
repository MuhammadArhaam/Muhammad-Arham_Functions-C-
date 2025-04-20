#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void addStudent() 
{
    ofstream studentsfile1;
    studentsfile1.open("students.txt", ios::app);
    string name, rollNo, dept;
    float gpa;
    cout << "Enter Name= ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Roll Number= ";
    getline(cin, rollNo);
    cout << "Enter Department= ";
    getline(cin, dept);
    cout << "Enter GPA= ";
    cin >> gpa;
    studentsfile1 << name << "," << rollNo << "," << dept << "," << gpa << endl;
    studentsfile1.close();
    cout << "Student record added successfully!" << endl;
}
void viewAllStudents()
{
    ifstream studentsfile2;
    studentsfile2.open("students.txt");
    string name, rollNo, dept, gpaStr;
    float gpa;
    cout << endl;
    cout << "Name\t\tRoll No\t\tDepartment\t\tGPA" << endl;
    cout << endl;
    while (getline(studentsfile2, name, ','))
    {
        getline(studentsfile2, rollNo, ',');
        getline(studentsfile2, dept, ',');
        getline(studentsfile2, gpaStr);
        gpa = stof(gpaStr);
        cout << name << "\t" << rollNo << "\t" << dept << "\t" << gpa << endl;
    }
    studentsfile2.close();
}
void searchStudent()
{
    ifstream studentsfile2;
    studentsfile2.open("students.txt");
    string searchRoll, name, rollNo, dept, gpaStr;
    float gpa;
    bool found = false;

    cout << "Enter Roll Number to search= ";
    cin.ignore();
    getline(cin, searchRoll);

    while (getline(studentsfile2, name, ',')) {
        getline(studentsfile2, rollNo, ',');
        getline(studentsfile2, dept, ',');
        getline(studentsfile2, gpaStr);
        gpa = stof(gpaStr);
        if (rollNo == searchRoll)
        {
            cout << endl;
            cout << "Student Found " << endl;
            cout << "Name= " << name << endl;
            cout << "Roll No= " << rollNo << endl;
            cout << "Department= " << dept << endl;
            cout << "GPA= " << gpa << endl;
            found = true;
            break;
        }
    }
    if (!found)
        cout << "Student with Roll Number " << searchRoll << " not found" << endl;
    studentsfile2.close();
}
void updateGPA()
{
    ifstream studentsfile2("students.txt");
    ofstream tempfile("temp.txt");
    string name, rollNo, dept, gpaStr, searchRoll;
    float gpa, newGPA;
    bool found = false;
    cout << "Enter Roll Number to update GPA= ";
    cin.ignore();
    getline(cin, searchRoll);
    while (getline(studentsfile2, name, ',')) {
        getline(studentsfile2, rollNo, ',');
        getline(studentsfile2, dept, ',');
        getline(studentsfile2, gpaStr);
        gpa = stof(gpaStr);
        if (rollNo == searchRoll) 
        {
            cout << "Enter new GPA= ";
            cin >> newGPA;
            tempfile << name << "," << rollNo << "," << dept << "," << newGPA << endl;
            found = true;
        }
        else {
            tempfile << name << "," << rollNo << "," << dept << "," << gpa << endl;
        }
    }
    studentsfile2.close();
    tempfile.close();
    remove("students.txt");
    rename("temp.txt", "students.txt");
    if (found) 
    {
        cout << "GPA updated successfully" << endl;
    }
    else
    {
        cout << "Student with Roll Number " << searchRoll << " not found" << endl;
    }
}
void deleteStudent() 
{
    ifstream studentsfile2("students.txt");
    ofstream tempfile("temp.txt");
    string name, rollNo, dept, gpaStr, searchRoll;
    float gpa;
    bool found = false;
    cout << "Enter Roll Number to delete: ";
    cin.ignore();
    getline(cin, searchRoll);
    while (getline(studentsfile2, name, ',')) {
        getline(studentsfile2, rollNo, ',');
        getline(studentsfile2, dept, ',');
        getline(studentsfile2, gpaStr);
        gpa = stof(gpaStr); 
        if (rollNo == searchRoll) 
        {
            found = true;
            continue;
        }
        tempfile << name << "," << rollNo << "," << dept << "," << gpa << endl;
    }
    studentsfile2.close();
    tempfile.close();
    remove("students.txt");
    rename("temp.txt", "students.txt");
    if (found)
    {
        cout << "Student deleted successfully" << endl;
    }
    else
    {
        cout << "Student with Roll Number " << searchRoll << " not found" << endl;
    }
}
int main() 
{
    int choice;
    do 
    {
        cout << endl;
        cout << "Student Management System" << endl;
        cout << "1. Add Student Record" << endl;
        cout << "2. View All Student Records" << endl;
        cout << "3. Search Student by Roll Number" << endl;
        cout << "4. Update Student GPA" << endl;;
        cout << "5. Delete Student Record" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1: 
            addStudent();
            break;
        case 2: 
            viewAllStudents(); 
            break;
        case 3: 
            searchStudent(); 
            break;
        case 4: 
            updateGPA(); 
            break;
        case 5: 
            deleteStudent(); 
            break;
        case 0: 
            cout << "Exiting" << endl;
            break;
        default: 
            cout << "Invalid choice. Try again" << endl;
        }
    } 
    while (choice != 0);
    return 0;
}