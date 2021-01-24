/*
 * tool.cpp
 *
 *  Created on: Jan 22, 2021
 *      Author: PC
 */

#include<iostream>
#include<string>
#include "Account.h"
#include "User.h"
#include "Admin.h"
#include "FileHandler.h"
#include "tool.h"

using namespace std;

vector<Account> returnInfoPiece(string line)
{
	vector<Account> anAccount;
	anAccount.push_back(Account());
	int position[3];
	int index = 0;
	for (int i = 0; i < line.length(); i++)
		if(line.at(i) == '-')
			position[index++] = i;

	string Iden = line.substr(0,  position[0]);
	string Pas = line.substr(position[0]+1, position[1]);
	bool isUser = (line.substr(position[1]+1, position[2]) == '1') ? true : false;
	bool aStatus = (line.substr(position[2]+1, line.length()) == '1') ? true : false;
	anAccount[0].setInfo(Iden, Pas, isUser, aStatus);
	return anAccount;
}


