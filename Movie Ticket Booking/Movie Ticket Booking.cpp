
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

// List of all functiona
void bye();
void error();


int main()
{
	system("CLS");

	int ent, a, b, N, x, cardid;
	char ans;
	//To display the system time.
	//Using time header file
	{time_t t = time(NULL);
	tm* timePtr = localtime(&t);
	cout << "**********************************************************************************************************************"<<endl;
	cout << "**********************************************************************************************************************" << endl;
	cout << "\t\t\t\t WELCOME TO THE TICKET BOOKING SYSTEM"														 <<endl;
	cout << "Time "                            << timePtr->tm_hour <<":" << timePtr->tm_min;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t   Date " << timePtr->tm_mday << "/" << timePtr->tm_mon << "/" << timePtr->tm_year + 1900 << endl;
	cout << endl;
	cout << "<1>\t\t\t\t  Login Menu"																						    << endl;
	cout << "<2>\t\t\t\t  Movie Timings"																							<< endl;
	cout << "<3>\t\t\t\t  Recieving Ticket"																						<< endl;
	cout << "<4>\t\t\t\t  For Information"																						<< endl;
	cout << "<5>\t\t\t\t  DTCard Registration"																					 << endl;
	cout << "<6>\t\t\t\t  Exit \n\n";
	cout << "Enter Your Choice :" << "\t";
	cin >> ent;
	cout << "**********************************************************************************************************************" << endl;
	cout << "**********************************************************************************************************************" << endl;
	switch (ent)
	{
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		bye();
		break;
	default:
		error();
		break;
	}

	}
}
void login()
{

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



