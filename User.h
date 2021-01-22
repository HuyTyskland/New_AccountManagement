/*
 * User.h
 *
 *  Created on: Jan 22, 2021
 *      Author: huy3.nguyen
 */

#ifndef USER_H_
#define USER_H_

class User : public Account {
public:
	User();
	void sendDeletionRequest();
	string printElement();
};

#endif /* USER_H_ */
