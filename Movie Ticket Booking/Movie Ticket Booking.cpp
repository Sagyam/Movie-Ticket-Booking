
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
string login();
void commingsoon();
void edit_upcommingsoon();
void registration();
bool search_user(string,string);


//Some global variables
string username;

//Some Classes used in this program
class person
{
public:
	string name,password,address;
	int mobile_number;
	void getdata()
	{
		cout << "Enter your Name" <<endl;
		cin >> name;
		cout << "Enter your Password" << endl;
		cin >> password;
		cout << "Enter your Address" <<endl;
		cin >> address;
		cout << "Enter your Mobile Number" << endl;
		cin >> mobile_number;
	}
};
class movie
{
public:
	string name;
	int time;
	bool seat_cell[10][10];
	void showname()
	{
		cout << name << endl;
	}
	void getname()
	{
		cin.ignore();
		getline(cin,name);
	}
	void timing()
	{
		int option;
		int time=0;
		system("CLS");
		cout << "\n\n\t\t\t\t Select the the timings: ";
		cout << "\n\t\t\t\t 1. 0600";
		cout << "\n\t\t\t\t 2. 0900";
		cout << "\n\t\t\t\t 3. 1200";
		cout << "\n\t\t\t\t 4. 1500";
		cout << "\n\t\t\t\t 5. 1800";					
		cout << "\n\n\t\t\t\t Please select the timings: ";
		cin >> option;
		if ((option < 7) && (option > 0))
		{
			time = 600+(option-1)*300;
		}
		else
		{
			cout << "Enter a valid choice";
			timing();
		}
		
		
	}
	
	
	void billing()
	{

	}
};

movie now_showing();
void edit_now_showing();

int main()
{
	movie user_choice;
	
		/*if (username.empty())
		{
			username = login();
		} */
	system("CLS");

	int choice;
	
	{time_t t = time(NULL);
	tm* timePtr = localtime(&t);
	cout << "**********************************************************************************************************************"<<endl;
	cout << "**********************************************************************************************************************" << endl;
	cout << "\t\t\t\t WELCOME " << username <<endl;
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
		user_choice = now_showing();
		user_choice.timing();
		user_choice.billing();
		break;
	case 2:
	 commingsoon();
	 main();
		break;
	case 3:
		registration();
		main();
		break;
	case 4:
		bye();
		break;
	default:
		cout << "Enter a valid choice";
		main();
		break;
	}

	}
}
void edit_now_showing()
{
	fstream file;
	movie movie;
	file.open("now_showing.dat", ios::out |ios::binary);
	file.seekp(0, ios::beg);
	movie.getname();
	//file << movie;
	file.write(reinterpret_cast<char*>(&movie), sizeof(movie));
	file.close();
	getch();
}
void registration()
{
	fstream file;
	person user;
	file.open("userlist.dat", ios::app | ios::binary);
	user.getdata();
	file.write(reinterpret_cast<char*>(&user), sizeof(user));
	cout << "Registration Sucessful" << endl;
	file.close();
	getch();
	main();

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

	if(search_user(username, password))
	{ 
		return username;
	}
	else
	{
			cout << "Invalid Username or Password" << endl;
			getch();
			login();
	}
	
}
movie now_showing()
{
	fstream file;
	movie movie;
	int i = 0,choice;
	file.open("now_showing.dat", ios::in | ios::binary);
	if (!file)
	{
		cout << "Sorry No Showings Avaliable";
		getch();
		main();

	}
	file.seekg(0, ios::beg);
	while (!file.eof())
	{
		file.read(reinterpret_cast<char*>(&movie), sizeof(movie));
		cout << i  ;
		movie.showname();
		cout << endl;
	}
	cout << "Enter your choice " <<endl;
	cin >> choice;
	file.seekg((choice - 1) * sizeof(movie));
	file.read(reinterpret_cast<char*>(&movie), sizeof(movie));
	return movie;
	file.close();

}
void commingsoon()
{
	fstream file;
	movie movie;
	file.open("upcomming_movies.dat", ios::in| ios::binary);
	if(!file)
	{
		cout << "Sorry No Upcomming Movies";
		getch();
		main();

	}
	file.seekg(0,ios::beg);
	
	while (!file.eof())
	{
		file.read(reinterpret_cast<char*>(&movie), sizeof(movie));
		movie.showname();
	}  
	
	file.close();
	getch();
}
void bye()
{
	system("CLS");

	cout << "**********************************************************************************************************************" << endl;
	cout << "**********************************************************************************************************************" << endl;
	cout << "\t\t\t\t THANK YOU FOR USING OUR SYSYTEM";
	cout << "\n\n\n\n\n\n";
	cout << "Press any key to quit" << endl;
	cout << "**********************************************************************************************************************" << endl;
	cout << "**********************************************************************************************************************" << endl;
	getch();
}
bool search_user(string qname,string qpassword)
{
	fstream file;
	person user;
	file.open("userlist.dat", ios::in | ios::binary);
	file.seekg(0, ios::beg);
	while (!file.eof())
	{
		file.read(reinterpret_cast<char*>(&user), sizeof(user));
		if((qname.compare(user.name)) && (qpassword.compare(user.password)))
		{
			return(1);
		}
	}
	return (0);
}
void edit_upcommingsoon()
{
	fstream file;
	movie movie;
	file.open("upcomming_movies.dat", ios::app | ios::binary);
	file.seekp(0,ios::beg);
	cout << "Enter movie name " << endl;
	movie.getname();
	file.write(reinterpret_cast<char*>(&movie), sizeof(movie));
	file.close();
	getch();
}



