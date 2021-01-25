/*
 * main.cpp
 *
 *  Created on: Jan 22, 2021
 *      Author: huy3.nguyen
 */


#include<iostream>
#include<string>
#include "Account.h"
#include "User.h"
#include "Admin.h"
#include "FileHandler.h"
#include "AccountManager.h"

using namespace std;

string regionList();
void regionAction(string);
void logMenu();
int adminOption();
void adminAction(int, string, vector<User>&, vector<Admin>&);
int userOption();
void userAction(int, string, vector<User>&);

int main()
{

}

string regionList()
{
	string region;
	cout << "***************************************" << endl;
	cout << "        WELCOME TO THE SYSTEM" << endl;
	cout << "<><><><><><><><><><><><><><><><><><><><>" << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "Which region you want to work with?" << endl;
	cout << "1. Ha Noi" << endl;
	cout << "2. Ho Chi Minh city" << endl;
	cout << "3. Da Nang city" << endl;
	cout << "Your choice: ";
	cin >> region;
	return region;
}

void regionAction(string region)
{
	int choice = 0;
	AccountManager *ptrAccMana = new AccountManager(region);
	logMenu();
	cin >> choice;
	switch(choice)
	{
	case 1:
	{
		cout << "Insert your account:" << endl;
		vector<string> anAccount = ptrAccMana->getAccountInfo();
		if (ptrAccMana->isAdminFound(anAccount[0], anAccount[1]))
		{
			adminAction(adminOption(),
					anAccount[0],
					ptrAccMana->returnUser(),
					ptrAccMana->returnAdmin());
		} else if(ptrAccMana->isUserFound(anAccount[0], anAccount[1]))
		{
			cout << "User menu" << endl;
		}
		break;
	}
	case 2:
	{
		cout << "Insert your new account info:" << endl;
		vector<string> newAccount = ptrAccMana->getAccountInfo();
		ptrAccMana->registerNewAccount(newAccount[0], newAccount[1]);
		cout << "Thank you for registering" << endl;
		break;
	}
	}

}

void logMenu()
{
	cout << "What do you want?" << endl;
	cout << "1. Log in" << endl;
	cout << "2. Log up" << endl;
	cout << "Your choice: ";
}

int adminOption()
{
	int choice = 0;
	cout << "Hello Admin, what do you want to do?" << endl;
	cout << "1. Display All Account" << endl;
	cout << "2. Display All Deletion Request" << endl;
	cout << "3. Approve Deletion Request" << endl;
	cout << "4. Disapprove Deletion Request" << endl;
	cout << "5. Change Password" << endl;
	cout << "6. Exit" << endl;
	cin >> choice;
	return choice;
}

void adminAction(int choice, string ID, vector<User> &userList, vector<Admin> &adminList)
{
	Admin *anAdmin = new Admin;
	switch(choice)
	{
	case 1:
	{
		anAdmin->showAllAccount(userList);
		break;
	}
	case 2:
	{
		anAdmin->showAllDeletionRequest(userList);
		break;
	}
	case 3:
	{
		string deletedID;
		cout << "Which deletion do you want to approve, please enter that ID: ";
		cin >> deletedID;
		anAdmin->approveAnRequest(deletedID, userList);
		break;
	}
	case 4:
	{
		cout << "Disapprove the request" << endl;
		break;
	}
	case 5:
	{
		string newPW;
		cout << "what is your new password: ";
		cin >> newPW;
		anAdmin->changeThePassword(ID, newPW, adminList);
		break;
	}
	}
	delete(anAdmin);
}

int userOption()
{
	int choice = 0;
	cout << "Hello, what do you want to do?" << endl;
	cout << "1. Send Deletion Request" << endl;
	cout << "2. Change Password" << endl;
	cout << "3. Exit" << endl;
	cout << "Your choice: ";
	cin >> choice;
	return choice;
}

void userAction(int choice, string ID, vector<User>& userList)
{
	User *anUser = new User;
	switch (choice)
	{
	case 1:
	{
		anUser->sendDeletionRequest(ID, userList);
		break;
	}
	case 2:
	{
		string newPW;
		cout << "what is your new password: ";
		cin >> newPW;
		anUser->changeThePassword(newPW, ID, userList);
		break;
	}
	}
}
