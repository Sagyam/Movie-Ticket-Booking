
#include "pch.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <conio.h>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <process.h>
#include <time.h>
using namespace std;

// List of all functions
void bye();
void error();
string login();
void commingsoon();

class movie
{
public:
	char name[128];
	movie()
	{
		strcpy(name, "\0");
	}
	void show()
	{
		cout << name<<	endl;
	}
};

int main()
{	
	string username = login();
	system("CLS");

	int choice;
	
	{time_t t = time(NULL);
	tm* timePtr = localtime(&t);
	cout << "**********************************************************************************************************************"<<endl;
	cout << "**********************************************************************************************************************" << endl;
	cout << "\t\t\t\t WELCOME " <<username														 <<endl;
	cout << "Time "                            << timePtr->tm_hour <<":" << timePtr->tm_min;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t   Date " << timePtr->tm_mday << "/" << timePtr->tm_mon << "/" << timePtr->tm_year + 1900 << endl;
	
	cout << "<1>\t\t\t\t  Now Showing"																		<< endl;
	cout << "<2>\t\t\t\t  Comming Soon"																					<<endl;
	cout << "<3>\t\t\t\t  User Registration"																						<< endl;
	cout << "<4>\t\t\t\t  Exit \n\n";
	cout << "Enter Your Choice :" << "\t";
	cin >> choice;
	cout << "**********************************************************************************************************************" << endl;
	cout << "**********************************************************************************************************************" << endl;
	switch (choice)
	{
	case 1:
		
		break;
	case 2:
	 commingsoon();
		break;
	case 3:

		break;
	case 4:

		break;
	case 5:
		bye();
		break;
	default:
		error();
		break;
	}

	}
}
string login()
{
	string username,password;
	system("CLS");
	cout << "\t\t\t\t\t\tLOGIN MENU"	<<	endl;
	cout << "Enter username" << endl;
	cin >> username;
	cout << "Enter password" << endl;
	cin >> password;
	if(1)
	{ 
	
	}
	else
	{
			cout << "Invalid Username or Password" << endl;
			getch();
			login();
	}
	return username;
}
void commingsoon()
{
	fstream file;
	movie movie;
	file.open("commingsoon.dat", ios::in | ios::out | ios::binary);
	if(!file)
	{
		cout << "File not found please contact admin";
		getch();
		exit(0);

	}
	file.seekg(0,ios::beg);
	while (!file.eof())
	{
		file.read(reinterpret_cast<char*>(&movie), sizeof(movie));
		movie.show();
	}
	file.close();
}
void error()
{
	cout << "Enter a valid choice";
}
void bye()
{
	system("CLS");

	cout << "**********************************************************************************************************************" << endl;
	cout << "**********************************************************************************************************************" << endl;
	cout << "\t\t\t\t THANK YOU FOR USING OUR SYSYTEM";
	cout << "\n\n\n\n\n\n";
	cout << "Press any key to quit"																									<<  endl;
	cout << "**********************************************************************************************************************" << endl;
	cout << "**********************************************************************************************************************" << endl;
	getch();
}



