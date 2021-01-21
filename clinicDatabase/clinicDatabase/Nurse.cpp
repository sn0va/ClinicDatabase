#include "Nurse.h"

int Nurse::nurseCount = 0;

Nurse::Nurse(string fN, string lN, string stAddr, int zipC, string City, int dayB, int monthB, int yearB, int ssn, string Gender, double Salary, string Speciality, bool isPrac): Employee(fN, lN, stAddr, zipC, City, dayB, monthB, yearB, ssn, Gender, Salary) 
{
	// Parametrized Constructor
	speciality_ = Speciality;
	practitioner_ = isPrac;

	++nurseCount;
	idNurse_ = "nr" + to_string(nurseCount);
}
string Nurse::getIdNurse() 
{
	// Accessor for Nurse Id
	return idNurse_;
}
string Nurse::getSpeciality() 
{
	// Accessor for Speciality
	return speciality_;
}
bool Nurse::getIfPrac()
{
	// Accessor for Practitioner
	return practitioner_;
}
void Nurse::setIdNurse(string idN) 
{
	// Modifier for Nurse Id
	idNurse_ = idN;
}
void Nurse::setSpeciality(string Speciality) 
{
	// Modifier for Speciality
	speciality_ = Speciality;
}
void Nurse::setPractitioner(bool prac) 
{
	// Modifier for Practitioner
	practitioner_ = prac;
}

bool Nurse::operator == (Nurse rhsNurse) {
	if (this->idNurse_ == rhsNurse.idNurse_)
		return true;

	else
		return false;
}
bool Nurse::reward(Appointment** appointments) {
	int appointment_count = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 8; i++) {
			if ((*((*(appointments + i)) + j)).get_idNurse() == this->idNurse_) {
				appointment_count++;
			}
		}
	}
	if (appointment_count > 10) {
		return true;
	}
	return false;
}

Nurse::~Nurse() {}