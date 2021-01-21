#pragma once

#include "Person.h"

//Class stores necescary info pertaining to patients that will enter the clinic and ask for appointments
class Patient:public Person 
{
	private:
		string idPatient_;

		int hour_;
		int day_;
		int month_;
		int year_;

		string idNurse_;
	public:
		Patient();
		Patient(int patNum, string fN, string lN, string stAddr, int zipC, string City, int dayB, int monthB, int yearB, int ssn, string Gender, int Hour, int Day, int Month, int Year, string idN);
		string get_idPatient();
		int get_hour();
		int get_day();
		int get_month();
		int get_year();
		string get_idNurse();
		void set_idPatient(int idPat);
		void set_hour(int hour);
		void set_day(int day);
		void set_month(int month);
		void set_year(int year);
		void set_idNurse(int idNur);
};