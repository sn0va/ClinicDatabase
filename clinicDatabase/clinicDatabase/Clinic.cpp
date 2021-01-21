#include "Clinic.h"

Clinic::Clinic(vector<Nurse> vecNur, int numNurses, int numDoctors = 2)
{
	// Parametrized Constructor
	nurses_ = vecNur;
	nbDoctors_ = numDoctors;
	nbNurses_ = numNurses;
}
int Clinic::getNumDoctors() 
{
	// Accessor for number of Doctors
	return nbDoctors_;
}
int Clinic::getNumNurses() 
{
	// Accessor for number of Nurses
	return nbNurses_;
}
vector<Nurse> Clinic::getNurses() 
{
	// Accessor for Nurse Vector
	return nurses_;
}
void Clinic::setNumDoctors(int nD) 
{
	// Modifier for number of Doctors
	nbDoctors_ = nD;
}
void Clinic::setNumNurses(int nN) 
{
	// Modifier for number of Nurses
	nbNurses_ = nN;
}
 
//set nurse vector
void Clinic::setNurses(vector<Nurse> n) 
{
	// Modifier for Nurse Vector
	nurses_ = n;
}


//add nurse to nurse vector
void Clinic::addNurse(Nurse& nurseToAdd)//Chris powers [11/6/2020]
{
	nbNurses_++;
	nurses_.push_back(nurseToAdd);
}

void Clinic::delNurse(Nurse& nurseToDel)//Chris powers [11/9/2020]
{
	for (int i = 0; i < nbNurses_; ++i) {	 //For every item in the vector

		if (nurses_[i] == nurseToDel)		 //If nurse exists in vector
		{			
			nbNurses_--;

			for (int j = i; j < nbNurses_; ++j)	//From that item onward until the last entry
				nurses_[j] = nurses_[j + 1];	//Set each item equal to the one ahead of it

			break;
		}
	}

	nurseToDel.~Nurse();					//call destructor of nurse object
}