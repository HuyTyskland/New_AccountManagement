/*
 * Admin.h
 *
 *  Created on: Jan 22, 2021
 *      Author: huy3.nguyen
 */

#ifndef ADMIN_H_
#define ADMIN_H_

#include<vector>

class Admin : public Account{
public:
	Admin();
	void showAllAccount(vector<User>);
	void showAllDeletionRequest(vector<User>);
	void approveAnRequest(string, vector<User>&);
	void changeThePassword(string, string, vector<Admin>&);
	void disapproveAnRequest(string, vector<User>&);
};

#endif /* ADMIN_H_ */
