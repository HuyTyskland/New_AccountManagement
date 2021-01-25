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
		break;
	}
	case 2:
	{
		vector<string> newAccount = ptrAccMana->getAccountInfo();
		ptrAccMana->registerNewAccount(newAccount[0], newAccount[1]);
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


