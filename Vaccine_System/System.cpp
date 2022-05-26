#pragma warning(suppress : 4996)
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <string>
#include <cstring>
#include <fstream>
#include <Windows.h>
#include <random>
#include <conio.h>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <queue>
#include "File.h"
#include "User.h"
#include "System.h"
#include "Python.h"
using namespace std;

System::System()
{
	ReadData();	
	ReturnToWaitingLists();
	Welcome();
}

System::~System()
{
	WriteData();
}

void System::Welcome()
{
	Sleep(1250);
	system("cls");
	cout << "1) Login as Admin\n2) Login as User\n3) Register\n4) About The Program\n5) Close the program\n\n";
	string choice;
	cout << "Enter your choice: ";
	cin >> choice;
	if (choice == "1")
	{
		bool isAdmin = true;
		Login(isAdmin);
	}

	else if (choice == "2")
	{
		bool isAdmin = false;
		Login(isAdmin);
	}

	else if (choice == "3")
	{
		RegisterUser();
	}
	else if (choice == "4")
	{
		system("cls");
		cout << "The Vaccine Tracking System welcomes you to the program dedicated to obtaining information related to the emerging coronavirus vaccines, and registering to receive the vaccine.In light of the spread of the new Corona virus all over the world, many researchersand specialized companies have sought to find a safe vaccine that will be an effective weapon in the battle against the virus, and the Arab Republic of Egypt has been keen to be at the forefront of countries providing these vaccines, taking into account all the controls announced by the World Health Organization.The global level in terms of countries' commitment to the emergency registration policy for those vaccines, with medical follow-up to the recipients of the vaccines.";
		cout << "\n\n\nPress any key to continue.....\n";
		string z; cin >> z;
		Welcome();
	}
	else if (choice == "5")
	{
		Exit();
	}
	else
	{
		cout << "Wrong entry, try again.\n";
		Sleep(1000);
		Welcome();
	}
}

void System::Login(bool isAdmin)
{
	system("cls");
	if (isAdmin) cout << "Admin Login\n------------------\n";
	else cout << "User Login\n------------------\n";
	cout << "Press on (-1) anytime to return back to the main menu.\n\n";

	string nationalId;
	string password;
	short int attempts = 0; // Login attempts counter for the user.
	bool verified = false; // Verification for the correct password entry.

	do // Loop for wrong entries
	{
		cout << "\nNational ID: "; cin >> nationalId;

		if (nationalId == "-1") Welcome();

		if (nationalId.size() != 14)
			cout << "Wrong national ID, enter your correct national ID: ";
	} while (nationalId.size() != 14);


	if (umap.find(nationalId) != umap.end()) // If the nationalId found in the unordered map (umap).
	{
	    password = umap.at(nationalId).GetPassword();
		bool flag = false;
		if (isAdmin && !umap.at(nationalId).GetAdmin()) {
			cout << "\nSorry you aren't an admin!\n";
			flag = false;
			verified = false;
		}

		else  if (isAdmin && umap.at(nationalId).GetAdmin()) {
			password = "88888888";
			flag = true;
		}

		if(!isAdmin)
		{
			password = umap.at(nationalId).GetPassword();
			flag = true;
		}

		if (flag) {
			do
			{
				attempts++;

				string ch; // Stores the input from the user.
				char z[100]; // Copies the input from the user from (ch) to this char array.
				int c = 0; // Counter for: if the entered character equals to the character in the same place of the saved password in declaration.
				int i = -1; // Index used for getting the original password from the index that corresponds to the entered password by the user.
				int a = 0; // Counter for: counting the number of the entered characters by the user.

				cout << "Password: ";
				ch = _getch(); // Works like cin, but _getch() enters character by character.
				a++;

				i = i + 1;
				strcpy_s(z, ch.c_str()); // Copy the entered character by the user from (ch) to (z)
				if (z[i] == password.at(i))
					c++;
				bool breaked = false; // If the user entered a password which size's exceed the original password's size, this boolean is marked as true and break from the while loop to avoid exceptions.

				while (ch != "\r") // While not pressed on the enter (not finished typing the password).
				{
					i = i + 1;

					cout << "*"; // To make the password entered in asterisks ( ******** ).
					ch = _getch();

					if (ch == "\r")
						break;
					a++;

					strcpy_s(z, ch.c_str()); // Copy the entered character by the user from (ch) to (z)

					if (password.size() == i) // If the original password's size = i, exit from the loop to avoid exceptions.
					{
						breaked = true;
						break;
					}

					if (z[0] == password.at(i))
						c++;
				}

				if (breaked) // Keeps the user entering the password until he press enter (\r) and prints that this password is incorrect.
				{
					while (ch != "\r")
					{
						cout << "*";
						ch = _getch();
					}
				}

				if (c == a && c == password.size() && !breaked) //If c (number of correct entered characters) = a (number of entered characters) then login successfully.
				{
					verified = 1;
					cout << "\nLogin successfully!" << endl;

					Sleep(2000);
					currentUser = nationalId;
					if(isAdmin) ListOfAdmin();
					else ListOfUser();
					break;
				}

				else // If the password is incorrect
				{
					if (attempts == 1)
						cout << "\nWrong password.\nYou have 2 tries left\n";
					else if (attempts == 2)
						cout << "\nWrong password.\nYou have 1 try left\n";
					else
						break;
				}
			} while (attempts <= 3);
		}
		//If not logged in successfully
		if (!verified)
		{
			cout << "\nLogin failed...\n";
			Sleep(1000);
			Welcome();
		}
	}
	else // If the nationalId isn't found in the unordered_map (umap).
	{
		cout << "You haven't registered yet!\n";
		Sleep(250);
		Welcome();
	}
}

void System::ListOfUser()
{
	system("cls");
	cout << "Welcome " << umap[currentUser].GetFullName() << endl;
	cout << "------------------------------------\n";
	cout << "1) Display my data\n2) Edit my data\n3) Delete my account\n4) Logout\n";
	string choice;
	cout << "Enter your choice: ";
	cin >> choice;

	bool flag = true;
	do
	{
		switch (choice[0])
		{
			case '1':
			{
				//Display all my data
				system("cls");
				cout << "Your data\n-----------------------------------------\n";
				ViewDataOfUserInUmap(currentUser);
				cout << "\nPress any key to continue.....\n";
				string choice;
				cin >> choice;
				
				ListOfUser();
			}
				break;
			case '2':
			{
				//Edit my data
				system("cls");
				EditDataOfUser(currentUser);
			}
				break;
			case '3':
			{
				//Delete my account
				cout << "Are you sure you want to delete your account? ( Y / N ) ";
				string c;

				do // Loop for wrong entries
				{
					cin >> c;
					c = tolower(c[0]); // To convert capital letters (if entered) to lower letters.

					if (c != "y" && c != "n")
						cout << "Wrong entry, try again: ";

				} while (c != "y" && c != "n");

				if (c == "y")
				{
					DeleteUser(currentUser);
				}
				else
				{
					Sleep(1000);
					ListOfUser();
				}

				Sleep(2000);
				Save();
				Welcome();
			}
				break;
			case '4':
			{
				//Logout
				cout << "\nLogging out......\n ";
				Save();
				Welcome();
			}
				break;
			default:
			{
				cout << "Wrong entry, try again. \n";
				Sleep(2000);
				flag = false;
				ListOfUser();
			}
				break;
		}
	} while (flag == false);
}

void System::RegisterUser()
{
	system("cls");
	cout << "Registration\n-----------------------------\n";
	cout << "Press on (-1) anytime to return back to the main menu.\n\n";
	cout << "Enter your name: ";
	string fullName;
	cin.ignore(); // To be able to enter a full name not only the first name.
	getline(cin, fullName);
	if (fullName == "-1") Welcome();

	cout << "Enter your country: ";
	string country;
	cin >> country;
	if (country == "-1") Welcome();
	transform(country.begin(), country.end(), country.begin(), ::tolower);

	if (country != "egypt")
	{
		cout << "\nSorry for the inconvenience, we are only accepting Egyptians who are living in Egypt for now.\n\nClosing the program......\n";
		Exit();
	}
	country = "Egypt";

	bool choiceee = 0;
	string governorate = ChosenGovernorate(choiceee);
	cout << "You have choosed " << governorate << ".\n\n";

	cout << "Enter your national ID: ";
	string nationalId;
	bool found = false;
	do // Loop for wrong entries
	{
		found = false;
		cin >> nationalId;
		if (nationalId == "-1") Welcome();

		if (nationalId.size() != 14)
			cout << "\nWrong national ID, enter your correct national ID: ";

		if (umap.find(nationalId) != umap.end() && nationalId.size() == 14) // The national ID already exists in the umap
		{
			found = true;
			cout << "\nThere is an account registered on the system with this national ID, enter your correct national ID: ";
		}
	} while (nationalId.size() != 14 || found);

	cout << "Enter your password: ";
	string password;
	do // Loop for wrong entries
	{
		cin >> password;
		if (password == "-1") Welcome();
		if (password.size() < 8)
			cout << "Password too small, try again with 8 characters minimum: ";
	} while (password.size() < 8);

	cout << "Enter your gender (M / F): ";
	string gender;
	do // Loop for wrong entries
	{
		cin >> gender;
		if (gender == "-1") Welcome();
		gender = tolower(gender[0]); // To convert capital letters (if entered) to lower letters.
		if (gender != "m" && gender != "f")
			cout << "Wrong entry, try again (M / F): ";
	} while (gender != "m" && gender != "f");

	cout << "Enter your age: ";
	string age;
	bool c = false; // To check whether the input is a number or not
	int numAge;
	do // Loop for wrong entries
	{
		cin >> age;
		if (age == "-1") Welcome();
		try {
			numAge = stoi(age);
			c = true;
		}
		catch (exception e) {
			cout << "Wrong entry, try again: " << '\n';
			c = false;
		}

		if (numAge < 18)
		{
			cout << "\nSorry for the inconvenience, we are only accepting peope who are over 18 years old.\n\nClosing the program......\n";
			Exit();
		}
	} while (!c);
	age = to_string(numAge);

	cout << "Are you vaccinated? (Y / N) "; // N -> NOTVACCINATEDQUEUE
	bool vaccinated = NULL;
	do // Loop for wrong entries
	{
		string c;
		cin >> c;
		if (c == "-1") Welcome();
		
		c = tolower(c[0]); // To convert capital letters (if entered) to lower letters.

		if (c != "y" && c != "n")
			cout << "Wrong entry, try again: ";
		else // c == "y" || c == "n"
		{
			if (c == "y")
			{
				vaccinated = true;
				cout << "How many doses have you taken? (1 / 2) ";
				string c;

				do // Loop for wrong entries
				{
					cin >> c;
					if (c == "-1") Welcome();
					if (c != "1" && c != "2")
						cout << "Wrong entry, try again: ";
				} while (c != "1" && c != "2");
				
				// Add vaccine type function
				string a = Add_Vaccine_Type();

				if (c == "1")
				{
					bool choicee = 0;
					//Check_Date_Values(choice);
					User u(nationalId, password, fullName, age, gender, country, governorate, vaccinated, true, false);
					string* z = Check_Date_Values(choicee, 0);
					u.SetDateOfFirstDose(z[0]);
					u.SetVaccineType(a);
					umap[nationalId] = u; // Adds the user to the (umap)
					waitingList_dose2.push(nationalId);
				
					delete[] z;
				}
				else // c == "2"
				{
					User u(nationalId, password, fullName, age, gender, country, governorate, vaccinated, true, true);
					bool choicee = 1;
					string* z = Check_Date_Values(choicee, 0);
					u.SetDateOfFirstDose(z[0]);
					u.SetDateOfSecondDose(z[1]);
					u.SetVaccineType(a);
					
					string ss = Add_Vaccine_Side_Effect();

					u.SetSideEffect(ss);
					umap[nationalId] = u; // Adds the user to the (umap)
					delete[] z;
				}
			}

			else // c == "n"
			{
				vaccinated = false;
				User u(nationalId, password, fullName, age, gender, country, governorate, vaccinated, false, false);

				waitingList_dose1.push(nationalId); // Adds the user to the waiting list (because he isn't vaccinated)
				umap[nationalId] = u; // Adds the user to the (umap)
			}
		}
	} while (vaccinated != true && vaccinated != false);

	cout << "Registered Successfully....." << endl;
	Sleep(2000);
	system("cls");

	cout << "Your entered data\n------------------------------------\n";
	ViewDataOfUserInUmap(nationalId);
	cout << "Press any key to continue...\n";
	cin >> nationalId;
	Welcome();
}

void System::DeleteUser(string nationalId)
{
	cout << "\nDeleted Succesfully...... \n\n";
	cout << "If you want to undo the deletion press (Y), else press (N): ";
	string c;

	do // Loop for wrong entries
	{
		cin >> c;
		c = tolower(c[0]); // To convert capital letters (if entered) to lower letters.

		if (c != "y" && c != "n")
			cout << "Wrong entry, try again: ";
	} while (c != "y" && c != "n");

	if (c == "y")
	{
		cout << "Undo successfully done.....\n";
		Sleep(2000);

	}

	else
	{
		if (!umap[nationalId].GetFirstDose() && !(umap[nationalId].GetSecondDose())) // Got NO Doses
		{
			vector<string>::iterator it;
			if (arrayList_Dose1.size() > 0) {
				while (arrayList_Dose1.size()) {
					it = arrayList_Dose1.begin();
					arrayList_Dose1.erase(it);
					it++;
				}
			}
		}

		else if(umap[nationalId].GetFirstDose() && !umap[nationalId].GetSecondDose()) // Got One Dose
		{
			vector<string>::iterator it;
			if (arrayList_Dose2.size() > 0) {
				while (arrayList_Dose2.size()) {
					it = arrayList_Dose2.begin();
					arrayList_Dose2.erase(it);
					it++;
				}
			}
		}

		umap.erase(nationalId);
		Welcome();
	}
}

void System::EditDataOfUser(string id)
{
	system("cls");
	string newpassword, choice, choice2, newname, newage, newgovernorate, newvaccine, newid;
	cout << "1) Password\t\t";
	cout << "2) Name\t\t\t";
	cout << "3) Age\t\t\n";
	cout << "4) Governorate\t\t";
	cout << "5) Number of doses\t";
	cout << "6) Return to user menu\n";

	cin >> choice;

	bool flag = true;

	do
	{
		switch (choice[0])
		{
		case '1':
		{
			system("cls");
			cout << "Press on (-1) anytime to return back to the main menu.\n\n";
			do
			{
				cout << "Enter your new password: ";
				cin >> newpassword;
				if (newpassword == "-1") ListOfUser();

				if (newpassword.size() < 8)
				{
					cout << "\nPassowrd size should be more than 8 characters.\n" << endl;
				}
			} while (newpassword.size() < 8);

			umap[id].SetPassword(newpassword);
			cout << "\nYour operation is done successfully..... \n\n";
			Sleep(2000);

			ListOfUser();
		}
		break;
		case '2':
		{
			system("cls");
			cout << "Press on (-1) anytime to return back to the main menu.\n\n";
			cout << "Enter your new name: ";
			getline(cin >> ws, newname);
			if (newname == "-1") ListOfUser();

			umap[id].SetFullName(newname);
			cout << "\nYour operation is done successfully \n\n";
			cout << "Here is your updated data: \n";
			cout << "-----------------------------------------\n";
			ViewDataOfUserInUmap(currentUser);
			cout << "\nPress any key to continue...\n";
			cin >> newid;

			ListOfUser();
		}
		break;
		case '3':
		{
			system("cls");
			cout << "Press on (-1) anytime to return back to the main menu.\n\n";
			cout << "Enter your new age: ";

			bool c;
			c = false; // To check whether the input is a number or not
			int numAge;
			do // Loop for wrong entries
			{
				cin >> newage;
				if (newage == "-1") ListOfUser();

				try {
					numAge = stoi(newage);
					c = true;
				}
				catch (exception e) {
					cout << "Wrong entry, try again: " << '\n';
					c = false;
				}
			} while (!c);

			umap[id].SetAge(newage);
			cout << "\nYour operation is done successfully \n\n";
			cout << "Here is your updated data: \n";
			cout << "-----------------------------------------\n";
			ViewDataOfUserInUmap(currentUser);
			cout << "\nPress any key to continue...\n";
			cin >> newid;

			ListOfUser();
		}
		break;
		case '4':
		{
			system("cls");
			cout << "Press on (-1) anytime to return back to the main menu.\n\n";
			//cout << "Enter your governorate: ";
			cout << "Choose your new governorate:" << endl;
			bool choiceee = 1;
			string s = ChosenGovernorate(choiceee);
			umap[id].SetGovernorate(s);
			cout << "\nYour operation is done successfully \n\n";
			cout << "Here is your updated data: \n";
			cout << "-----------------------------------------\n";
			ViewDataOfUserInUmap(currentUser);
			cout << "\nPress any key to continue...\n";
			cin >> newid;

			ListOfUser();
		}
		break;
		case '5':
		{
			system("cls");

			if (!umap[id].GetFirstDose())
			{
				if (!(find(arrayList_Dose1.begin(), arrayList_Dose1.end(), umap[id].GetNationalId()) != arrayList_Dose1.end()))
				{
					cout << "You haven't received the confirmation message to get your first dose, please wait until the message is sent to you.\n";
					Sleep(5000);
					EditDataOfUser(id);
				}

				cout << "Press on (-1) anytime to return back to the main menu.\n\n";

				cout << "Have you taken your first dose? ( Y / N ) ";	


				do
				{
					cin >> newvaccine;
					if (newvaccine == "-1") ListOfUser();
					newvaccine = tolower(newvaccine[0]); // To convert capital letters (if entered) to lower letters.

					if (newvaccine != "y" && newvaccine != "n")
						cout << "Wrong entry, try again: ";

				} while (newvaccine != "y" && newvaccine != "n");

				if (newvaccine == "y")
				{
					string a = Add_Vaccine_Type();

					bool choice = 0;

					string* z = Check_Date_Values(choice, 1);
					umap[id].SetDateOfFirstDose(z[0]);
					umap[id].SetFirstDose(true);
					umap[id].SetVaccineType(a);

					waitingList_dose2.push(id);
					
					auto it = find(arrayList_Dose1.begin(), arrayList_Dose1.end(), id);
					arrayList_Dose1.erase(it);
					umap[id].SetTimeToGet("N\\A");

					delete[] z;
				}
				else
				{
					Sleep(1500);
					ListOfUser();
				}
			}

			else if (umap[id].GetFirstDose() && !umap[id].GetSecondDose())
			{
				if (!(find(arrayList_Dose2.begin(), arrayList_Dose2.end(), umap[id].GetNationalId()) != arrayList_Dose2.end()))
				{
					cout << "You haven't received the confirmation message to get your second dose, please wait until the message is sent to you.\n";
					Sleep(5000);
					EditDataOfUser(id);
				}
				cout << "Press on (-1) anytime to return back to the main menu.\n\n";

				cout << "Have you taken your second dose? ( Y / N ) ";

				do
				{
					cin >> newvaccine;
					if (newvaccine == "-1") ListOfUser();
					newvaccine = tolower(newvaccine[0]); // To convert capital letters (if entered) to lower letters.

					if (newvaccine != "y" && newvaccine != "n")
						cout << "Wrong entry, try again: ";

				} while (newvaccine != "y" && newvaccine != "n");

				if (newvaccine == "y")
				{
					bool choice = 1;

					string* z = Check_Date_Values(choice, 1);

					string ss = Add_Vaccine_Side_Effect();

					umap[id].SetSecondDose(true);
					umap[id].SetDateOfSecondDose(z[0]);
					umap[id].SetSideEffect(ss);

					auto it = find(arrayList_Dose2.begin(), arrayList_Dose2.end(), id);
					arrayList_Dose2.erase(it);
					umap[id].SetTimeToGet("Concluded");

					delete[] z;
				}
				else
				{
					Sleep(1500);
					ListOfUser();
				}
			}

			else
			{
				cout << "You can't edit your doses.....\n";
				Sleep(2000);
				ListOfUser();
			}

			cout << "Your operation is done successfully \n\n";
			cout << "Here is your updated data: \n";
			cout << "-----------------------------------------\n";
			ViewDataOfUserInUmap(currentUser);
			cout << "\nPress any key to continue...\n";
			cin >> newid;

			ListOfUser();
		}
		break;
		case '6':
		{
			Sleep(1000);
			ListOfUser();
		}
		break;
		default:
		{
			cout << "Wrong entry, try again. \n";
			Sleep(2000);
			flag = false;
			EditDataOfUser(id);
		}
		break;
		}
	} while (flag == false);
}

void System::ListOfAdmin()
{
	system("cls");
	cout << "Welcome " << umap[currentUser].GetFullName() << endl;
	cout << "------------------------------------\n";
	cout << "1) Display all users in the system\n2) Display all users in Waiting List 1 (For users who haven't taken the first dose)\n3) Display all users in Waiting List 2 (For users who haven't taken the second dose)\n4) Display all users in Array List 1 (For users who received the message to take the first dose)\n5) Display all users in Array List 2 (For users who received the message to take the second dose)\n6) Search for a user\n7) Display statistics\n8) Delete a user\n9) Add an admin\n10) Move users from Waiting List to Array Lists to take get vaccinated\n11) Delete all users in the system\n12) Logout\n";
	string choice;
	cout << "\nEnter your choice: "; cin >> choice;
	bool flag = true;

	if (choice == "12") choice = "-";
	else if (choice == "10") choice = "0";
	else if (choice == "11") choice = "_";

	do
	{
		switch (choice[0])
		{
			case '1':
			{
				//Display all users in the system
				system("cls");
				ViewAllDataOfUsersInSystem();
			}
				break;
			case '2':
			{
				//Display all users in Waiting List 1 (For users who haven't taken the first dose)
				system("cls");
				ViewAllDataOfUsersInWaitingList_Dose1();
			}
				break;
			case '3':
			{
				//Display all users in Waiting List 2 (For users who haven't taken the second dose)
				system("cls");
				ViewAllDataOfUsersInWaitingList_Dose2();
			}
				break;
			case '4':
			{
				//Display all users in Array List 1 (For users who received the message to take the first dose)
				system("cls");
				ViewAllDataOfUsersInArrayList_Dose1();
			}
				break;
			case '5':
			{
				//Display all users in Array List 2 (For users who received the message to take the second dose)
				system("cls");
				ViewAllDataOfUsersInArrayList_Dose2();
			}
				break;
			case '6':
			{
				system("cls");
				cout << "Press on (-1) anytime to return back to the main menu.\n\n";
				cout << "Enter the national ID of the user: ";
				string nationalId;
				cin >> nationalId;
				if (nationalId == "-1") ListOfAdmin();
				
				if(umap.find(nationalId) != umap.end())
				{
					cout << "\n";
					ViewDataOfUserInUmap(nationalId);
					cout << "\nPress any key to continue.....\n";
					string choice;
					cin >> choice;

					ListOfAdmin();
				}
				else
				{
					do // Loop for wrong entries
					{
						if (nationalId == "-1")
						{
							Sleep(1000);
							ListOfAdmin();
							break;
						}

						if (nationalId.size() != 14)
							cout << "Wrong national ID, enter your correct national ID or press (-1) to return to the main menu: ";

						if (umap.find(nationalId) == umap.end() && nationalId.size() == 14) // The national ID already doesn't in the umap
						{
							cout << "There is no such an account in the system with this national ID, re-enter the correct national ID or press (-1) to return to the main menu.";
						}
						cin >> nationalId;

					} while (nationalId.size() != 14);	
						
				}
			}
				break;
			case '7':
			{
				// Display statistics
				system("cls");
				ViewStatistics();
			}
				break;
			case '8':
			{
				// Delete a user
				bool choice = 0;
				Add_Delete_As_Admin(choice);
				system("cls");
			}
				break;
			case '9':
			{
				// Add an user as an admin
				bool choice = 1;
				Add_Delete_As_Admin(choice);
				system("cls");
			}
				break;
			case '0':
			{
				system("cls");
				cout << "Press on (-1) anytime to return back to the main menu.\n\n";
				// Move users from Waiting List to Array Lists to take get vaccinated
				cout << "\nChoose which waiting list you want to move users from.\n\n1) Waiting List 1 (For users who haven't taken the first dose)\n2) Waiting List 2 (For users who haven't taken the second dose)\n\n";
				cout << "Available users in Waiting List 1: " << waitingList_dose1.size() << endl;
				cout << "Available users in Waiting List 2: " << waitingList_dose2.size() << endl;
				string c;
				do
				{
					cin >> c;
					if (c == "-1") ListOfAdmin();

					if (c != "2" && c != "1")
						cout << "Wrong entry, try again: ";
				} while (c != "2" && c != "1");

				cout << "\n\nEnter the number of users you want to move: ";
				string num;
				int n;
				bool cc = true;

				do
				{
					cin >> num;
					if (num == "-1") ListOfAdmin();
					try {
						n = stoi(num);
						cc = true;
					}
					catch (exception e) {
						cout << "Wrong entry, try again with entering only numbers: " << "\n";
						cc = false;
					}

					if (c == "1" && cc)
					{
						if (waitingList_dose1.size() < n)
						{
							cout << "The desired number is more than the users in the waiting list.\n";
						}
					}
					else if (c == "2" && cc)
					{
						if (waitingList_dose2.size() < n)
						{
							cout << "The desired number is more than the users in the waiting list.\n";
						}
					}

					// To break from the loop
					if (c == "1" && cc && waitingList_dose1.size() >= n) break;
					else if (c == "2" && cc && waitingList_dose2.size() >= n) break;
				} while (true);
				
				MoveFromWaitingListDose(c, n);
				cout << "\nYour operation is done successfully..... \n";
				Sleep(1000);
				ListOfAdmin();
			}
			break;
			case '_':
			{
				system("cls");
				cout << "Press on (-1) anytime to return back to the main menu.\n\n";
				
				cout << "CAUTION: This will erase all the existing data from our system!\n\nDo you wish to continue?\nPress (Y) to continue, otherwise will return you to the main menu:\n";
				string choice;
				cin >> choice;
				
				if (choice == "y" || choice == "Y")
				{
					DeleteAllUsers();
					cout << "\n\nAll data erased successfully.\n\n";
					cout << "Press any key to continue.....\n";
					cin >> choice;
					ListOfAdmin();
				}
				else
					ListOfAdmin();
			}
				break;
			case '-':
			{
				// Logout
				cout << "Logging out......\n ";
				Save();
				Welcome();
			}
				break;
			default: 
			{
				cout << "Wrong entry, try again. \n";
				flag = false;
				Sleep(1500);
				ListOfAdmin();
			}
				break;
		}
	} while (flag == false);
}

void System::AddAdmin(string nationalId)
{
	umap[nationalId].SetAdmin(true);
	cout << "Added successfully " <<umap[nationalId].GetFullName()<<" to the admins......\n";
	Sleep(1500);
	ListOfAdmin();
}

void System::DeleteAllUsers()
{
	umap.clear();
	arrayList_Dose1.clear();
	arrayList_Dose2.clear();
	queue<string> empty;
	waitingList_dose1 = empty;
	waitingList_dose2 = empty;
}

void System::MoveFromWaitingListDose(string list, int n)
{
	if (list == "1")
	{
		for (size_t i = 0; i < n; i++)
		{
			string nationalId = waitingList_dose1.front();
			if (umap.find(nationalId) != umap.end() && waitingList_dose1.size() > 0) {
				arrayList_Dose1.push_back(waitingList_dose1.front());
				 umap[nationalId].SetTimeToGet(GetTime());
			}
			else
				i--;
			waitingList_dose1.pop();
		}
	}
	else
	{
		for (size_t i = 0; i < n; i++)
		{
			string nationalId = waitingList_dose2.front();
			if (umap.find(nationalId) != umap.end() && waitingList_dose2.size()>0){
				arrayList_Dose2.push_back(waitingList_dose2.front());
				
				umap[nationalId].SetTimeToGet(GetTime());
			}
			else
				i--;
			waitingList_dose2.pop();
		}
	}
}

void System::Exit()
{
	WriteData();
	exit(0);
}

void System::ViewDataOfUserInUmap(string id)
{
	cout << "Name: " << umap[id].GetFullName() << endl;
	cout << "National ID: " << umap[id].GetNationalId() << endl;
	cout << "Age: " << umap[id].GetAge() << endl;
	cout << "Country: " << umap[id].GetCountry() << endl;
	cout << "Governorate: " << umap[id].GetGovernorate() << endl;
	cout << "Gender: " << umap[id].GetGender() << endl;
	cout << "Vaccinated: ";
	if (umap[id].GetVaccinated() == 1)
	{
		cout << "Yes" << endl;
		cout <<"First Dose Date: "<< umap[id].GetDateOfFirstDose()<<endl;//
		cout << "Second Dose Date: " << umap[id].GetDateOfSecondDose()<<endl;//
		cout << "Vaccine Type: " << umap[id].GetVaccineType()<<endl;//
		cout << "Side Effect: " << umap[id].GetSideEffect()<<endl;//
	}	
	else  cout << "No" << endl;
	cout << "-----------------------------------------";
	cout << endl;
}

void System::ViewDataOfUserInWaitingList_Dose1(string id)
{
	User u = umap[id];
	cout << "Name: " << u.GetFullName() << endl;
	cout << "National ID: " << u.GetNationalId() << endl;
	cout << "Age: " << u.GetAge() << endl;
	cout << "Country: " << u.GetCountry() << endl;
	cout << "Governorate: " << u.GetGovernorate() << endl;
	cout << "Gender: " << u.GetGender() << endl;
	cout << "Vaccinated: No" << endl;
	cout << "-----------------------------------------";
	cout << endl;
}

void System::ViewDataOfUserInWaitingList_Dose2(string id)
{
	User u = umap[id];
	cout << "Name: " << u.GetFullName() << endl;
	cout << "National ID: " << u.GetNationalId() << endl;
	cout << "Age: " << u.GetAge() << endl;
	cout << "Country: " << u.GetCountry() << endl;
	cout << "Governorate: " << u.GetGovernorate() << endl;
	cout << "Gender: " << u.GetGender() << endl;
	cout << "Vaccinated: Yes" << endl;
	cout << "First Dose Date: " << u.GetDateOfFirstDose() << endl;
	cout << "Vaccine Type: " << u.GetVaccineType() << endl;
	cout << "-----------------------------------------";
	cout << endl;
}

void System::ViewDataOfUserInArrayList_Dose1(string id)
{
	User u = umap[id];
	cout << "Name: " << u.GetFullName() << endl;
	cout << "National ID: " << u.GetNationalId() << endl;
	cout << "Age: " << u.GetAge() << endl;
	cout << "Country: " << u.GetCountry() << endl;
	cout << "Governorate: " << u.GetGovernorate() << endl;
	cout << "Gender: " << u.GetGender() << endl;
	cout << "Vaccinated: ";
	if (u.GetVaccinated())
	{
		cout << "Yes" << endl;
		cout << "First Dose Date: " << u.GetDateOfFirstDose() << endl;//
		cout << "Vaccine Type: " << u.GetVaccineType() << endl;//
	}
	else  cout << "No" << endl;
	cout << "Time to get: " << u.GetTimeToGet() << endl;
	cout << "-----------------------------------------";
	cout << endl;
}

void System::ViewDataOfUserInArrayList_Dose2(string id)
{
	User u = umap[id];
	cout << "Name: " << u.GetFullName() << endl;
	cout << "National ID: " << u.GetNationalId() << endl;
	cout << "Age: " << u.GetAge() << endl;
	cout << "Country: " << u.GetCountry() << endl;
	cout << "Governorate: " << u.GetGovernorate() << endl;
	cout << "Gender: " << u.GetGender() << endl;
	cout << "Vaccinated: ";
	cout << "Yes" << endl;
	cout << "First Dose Date: " << u.GetDateOfFirstDose() << endl;//
	cout << "Second Dose Date: " << u.GetDateOfSecondDose() << endl;//
	cout << "Vaccine Type: " << u.GetVaccineType() << endl;//
	cout << "Side Effect: " << u.GetSideEffect() << endl;//
	cout << "Time to get: " << u.GetTimeToGet() << endl;
	cout << "-----------------------------------------";
	cout << endl;
}

void System::ViewAllDataOfUsersInSystem()
{
	int i = 0;
	bool cont = true;
	for (auto m : umap)
	{
		ViewDataOfUserInUmap(m.first);
		i++;
		if (i % 20 == 0)
		{
			cout << "\nPress (Y) to continue displaying another 20 rows, otherwise you will be returned to main menu:\n";
			string x;
			cin >> x;
			if (x == "y" || x == "Y")
				continue;
			else
			{
				cont = false;
				break;
			}
		}
	}

	if (cont)
	{
		cout << "\n\nAll users are displayed successfully......\n";
		cout << "\nPress any key to continue......\n";
		string x;
		cin >> x;
	}
	ListOfAdmin();
}

void System::ViewAllDataOfUsersInWaitingList_Dose1()
{
	queue<string> test = waitingList_dose1;
	int i = 0;
	bool cont = true;

	while (!test.empty())
	{
		string id = test.front();

		ViewDataOfUserInWaitingList_Dose1(id);
		test.pop();
		i++;

		if (i % 20 == 0)
		{
			cout << "\nPress (Y) to continue displaying another 20 rows, otherwise you will be returned to main menu:\n";
			string x;
			cin >> x;
			if (x == "y" || x == "Y")
				continue;
			else
			{
				cont = false;
				break;
			}
		}
	}

	if (cont)
	{
		cout << "\n\nAll users are displayed successfully......\n";
		cout << "\nPress any key to continue......\n";
		string x;
		cin >> x;
	}
	ListOfAdmin();
}

void System::ViewAllDataOfUsersInWaitingList_Dose2()
{
	queue<string> test = waitingList_dose2;
	int i = 0;
	bool cont = true;

	while (!test.empty())
	{
		string id = test.front();
		ViewDataOfUserInWaitingList_Dose2(id);
		test.pop();
		i++;

		if (i % 20 == 0)
		{
			cout << "\nPress (Y) to continue displaying another 20 rows, otherwise you will be returned to main menu:\n";
			string x;
			cin >> x;
			if (x == "y" || x == "Y")
				continue;
			else
			{
				cont = false;
				break;
			}
		}
	}

	if (cont)
	{
		cout << "\n\nAll users are displayed successfully......\n";
		cout << "\nPress any key to continue......\n";
		string x;
		cin >> x;
	}
	ListOfAdmin();
}

void System::ViewAllDataOfUsersInArrayList_Dose1()
{
	int i = 0;
	bool cont = true;

	for (string p : arrayList_Dose1)
	{
		ViewDataOfUserInArrayList_Dose1(p);
		i++;
		if (i % 20 == 0)
		{
			cout << "\nPress (Y) to continue displaying another 20 rows, otherwise you will be returned to main menu:\n";
			string x;
			cin >> x;
			if (x == "y" || x == "Y")
				continue;
			else
			{
				cont = false;
				break;
			}
		}
	}

	if (cont)
	{
		cout << "\n\nAll users are displayed successfully......\n";
		cout << "\nPress any key to continue......\n";
		string x;
		cin >> x;
	}
	ListOfAdmin();
}

void System::ViewAllDataOfUsersInArrayList_Dose2()
{
	int i = 0;
	bool cont = true;

	for (string p : arrayList_Dose2)
	{
		ViewDataOfUserInArrayList_Dose2(p);
		i++;
		if (i % 20 == 0)
		{
			cout << "\nPress (Y) to continue displaying another 20 rows, otherwise you will be returned to main menu:\n";
			string x;
			cin >> x;
			if (x == "y" || x == "Y")
				continue;
			else
			{
				cont = false;
				break;
			}
		}
	}

	if (cont)
	{
		cout << "\n\nAll users are displayed successfully......\n";
		cout << "\nPress any key to continue......\n";
		string x;
		cin >> x;
	}
	ListOfAdmin();
}

void System::ViewStatistics()
	{
		string number;
		cout << "Enter the number of graph you want to see:\n";
		cout << "1) Percentage of First Dose\n2) Percentage of Second Dose\n3) Percentage of Females and Males registered in the system\n4) Highest vaccine type\n5) Highest governorate for people who fully vaccinated\n6) Highest vaccine for diarrhea side effect\n7) Highest vaccine for fever side effect Highest\n8) Highest vaccine for fatigue side effect\n9) Highest Vaccine for muscle pain side effect\n10) Highest vaccine for safety rate\n11) Display all the graphs\n12) Display statistical insights\n";
		cin >> number;

		if (number == "10") number = "0";
		else if (number == "11") number = ".";
		else if (number == "12") number = "-";


		Py_Initialize();
		switch (number[0])
		{
		case '1':
		{
			//Run a simple file
			FILE* PScriptFile = fopen("Percentage of First Dose.py", "r");
			if (PScriptFile)
			{
				PyRun_SimpleFile(PScriptFile, "Percentage of First Dose.py");
				fclose(PScriptFile);
			}

			ListOfAdmin();
		}
		break;
		case '2':
		{
			//Run a simple file
			FILE* PScriptFile = fopen("Percentage of Second Dose.py", "r");
			if (PScriptFile)
			{
				PyRun_SimpleFile(PScriptFile, "Percentage of Second Dose.py");
				fclose(PScriptFile);
			}

			ListOfAdmin();
		}
		break;
		case '3':
		{

			//Run a simple file
			FILE* PScriptFile = fopen("Percentage of Females and Males registered in the system.py", "r");
			if (PScriptFile)
			{
				PyRun_SimpleFile(PScriptFile, "Percentage of Females and Males registered in the system.py");
				fclose(PScriptFile);
			}

			ListOfAdmin();
		}
		break;
		case '4':
		{

			//Run a simple file
			FILE* PScriptFile = fopen("Highest vaccine type.py", "r");
			if (PScriptFile)
			{
				PyRun_SimpleFile(PScriptFile, "Highest vaccine type.py");
				fclose(PScriptFile);
			}

			ListOfAdmin();
		}
		break;
		case '5':
		{

			//Run a simple file
			FILE* PScriptFile = fopen("Highest governorate for people who fully vaccinated.py", "r");
			if (PScriptFile)
			{
				PyRun_SimpleFile(PScriptFile, "Highest governorate for people who fully vaccinated.py");
				fclose(PScriptFile);
			}

			ListOfAdmin();
		}
		break;
		case '6':
		{
			//Run a simple file
			FILE* PScriptFile = fopen("Highest vaccine for diarrhea side effect.py", "r");
			if (PScriptFile)
			{
				PyRun_SimpleFile(PScriptFile, "Highest vaccine for diarrhea side effect.py");
				fclose(PScriptFile);
			}

			ListOfAdmin();
		}
		break;
		case '7':
		{
			//Run a simple file
			FILE* PScriptFile = fopen("Highest vaccine for fatigue side effect.py", "r");
			if (PScriptFile)
			{
				PyRun_SimpleFile(PScriptFile, "Highest vaccine for fatigue side effect.py");
				fclose(PScriptFile);
			}

			ListOfAdmin();
		}
		break;
		case '8':
		{
			//Run a simple file
			FILE* PScriptFile = fopen("Highest vaccine for fever side effect.py", "r");
			if (PScriptFile)
			{
				PyRun_SimpleFile(PScriptFile, "Highest vaccine for fever side effect.py");
				fclose(PScriptFile);
			}

			ListOfAdmin();
		}
		break;
		case '9':
		{
			//Run a simple file
			FILE* PScriptFile = fopen("Highest Vaccine for muscle pain side effect.py", "r");
			if (PScriptFile)
			{
				PyRun_SimpleFile(PScriptFile, "Highest Vaccine for muscle pain side effect.py");
				fclose(PScriptFile);
			}

			ListOfAdmin();
		}
		break;
		case '0':
		{
			//Run a simple file
			FILE* PScriptFile = fopen("Highest vaccine for safety rate.py", "r");
			if (PScriptFile)
			{
				PyRun_SimpleFile(PScriptFile, "Highest vaccine for safety rate.py");
				fclose(PScriptFile);
			}

			ListOfAdmin();
		}
		break;
		case '.':
		{
			//Run a simple file
			FILE* PScriptFile = fopen("Display All The Graphs.py", "r");
			if (PScriptFile)
			{
				PyRun_SimpleFile(PScriptFile, "Display All The Graphs.py");
				fclose(PScriptFile);
			}

			ListOfAdmin();
		}
		break;
		case '-':
		{
			//Run a simple file
			system("cls");
			FILE* PScriptFile = fopen("Calculations.py", "r");
			if (PScriptFile)
			{
				PyRun_SimpleFile(PScriptFile, "Calculations.py");
				fclose(PScriptFile);
			}
			cout << "\n\nPress any key to continue.....\n";
			string x;
			cin >> x;
			ListOfAdmin();
		}
		break;
		default:
		{
			cout << "Wrong entry, try again. \n";
			Sleep(2000);
			ListOfAdmin();
		}
		break;
		}
		Py_Finalize();
	}
 
void System::ReturnToWaitingLists() 
{
	vector<string>::iterator it;

	if(arrayList_Dose1.size() > 0){
		int i = arrayList_Dose1.size();
		while (arrayList_Dose1.size() > 0 && i > 0) {
			it = arrayList_Dose1.begin();
			if (GetTodayDate(*it))
			{
				waitingList_dose1.push(*it);
				arrayList_Dose1.erase(it);
			}
			it++;
			i--;
		}
	}

	if (arrayList_Dose2.size() > 0) {
		int i = arrayList_Dose2.size();
		while (arrayList_Dose2.size() > 0 && i > 0) {
			it = arrayList_Dose2.begin();
			if (GetTodayDate(*it))
			{
				waitingList_dose2.push(*it);
				arrayList_Dose2.erase(it);
			}
			it++;
			i--;
		}
	}
}

///////////////////////////Helper Functions///////////////////////////

string System::GetTime()
{
	time_t now = time(0);
	tm* ltm = localtime(&now);
	int year = 1900 + ltm->tm_year;
	int month = 1 + ltm->tm_mon;
	int day = ltm->tm_mday;

	int day2 = day+14;
	int month2 = month;
	int year2 = year;
	if (day2 > 30)
	{
		day2 %= 30;
		month2++;
	}
	if (month2 > 12)
	{
		month2 %= 12;
		year2++;
	}
	string k = to_string(day2)+"/"+to_string(month2)+"/"+to_string(year2);
		return k;
}

bool System::GetTodayDate(string nationalId) {
	time_t now = time(0);
	tm* ltm = localtime(&now);
	int day = ltm->tm_mday;
	string deadline = umap[nationalId].GetTimeToGet();
	string currentday="";
	
	int i = 0;
	while( deadline[i] != '/'){
		currentday += deadline[i];
		i++;
	}
	int x = stoi(currentday);
	if (x == day) return true;
	else return false;
}

void System::Add_Delete_As_Admin(bool choice)
{
	system("cls");
	cout << "Press on (-1) anytime to return back to the main menu.\n\n";
	cout << "Enter the national ID of the user: ";
	string ID;

	do
	{
		cin >> ID;
		if (ID == "-1") ListOfAdmin();

		if (umap.find(ID) != umap.end()) // If the nationalId found in the unordered map (umap).
		{
			if (choice == 0)
			{
				cout << "\n";
				ViewDataOfUserInUmap(ID);
				cout << "Are you sure you want to delete the user associated with this national ID (" << ID << ")? ( Y / N ):\n";
			}
			else if (choice == 1)
			{
				if (umap[ID].GetAdmin() == 1)
				{
					cout << "This user is already an admin.\n";
					Sleep(2500);
					ListOfAdmin();
				}
				else
				{
					cout << "\n";
					ViewDataOfUserInUmap(ID);
					cout << "Are you sure you want to make this user an admin? ( Y / N ):\n";
				}
			}
			string c;

			do // Loop for wrong entries
			{
				cin >> c;
				if (c == "-1") ListOfAdmin();

				c = tolower(c[0]); // To convert capital letters (if entered) to lower letters.

				if (c != "y" && c != "n")
					cout << "Wrong entry, try again: ";

			} while (c != "y" && c != "n");

			if (c == "y")
			{
				if (choice == 0)
					DeleteUser(ID);
				else if (choice == 1)
					AddAdmin(ID);
				break;
			}
			else
			{
				Sleep(1500);
				ListOfAdmin();
				break;
			}
		}
		else
		{
			if (ID == "0")
			{
				ListOfAdmin();
				break;
			}
			cout << "Wrong national ID, enter the correct national ID: ";
		}
	} while (true);
}

string* System::Check_Date_Values(bool choice, bool function)
{
	int m = 0;
	if (!function) // RegisterUser
	{
		if (choice == 0) m = 1;
		else if (choice == 1) m = 2;
	}
	else  // EditDataOfUser
	{
		m = 1;
	}

	string s;
	string* x = new string [2];


	for (size_t i = 0; i < m; i++)
	{
		if (!function) // RegisterUser
		{
			if (i == 0)
				cout << "Enter the date of your first dose: \n";
			else
				cout << "Enter the date of your second dose: \n";
		}
		else // EditDataOfUser
		{
			if(choice == 0)
				cout << "Enter the date of your first dose: \n";
			else
				cout << "Enter the date of your second dose: \n";
		}

		string day, month, year;
		cout << "Day: "; cin >> day;
		if (day == "-1" && !function) Welcome();
		else if (day == "-1" && function) ListOfUser();
		
		cout << "Month: "; cin >> month;
		if (month == "-1" && !function) Welcome();
		else if (month == "-1" && function) ListOfUser();

		cout << "Year: "; cin >> year;
		if (year == "-1" && !function) Welcome();
		else if (year == "-1" && function) ListOfUser();

		// For checking if the date is valid

		bool c = false;
		int dayy, monthh, yearr;
		try {
			dayy = stoi(day);
			monthh = stoi(month);
			yearr = stoi(year);
			c = true;
		}
		catch (exception e) {
			cout << "\nWrong entry, try again with only entering numbers.\n" << '\n';
			c = false;
		}

		bool flag;

		if (2019 <= yearr <= 2022)
		{
			if ((monthh == 1 || monthh == 3 || monthh == 5 || monthh == 7 || monthh == 8 || monthh == 10 || monthh == 12) && (dayy > 0 && dayy <= 31))
				flag = true;
			else
			{
				if ((monthh == 4 || monthh == 6 || monthh == 9 || monthh == 11) && (dayy > 0 && dayy <= 30))
					flag = true;
				else
				{
					if (monthh == 2)
					{
						if ((yearr % 400 == 0 || (yearr % 100 != 0 && yearr % 4 == 0)) && (dayy > 0 && dayy <= 29))
							flag = true;
						else if (dayy > 0 && dayy <= 28)
							flag = true;
						else
						{
							flag = false;
							cout << "\nWrong date, try again with a valid date.\n" << "\n";
						}
					}
					else
					{
						flag = false;
						cout << "\nWrong date, try again with a valid date.\n" << "\n";
					}
				}
			}
		}
		else
		{
			flag = false;
			cout << "\nWrong date, try again with a valid date.\n" << "\n";
		}

		time_t now = time(0);
		tm* ltm = localtime(&now);
		int yearrrr = 1900 + ltm->tm_year;
		int monthhhh = 1 + ltm->tm_mon;
		int dayyyy = ltm->tm_mday;

		if ((yearrrr > yearr) || (yearr == yearrrr && monthhhh > monthh) || (yearr == yearrrr && (monthhhh == monthh) && dayyyy >= dayy))
		{
		}
		else
		{
			cout << "\nWrong date, try again with a valid date.\n" << "\n";
			i--;
			flag = false;
			continue;
		}


		if (c && flag)
		{
			s = day + '/' + month + '/' + year;

			if (!function) // RegisterUser
			{
				if (i == 0)
					x[0] = s;
				else
					x[1] = s;
			}
			else // EditDataOfUser
			{
				x[0] = s;
			}
		}
		else
			i--;
	}

	return x;
}

string System::Add_Vaccine_Type()
{
	cout << "\nWhat is the vaccine type that you have taken?: \n\n";
	int count = 1;
	for (auto t : vaccineTypes)
	{
		cout << count << ')' << " " << t << "\t";
		if (count % 4 == 0) cout << endl;
		count++;
	}

	string vT;
	bool f = false;
	int choice;
	do
	{
		cin >> vT;
		if (vT == "-1") Welcome();

		try {
			choice = stoi(vT);
			f = true;
		}
		catch (exception e) {
			cout << "Wrong entry, try again with entering the number beside the preferred vaccine type only e.g -> 1 for Astrazeneca: " << '\n';
			f = false;
		}


		if (choice >= 1 && choice <= 8)
			f = true;
		else
		{
			if (f == true)
				cout << "Wrong entry, try again with entering the number beside the preferred vaccine type only e.g -> 1 for Astrazeneca: " << '\n';
			f = false;
		}

	} while (f == false);

	cout << "You have choosed " << vaccineTypes[choice - 1] << "\n\n";

	string a = vaccineTypes[choice - 1];

	return a;
}

string System::Add_Vaccine_Side_Effect()
{
	cout << "\nAfter you have taken the 2 doses, are there any side effects that were noticeable? Please choose if any\n" << endl;
	int count = 1;
	for (auto s : sideEffects)
	{
		cout << count << ')' << " " << s << "\t\t";
		if (count % 3 == 0) cout << endl;
		count++;
	}
	cout << endl;

	string se;
	bool f = false;
	int choice;
	do
	{
		cin >> se;
		if (se == "-1") Welcome();
		try {
			choice = stoi(se);
			f = true;
		}
		catch (exception e) {
			cout << "Wrong entry, try again with entering the number beside the preferred vaccine type only e.g -> 1 for Fatigue: " << '\n';
			f = false;
		}


		if (choice >= 1 && choice <= 5)
			f = true;
		else
		{
			if (f == true)
				cout << "Wrong entry, try again with entering the number beside the preferred vaccine type only e.g -> 1 for Fatigue: " << '\n';
			f = false;
		}

	} while (f == false);

	cout << "You have choosed " << sideEffects[choice - 1] << "\n\n";
	string ss = sideEffects[choice - 1];

	return ss;
}

string System::ChosenGovernorate(bool choice)
{
	cout << "Choose one of the following governorates: \n\n";
	int count = 1;

	for (auto v : governorates)
	{
		cout << count << ')' << " " << v << "\t\t";
		if (count % 3 == 0) cout << endl;
		count++;
	}
	cout << endl;
	string governorate;
	bool c = false;
	int choicee;

	do
	{
		cin >> governorate;
		if (choice == 0) // RegisterUser
		{
			if (governorate == "-1") Welcome();
		}
		else if (choice == 1) // EditDataOfUser
		{
			if (governorate == "-1") ListOfUser();
		}
		try {
			choicee = stoi(governorate);
			c = true;
		}
		catch (exception e) {
			cout << "\nWrong entry, try again with entering the number beside the preferred governorate only e.g -> 1 for Alexandria: " << "\n";
			c = false;
		}

		if (choicee >= 1 && choicee <= 27)
			c = true;
		else
		{
			if(c == true)
				cout << "\nWrong entry, try again with entering the number beside the preferred governorate only e.g -> 1 for Alexandria: " << "\n";
			c = false;
		}

	} while (c == false);
	governorate = governorates[choicee - 1];
	return governorate;
}

///////////////////////////Excel Functions///////////////////////////

void System::ReadData()
{
	umap = file.ReadFromSystem();
	waitingList_dose1 = file.ReadWaitingList("waitingList_Dose1.csv");
	waitingList_dose2 = file.ReadWaitingList("waitingList_Dose2.csv");
	arrayList_Dose1 = file.ReadArrList("arrayList_Dose1.csv");
	arrayList_Dose2 = file.ReadArrList("arrayList_Dose2.csv");
	governorates = file.ReadTxt("governorate.txt");
}

void System::AddUsersAuto1(int n)
{
	vector<string> nationalIdvector;
	vector<string>namesmvector;
	vector<string>namesfvector;
	vector<string>governoratevector;
	vector<string> row;
	string line, word;
	string x;
	nationalIdvector = file.ReadTxt("nationalId.txt");
	namesfvector = file.ReadTxt("namesofgirls.txt");
	namesmvector = file.ReadTxt("namesofboys.txt");
	governoratevector = file.ReadTxt("governorate.txt");
	cout << nationalIdvector.size() << " " << namesfvector.size() << " " << namesmvector.size() << " " << governoratevector.size() << endl;
			
	fstream file1;
	fstream file2;
	fstream file3;
	// opens an existing csv file or creates a new file.
	file1.open("waitingList_Dose1.csv", ios::out | ios::app);
	if (file1.is_open())
		cout << "OPENED1\n";

	file2.open("waitingList_Dose2.csv", ios::out | ios::app);
	if (file2.is_open())
		cout << "OPENED2\n";

	file3.open("data.csv", ios::out | ios::app);
	if (file3.is_open())
		cout << "OPENED3\n";

	while (n--)
	{
		int n1, n2, n3, n4;
		int g = rand() % 27;
		int mood = rand() % 2;
		string id;
		if (mood == 0)
			n1 = rand() % 44;
		else
			n1 = rand() % 50;
		while (true)
		{
			n2 = rand() % 44;
			if (n2 != n1)
			{

				break;
			}
		}
		while (true)
		{
			n3 = rand() % 44;
			if (n3 != n2)
			{

				break;
			}
		}
		while (true)
		{
			n4 = rand() % 44;
			if (n4 != n3)
			{

				break;
			}
		}
		string name;
		if (mood == 0)
		{
				name = namesmvector[n1];
		}
		else
		{
			name = namesfvector[n1];
		}
		name+=" " + namesmvector[n2] + " " + namesmvector[n3] + " " + namesmvector[n4];
		string governorate = governoratevector[g];
		string age = to_string(rand() % 73 + 18);
		string gender;
		string password = to_string(rand() % 100000000 + 10000000);
		string vaccinated, firstDose, SecondDose;
		vaccinated = firstDose = SecondDose = "0";
		int i = rand() % nationalIdvector.size();
		string nationalId = nationalIdvector[i];
		auto it = nationalIdvector.begin() + i;
		nationalIdvector.erase(it);
		if (mood == 0)
			gender = "m";
		else
			gender = "f";

		string vaccineType, sideEffect, dateOfFirstDose,dateOfSecondDose, TimeToGet;
		vaccineType = sideEffect = dateOfFirstDose =dateOfSecondDose= TimeToGet="N\\A";

		file3 << nationalId << ","
			<< password << ","
			<< name << ","
			<< age << ","
			<< gender << ","
			<< "Egypt" << ","
			<< governorate << ","
			<< "0" << ","
			<< "0" << ","
			<< "0" << ","
			<< "0" << ","
			<< vaccineType << ","
			<< sideEffect << ","
			<< dateOfFirstDose << ","
			<< dateOfSecondDose << ","
			<< TimeToGet
			<< "\n";
		file1 << nationalId << endl;
	}
		
	fstream file;
	// opens an existing csv file or creates a new file.
	file.open("nationalId.txt", ios::out | ios::trunc);
	for (auto i : nationalIdvector)
	{
		file << i << endl;
	}
	file.close();
	file1.close();
	file2.close();
	file3.close();
}

void System::AddUsersAuto2(int n)
{
	vector<string> nationalIdvector;
	vector<string>namesmvector;
	vector<string>namesfvector;
	vector<string>governoratevector;
	vector<string> row;
	string line, word;
	string x;
	nationalIdvector = file.ReadTxt("nationalId.txt");
	namesfvector = file.ReadTxt("namesofgirls.txt");
	namesmvector = file.ReadTxt("namesofboys.txt");
	governoratevector = file.ReadTxt("governorate.txt");
	cout << nationalIdvector.size() << " " << namesfvector.size() << " " << namesmvector.size() << " " << governoratevector.size() << endl;

	fstream file1;
	fstream file2;
	fstream file3;

	// opens an existing csv file or creates a new file.
	file1.open("waitingList_Dose1.csv", ios::out | ios::app);
	if (file1.is_open())
		cout << "OPENED1\n";

	file2.open("waitingList_Dose2.csv", ios::out | ios::app);
	if (file2.is_open())
		cout << "OPENED2\n";

	file3.open("data.csv", ios::out | ios::app);
	if (file3.is_open())
		cout << "OPENED3\n";

	while (n--)
	{
		int n1, n2, n3, n4;
		int g = rand() % 27;
		int mood = rand() % 2;
		string id;
		if (mood == 0)
			n1 = rand() % 44;
		else
			n1 = rand() % 50;
		while (true)
		{
			n2 = rand() % 44;
			if (n2 != n1)
			{

				break;
			}
		}
		while (true)
		{
			n3 = rand() % 44;
			if (n3 != n2)
			{

				break;
			}
		}
		while (true)
		{
			n4 = rand() % 44;
			if (n4 != n3)
			{

				break;
			}
		}
		string name;
		if (mood == 0)
		{
			name = namesmvector[n1];
		}
		else
		{
			name = namesfvector[n1];
		}
		name += " " + namesmvector[n2] + " " + namesmvector[n3] + " " + namesmvector[n4];
		string governorate = governoratevector[g];
		string age = to_string(rand() % 73 + 18);
		string gender;
		string password = to_string(rand() % 100000000 + 10000000);
		string vaccinated, firstDose, SecondDose;
		vaccinated = firstDose = SecondDose = "0";
		int i = rand() % nationalIdvector.size();
		string nationalId = nationalIdvector[i];
		auto it = nationalIdvector.begin() + i;
		nationalIdvector.erase(it);
		if (mood == 0)
			gender = "m";
		else
			gender = "f";

		string vaccineType, sideEffect, dateOfFirstDose, dateOfSecondDose, TimeToGet;
		vaccineType = sideEffect = dateOfFirstDose = dateOfSecondDose = TimeToGet = "N\\A";
		int a;
		a = rand() % 8;
		vaccineType = vaccineTypes[a];
		int day, month, year;
		int yy = rand() % 4;
		if (yy == 0)
			year = 2019;
		else if (yy == 1)
			year = 2020;
		else if (yy == 2)
			year = 2021;
		else
			year = 2022;
		day = rand() % 28 + 1;
		if (year == 2022)
			month = rand() % 4 + 1;
		else
			month = rand() % 12 + 1;

		dateOfFirstDose = to_string(day) + "/" + to_string(month) + "/" + to_string(year);

		file3 << nationalId << ","
			<< password << ","
			<< name << ","
			<< age << ","
			<< gender << ","
			<< "Egypt" << ","
			<< governorate << ","
			<< "1" << ","
			<< "1" << ","
			<< "0" << ","
			<< "0" << ","
			<< vaccineType << ","
			<< sideEffect << ","
			<< dateOfFirstDose << ","
			<< dateOfSecondDose << ","
			<< TimeToGet
			<< "\n";
		file2 << nationalId << endl;
	}

	fstream file;
	// opens an existing csv file or creates a new file.
	file.open("nationalId.txt", ios::out | ios::trunc);
	for (auto i : nationalIdvector)
	{
		file << i << endl;
	}
	file.close();
	file1.close();
	file2.close();
	file3.close();
}

void System::AddUsersAuto3(int n)
{
	vector<string> nationalIdvector;
	vector<string>namesmvector;
	vector<string>namesfvector;
	vector<string>governoratevector;
	vector<string> row;
	string line, word;
	string x;
	nationalIdvector = file.ReadTxt("nationalId.txt");
	namesfvector = file.ReadTxt("namesofgirls.txt");
	namesmvector = file.ReadTxt("namesofboys.txt");
	governoratevector = file.ReadTxt("governorate.txt");
	cout << nationalIdvector.size() << " " << namesfvector.size() << " " << namesmvector.size() << " " << governoratevector.size() << endl;

	fstream file1;
	fstream file2;
	fstream file3;
	// opens an existing csv file or creates a new file.
	file1.open("waitingList_Dose1.csv", ios::out | ios::app);
	if (file1.is_open())
		cout << "OPENED1\n";

	file2.open("waitingList_Dose2.csv", ios::out | ios::app);
	if (file2.is_open())
		cout << "OPENED2\n";

	file3.open("data.csv", ios::out | ios::app);
	if (file3.is_open())
		cout << "OPENED3\n";

	while (n--)
	{
		int n1, n2, n3, n4;
		int g = rand() % 27;
		int mood = rand() % 2;
		string id;
		if (mood == 0)
			n1 = rand() % 44;
		else
			n1 = rand() % 50;
		while (true)
		{
			n2 = rand() % 44;
			if (n2 != n1)
			{

				break;
			}
		}
		while (true)
		{
			n3 = rand() % 44;
			if (n3 != n2)
			{

				break;
			}
		}
		while (true)
		{
			n4 = rand() % 44;
			if (n4 != n3)
			{

				break;
			}
		}
		string name;
		if (mood == 0)
		{
			name = namesmvector[n1];
		}
		else
		{
			name = namesfvector[n1];
		}
		name += " " + namesmvector[n2] + " " + namesmvector[n3] + " " + namesmvector[n4];
		string governorate = governoratevector[g];
		string age = to_string(rand() % 73 + 18);
		string gender;
		string password = to_string(rand() % 100000000 + 10000000);
		string vaccinated, firstDose, SecondDose;
		vaccinated = firstDose = SecondDose = "0";
		int i = rand() % nationalIdvector.size();
		string nationalId = nationalIdvector[i];
		auto it = nationalIdvector.begin() + i;
		nationalIdvector.erase(it);
		if (mood == 0)
			gender = "m";
		else
			gender = "f";

		string vaccineType, sideEffect, dateOfFirstDose, dateOfSecondDose, TimeToGet;
		vaccineType = sideEffect = dateOfFirstDose = dateOfSecondDose = TimeToGet = "N\\A";
			int a;
			a = rand() % 8;
			int b;
			b = rand() % 5;
			vaccineType = vaccineTypes[a];
			sideEffect = sideEffects[b];
		int day, month, year;
		int yy = rand() % 4;
		if (yy == 0)
			year = 2019;
		else if (yy == 1)
			year = 2020;
		else if (yy == 2)
			year = 2021;
		else
			year = 2022;
		day = rand() % 28 + 1;
		if (year == 2022)
			month = rand() % 3 + 1;
		else
			month = rand() % 12 + 1;

		int day2 = day + (rand() % 24) + 15;
		int month2=month;
		int year2=year;
		if(day2>30)
		{
			day2 %= 30;
			month2++;
		}
		if(month2>12)
		{
			month2 %= 12;
			year2++;
		}
		
		dateOfFirstDose = to_string(day) + "/" + to_string(month) + "/" + to_string(year);
		dateOfSecondDose = to_string(day2) + "/" + to_string(month2) + "/" + to_string(year2);

		file3 << nationalId << ","
			<< password << ","
			<< name << ","
			<< age << ","
			<< gender << ","
			<< "Egypt" << ","
			<< governorate << ","
			<< "1" << ","
			<< "1" << ","
			<< "1" << ","
			<< "0" << ","
			<< vaccineType << ","
			<< sideEffect << ","
			<< dateOfFirstDose << ","
			<< dateOfSecondDose << ","
			<< "Concluded"
			<< "\n";
	}

	fstream file;
	// opens an existing csv file or creates a new file.
	file.open("nationalId.txt", ios::out | ios::trunc);
	for (auto i : nationalIdvector)
	{
		file << i << endl;
	}
	file.close();
	file1.close();
	file2.close();
	file3.close();
}

void System::WriteData()
{
	file.WriteToSystem(umap);
	file.WriteWaitingList(waitingList_dose1, "waitingList_Dose1.csv");
	file.WriteWaitingList(waitingList_dose2, "waitingList_Dose2.csv");
	file.WriteArrList(arrayList_Dose1, "arrayList_Dose1.csv");
	file.WriteArrList(arrayList_Dose2, "arrayList_Dose2.csv");
}

void System::Save()
{
	WriteData();
}