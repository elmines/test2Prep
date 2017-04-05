#include "ProbeHash.cpp"
#include <iostream>
#include <ctime>
#include <cstdlib> //For rand and atoi
using namespace std;

int linearProbe(int i){ return i;}
int quadraticProbe(int i){return i * i;}

void intUI(ProbeHash<int>& table)
{
	string response = "-";
	string input = "-";
	const char *pInput;

	while (response[0] != 'Q')
	{
		system("clear");
		cout << "\t\t\t" << "Hashtable Menu" << endl;
		cout << "\t\t\t\t" << "(P)ut" << endl;
		cout << "\t\t\t\t" << "(R)emove (NOT FUNCTIONAL)" << endl;
		cout << "\t\t\t\t" << "(C)ontains" << endl;
		cout << "\t\t\t\t" << "(E)mpty?" << endl;
		cout << "\t\t\t\t" << "(O)utput" << endl;
		cout << "\t\t\t\t" << "(Q)uit" << endl;

		cout << endl << "\t\t\t\t" << "Choose an option: ";
		getline(cin, response);
		cin.sync();

		if (response[0] == 'P')
		{
			cout << "Enter an integer: ";
			getline(cin, input);
			cin.sync();
			pInput = input.c_str();
			
			try{
				table.put(atoi(pInput));
			}
			catch(const char *message)
			{
				cout << "Error in adding element: " << message << endl;
			}
		}
		else if (response[0] == 'R')
		{
			cout << "Enter an integer: ";
			getline(cin, input);
			cin.sync();
			pInput = input.c_str();

			bool removed = table.remove(atoi(pInput));

			cout << "Element removed: " << removed << endl;
		}
		else if (response[0] == 'C')
		{
			cout << "Enter an integer: ";
			getline(cin, input);
			cin.sync();
			pInput = input.c_str();

			bool present = table.contains(atoi(pInput));

			cout << "Element present: " << present << endl;
		}
		else if (response[0] == 'E')
		{
			bool empty = table.isEmpty();
			cout << "Table empty: " << empty << endl;
		}
		else if (response[0] == 'O')
		{
			table.output();
		}
		else if (response[0] == 'Q')
		{
			cout << "Final hashtable: "; table.output();
		}
		else{
			cout << "Invalid option selected." << endl;
		}
		cout << "Press Enter to continue. . .";
		getline(cin, input);
		cin.sync();
	}
}

int initialTest()
{
	int capacity = 17;
	srand( time(0) );

	ProbeHash<int> table(capacity, [](int a){return a % 17;}, &linearProbe);

	for (int i = 0; i < capacity; ++i) table.put( rand() % 100 + 1);	

	intUI(table);

	return 0;
}

int test2()
{
	ProbeHash<int> table(17, [](int i){return i % 17;}, &linearProbe);
	intUI(table);
	return 0;
}

int main()
{
	return test2();
}
