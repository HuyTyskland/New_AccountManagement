/*
 * FileHandler.cpp
 *
 *  Created on: Jan 22, 2021
 *      Author: huy3.nguyen
 */

#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include "Account.h"
#include "User.h"
#include "Admin.h"
#include "FileHandler.h"
#include "tool.h"

using namespace std;

//FileHandler::FileHandler(string whichRegion) {
FileHandler::FileHandler() {
	// TODO Auto-generated constructor stub
//	regionData = whichRegion;
	string line;
	fstream myfile;
//	myfile.open(regionData + ".txt");
	myfile.open("Hanoi.txt");
	int sizeUser = 0;
	int sizeAdmin = 0;
	while(getline(myfile, line))
	{
		if(returnInfoPieces(line)[0].getRole() == true)
		{
			userList.push_back(User());
			userList[sizeUser++].setInfo(returnInfoPieces(line)[0].getID(),
					returnInfoPieces(line)[0].getPW(),
					returnInfoPieces(line)[0].getRole(),
					returnInfoPieces(line)[0].getActiveness());
		} else
		{
			adminList.push_back(Admin());
			adminList[sizeAdmin++].setInfo(returnInfoPieces(line)[0].getID(),
					returnInfoPieces(line)[0].getPW(),
					returnInfoPieces(line)[0].getRole(),
					returnInfoPieces(line)[0].getActiveness());
		}
	}
	cout << "FileHandler.cpp - first" << endl;
	myfile.close();
	remove("Hanoi.txt");
	rename("temp.txt","Hanoi.txt");
	createNewFile();
}

FileHandler::~FileHandler()
{
	fstream myfile;
//	myfile.open(regionData + ".txt");
	myfile.open("Hanoi.txt");
	for (auto it = userList.begin(); it != userList.end(); ++it)
	{
		myfile << (*it).getID() << "-" << (*it).getPW() << "-" << (*it).getRole() << "-" << (*it).getActiveness();
		myfile << "\n";
	}
	for (auto it = adminList.begin(); it != adminList.end(); ++it)
	{
//		myfile << (*it).getID() << "-" << (*it).getPW() << "-" << (*it).getRole() << "-" << (*it).getActiveness();
		myfile << (*it).getID() << "-" << (*it).getPW() << "-" << (*it).getRole() << "-" << (*it).getActiveness();
		myfile << "\n";
	}
	myfile.close();
}

vector<Admin> FileHandler::returnAdminList()
{
	return adminList;
}

vector<User> FileHandler::returnUserList()
{
	return userList;
}

void FileHandler::insertNewAccount(string newID, string newPW)
{
	userList.push_back(User());
	userList[userList.size()].setInfo(newID, newPW, true, true);
}

void FileHandler::updateVector(vector<Admin> newAdminList, vector<User> newUserList)
{
	adminList = newAdminList;
	userList = newUserList;
}
