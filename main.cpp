#include <iostream>
#include <string>
#include <iomanip>
#include "AccountSystem.h"
using namespace std;


int main(){

    int type;
    AccountSystem sys;
	

cout << "+-------------------------------------------------+" << endl;// displays the introduction.
    cout << "|       Computer Science and Engineering          |" << endl; 
    cout << "|      CSCE 1040 - Computer Science II            |" << endl; 
    cout << "|Raunak Upreti  ru0044 RaunakUpreti@my.unt.edu |" << endl; 
    cout << "+-------------------------------------------------+ " << endl;
	
	sys.loadAccountSystem();

    do{// loops only if the type is not 6. Prints the menu.
        cout << endl;
        cout << '+' << setfill('-')<< setw(58) << '+' << endl;
        cout << setfill(' ');
        cout << '|' << setw(57) << left << "Enter account selection" << right << '|' << endl;
        cout << '|' << setw(57) << left << "1. Add new account" << right << '|' << endl;
        cout << '|' << setw(57) << left << "2. Deposit into Account" << right << '|' << endl;
        cout << '|' << setw(57) << left << "3. Withdraw from Account" << right << '|' << endl;
        cout << '|' << setw(57) << left << "4. Transfer into account" << right << '|' << endl;
        cout << '|' << setw(57) << left << "5. Print a list of all accounts" << right << '|' << endl;
        cout << '|' << setw(57) << left << "6. End transaction (Exit)" << right << '|' << endl;
        cout << '+' << setfill('-')<< setw(58) << '+' << endl;
        cout << setfill(' ');
        cin >> type;

        switch (type)// it outputs according to the user entere type.
        {
            case 1:
                sys.addAcc();
                break;
            case 2:
                sys.deposit();
                break;
            case 3:
                sys.withdraw();
                break;
            case 4:
                sys.transferAmt();
                break;
            case 5:
                sys.PrintAcc();
                break;
            case 6:
                cout << "Thank you for your business. Have a good day!" << endl;
                break;
            default:
                cout << "Error: Invalid selection. Enter a value between 1-6." << endl;// displays error when user enters number outside of the specified number.
                break;
        }
    } while (type != 6);
	
	sys.storeAccountSystem();
    return 0;
}
