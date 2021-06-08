#include "Users.h"

User::User() {
	login.clear();
	password.clear();
	state = 0;
}

int User::LogIn(vector <UserData> userInformation) {
	system("cls");

	cout << "Enter login:";
	cin >> login;
	cout << "Enter password:";
	cin >> password;

	for (UserData info : userInformation) {
		if (!info.login.compare(login) && !info.password.compare(password) && info.status.compare("Deactive")) {
			return info.id;
		}
	}

	cout << "Wrong login or password. Or your account has been deactivated.\n";
	_getch();
	return -1;
}

UserData User::OrderNetworkConnection(vector <UserData> userInformation, vector <string> tariffPlan) {
	system("cls");

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

	newUser.status = "Active";
	newUser.state = 1;

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
			status = info.status;
			balance = info.balance;
			tariff = info.tariff;
		}
	}
	state = 1;
}

void Client::ViewBalanceAndTariff() {
	system("cls");

	cout << "Your balance: " << balance << endl;
	cout << "Your tariff: " << tariff << endl;
	_getch();
}

RequestDetails Client::ChangeTariff() {
	system("cls");

	RequestDetails request;

	cout << "Enter your name: ";
	cin >> request.name;
	request.id = id;
	cout << "Enter your address: ";
	cin >> request.address;
	cout << "Enter your new tariff: ";
	cin >> request.problem;
	request.state = 2;

	return request;
}

int Client::OrderNetworkDisconnection() {
	system("cls");

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
	system("cls");

	RequestDetails request;

	cout << "Enter your name: ";
	cin >> request.name;
	request.id = id;
	cout << "Enter your address: ";
	cin >> request.address;
	cout << "Enter your new tariff: ";
	cin >> request.problem;
	request.state = 3;

	return request;
}

Engineer::Engineer(int _id) {
	id = _id;
	state = 2;
}

void Engineer::AcceptRequest(vector <RequestDetails> allRequests) {
	system("cls");

	int counter = 0;
	for (RequestDetails info : allRequests) {
		if (info.state == state) {
			cout << info.id << ' ' << info.name << ' ' << info.address << ' ' << info.problem << endl;
			counter++;
		}
	}

	if (!counter) {
		cout << "There's no information\n";
		_getch();
	}

	cout << "Which request do you accept?\n";
	cout << "-1 for leave\n";
	int choice;
	while (true) {
		cin >> choice;

		if (choice == -1) {
			return;
		}

		for (int i = 0; i < allRequests.size(); i++) {
			if (allRequests.at(i).state == state && allRequests.at(i).id == choice) {
				allRequests.erase(allRequests.begin() + i);
				return;
			}
		}
		cout << "No such number exists\n";
	}
}

Administrator::Administrator(int _id) {
	id = _id;
	state = 3;
}

void Administrator::BlockingClientAccess(vector <UserData> userInformation) {
	system("cls");

	int counter = 0;
	for (UserData info : userInformation) {
		if (info.state < 3 && info.status == "Active") {
			cout << info.id << ' ' << info.name << ' ' << info.address << ' ' << info.state << endl;
			counter++;
		}
	}

	if (!counter) {
		cout << "There's no information\n";
		_getch();
	}

	cout << "Which user do you want to block?\n";
	cout << "-1 for leave\n";
	int choice;
	while (true) {
		cin >> choice;

		if (choice == -1) {
			return;
		}

		for (int i = 0; i < userInformation.size(); i++) {
			if (userInformation.at(i).state < 3 && userInformation.at(i).status == "Active" && userInformation.at(i).id == choice) {
				userInformation.at(i).status = "Deactive";
				return;
			}
		}
		cout << "No such number exists\n";
	}
}

void Administrator::RemoveBlockingClientAccess(vector <UserData> userInformation) {
	system("cls");

	int counter = 0;
	for (UserData info : userInformation) {
		if (info.state < 3 && info.status == "Deactive") {
			cout << info.id << ' ' << info.name << ' ' << info.address << ' ' << info.state << endl;
			counter++;
		}
	}

	if (!counter) {
		cout << "There's no information\n";
		_getch();
	}

	cout << "Which user do you want to unblock?\n";
	cout << "-1 for leave\n";
	int choice;
	while (true) {
		cin >> choice;

		if (choice == -1) {
			return;
		}

		for (int i = 0; i < userInformation.size(); i++) {
			if (userInformation.at(i).state < 3 && userInformation.at(i).status == "Deactive" && userInformation.at(i).id == choice) {
				userInformation.at(i).status = "Active";
				return;
			}
		}
		cout << "No such number exists\n";
	}
}

void Administrator::ShowDatabase(vector <UserData> userInformation) {
	system("cls");

	for (UserData info : userInformation) {
		cout << info.id << ' ' << info.name << ' ' << info.address << ' ' << info.login << ' ' << info.password << ' ' << info.state << ' ' << info.status << info.tariff << endl;
	}

	_getch();
}

void Administrator::AcceptRequest(vector <string> tariffPlan, vector <RequestDetails> allRequests, vector <UserData> userInformation) {
	system("cls");

	int counter = 0;
	for (RequestDetails info : allRequests) {
		if (info.state == state) {
			cout << info.id << ' ' << info.name << ' ' << info.address << ' ' << info.problem << endl;
			counter++;
		}
	}

	if (!counter) {
		cout << "There's no information\n";
		_getch();
	}

	cout << "Which request do you accept?\n";
	cout << "-1 for leave\n";
	int choice;
	while (true) {
		cin >> choice;

		if (choice == -1) {
			return;
		}

		for (int i = 0; i < allRequests.size(); i++) {
			if (allRequests.at(i).state == state && allRequests.at(i).id == choice) {
				cout << "Choose tariff: ";
				int tariff;

				for (string tariff : tariffPlan) {
					cout << tariff << ";\n";
				}

				while (true) {
					cin >> tariff;

					if (tariff < 1 && tariff > 4) {
						cout << "There is no such tariff\n";
					}
					else {
						break;
					}
				}

				for (int j = 0; j < userInformation.size(); i++) {
					if (userInformation.at(j).id == allRequests.at(i).id) {
						userInformation.at(j).tariff = tariff;
					}
				}

				allRequests.erase(allRequests.begin() + i);
				return;
			}
		}
		cout << "No such number exists\n";
	}
}

Management::Management(int _id) {
	id = _id;
	state = 4;
}

void Management::ShowDatabase(vector <UserData> userInformation) {
	system("cls");

	int income = 0, expenses = 0;
	for (UserData info : userInformation) {
		cout << info.id << ' ' << info.name << ' ' << info.address << ' ' << info.login << ' ' << info.password << ' ' << info.state << ' ' << info.status << info.tariff << endl;
		income += info.balance;
		expenses++;
	}
	expenses *= 1000;

	cout << "Income: " << income << " Expenses: " << expenses << endl;
	cout << "Total: " << income - expenses << endl;

	_getch();
}