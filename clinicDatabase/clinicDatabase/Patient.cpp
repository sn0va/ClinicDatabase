#include "Patient.h"


Patient::Patient() : Person()
{
	//default costructor
	string id = "ptDEF";
	
	idPatient_ = id;
	hour_ = 0;
	day_ = 0;
	month_ = 0;
	year_ = 0;
	idNurse_ = "NO NURSE ASSIGNED";
}
Patient::Patient(int patNum, string fN, string lN, string stAddr, int zipC, string City, int dayB, int monthB, int yearB, int ssn, string Gender, int Hour, int Day, int Month, int Year, string idN):Person(fN, lN, stAddr, zipC, City, dayB, monthB, yearB, ssn, Gender) 
{
	// Parametrized Constructor

	idPatient_ = "pt" + to_string(patNum);
	hour_ = Hour;
	day_ = Day;
	month_ = Month;
	year_ = Year;
	idNurse_ = idN;
}
string Patient::get_idPatient() 
{
	// Accessor for Patient id
	return idPatient_;
}
int Patient::get_hour() 
{
	// Accessor for hour_
	return hour_;
}
int Patient::get_day() 
{
	// Accessor for day_
	return day_;
}
int Patient::get_month() 
{
	// Accessor for month_
	return month_;
}
int Patient::get_year() 
{
	// Accessor for year_
	return year_;
}
string Patient::get_idNurse() 
{
	// Accessor for Nurse id
	return idNurse_;
}
void Patient::set_idPatient(int idP) 
{
	// Accessor for Patient id
	idPatient_ = idP;
}
void Patient::set_hour(int Hour) 
{
	// Modifier for hour_
	hour_ = Hour;
}
void Patient::set_day(int Day) 
{
	// Modifier for day_
	day_ = Day;
}
void Patient::set_month(int Month) 
{
	// Modifier for month_
	month_ = Month;
}
void Patient::set_year(int Year) 
{
	// Modifier for year_
	year_ = Year;
}
void Patient::set_idNurse(int idN) 
{
	// Modifier for Nurse id
	idNurse_ = idN;
}
