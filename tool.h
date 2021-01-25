/*
 * tool.h
 *
 *  Created on: Jan 22, 2021
 *      Author: PC
 */

#ifndef TOOL_H_
#define TOOL_H_

#include<string>

using namespace std;

vector<Account> returnInfoPieces(string);
bool isPasswordValid(string);
bool isIdUnique(vector<User>, string);
void printList(vector<User>);


#endif /* TOOL_H_ */
