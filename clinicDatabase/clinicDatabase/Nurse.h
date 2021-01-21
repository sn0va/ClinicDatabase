#pragma once

#include <string>

#include "Appointment.h"
#include "Employee.h"

using namespace std;

//nurse class works with both doctors at the clinic when appointments are made
class Nurse: public Employee 
{
	private:
		string idNurse_;
		string speciality_;
		bool practitioner_;
	public:
		Nurse(string fN, string lN, string stAddr, int zipC, string City, int dayB, int monthB, int yearB, int ssn, string Gender, double Salary, string Speciality, bool isPrac);
		~Nurse();
		string getIdNurse();
		string getSpeciality();
		bool getIfPrac();
		void setIdNurse(string idNur);
		void setSpeciality(string specNur);
		void setPractitioner(bool isPrac);
		static int nurseCount; 
		bool operator == (Nurse rhsNurse);
		bool reward(Appointment**);
};