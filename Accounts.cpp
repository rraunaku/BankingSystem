//class definition of Accounts

#include "Accounts.h"
using namespace std;


Accounts :: Accounts()
{
   counter = 0;// resets the counter
}

Accounts :: ~Accounts()
{
    
	counter = 0;
}

void Accounts :: loadAccounts()// takes input from the file
{
	ifstream in("accounts.dat");
	int size;
	int ID;
	double bal;
	string name;
	
	if(in)
	{
	in >> size;
	for(!in.is_open()){
		Account temp;
		in >> ID >> bal;
		getline(in, name);
		temp.setAccID(ID);
		//in >> bal;
		temp.setBalance(bal);
		//getline(in,name);
	    temp.setName(name);
		//cin.ignore();
		firstObj.push_back(temp);
		counter++;
		
	}
	}
	else
	{
		cout << "Could not open the file." << endl;
	}
	in.close();
}

void Accounts :: storeAccounts()// stores output to the file
{
	ofstream out("accounts.dat");
	if(!out.is_open())
	{
		cout << "Could not open the file." << endl;
		exit(1);
	}
		out << firstObj.size() << endl;
	for (int i = 0; i < firstObj.size(); i++)
	{
		out << firstObj.at(i).GetaccID() << " ";
		out << firstObj.at(i).GetBal() << " ";
		out << firstObj.at(i).GetName() << endl;	
	}
	out.close();
}
	
void Accounts :: addAcc(Account& temp)// updating the counter as the account is added
{
    if(counter <= firstObj.size())//condition for limit
    {
        firstObj.push_back(temp);
        counter++;
    }

    else 
    {
        cout << "Max capacity reached. Cannot add more accounts." << endl;

    }
} 

Account& Accounts :: findObj(int ID)// finds the object containinf the ID
{
    for (unsigned int i = 0; i < firstObj.size(); i++)
    {
        if(firstObj.at(i).GetaccID() == ID)
        {
            return firstObj.at(i);
        }

        else
        {
            return firstObj.at(0);
        }
    } 
}

Account& Accounts :: at(const int i)  //returns the object of parameter
{
    if(i < counter)
    {
        return firstObj.at(i);
    }
    else 
    {
        cout << "Index out of bounds." << endl;
        return firstObj.at(0);
    }
}

void Accounts :: PrintInfo()// prints info
{
	for ( int i = 0; i < firstObj.size(); i++)
	{
	cout << '+' << setfill('-')<< setw(67) << '+' << endl;
	cout << setfill(' ');
          cout << '|' << setw(2) << firstObj.at(i).GetaccID() << setw(2) << '|' << " " <<left <<  firstObj.at(i).GetName() << right << setw(25) << "|$" << setw(9) << left << firstObj.at(i).GetBal() << right << setw(13) << '|' << endl; 
	}
}
