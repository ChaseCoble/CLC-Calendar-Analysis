#include <iostream>

using namespace std;
void testMenu() {
	cout << "* Test Menu *" << endl;
	cout << "* 1. isLeapYear *" << endl;
	cout << "* 2. getCenturyValue *" << endl;
	cout << "* 3. getYearValue *" << endl;
	cout << "* 4. getMonthValue *" << endl;
	cout << "* 5. dayOfWeek(month, day, year) *" << endl;
	cout << "* 6. dayOfWeek(day) * " << endl;
	cout << "* 7. Quit Testing * " << endl;
};
int isLeapYear(int year) {
	if (year > 1582) {
		if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		return 2;
	}
}
int getCenturyValue(int year) {
	if (year < 1582) {
		return 0;
	}
	return((3 - ((year / 100) % 4)) * 2);
}

int getYearValue(int year) {
	if (year < 1582) {
		return 0;
	}
	int lastTwo = year % 100;
	int leapYears = lastTwo / 4;
	return (lastTwo + leapYears);
}
int getMonthValue(int month, int year) {
	if (year < 1582 || month < 1 || month > 12) {
		return 7;
	}
	switch (month) {
	case 1:
		if (isLeapYear(year)) {
			return 6;
			break;
		}
		return 0;
		break;
	case 2:
		if (isLeapYear(year)) {
			return 2;
			break;
		}
		return 3;
		break;
	case 3:
		return 3;
		break;
	case 4:
		return 6;
		break;
	case 5:
		return 1;
		break;
	case 6:
		return 4;
		break;
	case 7:
		return 6;
		break;
	case 8:
		return 2;
		break;
	case 9:
		return 5;
		break;
	case 10:
		return 0;
		break;
	case 11:
		return 3;
		break;
	case 12:
		return 5;
		break;
	}
}
int dayOfWeek(int month, int day, int year) {
	if (year < 1582 || month < 1 || month > 12) {
		return -1;
	}
	if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31) {
		return -1;
	}
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
		return -1;
	}
	if ((isLeapYear(year) && month == 2 && day > 29) || (!isLeapYear(year) && month == 2 && day > 28)) {
		return -1;
	}
	int sum = day + getMonthValue(month, year) + getYearValue(year) + getCenturyValue(year);
	return sum % 7;
}
string dayOfWeek(int day) {
	if (day < 0 || day > 6) {
		return "Error";
	}
	switch (day) {
	case 0:
		return "Sunday";
		break;
	case 1:
		return "Monday";
		break;
	case 2:
		return "Tuesday";
		break;
	case 3:
		return "Wednesday";
		break;
	case 4:
		return "Thursday";
		break;
	case 5:
		return "Friday";
		break;
	case 6:
		return "Saturday";
		break;
	}
}
int main()
{
	int choice;
	int day, month, year;
	do
	{
		testMenu();
		cout << "Please choose from menu: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Please enter a year: ";
			cin >> year;
			switch (isLeapYear(year)) {
			case 1:
				cout << "Year " << year << " is a leap year" << endl;
				break;
			case 0:
				cout << "Year " << year << " is NOT a leap year" << endl;
				break;
			default:
				cout << "Invalid year, consult a Julian Calendar" << endl;
				break;
			}
			break;
		case 2:
			cout << "Please enter a year: ";
			cin >> year;
			if (getCenturyValue(year) == 0) {
				cout << "Invalid Year, consult Julian Calendar" << endl;
				break;
			}
			cout << "The century value is: " << getCenturyValue(year) << endl;
			break;
		case 3:
			cout << "Please enter a year: ";
			cin >> year;
			if (getYearValue(year) == 0) {
				cout << "Invalid year, consult Julian Calendar" << endl;
				break;
			}
			cout << "The year value is: " << getYearValue(year) << endl;
			break;
		case 4:
			cout << "Please enter a year and month: ";
			cin >> year >> month;
			if (getMonthValue(month, year) == 7) {
				cout << "Invalid month or year";
				break;
			}
			cout << "The month value is: " << getMonthValue(month, year) <<
				endl;
			break;
		case 5:
			cout << "Please enter a year, a month, and a day : ";
			cin >> year >> month >> day;
			if (dayOfWeek(month, day, year) == -1) {
				cout << "Invalid month, day or year";
			}
			cout << "The day of the week is: " << dayOfWeek(month, day, year)
				<< endl;
			break;
		case 6:
			cout << "Please enter a day of week (0 for Sunday, 1 for Monday, etc): ";
			cin >> day;
			if (dayOfWeek(day) == "Error") {
				cout << "Invalid day of the week number";
			}
			cout << "The name of the day of the week is: " << dayOfWeek(day)
				<< endl;
			break;
		case 7:
			cout << "Did you tested all functions yet ? if not, please rerun the program\n";
			break;
		default:
			cout << "wrong option. Please choose from menu\n";
			break;
		}
		system("pause");
	} while (choice != 7);
}