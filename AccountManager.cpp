/*
 * AccountManager.cpp
 *
 *  Created on: Jan 24, 2021
 *      Author: PC
 */

#include<iostream>
#include<string>
#include "Account.h"
#include "User.h"
#include "Admin.h"
#include "FileHandler.h"
#include "AccountManager.h"
#include "tool.h"

using namespace std;

AccountManager::AccountManager(string region) {
	whichRegion = region;
	// TODO Auto-generated constructor stub
}

AccountManager::~AccountManager() {
	// TODO Auto-generated destructor stub
	delete(fileHandler);
}

vector<Admin> AccountManager::returnAdmin()
{
	return fileHandler->returnAdminList();
}

vector<User> AccountManager::returnUser()
{
	return fileHandler->returnUserList();
}

bool AccountManager::isAdminFound(string ID, string PW)
{
	for(auto it = returnAdmin().begin(); it != returnAdmin().end(); ++it)
		if ((ID == (*it).getID()) && PW == (*it).getPW())
			return true;
		else return false;
	return false;
}

bool AccountManager::isUserFound(string ID, string PW)
{
	for(auto it = returnUser().begin(); it != returnUser().end(); ++it)
		if ((ID == (*it).getID()) && PW == (*it).getPW())
			return true;
		else return false;
	return false;
}

vector<string> AccountManager::getAccountInfo()
{
	string ID, PW;
	vector<string> accountInfo;
	cout << "ID: ";
	cin >> ID;
	accountInfo.push_back(ID);
	cout << endl;
	cout << "PW: ";
	cin >> PW;
	accountInfo.push_back(PW);
	return accountInfo;

}

void AccountManager::registerNewAccount(string newID, string newPW)
{
	if (isIdUnique(returnUser(), newID) && isPasswordValid(newPW))
	{
		fileHandler->insertNewAccount(newID, newPW);
		cout << "The account is created successfully" << endl;
	} else cout << "Your ID is not unique or your password is not valid" << endl;
}
