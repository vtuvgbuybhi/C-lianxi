#define _CRT_SECURE_NO_WARNINGS

#include"Data.h"

//此函数定义为内联函数，避免频繁调用此函数，增加函数栈帧的开销
inline int Data::GetMonthDay(int year, int month)
{
	//数组存储每月的天数
	static int monthDayArray[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	//获取这个月的天数
	int day = monthDayArray[month];
	
	//判断是否为闰年的2月
	if (month==2&&((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
	{
		day = 29;
	}
	return day;
}


//在类定义时，我们将将这个函数定义为全缺省的函数，但是定义和声明不能同时给
//初始值，我们在函数声明时给了全缺省，定义时就把全缺省去掉
Data::Data(int year,int month,int day)
{
	//检查日期的合法性
	if (year >= 0 && month > 0 && month < 13 && day>0 && day <= GetMonthDay(year, month))
	{
		_year = year;
		_month = month;
		_day = day;
	}
	else
	{
		cout << "illegal date" << ":";
		cout << year << "年" << month << "月" << day << "日" << endl;
	}
}


//+= 改变了原来的值
//使用+= ,那么当这个函数调用结束时， +=之后的变量属于这个类，不会销毁，所以使用传引用返回
Data& Data::operator+=(int day)
{
	//如果day<0，相当于日期往前走，那么就复用-=函数
	if (day < 0)
	{
		*this -= day;
	}
	else
	{
		//先将天数加上day
		_day += day;
		
		//天数不合法，让天数进位，让日期合法
		while (_day > GetMonthDay(_year, _month))
		{
			_day -= GetMonthDay(_year, _month);
			_month++;
			if (_month == 13)
			{
				_month = 1;
				_year++;
			}
		}
	}
	return *this;
}


// + 不改变原来的值    ret局部变量出了函数销毁，所以我们用传值返回
Data Data::operator+(int day)
{
	Data ret(*this);
	ret += day;
	return ret;
}

Data& Data::operator-=(int day)
{
	if (day < 0)
	{
		*this += day;
	}
	else
	{
		//先在_day中减去需要向前的天数
		_day -= day;

		//天数为负数，日期非法，继续调整
		while (_day < 0)
		{
			_month--;
			if (_month == 0)
			{
				_month = 12;
				_year--;
			}
			_day += GetMonthDay(_year, _month);
		}
	}
	return *this;
}


Data Data::operator-(int day)
{
	Data ret(*this);
	ret -= day;
	return ret;
}


//前置++
Data& Data::operator++()
{
	*this += 1;   //先+=1
	return *this;//返回加后的值
}

//后置++
Data Data::operator++(int)
{
	Data ret(*this);
	*this += 1;
	return ret; //返回++之前的数据
}


//前置--
Data& Data::operator--()
{
	*this -= 1;   //先-=1
	return *this;//返回-后的值
}


//后置--
Data Data::operator--(int)
{
	Data ret(*this);
	*this -= 1;
	return ret; //返回--之前的数据
}


bool Data::operator>(const Data&d)
{
	if (_year > d._year)
	{
		return true;
	}
	else if (_year == d._year && _month > d._month)
	{
		return true;
	}
	else if((_year == d._year) && (_month == d._month)&&(_day>d._day))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Data::operator==(const Data& d)
{
	return _year == d._year && _month == d._month && _day == d._day;
}

























































































