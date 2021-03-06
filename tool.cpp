/*
 * tool.cpp
 *
 *  Created on: Jan 22, 2021
 *      Author: PC
 */

#include<iostream>
#include<fstream>
#include<string>
#include<regex>
#include<vector>
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
	string Pas = line.substr(position[0]+1, position[1] - position[0] - 1);
	bool isUser = (line.substr(position[1]+1, position[2] - position[1] - 1) == "1") ? true : false;
	bool aStatus = (line.substr(position[2]+1, line.length() - position[2] - 1) == "1") ? true : false;
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

void printUserList(vector<User> userList)
{
	for (auto it = userList.begin(); it != userList.end(); ++it)
		cout << (*it).printElement() << endl;
}

void printDeletionRequest(vector<User> userList)
{
	for (auto it = userList.begin(); it != userList.end(); ++it)
		if ((*it).getActiveness() == false)
			cout << (*it).printElement() << endl;

}

void deleteAnAccount(string ID, vector<User>& userList)
{
	for(auto it = userList.begin(); it != userList.end(); ++it)
		if(ID == (*it).getID())
			userList.erase(it);
}

void changePassword(string ID, string newPW, vector<Admin>& adminList)
{
	for (auto it = adminList.begin(); it != adminList.end(); ++it)
		if ((*it).getID() == ID)
			(*it).setInfo(ID, newPW, false, true);
}

void changePassword(string ID, string newPW, vector<User>& userList)
{
	for (auto it = userList.begin(); it != userList.end(); ++it)
		if ((*it).getID() == ID)
			(*it).setInfo(ID, newPW, true, true);
}

void setPending(string ID, vector<User>& userList)
{
	for (auto it = userList.begin(); it != userList.end(); ++it)
		if ((*it).getID() ==  ID)
			(*it).setInfo(ID, (*it).getPW(), true, false);
}

void setActive(string ID, vector<User>& userList)
{
	for (auto it = userList.begin(); it != userList.end(); ++it)
		if ((*it).getID() ==  ID)
			(*it).setInfo(ID, (*it).getPW(), true, true);
}

void createNewFile()
{
	fstream myfile;
	myfile.open("temp.txt", ios::out);
	myfile.close();
}

void changeFile(int region)
{
	switch(region)
	{
	case 1:
	{
		remove("Hanoi.txt");
		rename("temp.txt", "Hanoi.txt");
		break;
	}
	case 2:
	{
		remove("Hochiminh.txt");
		rename("temp.txt", "Hochiminh.txt");
		break;
	}
	case 3:
	{
		remove("Danang.txt");
		rename("temp.txt", "Danang.txt");
		break;
	}
	}
}

int checkDeletionNum(vector<User> userList)
{
	int count = 0;
	for (auto it = userList.begin(); it != userList.end(); ++it)
		if ((*it).getActiveness() == false)
			count++;
	return count;
}
