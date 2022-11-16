//*****************************************************************************************************
//
//		File:					customer.h
//
//		Customer:				Urban Shocker
//
//		Assignment:				Program #10
//
//		Course Name:			Data Structures II
//
//		Course Number:			COSC 3100-01
//
//		Due:					16/11/22
//
//
//		This program Creates the Customer data structure.
//	
//		Other files required: 
//			1.	Heap.h
//			2.	waitlist.cpp
//			
//*****************************************************************************************************

#ifndef CUSTOMER_H
#define CUSTOMER_H

//*****************************************************************************************************

struct Customer
{
	char fname[15];
	char lname[15];
	int mileage;
	int years;
	int arrivalNum;
	int Priority;

	Customer();
	friend ostream & operator << (ostream & out, const Customer& data);
	bool operator == (const Customer& rhs) const;
	bool operator == (int value) const;
	bool operator != (const Customer& rhs) const;
	bool operator != (int value) const;
	bool operator < (const Customer& rhs) const;
	bool operator < (int value) const;
	bool operator <= (const Customer& rhs) const;
	bool operator <= (int value) const;
	bool operator > (const Customer& rhs) const;
	bool operator > (int value) const;
	bool operator >= (const Customer& rhs) const;
	bool operator >= (int value) const;
	int operator % (int value) const;
	Customer& operator = (int value);
};

//*****************************************************************************************************

ostream& operator << (ostream& out, const Customer& data)
{

	out<< left << setw(16) << data.lname << setw(16) << data.fname << setw(8) << data.arrivalNum << data.Priority;
	
	return out;
}

//*****************************************************************************************************

Customer::Customer()
{
	Priority = 0;
}

//*****************************************************************************************************

bool Customer::operator == (const Customer& rhs) const
{
	return this->Priority == rhs.Priority;
}

//*****************************************************************************************************

bool Customer::operator == (int value) const
{
	return this->Priority == value;
}

//*****************************************************************************************************

bool Customer::operator != (const Customer& rhs) const
{
	return this->Priority != rhs.Priority;
}

//*****************************************************************************************************

bool Customer::operator != (int value) const
{
	return this->Priority != value;
}

//*****************************************************************************************************

bool Customer::operator < (const Customer& rhs) const
{
	return this->Priority < rhs.Priority;
}

//*****************************************************************************************************

bool Customer::operator < (int value) const
{
	return this->Priority < value;
}

//*****************************************************************************************************

bool Customer::operator<=(const Customer& rhs) const
{
	return this->Priority <= rhs.Priority;
}

//*****************************************************************************************************

bool Customer::operator<=(int value) const
{
	return this->Priority <= value;
}

//*****************************************************************************************************

bool Customer::operator>(const Customer& rhs) const
{
	return this->Priority > rhs.Priority;
}

//*****************************************************************************************************

bool Customer::operator>(int value) const
{
	return this->Priority > value;
}

//*****************************************************************************************************

bool Customer::operator>=(const Customer& rhs) const
{
	return this->Priority >= rhs.Priority;
}

//*****************************************************************************************************

bool Customer::operator>=(int value) const
{
	return this->Priority >= value;
}

//*****************************************************************************************************

int Customer::operator % (int value) const
{
	return this->Priority % value;
}

//*****************************************************************************************************

Customer& Customer::operator=(int value)
{
	this->Priority = value;
	return * this;
}

//*****************************************************************************************************
#endif // !Customer_H
