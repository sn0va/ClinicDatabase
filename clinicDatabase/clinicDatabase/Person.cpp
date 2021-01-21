#include "Person.h"

Person::Person()
{
	//default constructor
	fName_ = "NO FNAME";
	lName_ = "NO LNAME";
	stAddress_ = "NO ADDR.";
	zipCode_ = 0;
	city_ = "NO CITY";
	dayBirth_ = 0;
	monthBirth_ = 0;
	yearBirth_ = 0;
	SSN_ = 0;
	gender_ = "NO GENDER";
}
Person::Person(string fN, string lN, string stAddr, int zipC, string City, int dayB, int monthB, int yearB, int ssn, string gender) 
{
	// Parametrized Constructor
	fName_ = fN;
	lName_ = lN;
	stAddress_ = stAddr;
	zipCode_ = zipC;
	city_ = City;
	dayBirth_ = dayB;
	monthBirth_ = monthB;
	yearBirth_ = yearB;
	SSN_ = ssn;
	gender_ = gender;
}
string Person::getFName() 
{
	// Acccessor for first name
	return fName_;
}
string Person::getLName() 
{
	// Acccessor for last name
	return lName_;
}
string Person::getStAddress() 
{
	// Acccessor for street address
	return stAddress_;
}
int Person::getZipCode() 
{
	// Acccessor for zip code
	return zipCode_;
}
string Person::getCity() 
{
	// Acccessor for city_
	return city_;
}
int Person::getDayBirth() 
{
	// Acccessor for day of birth
	return dayBirth_;
}
int Person::getMonthBirth() 
{
	// Acccessor for month of birth
	return monthBirth_;
}
int Person::getYearBirth() 
{
	// Acccessor for year of birth
	return yearBirth_;
}
int Person::getSSN() 
{
	// Acccessor for ssn
	return SSN_;
}
string Person::getGender() 
{
	// Acccessor for gender_
	return gender_;
}
void Person::setFName(string fN) 
{
	// Modifier for first name
	fName_ = fN;
}
void Person::setLName(string lN) 
{
	// Modifier for last name
	lName_ = lN;
}
void Person::setStAddress(string stAddr) 
{
	// Modifier for Street Address
	stAddress_ = stAddr;
}
void Person::setZipCode(int zipC) 
{
	// Modifier for Zip code
	zipCode_ = zipC;
}
void Person::setCity(string City) 
{
	// Modifier for City
	city_ = City;
}
void Person::setDayBirth(int dayB) 
{
	// Modifier for Day of birth
	dayBirth_ = dayB;
}
void Person::setMonthBirth(int monthB) 
{
	// Modifier for month of birth
	monthBirth_ = monthB;
}
void Person::setYearBirth(int yearB) 
{
	// Modifier for year of birth
	yearBirth_ = yearB;
}
void Person::setSSN(int ssn) 
{
	// Modifier for ssn
	SSN_ = ssn;
}
void Person::setGender(string Gender) 
{
	// Modifier for gender_
	gender_ = Gender;
}
