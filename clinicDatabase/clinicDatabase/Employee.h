#pragma once

#include "Person.h"

//Class derived from person, Doctor and Nurse inherit from this
class Employee:public Person 
{
	protected:
		double salary_;
	public:
		Employee();
		Employee(string fN, string lN, string stAddr, int zipC, string City, int dayB, int monthB, int yearB, int ssn, string Gender, double Salary);
		double getSalary();
		void setSalary(double);
};