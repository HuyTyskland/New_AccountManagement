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

AccountManager::AccountManager() {
	// TODO Auto-generated constructor stub
}

AccountManager::~AccountManager() {
	// TODO Auto-generated destructor stub
	fileHandler.~FileHandler();
}

vector<Admin> AccountManager::returnAdmin()
{
	return fileHandler.returnAdminList();
}

vector<User> AccountManager::returnUser()
{
	return fileHandler.returnUserList();
}
