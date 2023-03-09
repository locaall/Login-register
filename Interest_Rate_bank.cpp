#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <thread>
#include <iomanip>

/* Scene appearing after successfully logging in */
int AfterLoggingIn() {
	/* Currencies available to convert */
	convert:
	int value, money;
	double EUR_to_RSD = 117.31, RSD_to_EUR = 0.0085;
	system("CLS");
	std::cout << "Welcome to EBank! Choose the currency you want to exchange: \n1) EUR -> RSD\n2) RSD -> EUR" << std::endl;
	std::cout << "Your choice: "; std::cin >> value;
	/* Entering a choice */
	if (value == 1) {
		system("CLS");
		std::cout << "Selected: EUR -> RSD\nPlease enter the amount of money in EUR: ";
		std::cin >> money;
		std::cout << money << " EUR is " << money * EUR_to_RSD << "RSD" << std::endl;
	} else if (value == 2) {
		system("CLS");
		std::cout << "Selected: RSD -> EUR\nPlease enter the amount of money in RSD: ";
		std::cin >> money;
		std::cout << money << " RSD is " << money / RSD_to_EUR << "EUR" << std::endl;
	} else {
		std::cout << "\nYou pressed a wrong button!" << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(2500));
		goto convert;
	}
	return 0;
}

/* LogIn function */
bool LogIn() {
	system("CLS");
	/* Input values */
	std::string username, password, EnteredUser, EnteredPass;
	std::cout << "Enter username: "; std::cin >> username;
	std::cout << "Enter password: "; std::cin >> password;

	/* Reading the .txt document that has been just made */
	std::ifstream read(username + ".txt");
	std::getline(read, EnteredUser);
	std::getline(read, EnteredPass);

	/* Checking information stored in a .txt file */
	if (EnteredUser == username && EnteredPass == password) {
		return true;
	} else {
		return false;
	}
}

int main() {
	/* Declaring variables used in a program */
	int choice; std::string username, password;

	choices:
	system("CLS");
	std::cout << "Select a choice!\n1) Register\n2) Login\nYour choice: "; std::cin >> choice;

	/* Different choices */
	if (choice == 1) {
		system("CLS");
		std::cout << "Username: "; std::cin >> username;
		std::cout << "Password: "; std::cin >> password;
		std::ofstream file;

		/* Creating the .txt file for storing the account information */
		file.open(username + ".txt");
		file << username << std::endl << password << std::endl;
		file.close();
		main();
	} else if (choice == 2) {
		/* If a user selects logging in, then we check the typed information */
		bool status = LogIn();

		if (!status) {
			std::cout << "\nIncorrect information, please try again!" << std::endl;
			system("PAUSE");
			return 0;
		} else {
			std::cout << "\nLogging in successfully!" << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(2500));

			/* Switch screen after logging in */
			int a = AfterLoggingIn();
			std::cout << a;
			return 1;
		}
	} else {
		/* Entering a non-existing value for a program */
		std::cout << "\nYou pressed a wrong button!" << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(2500));
		goto choices;
	}
	return 0;
}