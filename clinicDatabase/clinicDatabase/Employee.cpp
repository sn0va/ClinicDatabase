#include "Employee.h"

Employee::Employee() : Person()
{
	//default constructor
	salary_ = 0;
}
Employee::Employee(string fN, string lN, string stAddr, int zipC, string City, int dayB, int monthB, int yearB, int ssn, string Gender, double Salary):Person(fN, lN, stAddr, zipC, City, dayB, monthB, yearB, ssn, Gender) 
{
	// Parametrized Constructor
	salary_ = Salary;
}
double Employee::getSalary() 
{
	// Accessor for Salary
	return salary_;
}
void Employee::setSalary(double Salary) 
{
	// Modifier for Salary
	salary_ = Salary;
}