#include "Database.h"

Database::Database() {
	allRequests.clear();
	userInformation.clear();
	tariffPlan.push_back("1 - Economy");
	tariffPlan.push_back("2 - Regular");
	tariffPlan.push_back("3 - Super");
	tariffPlan.push_back("4 - Ultra");

	expenses = 0;
	income = 0;
}

void Database::AddUserInformation(UserData newUser) {
	userInformation.push_back(newUser);
}

vector <UserData> Database::GetUserInformation() {
	return userInformation;
}

vector <string> Database::GetTariffPlan() {
	return tariffPlan;
}