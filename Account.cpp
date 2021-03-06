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


void Account::setInfo(string Identification, string Password, bool role, bool aStatus)
{
	ID = Identification;
	PW = Password;
	isActive = aStatus;
	isUser = role;
}

string Account::getID()
{
	return ID;
}

string Account::getPW()
{
	return PW;
}

bool Account::getActiveness()
{
	return isActive;
}

bool Account::getRole()
{
	return isUser;
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
