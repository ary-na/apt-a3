#include "Date.h"
#include <exception>

Date::Date() :
        year(1970), month(1), day(1) {
}

Date::Date(unsigned int year, unsigned int month, unsigned int day) :
        year(year), month(month), day(day) {
}

Date::Date(const Date &other) {
    year = other.year;
    month = other.month;
    day = other.day;
}

Date::Date(Date &&other) {
    year = other.year;
    month = other.month;
    day = other.day;
    other.year = 0;
    other.month = 0;
    other.day = 0;
}

Date::~Date() {

}

unsigned int Date::getDay() {
    return day;
}

unsigned int Date::getMonth() {
    return month;
}

unsigned int Date::getYear() {
    return year;
}


unsigned long Date::getDayNumber() const {
    unsigned long m = ((unsigned long) month + 9) % 12;
    unsigned long y = (unsigned long) year - ((unsigned long) month / 10);
    return 365 * y + y / 4 - y / 100 + y / 400
           + (m * 306 + 5) / 10 + ((unsigned long) day - 1);
}

void Date::setDate(unsigned long dayNumber) {
    unsigned long y = (10000 * ((unsigned long) dayNumber) + 14780) / 3652425;
    unsigned long ddd =
            (unsigned long) dayNumber - (365 * y + y / 4 - y / 100 + y / 400);
    if (ddd < 0) {
        y = y - 1;
        ddd = (unsigned long) dayNumber - (365 * y + y / 4 - y / 100 + y / 400);
    }
    unsigned long mi = (100 * ddd + 52) / 3060;
    unsigned long mm = (mi + 2) % 12 + 1;
    y = y + (mi + 2) / 12;
    unsigned long dd = ddd - (mi * 306 + 5) / 10 + 1;

    this->day = (unsigned int) dd;
    this->month = (unsigned int) mm;
    this->year = (unsigned int) y;
}

void Date::setDate(unsigned int year, unsigned int month, unsigned int day) {
    this->day = day;
    this->month = month;
    this->year = year;
}


Date::Date(unsigned long dayNumber) {
    this->setDate(dayNumber);
}

/*                                           */
/* YOU MAY ADD YOUR MODIFICATIONS HERE       */
/*                                           */

unsigned int &Date::operator[](const std::string &type) {
    if (type == "day") {
        return this->day;
    } else if (type == "month") {
        return this->month;
    } else if (type == "year") {
        return this->year;
    } else {
        throw std::invalid_argument("Invalid argument!");
    }
}

Date &Date::operator++(int number) {
    unsigned int newDayNumber = this->getDayNumber() + 1;
    this->setDate(newDayNumber);
    return *this;
}

Date &Date::operator--(int number) {
    unsigned int newDayNumber = this->getDayNumber() - 1;
    this->setDate(newDayNumber);
    return *this;
}

Date &Date::operator=(const Date &other) {
    this->day = other.day;
    this->month = other.month;
    this->year = other.year;
    return *this;
}

bool Date::operator!=(const Date &other) const {
    if (this->day == other.day && this->month == other.month &&
        this->year == other.year) {
        return false;
    } else {
        return true;
    }
}

bool Date::operator>(const Date &other) const {
    if (this->getDayNumber() > other.getDayNumber()) {
        return true;
    } else {
        return false;
    }
}

Date Date::operator+(const int &other) {
    int newDateNumber = this->getDayNumber();
    Date temp;
    temp.setDate(newDateNumber + other);
    return temp;
}

int Date::operator-(const Date &other) {
    unsigned int newDateNumber = this->getDayNumber() - other.getDayNumber();
    return newDateNumber;
}

void Date::operator+=(const int &other) {
    unsigned int newDateNumber = this->getDayNumber();
    newDateNumber += other;
    this->setDate(newDateNumber);
}