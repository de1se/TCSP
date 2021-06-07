#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct UserData {
	string name,
		address,
		login,
		password;
	double balance;
	int tariff;
};

struct RequestDetails {
	string name,
		address,
		problem;
};

class Database {
protected:
	vector <RequestDetails> allRequests;
	vector <UserData> userInformation;
	vector <string> tariffPlan;
	int income, expenses;
public:
	Database();

	void AddUserInformation(UserData _userInformation);
	void showAllRequests();
	void ShowUserInformation();
	void ShowTariffPlan();
	void DeleteRequest(int id);
	void DeleteUser(int id);
	
	vector <RequestDetails> GetRequests(string AccessLevel);
	vector <UserData> GetUserInformation();
	vector <string> GetTariffPlan();
};