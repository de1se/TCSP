#include "Users.h"

User::User() {
	login.clear();
	password.clear();
	accessLevel = 0;
}

int User::LogIn(vector <UserData> userInformation) {
	cout << "Enter login:";
	cin >> login;
	cout << "Enter password:";
	cin >> password;

	for (UserData info : userInformation) {
		if (!info.login.compare(login) && !info.password.compare(password)) {
			return info.id;
		}
	}
	return -1;
}
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

	newUser.state = "User";

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

	bool flag;
	for (int i = 0; i <= userInformation.size(); i++) {
		flag = true;
		for (UserData info : userInformation) {
			if (info.id == i) {
				flag = false;
				break;
			}
		}
		if (flag) {
			newUser.id = i;
			break;
		}
	}

	return newUser;
}

Client::Client(int _id, vector <UserData> userInformation) {
	id = _id;
	for (UserData info : userInformation) {
		if (info.id == id) {
			balance = info.balance;
			tariff = info.tariff;
		}
	}
	accessLevel = 1;
}

void Client::ViewBalanceAndTariff() {
	cout << "Your balance: " << balance << endl;
	cout << "Your tariff: " << tariff << endl;
	_getch();
}

RequestDetails Client::ChangeTariff() {
	RequestDetails request;

	cout << "Enter your name: ";
	cin >> request.name;
	request.id = id;
	cout << "Enter your address: ";
	cin >> request.address;
	cout << "Enter your new tariff: ";
	cin >> request.problem;
	request.type = 2;

	return request;
}

int Client::OrderNetworkDisconnection() {
	cout << "Are you sure?\n";
	cout << "1 - Yes\n";
	cout << "2 - No\n";
	
	int choice;
	while (true)
	{
		cin >> choice;

		if (choice == 1) {
			return id;
		}
		else if (choice == 2) {
			return -1;
		}
		else {
			cout << "Enter only 1 or 2\n";
		}
	}
}

RequestDetails Client::MakeMalfunctionRequest() {
	RequestDetails request;

	cout << "Enter your name: ";
	cin >> request.name;
	request.id = id;
	cout << "Enter your address: ";
	cin >> request.address;
	cout << "Enter your new tariff: ";
	cin >> request.problem;
	request.type = 3;

	return request;
}