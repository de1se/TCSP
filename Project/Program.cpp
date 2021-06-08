#include "Users.h"
#include "Database.h"

int UserFunctioning(User user, Database database);
void ClientFunctioning(Client client, Database database);
void EngineerFunctioning(Engineer engineer, vector <RequestDetails> allRequests);
void AdministratorFunctioning(Administrator administrator, Database database);
void ManagmentFunctioning(Management managment, vector <UserData> userInformation);

int main() {
	Database database;
	database.ReadFromFile();

	User *user;
	Client *client;
	Engineer *engineer;
	Administrator *administrator;
	Management *managment;

	while (true) {
		system("cls");
		
		user = new User();
		int choice = UserFunctioning(*user, database);
		delete user;

		if (!choice) {
			break;
		}

		for (UserData info : database.GetUserInformation()) {
			if (info.id == choice) {
				switch (info.state)
				{
				case 1:
					client = new Client(choice, database.GetUserInformation());
					ClientFunctioning(*client, database);
					delete client;
					break;
				case 2:
					engineer = new Engineer(choice);
					EngineerFunctioning(*engineer, database.GetRequests());
					delete engineer;
					break;
				case 3:
					administrator = new Administrator(choice);
					AdministratorFunctioning(*administrator, database);
					delete administrator;
					break;
				case 4:
					managment = new Management(choice);

					delete managment;
					break;
				}
			}
			break;
		}
	}

	database.WriteToFile();
}

int UserFunctioning(User user, Database database) {
	int choice;
	
	while (true) {
		system("cls");

		cout << "Choose function:\n";
		cout << "1 - LogIn\n";
		cout << "2 - Order network connection\n";
		cout << "0 - Exit\n";
		cin >> choice;

		if (choice < 0 && choice > 2) {
			cout << "There is no such command\n";
			_getch();
		}
		else {
			break;
		}
	}
	
	if (!choice) {
		return 0;
	}
	else if (choice == 1) {
		return user.LogIn(database.GetUserInformation());
	}
	else {
		database.AddUserInformation(user.OrderNetworkConnection(database.GetUserInformation(), database.GetTariffPlan()));
		return -1;
	}
}

void ClientFunctioning(Client client, Database database) {
	int choice;
	while (true) {
		while (true) {
			system("cls");

			cout << "Choose function:\n";
			cout << "1 - View balance and tariff\n";
			cout << "2 - Change tariff\n";
			cout << "3 - Deposit money\n";
			cout << "4 - Order network disconnection\n";
			cout << "5 - Make malfunction request\n";
			cout << "0 - Exit\n";
			cin >> choice;

			if (choice < 0 && choice > 5) {
				cout << "There is no such command\n";
				_getch();
			}
			else {
				break;
			}
		}

		switch (choice)
		{
		case 1:
			client.ViewBalanceAndTariff();
			break;
		case 2:
			database.AddRequest(client.ChangeTariff());
			break;
		case 3:
			database.AddBalance(client.GetID(), client.DepositMoney());
			break;
		case 4:
			database.DeleteUser(client.OrderNetworkDisconnection());
			return;
		case 5:
			database.AddRequest(client.MakeMalfunctionRequest());
			break;
		default:
			return;
		}
	}
}

void EngineerFunctioning(Engineer engineer, vector <RequestDetails> allRequests) {
	int choice;
	while (true) {
		while (true) {
			system("cls");

			cout << "Choose function:\n";
			cout << "1 - Accept requests\n";
			cout << "0 - Exit\n";
			cin >> choice;

			if (choice < 0 && choice > 1) {
				cout << "There is no such command\n";
				_getch();
			}
			else {
				break;
			}
		}

		switch (choice)
		{
		case 1:
			engineer.AcceptRequest(allRequests);
			break;
		default:
			return;
		}
	}
}

void AdministratorFunctioning(Administrator administrator, Database database) {
	int choice;
	while (true) {
		while (true) {
			system("cls");

			cout << "Choose function:\n";
			cout << "1 - Block client\n";
			cout << "2 - Unblock client\n";
			cout << "3 - Show database\n";
			cout << "4 - Accept requests\n";
			cout << "0 - Exit\n";
			cin >> choice;

			if (choice < 0 && choice > 4) {
				cout << "There is no such command\n";
				_getch();
			}
			else {
				break;
			}
		}

		switch (choice)
		{
		case 1:
			administrator.BlockingClientAccess(database.GetUserInformation());
			break;
		case 2:
			administrator.RemoveBlockingClientAccess(database.GetUserInformation());
			break;
		case 3:
			administrator.ShowDatabase(database.GetUserInformation());
			break;
		case 4:
			administrator.AcceptRequest(database.GetTariffPlan(), database.GetRequests(), database.GetUserInformation());
			break;
		default:
			return;
		}
	}
}

void ManagmentFunctioning(Management managment, vector <UserData> userInformation) {
	int choice;
	while (true) {
		while (true) {
			system("cls");

			cout << "Choose function:\n";
			cout << "1 - Accept requests\n";
			cout << "0 - Exit\n";
			cin >> choice;

			if (choice < 0 && choice > 1) {
				cout << "There is no such command\n";
				_getch();
			}
			else {
				break;
			}
		}

		switch (choice)
		{
		case 1:
			managment.ShowDatabase(userInformation);
			break;
		default:
			return;
		}
	}
}