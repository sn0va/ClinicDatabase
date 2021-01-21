#pragma once
#include <iostream>
#include <string>

#include "Employee.h"
#include "Patient.h"
#include "Appointment.h"
#include "Nurse.h"
#include "Clinic.h"

//Doctor class which contains a lot of the functionality of the program, such as adding/changing nurses, patients and appointments
class Doctor : public Employee 
{
public:
	Doctor(string fName, string lName, string stAddress, int zipCode, string city, int dayBirth,
		int monthBirth, int yearBirth, int SSN, string gender, double salary, string speciality,
		string degree, string medicalSchool, bool boardCertified, Clinic& clinic, int patCapacit);
	~Doctor();

	void addNurse(string fName, string lName, string stAddress, int zipCode, string city, int dayBirth,
		int monthBirth, int yearBirth, int SSN, string gender, double salary, string speciality, bool practitioner);
	void delNurse(Nurse& nurse);
	void addPatient(string, string, string, int, string, int, int, int yearB, int ssn, string Gender,
						int, int Day, int Month, int Year, string idN);
	string idNurse_;
	void addAppointment(string idPatient, int hour, int day, int month, int year, string idNurse, Doctor* otherDoc);
	bool checkNurse(int hour, int day, int month, int year, string idNurse);
	void cancelAppointment(string idPatient);
	void updateAppointment(string idPatient, int newHour, int newDay, int newMonth, int newYear, Doctor* otherDoc);

	//accessors
	int getPatientCapacity() const;
	int getPatientCount() const;
	std::string getIdDoctor() const;
	Patient* getPatientArray() const;
	std::string getSpecialty() const;
	std::string getDegree() const;
	std::string getMedSchool() const;
	bool getIfBoardCertified() const;
	Appointment** getAppointmentArray() const;

	//mutators
	void setPatientCOunt(int patCount);

	static int doctorCount;
private:
	Clinic* clinic_;
	std::string idDoctor_;
	std::string speciality_;
	std::string degree_;
	std::string medicalSchool_;
	bool isBoardCertified_;
	Patient* patients_;			//Pointer to dynArr of patients the doctor is seeing
	Appointment** appointments_;//2d schedule array for doctor's appointments
	int patientCount_;
	int capacity_;
	int firstDayOfSchedule_;
};