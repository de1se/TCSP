#include "Users.h"

bool User::LogIn(vector <UserData> userInformation) {
	cout << "Enter login:";
	cin >> login;
	cout << "Enter password:";
	cin >> password;

	for (UserData info : userInformation) {
		if (!info.login.compare(login) && !info.password.compare(password)) {
			return true;
		}
	}
	return false;
}