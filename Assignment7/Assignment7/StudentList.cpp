
#include <iostream>
#include <fstream>

using namespace std;

#include "Hashtable.h"
#include "Student.h"

void process(Hashtable<Student>&);
char getChoice();
void buildList(Hashtable<Student>&);
void displayStudents(Hashtable<Student>&);
void printStudents(Hashtable<Student>&);
void addStudent(Hashtable<Student>&);
void findStudent(Hashtable<Student>&);
void removeStudent(Hashtable<Student>&);
void displayStatisitics(Hashtable<Student>&);

int main()
{
    Hashtable<Student> test(61);

    buildList(test);
    process(test);

    

}

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
        case'D': list.displayTable();//displayStudents(list);
            break;
        case'P': printStudents(list);
            break;
        case'Q': break;
        }
    } while (choice != 'Q');

}

char getChoice()
{
    char choice;
    bool valid = false;

    cout << "========MENU =======\n"
        //<< "A: Add a student\n"
        //<< "F: Find a student\n"
        //<< "R: Remove student\n"
        //<< "S: Display stats\n"
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

void displayStudents(Hashtable<Student>&)
{
}

void printStudents(Hashtable<Student>&)
{
}

void addStudent(Hashtable<Student>&)
{
}

void findStudent(Hashtable<Student>&)
{
}

void removeStudent(Hashtable<Student>&)
{
}

void displayStatisitics(Hashtable<Student>&)
{
}
