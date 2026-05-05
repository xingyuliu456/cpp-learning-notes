#pragma once
#include <iostream>
using namespace std;

#include <assert.h>

class Date
{
    // 友元函数声明
    friend ostream& operator<<(ostream& out, const Date& d);
    friend istream& operator>>(istream& in, Date& d);

public:
    Date(int year = 1900, int month = 1, int day = 1);
    void Print() const;
    int GetMonthDay(int year, int month)
    {
        assert(month > 0 && month < 13);

        static int arr[13] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        // 处理闰年二月的特殊情况
        if(month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
        {
            return 29;
        }

        return arr[month];
    }

    bool CheckDate();

    bool operator<(const Date& d) const;
    bool operator<=(const Date& d) const;
    bool operator>(const Date& d) const;
    bool operator>=(const Date& d) const;
    bool operator==(const Date& d) const;
    bool operator!=(const Date& d) const;

    // d1 += 天数
    Date& operator+=(int day);
    Date operator+(int day) const;

    // d1 -= 天数
    Date& operator-=(int day);
    Date operator-(int day) const;

    // d1 - d2
    int operator-(const Date& d) const;

    // 前置++
    Date& operator++();
    // 后置++
    Date operator++(int);
    
    // 前置--
    Date& operator--();
    // 后置--
    Date operator--(int);

private:
    int _year;
    int _month;
    int _day;
};