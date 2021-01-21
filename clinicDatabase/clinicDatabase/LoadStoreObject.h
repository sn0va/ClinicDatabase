#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include"Patient.h"
#include"Doctor.h"
#include"Nurse.h"

//Contains class that handles the storing of data for classes used in clinic management program to text files
//and the retreval of the info in those text files uppon the program reopening.
class LoadStoreObject
{
public:
	///these are the only functions that will be called
	///the rest of the sub functions are called within these two
	void storeClinicData(Clinic& clinicToStore, Doctor& doc1ToStore, Doctor& doc2ToStore);

	void loadClinicData(Clinic*& clinicToLoad, Doctor*& doc1ToLoad, Doctor*& doc2ToLoad);

private:
	//store doctor data
	void storeDoctorData(Doctor& doc);

	//store nurse data
	void storeNurseData(Clinic& clinic);

	//store patient
	void storePatientData(Doctor& doc);

	//store appointment scheduel data
	void storeApptData(Doctor& doc);

	//////LOADING//////////

	//load doctor data
	void loadDoctorData(Clinic* clinic, Doctor*& doc1, Doctor*& doc2);

	//load nurse data
	Nurse loadNurseData(int nurseNumber);

	//load patient data
	void loadPatientData(Doctor* doc, int n);
	
	//load appt scheduel data
	void loadApptData(Doctor*& docToLoadAppts);
};
