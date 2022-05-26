#include "File.h"
using namespace std;

unordered_map<string, User> File::ReadFromSystem() // From Excel -> to System 
{
	unordered_map<string, User> umap;
	vector<vector<string>> content;
	vector<string> row;
	string line, word;
	fstream file("data.csv", ios::in);
	if (file.is_open())
	{
		while (getline(file, line))
		{
			row.clear();

			stringstream str(line);

			while (getline(str, word, ','))
				row.push_back(word);
			content.push_back(row);
		}
	}
	else
		cout << "Could not open the file.\n";

	for (int i = 1; i < content.size(); i++)
	{
		User h(content[i][0], content[i][1], content[i][2], content[i][3], content[i][4], content[i][5], content[i][6]);
		if (content[i][8] == "1")
			h.SetFirstDose(true);
		if (content[i][9] == "1")
			h.SetSecondDose(true);
		if (content[i][10] == "1")
			h.SetAdmin(true);
		h.SetVaccineType(content[i][11]);
		h.SetSideEffect(content[i][12]);
		h.SetDateOfFirstDose(content[i][13]);
		h.SetDateOfSecondDose(content[i][14]);
		h.SetTimeToGet(content[i][15]);

		umap[h.GetNationalId()] = h;
	}
	file.close();
	return umap;
}

vector<string> File::ReadTxt(string filename)
{
	vector<string>v;
	string  word;
	fstream file(filename, ios::in);
	if (file.is_open())
	{
		while (getline(file, word))
		{
			v.push_back(word);
		}
	}
	else
		cout << "Could not Welcome the file\n";
	file.close();
	return v;
}

queue<string> File::ReadWaitingList(string filename)
{
	int x = 0;
	queue<string> q;
	string word;
	fstream file(filename, ios::in);
	if (file.is_open())
	{
		while (getline(file, word))
		{
			if(x != 0)
				q.push(word);
			x++;
		}
	}
	else
		cout << "Could not Welcome the file\n";
	file.close();
	return q;
}

vector<string> File::ReadArrList(string filename)
{
	int x = 0;
	vector<string> v;
	string  word;
	fstream file(filename, ios::in);
	if (file.is_open())
	{
		while (getline(file, word))
		{
			if(x != 0)
				v.push_back(word);
			x++;
		}
	}
	else
		cout << "Could not Welcome the file\n";
	file.close();
	return v;
}

void File::WriteArrList(vector<string>arrList,string filename)
{
	fstream file1;
	// opens an existing csv file or creates a new file.
	file1.open(filename, ios::out | ios::trunc);
	file1 << "National Id" << endl;
		
	for (int i = 0; i < arrList.size(); i++)
	{
		file1 << arrList[i] << endl;
	}
	file1.close();
}

void File::WriteWaitingList(queue<string>waitingList,string filename)
{
	fstream file1;
	file1.open(filename, ios::out | ios::trunc);
	file1 << "National Id" << "\n";
		
	while (!waitingList.empty())
	{
		file1 << waitingList.front() << endl;
		waitingList.pop();
	}
	file1.close();
}

void File::WriteToSystem(unordered_map<string,User>umap) //From System -> Excell
{
	fstream file;
	// opens an existing csv file or creates a new file.
	file.open("data.csv", ios::out | ios::trunc);
	file << "National Id" << ","
		<< "Password" << ","
		<< "Name" << ","
		<< "Age" << ","
		<< "Gender" << ","
		<< "Country" << ","
		<< "Governorate" << ","
		<< "Vaccinated" << ","
		<< "First Dose" << ","
		<< "Second Dose" << ","
		<< "Admin" << ","
		<< "Vaccine Type" << ","
		<< "Side Effect" << ","
		<< "Date of First Dose" << ","
		<< "Date of Second Dose" << ","
		<< "Time to Get"
		<< "\n";
	for (auto i : umap)
	{
		//cout << "a\n";

		file << i.second.GetNationalId() << ","
			<< i.second.GetPassword() << ","
			<< i.second.GetFullName() << ","
			<< i.second.GetAge() << ","
			<< i.second.GetGender() << ","
			<< i.second.GetCountry() << ","
			<< i.second.GetGovernorate() << ","
			<< i.second.GetFirstDose() << ","
			<< i.second.GetFirstDose() << ","
			<< i.second.GetSecondDose() << ","
			<< i.second.GetAdmin() << ","
			<< i.second.GetVaccineType() << ","
			<< i.second.GetSideEffect() << ","
			<< i.second.GetDateOfFirstDose() << ","
			<< i.second.GetDateOfSecondDose() << ","
			<< i.second.GetTimeToGet()
			<< "\n";
	}
	file.close();
}

void File::WriteTxt(vector<string>v,string filename)
{
	fstream file;
	// opens an existing csv file or creates a new file.
	file.open(filename, ios::out | ios::trunc);
	for (auto i : v)
	{
		file << i << endl;
	}
	file.close();
}
