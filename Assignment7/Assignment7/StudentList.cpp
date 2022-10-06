//*****************************************************************************************************
//
//		File:					StudentList.cpp
//
//		Student:				Urban Shocker
//
//		Assignment:				Program #08
//
//		Course Name:			Data Structures II
//
//		Course Number:			COSC 3100-01
//
//		Due:					06/10/22
//
//
//		This program Creates the student data structure
//	
//		Other files required: 
//			1.	Node.h
//			2.	Student.h
//          3.  Hashtable.h
//			
//*****************************************************************************************************

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

#include "Hashtable.h"
#include "Student.h"

//*****************************************************************************************************

void process(Hashtable<Student>&);
char getChoice();
void buildList(Hashtable<Student>&);
void displayStudents(Hashtable<Student>&);
void printStudents(Hashtable<Student>&);
void addStudent(Hashtable<Student>&);
void findStudent(Hashtable<Student>&);
void removeStudent(Hashtable<Student>&);
void displayStatisitics(Hashtable<Student>&);

//*****************************************************************************************************

int main()
{
    Hashtable<Student> stuList(61);

    buildList(stuList);
    process(stuList);

    
    return 0;
}

//*****************************************************************************************************

void process(Hashtable<Student>& list)
{
    char choice;

    do
    {
        choice = getChoice();

        switch (choice)
        {
        case'A': addStudent(list);
            break;
        case'F': findStudent(list);
            break;
        case'R': removeStudent(list);
            break;
        case'S': displayStatisitics(list);
            break;
        case'D': displayStudents(list);
            break;
        case'P': printStudents(list);
            break;
        case'Q': break;
        }
    } while (choice != 'Q');

}

//*****************************************************************************************************

char getChoice()
{
    char choice;
    bool valid = false;

    cout << "========MENU =======\n"
        << "A: Add a student\n"
        << "F: Find a student\n"
        << "R: Remove student\n"
        << "S: Display stats\n"
        << "D: Display table\n"
        << "P: Print to file\n"
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
        case'F': valid = true;
            break;
        case'R': valid = true;
            break;
        case'S': valid = true;
            break;
        case'D': valid = true;
            break;
        case'P': valid = true;
            break;
        case'Q': valid = true;
            break;
        }
    } 
    while (!valid);

    return choice;
}

//*****************************************************************************************************

void buildList(Hashtable<Student>& list)
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

void displayStudents(Hashtable<Student>& list)
{
    list.displayTable();
}

//*****************************************************************************************************

void printStudents(Hashtable<Student>& list)
{
    list.writeFile();
}

//*****************************************************************************************************

void addStudent(Hashtable<Student>& list)
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
// Unsure of what you wanted us to do with the found studnt
// there was no info on the handout as to what this function
// is supposed to do
void findStudent(Hashtable<Student>&list) 
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
    }
    else
    {
        cout << "Student not Found" << endl;
    }
}

//*****************************************************************************************************
// Unsure of what you wanted us to do with the removed studnt
// there was no info on the handout as to what this function
// is supposed to do
void removeStudent(Hashtable<Student>& list)
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
    }
    else
    {
        cout << "Student not Removed" << endl;
    }
}

//*****************************************************************************************************

void displayStatisitics(Hashtable<Student>& list)
{
    bool empty;

    list.statistics();
    empty = list.isEmpty();

    if (empty)
    {
        cout << endl << "Table is empty" << endl << endl;
    }
    else
    {
        cout << endl << "Table is not empty" << endl << endl;
    }
}

//*****************************************************************************************************
//Output

/*

Table size:             67
Number of Elements:     61
Empty Positions:        28
Num.of Chains:          17
Max Chain Length:        4
Num. of Collisions:     22
Avg.Chain Length:        1.3%
Percentage Collisions:  36.1%
Load Factor:            58.2%
Avg# Search Steps:       1.508

*/