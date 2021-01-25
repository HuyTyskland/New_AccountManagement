/*
 * AccountManager.h
 *
 *  Created on: Jan 24, 2021
 *      Author: PC
 */

#ifndef ACCOUNTMANAGER_H_
#define ACCOUNTMANAGER_H_

class AccountManager {
public:
	AccountManager(string);
	virtual ~AccountManager();
	vector<Admin> returnAdmin();
	vector<User> returnUser();
	bool isAccountFound(string,string);
	vector<string> getAccountInfo();
private:
	FileHandler *fileHandler = new FileHandler(whichRegion);
	string whichRegion;
};

#endif /* ACCOUNTMANAGER_H_ */
