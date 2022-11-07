//*****************************************************************************************************
//
//		File:					StudentList.cpp
//
//		Student:				Urban Shocker
//
//		Assignment:				Program #09
//
//		Course Name:			Data Structures II
//
//		Course Number:			COSC 3100-01
//
//		Due:					05/11/22
//
//
//		This program Creates the student data structure
//	
//		Other files required: 
//			1.	BST.h
//			2.	Student.h
//			
//*****************************************************************************************************

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

#include "Student.h"
#include "BST.h"

//*****************************************************************************************************

void buildList(BST<Student>& list);
char getChoice();
void process(BST<Student>&);
void addStudent(BST<Student>&);
void findStudent(BST<Student>&);
void removeStudent(BST<Student>&);
void updateStudent(BST<Student>&);
void printStudents(BST<Student>&);
void displayOneStu(Student);
void listInfo(BST<Student>&);

//*****************************************************************************************************

int main()
{
    BST<Student> StuList;

    buildList(StuList);
    process(StuList);

    return 0;
}

//*****************************************************************************************************

void buildList(BST<Student>& list)
{

    Student student;
    ifstream studentData("studentFile.txt");

    while (studentData >> student.id)
    {
        studentData.ignore();
        studentData.getline(student.name, 50);
        studentData.getline(student.citystate, 50);
        studentData >> student.phone
            >> student.gender
            >> student.year
            >> student.credits
            >> student.gpa
            >> student.major;

        list.insert(student);
    }

}

//*****************************************************************************************************

char getChoice()
{
    char choice;
    bool valid = false;

    cout << "========MENU =======\n"
        << "A: Add a student\n"
        << "S: Search for a student\n"
        << "U: Update a Student\n"
        << "D: Delete student\n"
        << "P: Print List\n"
        << "X: List Info\n"
        << "Q: Quit\n\n"
        << "Enter A choice: ";

    do
    {
        cin >> choice;
        choice = toupper(choice);
        switch (choice)
        {
        case'A': valid = true;
            break;
        case'S': valid = true;
            break;
        case'U': valid = true;
            break;
        case'D': valid = true;
            break;
        case'P': valid = true;
            break;
        case'X': valid = true;
            break;
        case'Q': valid = true;
            break;
        }
    } while (!valid);

    return choice;
}

//*****************************************************************************************************

void process(BST<Student>& list)
{
    char choice;

    do
    {
        choice = getChoice();

        switch (choice)
        {
        case'A': addStudent(list);
            break;
        case'S': findStudent(list);
            break;
        case'U': updateStudent(list);
            break;
        case'D': removeStudent(list);
            break;
        case'P': printStudents(list);
            break;
        case'X': listInfo(list);
            break;
        case'Q': break;
        }
    } while (choice != 'Q');

}

//*****************************************************************************************************

void addStudent(BST<Student>& list)
{
    Student student;

    cout << "Enter Student ID: ";
    cin >> student.id;
    cin.ignore();
    cout << "Enter Student Name: ";
    cin.getline(student.name, 50, '\n');
    cout << "Enter Student City and State: ";
    cin.getline(student.citystate, 50, '\n');
    cout << "Enter Student Phone: ";
    cin >> student.phone;
    cin.ignore();
    cout << "Enter Student Gender (M/F): ";
    cin >> student.gender;
    cin.ignore();
    cout << "Enter Student Year: ";
    cin >> student.year;
    cin.ignore();
    cout << "Enter Student Credits: ";
    cin >> student.credits;
    cin.ignore();
    cout << "Enter Student GPA: ";
    cin >> student.gpa;
    cin.ignore();
    cout << "Enter Student Major: ";
    cin >> student.major;
    cin.ignore();

    list.insert(student);

}

//*****************************************************************************************************

void findStudent(BST<Student>& list)
{
    Student student;
    bool found;

    cout << "Enter Student ID: ";
    cin >> student.id;
    cin.ignore();

    found = list.retrieve(student);

    if (found)
    {
        cout << "Student Found" << endl;
        cout << "ID" << setw(8) << "Name" << setw(24) << "GPA" << setw(8) << "Major" << endl;
        displayOneStu(student);
    }
    
}

//*****************************************************************************************************

void removeStudent(BST<Student>& list)
{
    Student student;
    bool found;

    cout << "Enter Student ID: ";
    cin >> student.id;
    cin.ignore();

    found = list.remove(student);

    if (found)
    {
        cout << "Student Removed" << endl;
        cout << "ID" << setw(8) << "Name" << setw(24) << "GPA" << setw(8) << "Major" << endl;
        displayOneStu(student);
    }
}

//*****************************************************************************************************

void updateStudent(BST<Student>& list)
{
    Student student;
    bool found;

    cout << "Enter Student ID: ";
    cin >> student.id;
    cin.ignore();
    cout << "Enter Student Name: ";
    cin.getline(student.name, 50, '\n');
    cout << "Enter Student City and State: ";
    cin.getline(student.citystate, 50, '\n');
    cout << "Enter Student Phone: ";
    cin >> student.phone;
    cin.ignore();
    cout << "Enter Student Gender (M/F): ";
    cin >> student.gender;
    cin.ignore();
    cout << "Enter Student Year: ";
    cin >> student.year;
    cin.ignore();
    cout << "Enter Student Credits: ";
    cin >> student.credits;
    cin.ignore();
    cout << "Enter Student GPA: ";
    cin >> student.gpa;
    cin.ignore();
    cout << "Enter Student Major: ";
    cin >> student.major;
    cin.ignore();

    found = list.update(student);

    if (found)
    {
        cout << "Student Updated" << endl;
        cout << "ID" << setw(8) << "Name" << setw(24) << "GPA" << setw(8) << "Major" << endl;
        displayOneStu(student);
    }

}

//*****************************************************************************************************

void printStudents(BST<Student>& list)
{
    cout << "ID" << setw(8) << "Name"  << setw(24) << "GPA" << setw(8) << "Major" << endl;
    list.inorderTraverse(displayOneStu);
}

//*****************************************************************************************************

void displayOneStu(Student out)
{
    cout << left << setw(6) << out.id << setw(25)  << out.name << setw(6) << fixed << setprecision(2) << out.gpa  << out.major << endl;
}

//*****************************************************************************************************

void listInfo(BST<Student>& list)
{
    bool empty;
    bool full;
    bool complete;
    bool balanced;

    empty = list.isEmpty();
    full = list.isFull();
    complete = list.isComplete();
    balanced = list.isBalanced();

    cout << "========Tree Info========" << endl;
    cout << left << setw(20) << "Number of students: " << list.getCount() << endl;
    cout << left << setw(20) << "Height of Tree: " << list.getHt() << endl;
    cout << left << setw(20) << "Empty: ";

    if (empty)
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
    cout << left << setw(20) << "Full: ";

    if (full)
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
    cout << left << setw(20) << "Complete: ";

    if (complete)
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
    cout << left << setw(20) << "Balanced: ";

    if (balanced)
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
    cout << "=========================" << endl << endl;
    
}

//*****************************************************************************************************

