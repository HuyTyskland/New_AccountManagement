/*
 * Account.cpp
 *
 *  Created on: Jan 22, 2021
 *      Author: huy3.nguyen
 */

#include<iostream>
#include<string>
#include "Account.h"

using namespace std;

Account::Account() {
	// TODO Auto-generated constructor stub

}

void Account::setInfo(string Identification, string Password, bool aStatus)
{
	ID = Identification;
	PW = Password;
	status = aStatus;
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
	return status;
}

void Account::changePassword(string newPW)
{
	cout << "change the password to " << newPW << endl;
}
