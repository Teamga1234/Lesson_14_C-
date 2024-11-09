#pragma once
#include "Violation.h"
struct Driver {
	char name[100] = "";
	char carNumber[20] = "";
	int sizeViol = 0;
	Violation* arrViol = nullptr;
	void fillDriver(){
		cout << "Input name: ";
		cin.getline(name, 100);
		cout << "Car number: ";
		cin >> carNumber;


	}
	void showDriver()
	{
		cout << "Name: " << name << endl;
		cout << "Car: " << carNumber << endl;
		if (sizeViol == 0) cout << name << " hasn`t violations";
		else {
			for (int i = 0; i < sizeViol; i ++ )
			{
				cout << "#" << i + 1 << endl;
				arrViol[i].showViolation();
			}
		}
	}
};
