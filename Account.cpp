/*
 * Account.cpp
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

Account::Account() {
	// TODO Auto-generated constructor stub
	isUser = true;
}


void Account::setInfo(string Identification, string Password, bool aStatus)
{
	ID = Identification;
	PW = Password;
	theStatus = aStatus;
}

string Account::getID()
{
	return ID;
}

string Account::getPW()
{
	return PW;
}

bool Account::getStatus()
{
	return theStatus;
}

void Account::changePassword(string newPW)
{
	cout << "change the password to " << newPW << endl;
}

string Account::printElement()
{
	string s = "";
	s.append("ID: ");
	s.append(ID);
	s.append(" PW: ");
	s.append(PW);
	return s;
}
