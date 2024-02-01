
#ifndef ACCOUNT_SYSTEM_H
#define ACCOUNT_SYSTEM_H

#include "Accounts.h"
class AccountSystem
{
    public: // declaring functions
    void addAcc();
    void deposit();
    void withdraw();
    void transferAmt();
	void loadAccountSystem();
	void storeAccountSystem();
    void PrintAcc();

    private: // decalring private variable
    Accounts accts;
};

#endif
