#define _CRT_SECURE_NO_WARNINGS

#include"Data.h"

//�˺�������Ϊ��������������Ƶ�����ô˺��������Ӻ���ջ֡�Ŀ���
inline int Data::GetMonthDay(int year, int month)
{
	//����洢ÿ�µ�����
	static int monthDayArray[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	//��ȡ����µ�����
	int day = monthDayArray[month];
	
	//�ж��Ƿ�Ϊ�����2��
	if (month==2&&((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
	{
		day = 29;
	}
	return day;
}


//���ඨ��ʱ�����ǽ��������������Ϊȫȱʡ�ĺ��������Ƕ������������ͬʱ��
//��ʼֵ�������ں�������ʱ����ȫȱʡ������ʱ�Ͱ�ȫȱʡȥ��
Data::Data(int year,int month,int day)
{
	//������ڵĺϷ���
	if (year >= 0 && month > 0 && month < 13 && day>0 && day <= GetMonthDay(year, month))
	{
		_year = year;
		_month = month;
		_day = day;
	}
	else
	{
		cout << "illegal date" << ":";
		cout << year << "��" << month << "��" << day << "��" << endl;
	}
}


//+= �ı���ԭ����ֵ
//ʹ��+= ,��ô������������ý���ʱ�� +=֮��ı�����������࣬�������٣�����ʹ�ô����÷���
Data& Data::operator+=(int day)
{
	//���day<0���൱��������ǰ�ߣ���ô�͸���-=����
	if (day < 0)
	{
		*this -= day;
	}
	else
	{
		//�Ƚ���������day
		_day += day;
		
		//�������Ϸ�����������λ�������ںϷ�
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


// + ���ı�ԭ����ֵ    ret�ֲ��������˺������٣����������ô�ֵ����
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
		//����_day�м�ȥ��Ҫ��ǰ������
		_day -= day;

		//����Ϊ���������ڷǷ�����������
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


//ǰ��++
Data& Data::operator++()
{
	*this += 1;   //��+=1
	return *this;//���ؼӺ��ֵ
}

//����++
Data Data::operator++(int)
{
	Data ret(*this);
	*this += 1;
	return ret; //����++֮ǰ������
}


//ǰ��--
Data& Data::operator--()
{
	*this -= 1;   //��-=1
	return *this;//����-���ֵ
}


//����--
Data Data::operator--(int)
{
	Data ret(*this);
	*this -= 1;
	return ret; //����--֮ǰ������
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

























































































