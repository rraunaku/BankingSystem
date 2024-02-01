bank: main.o Account.o Accounts.o AccountSystem.o
	g++ main.o Account.o Accounts.o AccountSystem.o -o bank

main.o: main.cpp
	g++ -c main.cpp

Account.o: Account.cpp
	g++ -c Account.cpp

Accounts.o: Accounts.cpp
	g++ -c Accounts.cpp

AccountSystem.o: AccountSystem.cpp
	g++ -c AccountSystem.cpp

clean:
	rm * .o bank