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
	User();
	int LogIn(vector <UserData> userInformation);
	UserData OrderNetworkConnection(vector <UserData> userInformation, vector <string> tariffPlan);
};

class Client {
protected:
	double balance;
	string tariff;
	int accessLevel, id;
public:
	Client(int _id, vector <UserData> userInformation);
	void ViewBalanceAndTariff();
	RequestDetails ChangeTariff();
	int OrderNetworkDisconnection();
	RequestDetails MakeMalfunctionRequest();
};

class Engineer {
protected:
	int accessLevel, id;;
public:
	Engineer();
	friend void AcceptRequest();
};


class Administrator {
protected:
	int accessLevel, id;;
public:
	Administrator();
	void BlockingClientAccess();
	void RemoveBlockingClientAccess();
	void ShowDatabase(Database information);
	friend void AcceptRequest();
};

class Management {
protected:
	int accessLevel, id;;
public:
	Management();
};