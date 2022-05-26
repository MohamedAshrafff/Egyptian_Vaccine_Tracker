#pragma once
#include <string>
#include <iostream>
using namespace std;

struct VaccineInfo
{
	string sideEffect = "N/A";
	string vaccineType = "N/A";
	string timeToGet = "N/A"; // 14 days
	string dateOfFirstDose = "N/A";
	string dateOfSecondDose = "N/A";
};

class User
{
private:
	string nationalId;
	string password;
	string age;
	string fullName;
	string gender;
	string country;
	string governorate;
	bool admin = false;
	bool vaccinated;
	bool firstDose;
	bool secondDose;
	VaccineInfo VaccineInformation;

public:
	User();
	User(string nationalId, string password, string fullName, string age, string gender, string country, string governorate);
	User(string nationalId, string password, string fullName, string age, string gender, string country, string governorate,bool vaccinated,bool firstDose,bool secondDose);
	~User();

	void SetSideEffect(string sideEffect);
	string GetSideEffect();
	
	void SetVaccineType(string vaccineType);
	string GetVaccineType();
	
	void SetTimeToGet(string timeToGet);
	string GetTimeToGet();
	
	void SetDateOfFirstDose(string dateOfFirstDose);
	string GetDateOfFirstDose();

	void SetDateOfSecondDose(string dateOfSecondDose);
	string GetDateOfSecondDose();

	void SetNationalId(string nationalId);
	string GetNationalId();

	void SetFullName(string name);
	string GetFullName();

	void SetPassword(string password);
	string GetPassword();

	void SetGender(string gender);
	string GetGender();

	void SetGovernorate(string governorate);
	string GetGovernorate();

	void SetCountry(string Country);
	string GetCountry();

	void SetAge(string age);
	string GetAge();

	void SetFirstDose(bool firstDose);
	bool GetFirstDose();

	void SetSecondDose(bool secondDose);
	bool GetSecondDose();

	void SetAdmin(bool admin);
	bool GetAdmin();

	void SetVaccinated(bool vaccinated);
	bool GetVaccinated();
};