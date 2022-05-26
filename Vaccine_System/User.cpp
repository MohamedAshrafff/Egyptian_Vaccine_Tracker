 #include "User.h"
#include <string>
#include <cstring>

User::User()
{
} 

User::User(string nationalId, string password, string fullName, string age, string gender, string country, string governorate)
{
	this->nationalId = nationalId;
	this->password = password;
	this->age = age;
	this->gender = gender;
	this->country = country;
	this->governorate = governorate;
	this->fullName = fullName;
	this->firstDose = false;
	this->secondDose = false;
	this->vaccinated = false;
	this->admin = false;
}
User::User(string nationalId, string password, string fullName, string age, string gender, string country, string governorate,bool vaccinated ,bool firstDose,bool secondDose)
{
	this->nationalId = nationalId;
	this->password = password;
	this->age = age;
	this->gender = gender;
	this->country = country;
	this->governorate = governorate;
	this->fullName = fullName;
	this->firstDose = firstDose;
	this->secondDose = secondDose;
	this->vaccinated = vaccinated;
	this->admin = false;
}


User::~User()
{
}


// Setters & Getters


void User::SetSideEffect(string sideEffect)
{
	this->VaccineInformation.sideEffect = sideEffect;
}
string User::GetSideEffect()
{
	return VaccineInformation.sideEffect;
}

void User::SetVaccineType(string vaccineType)
{
	this->VaccineInformation.vaccineType = vaccineType;

}
string User::GetVaccineType()
{
	return VaccineInformation.vaccineType;

}

void User::SetTimeToGet(string timeToGet)
{
	this->VaccineInformation.timeToGet = timeToGet;
}
string User::GetTimeToGet()
{
	return VaccineInformation.timeToGet;
}

void User::SetDateOfFirstDose(string dateOfFirstDose)
{
	this->VaccineInformation.dateOfFirstDose = dateOfFirstDose;
}
string User::GetDateOfFirstDose()
{
	return VaccineInformation.dateOfFirstDose;
}

void User::SetDateOfSecondDose(string dateOfSecondDose)
{
	this->VaccineInformation.dateOfSecondDose = dateOfSecondDose;
}
string User::GetDateOfSecondDose()
{
	return VaccineInformation.dateOfSecondDose;
}

void User::SetFirstDose(bool firstDose)
{
	this->vaccinated = firstDose;
	this->firstDose = firstDose;
}
bool User::GetFirstDose()
{
	return firstDose;
}

void User::SetSecondDose(bool secondDose)
{
	this->secondDose = secondDose;
}
bool User::GetSecondDose()
{
	return secondDose;
}

void User::SetNationalId(string nationalId)
{
	this->nationalId = nationalId;
}
string User::GetNationalId()
{
	return nationalId;
}

void User::SetPassword(string password)
{
	this->password = password;
}
string User::GetPassword()
{
	return password;
}

void User::SetFullName(string name)
{
	this->fullName = name;
}
string User::GetFullName()
{
	return fullName;
}

void User::SetCountry(string Country)
{
	this->country = Country;
}
string User::GetCountry()
{
	return country;
}

void User::SetGovernorate(string governorate)
{
	this->governorate = governorate;
}
string User::GetGovernorate()
{
	return governorate;
}

void User::SetAge(string age)
{
	this->age = age;
}
string User::GetAge()
{
	return age;
}

void User::SetGender(string gender)
{
	this->gender = gender;
}
string User::GetGender()
{
	return gender;
}


void User::SetAdmin(bool admin)
{
	this->admin = admin;
}
bool User::GetAdmin()
{
	return admin;
}

void User::SetVaccinated(bool vaccinated)
{
	this->vaccinated = vaccinated;
}
bool User::GetVaccinated()
{
	return vaccinated;
}