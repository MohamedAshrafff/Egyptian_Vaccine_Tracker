#pragma warning(suppress : 4996)
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstring>
#include <fstream>
#include <random>
#include <map>
#include <ctime>
#include <chrono>
#include <vector>
#include <queue>
#include "File.h"
#include "date.h"
#include "Python.h"
#include "User.h"
#include "System.h"
#include "Windows.h"
using namespace std;
using namespace date;
using namespace chrono;

int main()
{
	string ss = "Welcome to Vaccine Tracking System!";
	cout << "\t\t\t\t\t";
	for (int i = 0; i < ss.size(); i++)
	{
		Sleep(30);
		string m = "12345678ABCDEF";
		char h[100] = { 'c', 'o' , 'l' , 'o' , 'r' ,' ','0', m[i%m.size()]};
		system(h);
		cout << ss[i];
	}
	system("color 0b");
	cout << "\n\n";

	System s;
	return 0;
}
//Ashraf123