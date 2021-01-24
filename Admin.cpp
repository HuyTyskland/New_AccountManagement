/*
 * Admin.cpp
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

Admin::Admin() {
	// TODO Auto-generated constructor stub
}

void Admin::showAllAccount()
{
	cout << "Show All Accounts" << endl;
}

void Admin::showAllDeletionRequest()
{
	cout << "Show All deletion request" << endl;
}

void Admin::DeleteAnAccount()
{
	cout << "delete an account" << endl;
}

void Admin::ApproveDeletionRequest()
{
	cout << "Approve a deletion request" << endl;
}


