#include "LoadStoreObject.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//STORING OBJECTS
void LoadStoreObject::storeClinicData(Clinic& clinic, Doctor& doc1, Doctor& doc2)
{
	std::ofstream clinicFile;

	clinicFile.open("object data/clinicData.txt");
	
	if (clinicFile.fail())				//if file could not be opened 
	{									//standard output stream for errors
		std::cerr << "Error Opening clinicData.txt" << std::endl;
		exit(1);
	}
	else
	{
		//store data the way it appears in constructor for clinic object
		clinicFile << clinic.getNumNurses() << std::endl << doc1.getPatientCapacity() << std::endl
			<< doc1.getPatientCount() << std::endl << doc2.getPatientCapacity() << std::endl
			<< doc2.getPatientCount();

		storeDoctorData(doc1);	//next store the doctors in their text files
		storeDoctorData(doc2);	

		storeNurseData(clinic);	//and then nurses

		//close file when done
		clinicFile.close();
	}
}

void LoadStoreObject::storeDoctorData(Doctor& doc)
{
	std::string docFileName = "object data/";
	docFileName.append(doc.getIdDoctor()); 
	docFileName.append(".txt");			//"object data/dr(docNum).txt"

	std::ofstream docFile;

	docFile.open(docFileName);

	if (docFile.fail())				//if file could not be opened 
	{							
		std::cerr << "Error Opening " << docFileName << std::endl;
		exit(1);
	}
	else
	{
		//store data in this order: 
		//nbNurses, Dr1Capacity, Dr1NbPatients, Dr2Capcity, Dr2NbPatients
		docFile << doc.getFName() << std::endl << doc.getLName() << std::endl << doc.getStAddress() << std::endl
			<< doc.getZipCode() << std::endl << doc.getCity() << std::endl << doc.getDayBirth() << std::endl
			<< doc.getMonthBirth() << std::endl << doc.getYearBirth() << std::endl << doc.getSSN() << std::endl
			<< doc.getGender() << std::endl << doc.getSalary() << std::endl << doc.getSpecialty() << std::endl
			<< doc.getDegree() << std::endl << doc.getMedSchool() << std::endl << doc.getIfBoardCertified() << std::endl 
			<< doc.getPatientCapacity();

		storePatientData(doc);		//store arrays in doctor to text files
		storeApptData(doc);

		//close file when done
		docFile.close();
	}
}

void LoadStoreObject::storeNurseData(Clinic& clinic)
{
	for (int i = 0; i < clinic.getNumNurses(); i++)//for every nurse in the clinic 
	{
		std::string nurFileName = "object data/";
		nurFileName.append(clinic.getNurses()[i].getIdNurse());
		nurFileName.append(".txt");			//"object data/nr(nurseNum).txt"

		std::ofstream nurFile;
		
		nurFile.open(nurFileName);			//open nurse file for writing

		if (nurFile.fail())				//if file could not be opened 
		{
			std::cerr << "Error Opening " << nurFileName << std::endl;
			exit(1);
		}
		else
		{
			nurFile << clinic.getNurses()[i].getFName() << std::endl << clinic.getNurses()[i].getLName() << std::endl << clinic.getNurses()[i].getStAddress() << std::endl
				<< clinic.getNurses()[i].getZipCode() << std::endl << clinic.getNurses()[i].getCity() << std::endl << clinic.getNurses()[i].getDayBirth() << std::endl
				<< clinic.getNurses()[i].getMonthBirth() << std::endl << clinic.getNurses()[i].getYearBirth() << std::endl << clinic.getNurses()[i].getSSN() << std::endl
				<< clinic.getNurses()[i].getGender() << std::endl << clinic.getNurses()[i].getSalary() << std::endl << clinic.getNurses()[i].getSpeciality() << std::endl
				<< clinic.getNurses()[i].getIfPrac() << std::endl;

			nurFile.close();
		}
	}
}

void LoadStoreObject::storePatientData(Doctor& doc)	//stores the data of the patients a doctor is seeing
{		
	//for each patient the doctor is seeing
	for (int i = 0; i < doc.getPatientCount(); i++)
	{
		Patient* ptrPatArr = doc.getPatientArray();

		//write data about cuttent patient to text file
		std::string patFileName = "object data/";
		patFileName.append(doc.getIdDoctor());
		patFileName.append("_");
		patFileName.append((ptrPatArr + i)->get_idPatient());
		patFileName.append(".txt");			//new file name with directory "object data/dr(doctor num)_pt(patient number).txt"

		//Uppon creation of a doctor, its patient array will be filled with default patients with ids of ptDEF
		//We do not want to save those because they are irrelivent
		//If a patient has an id of a defualt patient DO NOT save it's info to files
		std::string ptIdCatch = "ptDEF";
		
		if ((ptrPatArr + i)->get_idPatient() != ptIdCatch)
		{
			std::ofstream patFile;

			patFile.open(patFileName);		//open file to begin writing to it 

			if (patFile.fail())				//if file could not be opened 
			{
				std::cerr << "Error Opening " << patFileName << std::endl;
				exit(1);
			}
			else
			{
				//write info to file in order it will be passed into constructor
				patFile << (ptrPatArr + i)->getFName() << std::endl << (ptrPatArr + i)->getLName() << std::endl << (ptrPatArr + i)->getStAddress() << std::endl
					<< (ptrPatArr + i)->getZipCode() << std::endl << (ptrPatArr + i)->getCity() << std::endl << (ptrPatArr + i)->getDayBirth() << std::endl
					<< (ptrPatArr + i)->getMonthBirth() << std::endl << (ptrPatArr + i)->getYearBirth() << std::endl << (ptrPatArr + i)->getSSN() << std::endl
					<< (ptrPatArr + i)->getGender() << std::endl << (ptrPatArr + i)->get_hour() << std::endl << (ptrPatArr + i)->get_day() << std::endl
					<< (ptrPatArr + i)->get_month() << std::endl << (ptrPatArr + i)->get_year() << std::endl << (ptrPatArr + i)->get_idNurse();

				//close file when done
				patFile.close();
			}
		}
	}
}

void LoadStoreObject::storeApptData(Doctor& doc)
{
	
	Appointment** docApptSchedule = doc.getAppointmentArray();
	
	std::string apptFileName = "object data/";
	apptFileName.append(doc.getIdDoctor());
	apptFileName.append("appt.txt");

	std::ofstream apptFile;

	apptFile.open(apptFileName);		//open file to begin writing to it 

	if (apptFile.fail())				//if file could not be opened 
	{
		std::cerr << "Error Opening " << apptFileName << std::endl;
		exit(1);
	}
	else
	{
		for (int i = 0; i < 5; i++)		//5 days 8 time slots
		{
			for (int j = 0; j < 8; j++)
			{
				apptFile << (*(docApptSchedule + i) + j)->get_idPatient() << std::endl << (*(docApptSchedule + i) + j)->get_idNurse() << std::endl
					<< (*(docApptSchedule + i) + j)->get_date() << std::endl;
				
				//at the end of a time slot, insert "|" to indicate the end of that slot (row)
				apptFile << "|" << std::endl;
			}

			apptFile << "-" << std::endl;
			//at the end of a day, insert "-" to indicate the end of that day (column)			
		}
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//LOADING OBJECTS

void LoadStoreObject::loadClinicData(Clinic*& clinicToLoad, Doctor*& doc1ToLoad, Doctor*& doc2ToLoad)
{
	std::ifstream inFileClinic;
	//inFileClinic.open("object data/clinicData.txt");

	//clinic needs a vector of nurses to be created
	vector<Nurse> vecNur;
	clinicToLoad = new Clinic(vecNur, 0, 2);	//2 doctors and no nurses by default

	inFileClinic.open("object data/clinicData.txt");
	//Read info from text file and assign it to the member variables of clinic through mutators
	if (inFileClinic.fail())				//if file could not be opened 
	{
		std::cerr << "Error Opening clinicData.txt" << std::endl;
		exit(1);
	}
	else
	{
		int numNurses;
		int numPatients;

		Nurse* nurseToAdd = nullptr;

		inFileClinic >> numNurses;
		clinicToLoad->setNumNurses(numNurses);

		//loop to add all the nurses to the clinic vector
		for (int i = 1; i <= numNurses; i++)
		{
			nurseToAdd = &loadNurseData(i);

			clinicToLoad->addNurse(*nurseToAdd);
		}
		//clinic info loading should be completed

		loadDoctorData(clinicToLoad, doc1ToLoad, doc2ToLoad);//instantiates both doctors
				
		inFileClinic.ignore();	//dont need capacity from clinic as that is in the doc.txt files too
		inFileClinic >> numPatients;
		doc1ToLoad->setPatientCOunt(numPatients);	 //fill in dr 1 and 2 patient capacity

		inFileClinic.ignore();
		inFileClinic >> numPatients;
		doc2ToLoad->setPatientCOunt(numPatients);
	}
}

void LoadStoreObject::loadDoctorData(Clinic* clinic, Doctor*& doc1, Doctor*& doc2)
{

	std::string docFileName = "object data/dr1.txt";

	string line;
	ifstream doc1File(docFileName);

	std::string FName;
	std::string LName;
	std::string StAddr;
	int ZipCode;
	std::string City;
	int BDay;
	int BMonth;
	int BYear;
	int SSN;
	std::string Gender;
	double Salary;
	std::string Specialty;
	std::string Degree;
	std::string MedSchool;
	bool BoardCertified;
	int PatientCapacity;

	if (doc1File.is_open())
	{

		getline(doc1File, line);
		FName = line;

		getline(doc1File, line);
		LName = line;

		getline(doc1File, line);
		StAddr = line;

		getline(doc1File, line);
		ZipCode = std::stoi(line);

		getline(doc1File, line);
		City = line;

		getline(doc1File, line);
		BDay = std::stoi(line);

		getline(doc1File, line);
		BMonth = std::stoi(line);

		getline(doc1File, line);
		BYear = std::stoi(line);

		getline(doc1File, line);
		SSN = std::stoi(line);

		getline(doc1File, line);
		Gender = line;

		getline(doc1File, line);
		Salary = std::stod(line);

		getline(doc1File, line);
		Specialty = line;

		getline(doc1File, line);
		Degree = line;

		getline(doc1File, line);
		MedSchool = line;

		getline(doc1File, line);
		if (line == "1")
			BoardCertified = true;
		else
			BoardCertified = false;

		getline(doc1File, line);
		PatientCapacity = std::stoi(line);

		//instantiate dr1 from data given by file
		doc1 = new Doctor(FName, LName, StAddr, ZipCode, City, BDay, BMonth, BYear, SSN, Gender, Salary,
			Specialty, Degree, MedSchool, BoardCertified, *clinic, PatientCapacity);


		loadPatientData(doc1, doc1->getPatientCount());//fill doctor's patient array
		loadApptData(doc1);				//load up doctor's schedule

		doc1File.close();
	}
	else cout << "Unable to open file object data/dr1.txt";

	docFileName = "object data/dr2.txt";
	ifstream doc2File(docFileName);

	if (doc2File.is_open())
	{

		getline(doc2File, line);
		FName = line;

		getline(doc2File, line);
		LName = line;

		getline(doc2File, line);
		StAddr = line;

		getline(doc2File, line);
		ZipCode = std::stoi(line);

		getline(doc2File, line);
		City = line;

		getline(doc2File, line);
		BDay = std::stoi(line);

		getline(doc2File, line);
		BMonth = std::stoi(line);

		getline(doc2File, line);
		BYear = std::stoi(line);

		getline(doc2File, line);
		SSN = std::stoi(line);

		getline(doc2File, line);
		Gender = line;

		getline(doc2File, line);
		Salary = std::stod(line);

		getline(doc2File, line);
		Specialty = line;

		getline(doc2File, line);
		Degree = line;

		getline(doc2File, line);
		MedSchool = line;

		getline(doc2File, line);
		if (line == "1")
			BoardCertified = true;
		else
			BoardCertified = false;

		getline(doc2File, line);
		PatientCapacity = std::stoi(line);

		//instantiate second doctor object
		doc2 = new Doctor(FName, LName, StAddr, ZipCode, City, BDay, BMonth, BYear, SSN, Gender, Salary,
			Specialty, Degree, MedSchool, BoardCertified, *clinic, PatientCapacity);

		loadPatientData(doc2, doc2->getPatientCount());//fill doctor's patient array
		loadApptData(doc2);					//load up the doctor's schedule

		doc2File.close();
	}
	else cout << "Unable to open object data/dr2.txt";
}

Nurse LoadStoreObject::loadNurseData(int nurseNumber) 
{
	std::string nurseFileName = "object data/nr";
	nurseFileName.append(std::to_string(nurseNumber));
	nurseFileName.append(".txt");

	string line;
	ifstream nurseFile(nurseFileName);

	std::string FName;
	std::string LName;
	std::string StAddr;
	int ZipCode;
	std::string City;
	int BDay;
	int BMonth;
	int BYear;
	int SSN;
	std::string Gender;
	double Salary;
	std::string Specialty;
	bool isPrac;

	if (nurseFile.is_open())
	{

		getline(nurseFile, line);
		FName = line;

		getline(nurseFile, line);
		LName = line;

		getline(nurseFile, line);
		StAddr = line;

		getline(nurseFile, line);
		ZipCode = std::stoi(line);

		getline(nurseFile, line);
		City = line;

		getline(nurseFile, line);
		BDay = std::stoi(line);

		getline(nurseFile, line);
		BMonth = std::stoi(line);

		getline(nurseFile, line);
		BYear = std::stoi(line);

		getline(nurseFile, line);
		SSN = std::stoi(line);

		getline(nurseFile, line);
		Gender = line;

		getline(nurseFile, line);
		Salary = std::stod(line);

		getline(nurseFile, line);
		Specialty = line;

		getline(nurseFile, line);
		if (line == "1")
			isPrac = true;
		else
			isPrac = false;

		Nurse nur(FName, LName, StAddr, ZipCode, City, BDay, BMonth, BYear, SSN, Gender, Salary, Specialty, isPrac);

		return nur;

		nurseFile.close();
	}

	else cout << "Unable to open " << nurseFileName;

}

void LoadStoreObject::loadPatientData(Doctor* doc, int n) 
{

	string fN, lN, stAddr, City, Gender, idN, line;
	int zipC, dayB, monthB, yearB, ssn, Hour, Day, Month, Year; 

	for (int i = 1; i <= n; i++)
	{
		std::string patFileName = "object data/";
		patFileName.append(doc->getIdDoctor());
		patFileName.append("_pt");
		patFileName.append(to_string(i));
		patFileName.append(".txt");

		std::ifstream patFile;

		patFile.open(patFileName);            //open nurse file for writing

		if (patFile.fail())                //if file could not be opened 
		{
			std::cerr << "Error Opening " << patFileName << std::endl;
			exit(1);
		}
		else
		{
			std::getline(patFile, fN);
			std::getline(patFile, lN);
			std::getline(patFile, stAddr);

			std::getline(patFile, line);
			zipC = atoi(line.c_str());

			std::getline(patFile, City);

			std::getline(patFile, line);
			dayB = atoi(line.c_str());

			std::getline(patFile, line);
			monthB = atoi(line.c_str());

			std::getline(patFile, line);
			yearB = atoi(line.c_str());

			std::getline(patFile, line);
			ssn = atoi(line.c_str());

			std::getline(patFile, Gender);

			std::getline(patFile, line);
			Hour = atoi(line.c_str());

			std::getline(patFile, line);
			Day = atoi(line.c_str());

			std::getline(patFile, line);
			Month = atoi(line.c_str());

			std::getline(patFile, line);
			Year = atoi(line.c_str());

			std::getline(patFile, idN);

			doc->addPatient(fN, lN, stAddr, zipC, City, dayB, monthB, yearB, ssn, Gender, Hour, Day, Month, Year, idN);
		}
	}
}



void LoadStoreObject::loadApptData(Doctor*& docToLoadAppts)
{
	std::string apptFilename = "object data/";
	apptFilename.append(docToLoadAppts->getIdDoctor());
	apptFilename.append("appt.txt"); //object data/doc(docId)appt.txt

	std::ifstream inFileDocAppts;
	inFileDocAppts.open(apptFilename);

	if (inFileDocAppts.fail())	//cant open file
	{
		std::cerr << "Error Opening " << apptFilename << std::endl;
		exit(1);
	}
	else
	{
		Appointment** docAptArr = docToLoadAppts->getAppointmentArray();

		int i = 0;			//day
		int j = 0;			//timeslot

		std::string txtStrIn;

		while (inFileDocAppts.peek() != std::ifstream::traits_type::eof())//Keeps reading the text untill the end of the file
		{
			std::getline(inFileDocAppts, txtStrIn);				//should read id of patient
			(*(docAptArr + i) + j)->set_idPatient(txtStrIn);
			std::getline(inFileDocAppts, txtStrIn);				//should read id of the nurse
			(*(docAptArr + i) + j)->set_idNurse(txtStrIn);
			std::getline(inFileDocAppts, txtStrIn);				//should read the date of the appointment
			(*(docAptArr + i) + j)->set_date(txtStrIn);


			if (inFileDocAppts.peek() == '|')	//if the next line reads "|" incriment j
			{
				inFileDocAppts.ignore();
				inFileDocAppts.ignore();	//ignore that character and the null character
				j++;
				if (inFileDocAppts.peek() == '-')//if the next line reads "-" incriment i
				{
					inFileDocAppts.ignore();
					inFileDocAppts.ignore();	//ignore that character and the null character
					j = 0;
					i++;
				}
			}
		}
	}
}