#include "Appointment.h"

Appointment::Appointment()
{
	//default constructor
	idPatient_ = "0";
	idNurse_ = "0";
	date_ = "NO DATE";
}
Appointment::Appointment(string id_Patient, string id_nurse, string date)
{
	// Parametrized Constructor
	idPatient_ = id_Patient;
	idNurse_ = id_nurse;
	date_ = date;
}
string Appointment::get_date() 
{
	// Accessor for date_
	return date_;
}
string Appointment::get_idPatient()
{
	// Accessor for doctor id
	return idPatient_;
}
string Appointment::get_idNurse()
{
	// Accessor for Nurse id
	return idNurse_;
}
void Appointment::set_date(string date) 
{
	// Modifier for date_
	date_ = date;
}
void Appointment::set_idPatient(string id_doctor)
{
	// Modifier for Doctor id
	idPatient_ = id_doctor;
}
void Appointment::set_idNurse(string id_nurse)
{
	// Modifier for Nurse Id
	idNurse_ = id_nurse;
}
