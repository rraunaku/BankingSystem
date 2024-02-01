 #include<iostream>
#include"Account.h"// header file
using namespace std;

Account:: Account()//constructor
{
    accID = new int;
    *accID = 0;
    cusName = " ";
    balance = 0;
}

Account::~Account()//deconstructor
{
    delete accID;//deletes object
}

Account :: Account (const Account& origObj)//copy constructor
{
    accID = new int;//assigns new address
    *accID = *(origObj.accID);
    cusName = origObj.cusName;
    balance = origObj.balance;
}

Account& Account:: operator=(const Account& objToCopy)//copy assignment operator
{
    if(this!= &objToCopy)
    {
        delete accID;
        accID = new int;
        *accID = *(objToCopy.accID);
        cusName = objToCopy.cusName;
        balance = objToCopy.balance;
    }
    return *this;//return all the private variables
}

void Account:: setName(string cusName) //assigning the private variable with parameter
{
    this->cusName = cusName;
}

string Account :: GetName() const// returns the name 
{
    return cusName;
}

void Account :: setAccID(int ID)//setting the user entered ID in the private data member
{
    *accID = ID;
}

int Account :: GetaccID() const
{
    return *accID;
}

void Account :: setBalance(double balance)
{
    this->balance = balance;
}

double Account :: GetBal() const
{
    return balance;
}

void Account :: setAccountType(int acctType)
{
	accountType = acctType;
}

int Account :: getAccountType() const
{
	return accountType;
}


