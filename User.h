/*
 * User.h
 *
 *  Created on: Jan 22, 2021
 *      Author: huy3.nguyen
 */

#ifndef USER_H_
#define USER_H_

#include<vector>

class User : public Account {
public:
	User();
	void sendDeletionRequest(string, vector<User>&);
	void changeThePassword(string, string, vector<User>&);
};

#endif /* USER_H_ */
