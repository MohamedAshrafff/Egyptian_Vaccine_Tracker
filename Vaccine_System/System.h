#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <string>
#include <cstring>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <queue>
#include "File.h"
#include "User.h"
#include "List.cpp"
using namespace std;

class System
{
private:
	File file;
	string currentUser;
	vector<string> governorates;
	unordered_map<string, User> umap;
	queue<string> waitingList_dose1, waitingList_dose2;
	vector<string> arrayList_Dose1, arrayList_Dose2;
	vector<string> vaccineTypes = {"Astrazeneca","Sinopharm","Pfizer","Moderna","Johnson & Johnson","Sinovac","Sputnik","Other"};
	vector<string> sideEffects = {"Fatigue","Muscle pain","Fever","Diarrhea","None"};

public:
	System();

	~System();

	void Welcome();
	
	void Login(bool isAdmin);
	
	void ListOfUser();

	void RegisterUser();

	void DeleteUser(string nationalId);

	void EditDataOfUser(string nationalId);

	void ListOfAdmin();

	void AddAdmin(string nationalId);

	void DeleteAllUsers();
	
	void MoveFromWaitingListDose(string list, int n);
	
	void Exit();

	void ViewDataOfUserInUmap(string id);

	void ViewDataOfUserInWaitingList_Dose1(string id);

	void ViewDataOfUserInWaitingList_Dose2(string id);

	void ViewDataOfUserInArrayList_Dose1(string id);

	void ViewDataOfUserInArrayList_Dose2(string id);

	void ViewAllDataOfUsersInSystem();

	void ViewAllDataOfUsersInWaitingList_Dose1();

	void ViewAllDataOfUsersInWaitingList_Dose2();

	void ViewAllDataOfUsersInArrayList_Dose1();

	void ViewAllDataOfUsersInArrayList_Dose2();

	void ViewStatistics();
	
	void ReturnToWaitingLists();

	///////////////////////////Helper Functions///////////////////////////
	string GetTime();

	bool GetTodayDate(string nationalId);

	void Add_Delete_As_Admin(bool choice);

	string* Check_Date_Values(bool choice, bool function);

	string Add_Vaccine_Type();

	string Add_Vaccine_Side_Effect();

	string ChosenGovernorate(bool choice);

	///////////////////////////Excel Functions///////////////////////////

	void ReadData();
	
	void AddUsersAuto1(int n);

	void AddUsersAuto2(int n);

	void AddUsersAuto3(int n);

	void WriteData();

	void Save();
};