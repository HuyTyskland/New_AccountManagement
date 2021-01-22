/*
 * Account.h
 *
 *  Created on: Jan 22, 2021
 *      Author: huy3.nguyen
 */

#ifndef ACCOUNT_H_
#define ACCOUNT_H_

using namespace std;

class Account {
public:
	Account();
	void setInfo(string, string, bool);
	string getID();
	string getPW();
	bool getStatus();
	void changePassword(string);
	string printElement();
protected:
	string ID;
	string PW;
	bool isUser;
	bool theStatus;

};

#endif /* ACCOUNT_H_ */
