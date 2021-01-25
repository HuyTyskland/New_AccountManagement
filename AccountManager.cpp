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

bool AccountManager::isAccountFound(string ID, string PW)
{
	for(auto it = returnAdmin().begin(); it != returnAdmin().end(); ++it)
		if ((ID == (*it).getID()) && PW == (*it).getPW())
			return true;
		else return false;
	return false;
}
