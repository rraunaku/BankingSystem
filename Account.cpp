#include<iostream>
#include"Account.h" // header file
using namespace std;

Account:: Account(){ // Default Constructor
    accID = new int;
    *accID = 0;
    cusName = " ";
    balance = 0;
}

Account::~Account(){ // Destructor
    delete accID; // deletes object
}

Account :: Account (const Account& origObj){ // Copy Constructor
    accID = new int; //assigns new address
    *accID = *(origObj.accID);
    cusName = origObj.cusName;
    balance = origObj.balance;
}

Account& Account:: operator=(const Account& objToCopy){
    if(this!= &objToCopy){
        delete accID;
        accID = new int;
        *accID = *(objToCopy.accID);
        cusName = objToCopy.cusName;
        balance = objToCopy.balance;
    }
    return *this; //return all the private variables
}

void Account:: setName(string cusName){
    this->cusName = cusName;
}

string Account :: GetName() const{ // returns the name
    return cusName;
}

void Account :: setAccID(int ID){
    *accID = ID;
}

int Account :: GetaccID() const{
    return *accID;
}

void Account :: setBalance(double balance){
    this -> balance = balance;
}

double Account :: GetBal() const{
    return balance;
}

void Account :: setAccountType(int acctType){
	accountType = acctType;
}

int Account :: getAccountType() const{
	return accountType;
}


