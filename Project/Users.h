#pragma once

#include "Database.h"
#include <iostream>
#include <string.h>
#include <conio.h>

using namespace std;

class User {
public:
	string login, password;
	int state;
public:
	User();
	int LogIn(vector <UserData> userInformation);
	UserData OrderNetworkConnection(vector <UserData> userInformation, vector <string> tariffPlan);
};

class Client {
protected:
	double balance;
	string tariff, status;
	int state, id;
public:
	Client(int _id, vector <UserData> userInformation);
	void ViewBalanceAndTariff();
	RequestDetails ChangeTariff();
	int OrderNetworkDisconnection();
	RequestDetails MakeMalfunctionRequest();
};

class Engineer {
protected:
	int state, id;;
public:
	Engineer(int _id);
	void AcceptRequest(vector <RequestDetails> allRequests);
};


class Administrator {
protected:
	int state, id;
public:
	Administrator(int _id);
	void BlockingClientAccess(vector <UserData> userInformation);
	void RemoveBlockingClientAccess(vector <UserData> userInformation);
	void ShowDatabase(vector <UserData> userInformation);
	void AcceptRequest(vector <string> tariffPlan, vector <RequestDetails> allRequests, vector <UserData> userInformation);
};

class Management {
protected:
	int state, id;;
public:
	Management(int _id);
	void ShowDatabase(vector <UserData> userInformation);
};