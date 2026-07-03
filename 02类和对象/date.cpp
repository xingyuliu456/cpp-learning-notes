// 日期类实现

#include "date.h"

bool Date::CheckDate()
{
    if(_month < 1 || _month > 12 || _day < 1 || _day > GetMonthDay(_year, _month))
    {
        return false;
    }

    return true;
}

// 缺省值只能在声明中出现
Date::Date(int year, int month, int day)
{
    _year = year;
    _month = month;
    _day = day;

    if(!this->CheckDate())
    {
        cout << "日期非法" << endl;
    }
}

void Date::Print() const
{
    cout << _year << "-" << _month << "-" << _day;
}

Date& Date::operator+=(int day)
{
    if(day < 0) return *this -= (-day);

    _day += day;
    while(_day > GetMonthDay(_year, _month))
    {
        _day -= GetMonthDay(_year, _month);
        _month++;

        if(_month == 13)
        {
            _year++;
            _month = 1;
        }
    }

    return *this;
}

Date Date::operator+(int day) const
{
    Date tmp = *this;
    tmp += day;
    return tmp;
}

Date& Date::operator-=(int day)
{
    if(day < 0) return *this += (-day);
    
    _day -= day;
    while(_day <= 0)
    {
        _month--;
        if(_month == 0)
        {
            _year--;
            _month = 12;
        }

        _day += GetMonthDay(_year, _month);
    }

    return *this;
}

Date Date::operator-(int day) const
{
    Date tmp = *this;
    tmp -= day;
    return tmp;
}

int Date::operator-(const Date& d) const
{
    int flag = 1;

    Date max = *this;
    Date min = d;

    if(max < min)
    {
        max = d;
        min = *this;
        flag = -1;
    }

    int count = 0;
    while(min != max)
    {
        ++min;
        ++count;
    }

    return count * flag;
}



bool Date::operator<(const Date& d) const
{
    if(_year != d._year)
    {
        return _year < d._year;
    }
    if(_month != d._month)
    {
        return _month < d._month;
    }
    return _day < d._day;
}

bool Date::operator<=(const Date& d) const
{
    return *this < d || *this == d;
}

bool Date::operator>(const Date& d) const
{
    return !(*this <= d);
}

bool Date::operator>=(const Date& d) const
{
    return !(*this < d);
}

bool Date::operator==(const Date& d) const
{
    return _day == d._day && _month == d._month && _year == d._year;
}

bool Date::operator!=(const Date& d) const
{
    return !(*this == d);
}

// 前置++
Date& Date::operator++()
{
    *this += 1;
    return *this;
}

// 后置++
Date Date::operator++(int)
{
    Date tmp = *this;
    *this += 1;
    return tmp;
}

// 前置--
Date& Date::operator--()
{
    *this -= 1;
    return *this;
}

// 后置--
Date Date::operator--(int)
{
    Date tmp = *this;
    *this -= 1;
    return tmp;
}

// 友元函数声明
ostream& operator<<(ostream& out, const Date& d)
{
    out << d._year << "-" << d._month << "-" << d._day;
    return out;
}

istream& operator>>(istream& in, Date& d)
{
    while(1)
    {
        cout << "请依次输入年月日:>";
        in >> d._year >> d._month >> d._day;
        if(!d.CheckDate())
        {
            cout << "日期非法" << endl;
        }
        else break;
    }

    return in;
}