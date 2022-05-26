#pragma once
#include <iostream>
#include <string>
#include "User.h"
#include <queue>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;

class File
{
public:
	unordered_map<string, User> ReadFromSystem();

	void WriteToSystem(unordered_map<string,User>);

	vector<string> ReadTxt(string);
	
	void WriteTxt(vector<string>,string);

	queue<string> ReadWaitingList(string);

	void WriteWaitingList(queue<string>,string);

	vector<string> ReadArrList(string);

	void WriteArrList(vector<string>,string);	
};