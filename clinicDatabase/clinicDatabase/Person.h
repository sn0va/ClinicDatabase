#pragma once

#include <string>

using namespace std;

//Base class for all basic person objects, such as patients
class Person 
{
	protected:
		string fName_;
		string lName_;
		string stAddress_;
		int zipCode_;
		string city_;
		int dayBirth_;
		int monthBirth_;
		int yearBirth_;
		int SSN_;
		string gender_;
	public:
		Person();
		Person(string fN, string lN, string stAddr, int zipC, string City, int dayB, int monthB, int yearB, int ssn, string gender);
		string getFName();
		string getLName();
		string getStAddress();
		int getZipCode();
		string getCity();
		int getDayBirth();
		int getMonthBirth();
		int getYearBirth();
		int getSSN();
		string getGender();
		void setFName(string fN);
		void setLName(string lN);
		void setStAddress(string stAddr);
		void setZipCode(int);
		void setCity(string zipC);
		void setDayBirth(int dayB);
		void setMonthBirth(int monthB);
		void setYearBirth(int yearB);
		void setSSN(int ssn);
		void setGender(string gender);
};