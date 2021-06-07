#pragma once

#include "Database.h"
#include <iostream>
#include <string.h>
#include <conio.h>

using namespace std;

class User {
public:
	string login, password;
	int accessLevel;
public:
	bool LogIn(vector <UserData> userInformation);
	UserData OrderNetworkConnection(vector <UserData> userInformation, vector <string> tariffPlan);
};

class Client {
protected:
	double balance;
	string tariff;
	int accessLevel;
public:
	friend void LogOut();
	void ViewBalanceAndTariff();
	void ChangeTariff();
	void OrderNetworkDisconnection();
	void MakeMalfunctionRequest();
};

class Engineer {
protected:
	int accessLevel;
public:
	friend void LogOut();
	friend void AcceptRequest();
};


class Administrator {
protected:
	int accessLevel;
public:
	friend void LogOut();
	void BlockingClientAccess();
	void RemoveBlockingClientAccess();
	void ShowDatabase(Database information);
	friend void AcceptRequest();
};

class Management {
protected:
	int accessLevel;
public:
	friend void LogOut();
};