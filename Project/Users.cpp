#include "Users.h"

UserData User::OrderNetworkConnection(vector <UserData> userInformation, vector <string> tariffPlan) {
	UserData newUser;
	bool loop = true;

	cout << "Enter name: ";
	getline(cin, newUser.name);

	cout << "Enter address: ";
	getline(cin, newUser.address);
	
	cout << "Enter login: ";
	while (loop) {
		getline(cin, newUser.login);

		for (UserData info : userInformation) {
			if (!info.login.compare(newUser.login)) {
				cout << "Login already exists\n";
			}
			else {
				loop = false;
			}
		}
	}

	cout << "Enter password: ";
	getline(cin, newUser.password);

	cout << "How much money do you want to deposit: ";
	cin >> newUser.balance;

	cout << "Choose tariff: ";
	for (string tariff : tariffPlan) {
		cout << tariff << ";\n";
	}
	while (true) {
		cin >> newUser.tariff;

		if (newUser.tariff < 1 && newUser.tariff > 4) {
			cout << "There is no such tariff\n";
		}
		else {
			break;
		}
	}

	return newUser;
}