#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct work
{
	string name;
	int id;
	string job;
}workers[10];
int main()
{
	int numWorkers = 0;
	int option = 0;
	ofstream file;
	while (1)
	{
		cout << endl;
		cout << "Ryan Darling   Brandon Roy   Logan Mularski   Presents..." << endl;
		cout << "\nThe Super Amazing Storage Database!!!\n1 - Enter New Data\n2 - Read Data File\n3 - Save Data File\n";
		cin >> option;
		switch (option)
		{
		case 1:
			cout << "Enter Amount of Workers:" << endl;
			cin >> numWorkers;
			for (int i = 0; i < numWorkers; i++)
			{
				cout << endl << "Enter Worker Name:" << endl;
				cin.get();
				getline(cin, workers[i].name);
				cout << endl << "Enter ID Number:" << endl;
				cin >> workers[i].id;
				cout << endl << "Enter Job:" << endl;
				cin.get();
				getline(cin, workers[i].job);
				cout << endl;
			}
			break;
		case 2:
			for (int i = 0; i < numWorkers; i++)
				cout << endl << "Worker Number: " << i + 1 << " Name: " << workers[i].name << " ID: " << workers[i].id << " Job: " << workers[i].job;
			cout << endl << endl;
			break;
		case 3:
			file.open("Employee Info.txt");
			for (int i = 0; i < numWorkers; i++)
				file << endl << "Worker Number " << i + 1 << " Name: " << workers[i].name << " ID: " << workers[i].id << " Job: " << workers[i].job << endl;
			file << endl;
			file.close();
			cout << "The file is saved" << endl;
			break;
		}
	}
	return 0;
}
