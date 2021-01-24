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
	AccountManager();
	virtual ~AccountManager();
	vector<Admin> returnAdmin();
	vector<User> returnUser();
private:
	FileHandler fileHandler;
};

#endif /* ACCOUNTMANAGER_H_ */
