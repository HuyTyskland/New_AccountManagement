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
	FileHandler();
	void writeFile(vector<User>, vector<Admin>);
private:
	vector<Admin> adminList;
	vector<User> userList;
};

#endif /* FILEHANDLER_H_ */
