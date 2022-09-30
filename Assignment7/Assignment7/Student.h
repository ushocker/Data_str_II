//*****************************************************************************************************
//
//		File:					Student.h
//
//		Student:				Urban Shocker
//
//		Assignment:				Program #07
//
//		Course Name:			Data Structures II
//
//		Course Number:			COSC 3100-01
//
//		Due:					22/09/22
//
//
//		This program Creates the student data structure
//	
//		Other files required: 
//			1.	Node.h
//			2.	StudentList.cpp
//          3.  Hashtable.h
//			
//*****************************************************************************************************


#ifndef STUDENT_H
#define STUDENT_H

struct Student
{
	int id;
	char name[50];
	char citystate[50];
	char phone[12];
	char gender;
	int year;
	int credits;
	float gpa;
	char major[6];

	Student();
	friend ostream & operator << (ostream & out, const Student& data);
	bool operator == (const Student& rhs) const;
	bool operator == (int value) const;
	bool operator != (const Student& rhs) const;
	bool operator != (int value) const;
	bool operator < (const Student& rhs) const;
	bool operator < (int value) const;
	bool operator <= (const Student& rhs) const;
	bool operator <= (int value) const;
	bool operator > (const Student& rhs) const;
	bool operator > (int value) const;
	bool operator >= (const Student& rhs) const;
	bool operator >= (int value) const;
	int operator % (int value) const;
	Student& operator = (int value);
};

//*****************************************************************************************************

ostream& operator << (ostream& out, const Student& data)
{
	out << setw(5) << data.id << "/";
	for (int i = 0; i < 6; i++)
	{
		out << data.name[i];
	}
	
	return out;
}

//*****************************************************************************************************

Student::Student()
{
	id = 0;
}

//*****************************************************************************************************

bool Student::operator == (const Student& rhs) const
{
	return this->id == rhs.id;
}

//*****************************************************************************************************

bool Student::operator == (int value) const
{
	return this->id == value;
}

//*****************************************************************************************************

bool Student::operator != (const Student& rhs) const
{
	return this->id != rhs.id;
}

//*****************************************************************************************************

bool Student::operator != (int value) const
{
	return this->id != value;
}

//*****************************************************************************************************

bool Student::operator < (const Student& rhs) const
{
	return this->id < rhs.id;
}

//*****************************************************************************************************

bool Student::operator < (int value) const
{
	return this->id < value;
}

//*****************************************************************************************************

bool Student::operator<=(const Student& rhs) const
{
	return this->id <= rhs.id;
}

//*****************************************************************************************************

bool Student::operator<=(int value) const
{
	return this->id <= value;
}

//*****************************************************************************************************

bool Student::operator>(const Student& rhs) const
{
	return this->id > rhs.id;
}

//*****************************************************************************************************

bool Student::operator>(int value) const
{
	return this->id > value;
}

//*****************************************************************************************************

bool Student::operator>=(const Student& rhs) const
{
	return this->id >= rhs.id;
}

//*****************************************************************************************************

bool Student::operator>=(int value) const
{
	return this->id >= value;
}

//*****************************************************************************************************

int Student::operator % (int value) const
{
	return this->id % value;
}

//*****************************************************************************************************

Student& Student::operator=(int value)
{
	this->id = value;
	return * this;
}

#endif // !STUDENT_H
