
#ifndef ACCOUNTS_H
#define ACCOUNTS_H

#include <vector>
#include <fstream>
#include <string>
#include "Account.h"

class Accounts
{
    private:
    vector<Account> firstObj;
	
    public:
    Accounts();
    ~Accounts();
    void addAcc(Account& temp);
    Account& findObj(int ID);
    Account& at(const int i);
	void loadAccounts();
	void storeAccounts();
	int counter;
	void PrintInfo();
    
};

#endif

