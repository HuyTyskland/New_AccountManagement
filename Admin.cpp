/*
 * Admin.cpp
 *
 *  Created on: Jan 22, 2021
 *      Author: huy3.nguyen
 */

#include<iostream>
#include<string>
#include<vector>
#include "Account.h"
#include "User.h"
#include "Admin.h"
#include "tool.h"

using namespace std;

Admin::Admin() {
	// TODO Auto-generated constructor stub
}

void Admin::showAllAccount(vector<User> userList)
{
	printUserList(userList);
}

void Admin::showAllDeletionRequest(vector<User> userList)
{
	printDeletionRequest(userList);
}

void Admin::approveAnRequest(string deletedID, vector<User>& userList)
{
	deleteAnAccount(deletedID, userList);
}

void Admin::changeThePassword(string ID, string newPW, vector<Admin>& adminList)
{
	changePassword(ID, newPW, adminList);
}

void Admin::disapproveAnRequest(string disapprovedID, vector<User>& userList)
{
	setActive(disapprovedID, userList);
}
