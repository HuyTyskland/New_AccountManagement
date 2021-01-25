/*
 * User.cpp
 *
 *  Created on: Jan 22, 2021
 *      Author: huy3.nguyen
 */

#include<iostream>
#include<string>
#include "Account.h"
#include "User.h"
#include "Admin.h"
#include "tool.h"

using namespace std;

User::User() {
	// TODO Auto-generated constructor stub
}

void User::sendDeletionRequest(string ID, vector<User> userList)
{
	setPending(ID, userList);
}

void User::changeThePassword(string newPW, string ID, vector<User> userList)
{
	changePassword(ID, newPW, userList);
}

