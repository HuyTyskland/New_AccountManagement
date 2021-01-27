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
void printUserList(vector<User>);
void printDeletionRequest(vector<User>);
void deleteAnAccount(string, vector<User>&);
void changePassword(string, string, vector<Admin>&);
void changePassword(string, string, vector<User>&);
void setPending(string, vector<User>&);
void setActive(string, vector<User>&);
void createNewFile();
void changeFile(int);


#endif /* TOOL_H_ */
