//////////////////////////////////////////////////////////////////////////
//Clinic Management System												//
//Fall 2020																//
//																		//
//Authors:																//
//Justin ****															//
//Sean Novak															//
//Christopher ****														//
//																		//
//////////////////////////////////////////////////////////////////////////

//Driver code for the clinic management system
#include <iostream>
#include <fstream>

#include "Clinic.h"
#include "Patient.h"
#include "Doctor.h"
#include "Nurse.h"
#include "LoadStoreObject.h"

////////////////Function Prototypes////////////////
void startProgram(Clinic*& clinic1, Doctor*& doc1, Doctor*& doc2);
void modify(Clinic*& clinic1, Doctor*& doc1, Doctor*& doc2);
void menueOpt1_AddAPpt(int& menuChoice, Doctor*& doc1, Doctor*& doc2);
void menueOpt2_RemoveAppt(int& menuChoice, Doctor*& doc1, Doctor*& doc2);
void closeProgram(Clinic*& clinic1, Doctor*& doc1, Doctor*& doc2);

void createDefaultClinic(Clinic*& clin);
void createDefaultDoctors(Clinic* clinic1, Doctor*& doc1, Doctor*& doc2);
void createDefaultNurses(Doctor* doc);
void createDefaultPatients(Doctor* doc1, Doctor* doc2);
void createDefaultAppts(Doctor* doc1, Doctor* doc2);
void inputNewAppt(Doctor* doc1, Doctor* otherDoc);

int main()
{
	Clinic* testClinic;	//pointers to classes that contain most of the functionality and drive the program
	Doctor* doc1;
	Doctor* doc2;

	startProgram(testClinic, doc1, doc2);

	modify(testClinic, doc1, doc2);		//user inputting data

	closeProgram(testClinic, doc1, doc2);

	return 0;
}

////////////////Function Bodies////////////////

void startProgram(Clinic*& clinic1, Doctor*& doc1, Doctor*& doc2)
//checks to see if there is clinic data in text files to load from
//if not builds everything from scratch
{
	std::ifstream clinicFile;
	clinicFile.open("object data/clinicData.txt");

	if (clinicFile.fail() || clinicFile.peek() == std::ifstream::traits_type::eof())
		//if file doesnt exist or it exists and isn't empty
	{
		std::cout << "No clinic data found..." << std::endl << "Building from default data" << std::endl;

		createDefaultClinic(clinic1);
		createDefaultDoctors(clinic1, doc1, doc2);
		//createDefaultNurses(doc1);
		//createDefaultPatients(doc1, doc2);
		//createDefaultAppts(doc1, doc2);
	}
	else
	{
		LoadStoreObject loadObj;

		//build clinic object from found files
		std::cout << "Existing clinic data found" << std::endl << "Loading from existing data" << std::endl;
		
		loadObj.loadClinicData(clinic1, doc1, doc2);
	}
}

void modify(Clinic*& clinic1, Doctor*& doc1, Doctor*& doc2)//User interface
{
	int userInput;

	do						//user input checking
	{
		do
		{
			if (cin.fail() == true)//clear input buffer up to the newline character
			{
				cout << endl << "---Invalid entry, try again---" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}

			cout << "Would would you like to do?" << endl
				<< "1. Add new appointment" << endl
				<< "2. Cancel appointment" << endl
				<< "3. Quit" << endl;
			cin >> userInput;

		} while(cin.fail());	//if user inputs anything but a number

		switch (userInput)		//controls main menue operation
		{
			////////////adding an appt////////////
		case 1:
			menueOpt1_AddAPpt(userInput, doc1, doc2);
			break;

			////////////Canceling and appt////////////
		case 2:
			menueOpt2_RemoveAppt(userInput, doc1, doc2);
			break;

			////////////Ending Program////////////
		case 3:
			cout << endl << "Quitting Program!";
			break;

		default:
			cout << endl << "---Invalid Choice---" << endl;
			break;
		}
	} while (userInput < 1 || userInput > 3);
}

void menueOpt1_AddAPpt(int& menuChoice, Doctor*& doc1, Doctor*& doc2)
{
	int docChoice;

	do						//user input checking
	{
		do
		{
			if (cin.fail() == true)//clear input buffer up to the newline character
			{
				cout << endl << "---Invalid entry, try again---" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}

			cout << "Which doctor would you like to add an appointment for?" << endl
				<< "1. " << doc1->getFName() << " " << doc1->getLName() << endl
				<< "2. " << doc2->getFName() << " " << doc2->getLName() << endl
				<< "3. <Go back" << endl;
			cin >> docChoice;

		} while (cin.fail()); //if user inputs anything but a number

		switch (docChoice)
		{

		case 1:
			inputNewAppt(doc1, doc2);
			break;

		case 2:
			inputNewAppt(doc2, doc1);
			break;

		case 3:
			menuChoice = -1; //Set main menu value to unaccepted value so program prints it again
			break;

		default:			//choice not on list
			cout << endl << "---Invalid Choice---" << endl;
			break;
		}
	} while (docChoice < 1 || docChoice > 3);
}

void menueOpt2_RemoveAppt(int& menuChoice, Doctor*& doc1, Doctor*& doc2)
{
	std::string patId;
	int docChoice;

	do							//user input checking 
	{
		do
		{
			if (cin.fail() == true)//clear input buffer up to the newline character
			{
				cout << "---Invalid entry, try again---" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}

			cout << "Which doctor would you like to cancel an appointment for?" << endl
				<< "1. " << doc1->getFName() << " " << doc1->getLName() << endl
				<< "2. " << doc2->getFName() << " " << doc2->getLName() << endl
				<< "3. <Go back" << endl;
			cin >> docChoice;

		} while (cin.fail()); //if user inputs anything but a number

		switch (docChoice)
		{
		case 1:
			cout << endl << "Please enter a patient ID: "; cin >> patId;
			doc1->cancelAppointment(patId);
			break;

		case 2:
			cout << endl << "Please enter a patient ID: "; cin >> patId;
			doc2->cancelAppointment(patId);
			break;

		case 3:
			menuChoice = -1; //Set main menue value to unaccepted value so it prints info again 
			break;

		default:
			cout << endl << "---Invalid Choice---" << endl;
			break;
		}
	} while (docChoice < 1 || docChoice > 3);
}

void closeProgram(Clinic*& clinic1, Doctor*& doc1, Doctor*& doc2) 
{
	LoadStoreObject store;

	cout << endl << "~~~ SAVING CLINIC DATA ~~~" << endl;

	store.storeClinicData(*clinic1, *doc1, *doc2);//save clinic data to text files

	//take care of dynamic memory used to instantiate these objects
	delete clinic1;
	delete doc1;
	delete doc2;

	clinic1 = nullptr;
	doc1 = nullptr;
	doc2 = nullptr;

	cout << "Goodbye!" << endl;
}

void inputNewAppt(Doctor* doc1, Doctor* otherDoc) {
	std::string idPatient;
	int hour, day, month, year;
	std::string idNurse;

	cout << endl << "Patient ID: "; cin >> idPatient;
	cout << endl << "Year: "; cin >> year;
	cout << endl << "Month: "; cin >> month;
	cout << endl << "Day (15-19 accepted): "; cin >> day;
	cout << endl << "Hour (9-17 military time): "; cin >> hour;
	cout << endl << "Nurse ID: "; cin >> idNurse;

	doc1->addAppointment(idPatient, hour, day, month, year, idNurse, otherDoc);
}

void createDefaultClinic(Clinic*& clin)
{
	vector<Nurse> vecNur;

	clin = new Clinic(vecNur, 0, 2);//no nurses and 2 doctors 
}

void createDefaultDoctors(Clinic* clinic1, Doctor*& doc1, Doctor*& doc2)
{
	std::string doc1FName = "Joanne";
	std::string doc1LName = "Healthy";
	std::string doc1StAddr = "Five Forks Rd.";
	int doc1ZipCode = 24523;
	std::string doc1City = "Bedford";
	int doc1BDay = 12;
	int doc1BMonth = 6;
	int doc1BYear = 1986;
	int doc1SSN = 222334444;
	std::string doc1Gender = "Female";
	double doc1Salary = 90850.50;
	std::string doc1Specialty = "Psychiatrist";
	std::string doc1Degree = "Doctor of Medicine";
	std::string doc1MedSchool = "The School of Medical Practice in New York";
	bool doc1BoardCertified = true;
	int doc1PatientCapacity = 30;

	std::string doc2FName = "Johnny";
	std::string doc2LName = "Hefty";
	std::string doc2StAddr = "Jappa Mill Rd.";
	int doc2ZipCode = 24523;
	std::string doc2City = "Bedford";
	int doc2BDay = 3;
	int doc2BMonth = 6;
	int doc2BYear = 1978;
	int doc2SSN = 111221111;
	std::string doc2Gender = "Male";
	double doc2Salary = 100340.91;
	std::string doc2Specialty = "Surgeon";
	std::string doc2Degree = "Doctor of Medicine";
	std::string doc2MedSchool = "The School of Medical Practice";
	bool doc2BoardCertified = true;
	int doc2PatientCapacity = 36;

	//instantiate doctor objects on heap
	doc1 = new Doctor(doc1FName, doc1LName, doc1StAddr, doc1ZipCode, doc1City, doc1BDay, doc1BMonth, doc1BYear, doc1SSN, doc1Gender, doc1Salary,
		doc1Specialty, doc1Degree, doc1MedSchool, doc1BoardCertified, *clinic1, doc1PatientCapacity);

	doc2 = new Doctor(doc2FName, doc2LName, doc2StAddr, doc2ZipCode, doc2City, doc2BDay, doc2BMonth, doc2BYear, doc2SSN, doc2Gender, doc2Salary,
		doc2Specialty, doc2Degree, doc2MedSchool, doc2BoardCertified, *clinic1, doc2PatientCapacity);
}


void createDefaultNurses(Doctor* doc) {

	std::string fName = "Beth";
	std::string lName = "Jones";
	std::string stAddress = "113 Kings ln";
	int zip = 24553;
	std::string city = "Lynchburg";
	int dayBirth = 13;
	int monthBirth = 8;
	int yearBirth = 1997;
	int SSN = 212234444;
	std::string gender = "Female";
	double salary = 4526.29;
	std::string spec = "Pediatrician";
	bool practitioner = false;

	doc->addNurse(fName, lName, stAddress, zip, city, dayBirth, monthBirth, yearBirth, SSN, gender, salary, spec, practitioner);

	fName = "Mairead";
	lName = "Levi";
	stAddress = "771 Daisy rd";
	zip = 24587;
	city = "Forest";
	dayBirth = 23;
	monthBirth = 11;
	yearBirth = 1987;
	SSN = 133224545;
	gender = "Female";
	salary = 6526.29;
	spec = "Sergeon";
	practitioner = true;

	doc->addNurse(fName, lName, stAddress, zip, city, dayBirth, monthBirth, yearBirth, SSN, gender, salary, spec, practitioner);

	fName = "Joe";
	lName = "Driver";
	stAddress = "223 Stirling st";
	zip = 25663;
	city = "Rustburg";
	dayBirth = 11;
	monthBirth = 7;
	yearBirth = 1995;
	SSN = 817363677;
	gender = "Male";
	salary = 5526.90;
	spec = "Anesthesiologist";
	practitioner = false;

	doc->addNurse(fName, lName, stAddress, zip, city, dayBirth, monthBirth, yearBirth, SSN, gender, salary, spec, practitioner);
}

void createDefaultPatients(Doctor* doc1, Doctor* doc2) {

	std::string fName = "Chet";
	std::string lName = "Livingston";
	std::string stAddress = "116 living ln";
	int zip = 24754;
	std::string city = "Lynchburg";
	int dayBirth = 17;
	int monthBirth = 10;
	int yearBirth = 1992;
	int SSN = 775341124;
	std::string gender = "Male";
	int hour = 11;
	int day = 16;
	int month = 8;
	int year = 2020;
	string nurseID = "nr2";

	doc1->addPatient(fName, lName, stAddress, zip, city, dayBirth, monthBirth, yearBirth, SSN, gender, hour, day, month, year, nurseID);

	fName = "Laura";
	lName = "Ruth";
	stAddress = "224 sunburst rd";
	zip = 264322;
	city = "Richmond";
	dayBirth = 12;
	monthBirth = 2;
	yearBirth = 1998;
	SSN = 989885436;
	gender = "Female";
	hour = 13;
	day = 18;
	month = 8;
	year = 2020;
	nurseID = "nr1";

	doc1->addPatient(fName, lName, stAddress, zip, city, dayBirth, monthBirth, yearBirth, SSN, gender, hour, day, month, year, nurseID);

	fName = "Matthew";
	lName = "Levi";
	stAddress = "771 Daisy rd";
	zip = 24587;
	city = "Forest";
	dayBirth = 17;
	monthBirth = 7;
	yearBirth = 1995;
	SSN = 17543654;
	gender = "Male";
	hour = 11;
	day = 17;
	month = 8;
	year = 2020;
	nurseID = "nr3";

	doc2->addPatient(fName, lName, stAddress, zip, city, dayBirth, monthBirth, yearBirth, SSN, gender, hour, day, month, year, nurseID);

	fName = "Leeana";
	lName = "Kin";
	stAddress = "441 moonshine rd";
	zip = 73838;
	city = "Dallas";
	dayBirth = 15;
	monthBirth = 4;
	yearBirth = 1970;
	SSN = 544227767;
	gender = "Female";
	hour = 16;
	day = 19;
	month = 8;
	year = 2020;
	nurseID = "nr2";

	doc2->addPatient(fName, lName, stAddress, zip, city, dayBirth, monthBirth, yearBirth, SSN, gender, hour, day, month, year, nurseID);
}

void createDefaultAppts(Doctor* doc1, Doctor* doc2) {

	std::string patID = "pt1";
	int hour = 15;
	int day = 17;
	int month = 6;
	int year = 2020;
	std::string nuID = "nu2";


	doc1->addAppointment(patID, hour, day, month, year, nuID, doc2);

	patID = "pt3";
	hour = 16;
	day = 16;
	month = 9;
	year = 2020;
	nuID = "nu1";


	doc2->addAppointment(patID, hour, day, month, year, nuID, doc1);
}

