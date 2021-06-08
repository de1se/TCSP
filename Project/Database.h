#pragma once

#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <vector>


using namespace std;

struct UserData {
	string name,
		address,
		login,
		password,
		status;
	int balance,
		tariff, 
		state,
		id;
};

struct RequestDetails {
	string name,
		address,
		problem;
	int state,
		id;
};

class Database {
protected:
	vector <RequestDetails> allRequests;
	vector <UserData> userInformation;
	vector <string> tariffPlan;
public:
	Database();

	void AddUserInformation(UserData info);
	void AddRequest(RequestDetails request);
	void WriteToFile();
	void ReadFromFile();
	void AddBalance(int id, int balance);
	void DeleteUser(int id);

	vector <RequestDetails> GetRequests();
	vector <UserData> GetUserInformation();
	vector <string> GetTariffPlan();
};