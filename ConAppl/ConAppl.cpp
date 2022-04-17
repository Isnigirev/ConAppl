#include <iostream>

/*1. 
* 
Для него вызовите по отдельности методы доступа к полям класса Date, 
а также выведите на экран данные всего объекта с помощью перегруженного оператора 
вывода. 

Затем переместите ресурс, которым владеет указатель today в указатель date. 

Проверьте, являются ли нулевыми указатели today и date 
и выведите соответствующую информацию об этом в консоль.*/

//1
class Date
{
	int iDay;
	int iMonth;
	int iYear;

public:
	Date(int day, int month, int year) : iDay(day), iMonth(month), iYear(year) {}

	int getDay() const
	{
		return iDay;
	}

	int getMonth() const
	{
		return iMonth;
	}

	int getYear() const
	{
		return iYear;
	}

	friend std::ostream& operator<<(std::ostream& os, const Date& d)
	{
		os << d.iDay << '.' << d.iMonth << '.' << d.iYear;

		return os;
	}
};

template <class T>
class Ptr
{
	T* tPtr;
public:
	Ptr(T* ptr = nullptr) : tPtr(ptr) {}
	~Ptr() { delete tPtr; }

	Ptr(Ptr& p)
	{
		tPtr = p.tPtr;
		p.tPtr = nullptr;
	}

	Ptr& operator=(Ptr& p)
	{
		if (&p == this)
			return *this;

		delete tPtr;
		tPtr = p.tPtr;
		p.tPtr = nullptr;

		return *this;
	}

	T& operator*() const 
	{ 
		return *tPtr;
	}

	T* operator->() const 
	{ 
		return tPtr;
	}

	bool isNull() const 
	{ 
		return tPtr == nullptr;
	}
};

//2

const Ptr<Date>& ComparesDates(const Ptr<Date>& a, const Ptr<Date>& b)
{
	if (a->getYear() > b->getYear())
	{
		return a;
	}
	else if (a->getYear() < b->getYear())
	{
		return b;
	}
	else
	{
		if (a->getMonth() > b->getMonth())
		{ 
			return a;
		}
			
		else if (a->getMonth() < b->getMonth())
		{
			return b;
		}
		else
		{
			if (a->getDay() > b->getDay())
			{ 
				return a;
			}
			else
			{
				return b;
			}
		}
	}
}

void SwapDates(Ptr<Date>& a, Ptr<Date>& b)
{
	Ptr<Date> temp(a);

	a = b;

	b = temp;
}



int main()
{
    setlocale(LC_ALL, "Ru");

    //1

    Ptr<Date> today (new Date(17, 04, 2022));

    std::cout << "Day: " << today->getDay() << std::endl;
    std::cout << "Month: " << today->getMonth() << std::endl;
    std::cout << "Year: " << today->getYear() << std::endl;
    std::cout << "today: " << *today << std::endl;

	Ptr<Date> date;

    std::cout << "today is " << (today.isNull() ? "null\n" : "not null\n");
    std::cout << "date is " << (date.isNull() ? "null\n" : "not null\n");

    date = today;

    std::cout << "today is " << (today.isNull() ? "null\n" : "not null\n");
    std::cout << "date is " << (date.isNull() ? "null\n" : "not null\n");

    std::cout << "date: " << *date << std::endl;

    //2

	Ptr<Date> date1(new Date(9, 01, 2022));
	Ptr<Date> date2(new Date(10, 02, 2022));
	Ptr<Date> date3(new Date(11, 03, 2022));

	std::cout << *ComparesDates(date1, date2) << std::endl;

	SwapDates(date2, date3);

	std::cout << *ComparesDates(date1, date2) << std::endl;

	//3




    return 0;
}