#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <iomanip>
using namespace std;

class Account{
	friend class AccountChecking;
	friend class AccountSaving;

    protected:
    int* accID;
    string cusName;
    double balance;
	int accountType;

    public:
    Account();
    ~Account();
    Account(const Account& origObj);
    Account& operator = (const Account& objToCopy);
    
    Account& operator +=(const Account& origObj){
	    this -> balance += origObj.balance;
		return *this;
    }

    virtual void deposit(double amt){
		balance += amt;
	}

    virtual void withdraw(double amt){
		balance -= amt;
	}

    void setName(string cusName);
    void setBalance(double balance);
    void setAccID(int id);
    string GetName() const;
    double GetBal() const;
    int GetaccID() const;
	void setAccountType(int acctType);
	int getAccountType() const;
    
};

#endif

