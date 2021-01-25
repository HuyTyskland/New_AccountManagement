/*
 * FileHandler.h
 *
 *  Created on: Jan 22, 2021
 *      Author: huy3.nguyen
 */

#ifndef FILEHANDLER_H_
#define FILEHANDLER_H_

#include<vector>

class FileHandler {

public:
	FileHandler(string);
	~FileHandler();
	vector<Admin> returnAdminList();
	vector<User> returnUserList();
	void insertNewAccount(string, string);
private:
	vector<Admin> adminList;
	vector<User> userList;
	string regionData;
};

#endif /* FILEHANDLER_H_ */
