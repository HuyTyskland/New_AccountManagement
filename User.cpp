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

using namespace std;

User::User() {
	// TODO Auto-generated constructor stub
	isUser = true;
}

void User::sendDeletionRequest()
{
	cout << "send deletion request" << endl;
}

string User::printElement()
{
	string s = "";
	s.append("User: ");
	s.append("ID: ");
	s.append(ID);
	s.append(" PW: ");
	s.append(PW);
	return s;
}
