#pragma once

#include <string>

using namespace std;

//Class stores necessary information for appointments the doctor has
class Appointment 
{
	private:
		string idPatient_;	
		string idNurse_;	
		string date_;
	public:
		Appointment();
		Appointment(string id_Patient, string id_nurse, string date);
		string get_idPatient();
		string get_idNurse();
		string get_date();
		void set_idPatient(string id_Patient);
		void set_idNurse(string id_nurse);
		void set_date(string date);
};