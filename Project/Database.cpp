#include "Database.h"

Database::Database() {
	allRequests.clear();
	userInformation.clear();
	tariffPlan.push_back("1 - Economy");
	tariffPlan.push_back("2 - Regular");
	tariffPlan.push_back("3 - Super");
	tariffPlan.push_back("4 - Ultra");
}

void Database::AddUserInformation(UserData info) {
	userInformation.push_back(info);
}

void Database::AddRequest(RequestDetails request) {
	allRequests.push_back(request);
}

void Database::WriteToFile() {
	ofstream out;
	
	out.open("UserInfo.txt", ios_base::out);
	for (UserData info : userInformation) {
		out << info.name << '\n' << info.address << '\n' << info.login << '\n' << info.password << '\n' << info.status 
			<< '\n' << info.balance << '\n' << info.tariff << '\n' << info.state << '\n' << info.id << '\n';
	}
	out.close();

	out.open("Request.txt", ios_base::out);
	for (RequestDetails request : allRequests) {
		out << request.name << '\n' << request.address << '\n' << request.problem << '\n' << request.state << '\n' << request.id << '\n';
	}
	out.close();
}

void Database::ReadFromFile() {
	ifstream in;

	in.open("UserInfo.txt", ios_base::in);
	if (in.is_open()) {
		in.seekg(0);
		UserData newUser;
		while (!in.eof()) {
			getline(in, newUser.name);
			getline(in, newUser.address);
			getline(in, newUser.login);
			getline(in, newUser.password);
			getline(in, newUser.status);
			in >> newUser.balance;
			in >> newUser.tariff;
			in >> newUser.state;
			in >> newUser.id;

			AddUserInformation(newUser);
		}
		in.close();
	}
	else {
		cout << "No info in the fil\n";
		_getch();
	}
	
	in.open("Request.txt", ios_base::in);
	if (in.is_open()) {
		in.seekg(0);
		RequestDetails newRequest;
		while (!in.eof()) {
			getline(in, newRequest.name);
			getline(in, newRequest.address);
			getline(in, newRequest.problem);
			in >> newRequest.state;
			in >> newRequest.id;

			AddRequest(newRequest);
		}
	}
	else {
		cout << "No info in the file\n";
		_getch();
	}
}

void Database::AddBalance(int id, int balance) {
	for (int i = 0; i < userInformation.size(); i++) {
		if (userInformation.at(i).id == id) {
			userInformation.at(i).balance = balance;
		}
	}
}

void Database::DeleteUser(int id) {
	userInformation.erase(userInformation.begin() + id);
}

vector <RequestDetails> Database::GetRequests() {
	return allRequests;
}

vector <UserData> Database::GetUserInformation() {
	return userInformation;
}

vector <string> Database::GetTariffPlan() {
	return tariffPlan;
}