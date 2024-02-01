#include <iostream>
#include <iomanip>
#include <string>

#include "AccountSystem.h"
using namespace std;


void AccountSystem :: loadAccountSystem()
{
	accts.loadAccounts();
}

void AccountSystem :: storeAccountSystem()
{
	accts.storeAccounts();
}

void AccountSystem::addAcc() 
{
    Account acct;//initialize and variable of Account dat typedef
    int ID;
    string name;
    double balance;
	bool found = false;// setting a boolean for conditional statement
    cout << "Enter account id: ";
    cin >> ID;
    acct.setAccID(ID);//sets the user entered name to the private variable of the onject
    for (int i = 0; i < accts.counter; i++) //checks if there is any accounts
	{
        if (accts.at(i).GetaccID() == ID) 
		{
            cout << "Account already exists." << endl;
			found = true;// changes the bool
        }
    }
	if(!found)//proceeds if the account doesnt exists
	{
    cout << "Enter customer account name: ";
	cin.ignore();
    getline(cin, name);
    acct.setName(name);//sets the name 
    cout << "Enter initial deposit amount: ";
    cin >> balance;
    acct.setBalance(balance);
    accts.addAcc(acct);
    cout << "Added new account id " << ID << " with initial balance $" << balance << endl;
	}
	else //if exists
	{
		cout << "Please try a new ID." << endl;
	}
	}


void AccountSystem::deposit()
 {
    int ID;
	int add;
    double amt;
	bool found = false;// setting a boolean for conditional statement
	if(accts.counter == 0)
	{
		cout << "Empty account list." << endl;
	}
	else
	{
    cout << "Enter account id: ";// prompts user to enter ID
    cin >> ID;
	 for (int i = 0; i < accts.counter; i++) 
	{
        if (accts.at(i).GetaccID() == ID) // if the ID matches the ID stored then the address is noted and the booolean variable is set to true
		{
			found = true;
			add = i;
        }
    }
	if(found) // if the boolean variable id true the proceeds
	{
    Account acct = accts.findObj(ID);
    cout << "Enter deposit amount: ";
    cin >> amt;
    accts.at(add).deposit(amt);
    cout << "Deposited $" << fixed << setprecision(2) << amt << " into account id " << ID <<  endl;
	}
	else // if not error output is displayed.
	{
		cout << "Error: account with id "<< ID << " not found." << endl;
	}
	}
}

void AccountSystem::withdraw() 
{
    int ID;
	int add;
    double amt;
	bool found = false;// setting a boolean for conditional statement
	if(accts.counter == 0)
	{
		cout << "Empty account List." << endl;
	}
	else{
    cout << "Enter account id: ";//prompts user to enter ID
    cin >> ID;
	for (int i = 0; i < accts.counter; i++) 
	{
        if (accts.at(i).GetaccID() == ID) // if the ID matches the ID stored then the address is noted and the booolean variable is set to true
		{
			found = true;
			add = i;
        }
    }
	if(found)// if the boolean variable id true the proceeds
	{
    Account acct = accts.findObj(ID);
    cout << "Enter withdraw amount: ";
    cin >> amt;
    if (accts.at(add).GetBal() < amt) {
        cout << "Insufficient balance." << endl;
    }
	else
	{
    accts.at(add).withdraw(amt);//uses the member function of the variable accts of data type Accounts which return the the specific array whihc of data type Account and calls the member function to add the amount to the current balance.
    cout << "Withdrew $" << fixed << setprecision(2) << amt << " from account id " << ID << endl;
    }
	}
	else // if not error output is displayed.
	{
		cout << "Error: account with id " << ID << " not found." << endl;
	}
	}
}

void AccountSystem::transferAmt() 
{
    int srcAcctID;
    int dstAcctID;
    double amt;
	bool found = false;// setting a boolean for conditional statement
	bool found2 = false;
	if(accts.counter == 0)// checks if there is any account added to the array
	{
		cout << "Empty account list." << endl;
	}
	else 
	{
    cout << "Enter source account ID: ";// prompts the user to enter the ID for the source account
    cin >> srcAcctID;
	int add1;// variables to store the address 
	int add2;
	for (int i = 0; i < accts.counter; i++) // loop to check every array 
	{
        if (accts.at(i).GetaccID() == srcAcctID) // condition to check if the user entered ID matches any account registered.
		{
			found = true;// sets the boolean to true if found
			add1 = i;// stores the address of this specific array
			cout << "Enter destination account ID: ";
            cin >> dstAcctID;// only when the source account ID matches, it prompts the user to enter the ID of the destination account
	for (int i = 0; i < accts.counter; i++) // loop to check every array 
	{
        if (accts.at(i).GetaccID() == dstAcctID) // condition to check if the user entered ID matches any account registered
		{
			found2 = true;// sets the boolean to true if found
			add2 = i;// stores the address of this specific array
        }
    }
		}
	
    }
	if(found && found2)//proceeds only when both the boolean variable is true which verifies that the user entered ID matches the the ones in the array.
	{
			Account srcAcct = accts.findObj(srcAcctID);// return the array of the ID matched with the user entered ID
			Account destAcct = accts.findObj(dstAcctID);
			cout << "Enter transfer amount: ";
			cin >> amt;// prompts the user to enter the amount to be transfered.
		if (accts.at(add1).GetBal() < amt) // checks if the source account has enough balance to be transfered
		{
			cout << "Insufficient balance." << endl;
		}
		else
		{
			accts.at(add1).withdraw(amt);
			accts.at(add2).deposit(amt);
			destAcct += srcAcct;
			cout << "Successfully transferred amount $" << fixed << setprecision(2) << amt << " from source account id " << srcAcctID << " to destination account id " << dstAcctID << endl;
		}
	}
	else 
	{
			cout << "Error: Source or destination account number not found." << endl;
	}
	
}
}
void AccountSystem::PrintAcc() // prints the registered information in correct format.
{
	Accounts temp;
    if (accts.counter == 0) {
        cout << "Empty account list." << endl;
    }
    else 
    {
    cout << '+' << setfill('-')<< setw(67) << '+' << endl;
	cout << setfill(' ');
   cout << '|' << setw(2) << "Acct" << setw(2) << '|' << " " << left << "Customer Account Name" << right << setw(25) << "| Balance" << setw(13) << '|' << endl; 
    accts.PrintInfo();
     }
}


