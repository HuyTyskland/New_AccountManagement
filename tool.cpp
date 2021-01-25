/*
 * tool.cpp
 *
 *  Created on: Jan 22, 2021
 *      Author: PC
 */

#include<iostream>
#include<string>
#include<regex>
#include "Account.h"
#include "User.h"
#include "Admin.h"
#include "FileHandler.h"
#include "tool.h"

using namespace std;

vector<Account> returnInfoPieces(string line)
{
	vector<Account> anAccount;
	anAccount.push_back(Account());
	int position[3];
	int index = 0;
	for (int i = 0; i < (int)line.length(); i++)
		if(line.at(i) == '-')
			position[index++] = i;

	string Iden = line.substr(0,  position[0]);
	string Pas = line.substr(position[0]+1, position[1]);
	bool isUser = (line.substr(position[1]+1, position[2]) == "1") ? true : false;
	bool aStatus = (line.substr(position[2]+1, line.length()) == "1") ? true : false;
	anAccount[0].setInfo(Iden, Pas, isUser, aStatus);
	return anAccount;
}

bool isPasswordValid(string PW)
{
	regex regCri1 ("[^a-zA-Z0-9]");
	regex regCri2 ("[a-z]");
	regex regCri3 ("[A-Z]");
	regex regCri4 ("[0-9]");
	smatch matches;
	if (PW.length() >= 8) // valid number of character in password
		return (regex_search(PW, matches, regCri1)
				&& regex_search(PW, matches, regCri2)
				&& regex_search(PW, matches, regCri3)
				&& regex_search(PW, matches, regCri4));
	else return false;
}

bool isIdUnique(vector<User> userList, string ID)
{
	for (auto it = userList.begin(); it != userList.end(); ++it)
		if (ID == (*it).getID())
			return false;
	return true;
}
