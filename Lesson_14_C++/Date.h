#pragma once
#include <iostream>
#include <ctime>
using namespace std;

struct Date {
	int day = 0;
	int month = 0;
	int year = 0;
	char str[50] = "";

	void fillDate() {
		cout << "Day -> ";
		cin >> day;
		cout << "Month -> ";
		cin >> month;
		cout << "Year -> ";
		cin >> year;
	}

	void printDate() {
		cout << day / 10 << day % 10 << "." << month / 10 << month % 10 << "." << year << endl;
	}

	const char* toString(const char* format = "%d %B %Y") {
		tm dateInfo = { 0, 0, 0, day, month - 1, year - 1900 };
		strftime(str, 50, format, &dateInfo);
		return str;
	}

	void getNowDate() {
		time_t seconds = time(NULL);
		tm dateInfo = { 0 };
		localtime_s(&dateInfo, &seconds);

		year = dateInfo.tm_year + 1900;
		month = dateInfo.tm_mon + 1;
		day = dateInfo.tm_mday;
	}

	void toNextDate() {
		tm dateInfo = { 0, 0, 0, day, month - 1, year - 1900 };
		time_t seconds = mktime(&dateInfo);
		seconds += 3600 * 24; // + 1 day
		localtime_s(&dateInfo, &seconds);

		year = dateInfo.tm_year + 1900;
		month = dateInfo.tm_mon + 1;
		day = dateInfo.tm_mday;
	}

	void toPrevDate() {
		tm dateInfo = { 0, 0, 0, day, month - 1, year - 1900 };
		time_t seconds = mktime(&dateInfo);
		seconds -= 3600 * 24; // - 1 day
		localtime_s(&dateInfo, &seconds);

		year = dateInfo.tm_year + 1900;
		month = dateInfo.tm_mon + 1;
		day = dateInfo.tm_mday;
	}

	void addDays(int d) {
		tm dateInfo = { 0, 0, 0, day, month - 1, year - 1900 };
		time_t seconds = mktime(&dateInfo);
		seconds += 3600 * 24 * d; // + d days
		localtime_s(&dateInfo, &seconds);

		year = dateInfo.tm_year + 1900;
		month = dateInfo.tm_mon + 1;
		day = dateInfo.tm_mday;
	}

	void delDays(int d) {
		tm dateInfo = { 0, 0, 0, day, month - 1, year - 1900 };
		time_t seconds = mktime(&dateInfo);
		seconds -= 3600 * 24 * d; // - d days
		localtime_s(&dateInfo, &seconds);

		year = dateInfo.tm_year + 1900;
		month = dateInfo.tm_mon + 1;
		day = dateInfo.tm_mday;
	}
};