/*
 * Admin.h
 *
 *  Created on: Jan 22, 2021
 *      Author: huy3.nguyen
 */

#ifndef ADMIN_H_
#define ADMIN_H_

class Admin : public Account{
public:
	Admin();
	void showAllAccount();
	void showAllDeletionRequest();
	void ApproveDeletionRequest();
	void DeleteAnAccount();
};

#endif /* ADMIN_H_ */
