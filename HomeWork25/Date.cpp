#include "Date.h"

int Date::daysInMonth() const
{
	switch (month)
	{
	case 2:
		return 28;
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
	default:
		return 31;
	}
}

Date& Date::operator++() {
	++day;
	if (day > daysInMonth()) {
		day = 1;
		++month;
		if (month > 12) {
			month = 1;
			++year;
		}
	}
	return *this;
}

Date Date::operator++(int) {
	Date old = *this;
	++(*this);
	return old;
}

Date &Date::operator--() {
	if (day > 1)
		--day;
	else 
	{
		if (month > 1)
			--month;
		else 
		{
			month = 12;
			--year;
		}
		day = daysInMonth();
	}
	return *this;
}

Date Date::operator--(int) {
	Date old = *this;
	--(*this);
	return old;
}

Date& Date::operator+=(const int days) {
	if (days <= 0)
		return *this;
	for (int i = 0; i < days; ++i)
		++(*this);
	return *this;
}

Date Date::operator+(const int days) {
	Date result = *this;
	result += days;
	return result;
}

Date& Date::operator-=(const int days) {
	if (days <= 0)
		return *this;
	for (int i = 0; i < days; ++i)
		--(*this);
	return *this;
}

Date Date::operator-(const int days) {
	Date result = *this;
	result -= days;
	return result;
}

int Date::operator-(const Date& other) const {
	if (*this < other) {
		return -(other - *this);
	}
	else {
		Date temp = other;
		int count = 0;
		while (temp < *this) {
			++temp;
			++count;
		}
		return count;
	}
}
