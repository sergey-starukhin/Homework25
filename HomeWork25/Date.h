#include <iostream>
#pragma once

using namespace std;

class Date
{
private:
	int day;
	int month;
	int year;

	int daysInMonth() const;

public:
	Date(const int day_, const int month_, const int year_) : day(1), month(1), year(1)
	{
		if (month_ >= 1 && month_ <= 12)
			month = month_;
		if (year_ > 1)
			year = year_;
		if (day_ > 1 && day_ <= daysInMonth())
			day = day_;
	}

	Date& operator++();
	Date operator++(int);
	Date& operator--();
	Date operator--(int);
	Date& operator+=(const int days);
	Date operator+(const int days);
	Date& operator-=(const int days);
	Date operator-(const int days);
	int operator-(const Date& other) const;
	bool operator==(const Date& other) const;
	bool operator<(const Date& other) const;
	bool operator!=(const Date& other) const;
	bool operator>(const Date& other) const;
	bool operator<=(const Date& other) const;
	bool operator>=(const Date& other) const;
	void print() const;

};

inline bool Date::operator==(const Date& other) const {
	return day == other.day && month == other.month && year == other.year;
}

inline bool Date::operator<(const Date& other) const {
	if (year != other.year)
		return year < other.year;
	if (month != other.month)
		return month < other.month;
	return day < other.day;
}

inline bool Date::operator!=(const Date& other) const {
	return !(*this == other);
}

inline bool Date::operator>(const Date& other) const {
	return other < *this;
}

inline bool Date::operator<=(const Date& other) const {
	return !(*this > other);
}

inline bool Date::operator>=(const Date& other) const {
	return !(*this < other);
}

inline void Date::print() const {
	cout << (day < 10 ? "0" : "") << day << "." << (month < 10 ? "0" : "") << month << "." << year << endl;
}

