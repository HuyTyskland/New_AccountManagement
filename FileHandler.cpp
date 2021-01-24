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

using namespace std;

FileHandler::FileHandler() {
	// TODO Auto-generated constructor stub
	string line;
	fstream myfile;
	myfile.open("data.txt");
	while(getline(myfile, line))
	{

	}
}

