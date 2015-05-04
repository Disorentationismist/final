//Sql.cpp
#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;
struct work
{
	char name[100];
	int id;
	char job[10];
}workers[10];
int main()
{
	int numWorkers = 0;
	int option = 0;
	ofstream file;
	while (1)
	{
		cout << "\nThe c++ Database application\n1-To enter the data\n2-To read the data\n3-To save the data\n";
		cin >> option;
		switch (option)
		{
		case 1:
			cout << "Enter the no. of workers:" << endl;
			cin >> numWorkers;
			for (int i = 0; i < numWorkers; i++)
			{
				cout << endl << "Enter the name of the worker:" << endl;
				cin >> workers[i].name;
				cout << endl << "Enter the ID no. of the worker:" << endl;
				cin >> workers[i].id;
				cout << endl << "Enter the job of the worker:" << endl;
				cin >> workers[i].job;
				cout << endl;
			}
			break;
		case 2:
			for (int i = 0; i < numWorkers; i++)
				cout << endl << "The worker no. " << i + 1 << " is " << workers[i].name << " with an ID no. of " << workers[i].id;
			cout << endl << endl;
			break;
		case 3:
			file.open("report.txt");
			for (int i = 0; i < numWorkers; i++)
				file << endl << "The worker no. " << i + 1 << " is " << workers[i].name << " with an ID no. of " << workers[i].id << endl;
			file << endl;
			file.close();
			cout << "The file is saved" << endl;
			_getch();
			break;
		}
	}
	return 0;
}
