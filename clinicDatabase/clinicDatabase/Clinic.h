#pragma once

#include <vector>

#include "Nurse.h"

using namespace std;

//Clinic stores ammount of doctors and nurses currently working there
//Clinic also handles adding and removing nurses from the clinic
class Clinic 
{
	private:
		vector<Nurse> nurses_;
		int nbDoctors_;
		int nbNurses_;
	public:
		Clinic(vector<Nurse> vecNur, int numNurses, int numDoctors);
		vector<Nurse> getNurses();
		int getNumDoctors();
		int getNumNurses();
		void setNurses(vector<Nurse> n);
		void setNumDoctors(int numDoctors);
		void setNumNurses(int numNurses);

		void addNurse(Nurse& nurseToAdd);
		void delNurse(Nurse& nurseToDel);

};