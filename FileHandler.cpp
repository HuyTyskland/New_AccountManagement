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

FileHandler::FileHandler() {
	// TODO Auto-generated constructor stub
	string line;
	fstream myfile;
	myfile.open("data.txt");
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
					returnInfoPieces(line)[0].getStatus());
		} else
		{
			adminList.push_back(Admin());
			adminList[sizeAdmin++].setInfo(returnInfoPieces(line)[0].getID(),
					returnInfoPieces(line)[0].getPW(),
					returnInfoPieces(line)[0].getRole(),
					returnInfoPieces(line)[0].getStatus());
		}
	}
}

