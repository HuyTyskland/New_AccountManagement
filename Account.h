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
	void setInfo(string, string, bool, bool);
	string getID();
	string getPW();
	void changePassword(string);

protected:
	string ID;
	string PW;
	bool role;
	bool status;

};

#endif /* ACCOUNT_H_ */
