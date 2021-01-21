#include <iostream>
#include <string>

#include "Doctor.h"

using namespace std;

int Doctor::doctorCount = 0;

//constructor destructor
Doctor::Doctor(string fName, string lName, string stAddress, int zipCode, string city, int dayBirth,
	int monthBirth, int yearBirth, int SSN, string gender, double salary, string speciality,
	string degree, string medicalSchool, bool boardCertified, Clinic& clinic, int patCapacity) : 
	Employee(fName, lName, stAddress, zipCode, city, dayBirth, monthBirth, yearBirth, SSN, gender, salary),
	speciality_(speciality), degree_(degree), medicalSchool_(medicalSchool), isBoardCertified_(boardCertified), capacity_(patCapacity)
{
	++doctorCount;
	idDoctor_ = "dr" + to_string(doctorCount);
	
	patients_ = new Patient[capacity_];
	patientCount_ = 0;

	//create doctor's schedule 
	appointments_ = new Appointment* [5];			//5 days in the week
	for (int i = 0; i < 5; i++)
	{
		*(appointments_ + i) = new Appointment[8];	//8 time slots per day
	}
	
	clinic_ = &clinic;							//pointer to clinic doctor belongs to

	firstDayOfSchedule_ = 15;
}

Doctor::~Doctor()
{
	//clean up dynamic memory
	delete[] patients_;
	patients_ = nullptr;

	//free each sub array
	for (int i = 0; i < 5; i++)
	{
		delete[] * (appointments_ + i);//delete the data for each day in the week
	}
	//free array of pointers 
	delete[] appointments_;
	appointments_ = nullptr;
}

void Doctor::addNurse(string fName, string lName, string stAddress, int zipCode, string city, int dayBirth,
	int monthBirth, int yearBirth, int SSN, string gender, double salary, string speciality, bool practitioner)
{
	Nurse nurseToAdd(fName, lName, stAddress, zipCode, city, dayBirth, monthBirth, yearBirth, SSN,
		gender, salary, speciality, practitioner);			//create nurse object to add to the clinic 
	clinic_->addNurse(nurseToAdd);						//Pass nurse to clinic to add it to the nurse vector
}

void Doctor::delNurse(Nurse& nurse) 
{
	clinic_->delNurse(nurse);
}


void Doctor::addPatient(string fN, string lN, string stAddr, int zipC, string City,
	int dayB, int monthB, int yearB, int ssn, string Gender, int Hour, int Day, int Month, int Year, string idN)
{
	if (patientCount_ < capacity_)			//if the doctor has space 
	{
		//create instance of patient in patient array with passed in parameters
		*(patients_ + patientCount_) = Patient((patientCount_ + 1), fN, lN, stAddr, zipC, City, dayB, monthB, yearB, ssn, Gender, Hour, Day, Month, Year, idN);

		patientCount_++;					//incriment num of patients
	}
	else
		std::cout << idDoctor_ << " patient capacity reached!" << std::endl;
}

//add new appt to scheduel of clinic
void Doctor::addAppointment(string idPatient, int hour, int day, int month, int year, string idNurse, Doctor* otherDoc)
{
	int hourIndex = hour - 9;					//index of the given hour assuming the workday is between 9 and 17 (24 hour clock)
	int dayIndex = day - firstDayOfSchedule_;	//finds the index of the given day by determining it's distance from the first day of the schedule
	string idPatInArray = (*(appointments_ + dayIndex) + hourIndex)->get_idPatient();


	//if the appointment's patient's ID == 0 and the given nurse doesn't have an appointment with the other doctor:
	if (idPatInArray == "0" && !otherDoc->checkNurse(hour, day, month, year, idNurse))
	{
		string date = to_string(month) + "-" + to_string(day) + "-" + to_string(year);

		Appointment newAppt(idPatient, idNurse, date); //Create a new appointment using the info

		*(*(appointments_ + dayIndex) + hourIndex) = newAppt; //Add it to the doctor's appointments_ array
		
		cout << endl << "Appointment creation successful for " << this->fName_ << " " << this->lName_ << endl;
	}

	else 
	{	//If the doctor or the nurse already has something in that time slot
		cout << endl << "Timeslot unavailable" << endl;
	}

}


bool Doctor::checkNurse(int hour, int day, int month, int year, string idNurse) // indicate if a nurse has an appointment in the given time parameters
{
	int hourIndex = hour - 9;					//index of the given hour assuming the workday is between 9 and 17 (24 hour clock)
	int dayIndex = day - firstDayOfSchedule_;	//finds the index of the given day by determining it's distance from the first day of the schedule

	if ((*(appointments_ + dayIndex) + hourIndex)->get_idNurse() == idNurse) //If the nurse associated with this timeslot is the one being checked
		return true;
	else
		return false;
}

void Doctor::cancelAppointment(string idPatient) //cancel appt from scheduel of doctor object it is called from
{
	bool wasFound = false;

	//Find the given patient in the array
	for (int i = 0; i < 5; ++i) { //For every day
		for (int j = 0; j < 8; ++j) { //For every hour in that day

			if (((*(appointments_ + i) + j)->get_idPatient()) == idPatient) //If the current day and hour's patient == the one passed in
			{
				//Set it to the default values
				(*(appointments_ + i) + j)->set_idPatient("0");
				(*(appointments_ + i) + j)->set_idNurse("0");
				(*(appointments_ + i) + j)->set_date("NO DATE");

				wasFound = true;

				break;
			}
		}
	}

	if (wasFound == true)
		cout << endl << "Appointment cancellation successful for " << this->fName_ << " " << this->lName_ << endl;
	else
		cout << endl << "No appointment with that ID found";

}


void Doctor::updateAppointment(string idPatient, int hour, int day, int month, int year, Doctor* otherDoc) //replaces time variables with new ones provided 
{
	string nurseID;
	int oldDay;
	int oldHour;

	//Find the given patient in the array and find the nurse associated with their appointment
	for (int i = 0; i < 5; ++i) { //For every day
		for (int j = 0; j < 8; ++j) { //For every hour in that day

			if ((*(appointments_ + i) + j)->get_idPatient() == idPatient) //If the current day and hour's patient == the one passed in
			{
				//Store location of the appointment before being updated
				oldDay = i;
				oldHour = j;

				nurseID = (*(appointments_ + i) + j)->get_idNurse(); //Store the id of the nurse associated with the appointment

				break;
			}
		}
	}

	this->addAppointment(idPatient, hour, day, month, year, nurseID, otherDoc); //Add a new appointment with the given parameters

	int hourIndex = hour - 9;					//index of the given hour assuming the workday is between 9 and 17 (24 hour clock)
	int dayIndex = day - firstDayOfSchedule_;	//finds the index of the given day by determining it's distance from the first day of the schedule


	//If the patient of the given timeslot has been changed to the patient passed in (addAppointment was successful)
	if ((*(appointments_ + dayIndex) + hourIndex)->get_idPatient() == idPatient)
	{
		//Erase the old appointment
		(*(appointments_ + oldDay) + oldHour)->set_idPatient("0");
		(*(appointments_ + oldDay) + oldHour)->set_idNurse("0");
		(*(appointments_ + oldDay) + oldHour)->set_date("NO DATE");
	}

	else { //Doctor or nurse was busy
		cout << "Timeslot unavailable";
	}

}

//accessors and mutators
int Doctor::getPatientCapacity() const
{
	return capacity_;
}
int Doctor::getPatientCount() const
{
	return patientCount_;
}

void Doctor::setPatientCOunt(int patCount)
{
	patientCount_ = patCount;
}

std::string Doctor::getIdDoctor() const
{
	return idDoctor_;
}
Patient* Doctor::getPatientArray() const
{
	return patients_;
}
std::string Doctor::getSpecialty() const
{
	return speciality_;
}
std::string Doctor::getDegree() const
{
	return degree_;
}
std::string Doctor::getMedSchool() const
{
	return medicalSchool_;
}
bool Doctor::getIfBoardCertified() const
{
	return isBoardCertified_;
}
Appointment** Doctor::getAppointmentArray() const
{
	return appointments_;
}