#pragma once
#include "Date.h"

struct Violation
{
	Date date;             //����
	char info[100] = "";    //���� ���������
	double fine = 0;          //�����

	void fillViolation()
	{
		cout << "Input date(dd mm yyyy): ";
		cin >> date.day >> date.month >> date.year;
		cout << "Input info: ";
		cin.ignore();
		cin.getline(info, 100);
		cout << "Input fine: ";
		cin >> fine;
	}
	void showViolation()
	{
		cout << "\tDate: " << date.toString("%Y %m %d") << endl;
		cout << "\tInfo: " << info << endl;
		cout << "\tFine: " << fine << "UAH\n\n";
 	}
};