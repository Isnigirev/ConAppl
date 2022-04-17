#include <iostream>
#include <vector>

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

//////////////////////////////////////////////////////////////
//5
class Card
{
    std::string stSuit;
    enum Suit
    {
        Worms,
        Diamonds,
        Clubs,
        Peaks
    };

    std::string stMapValue;
    enum MapValue
    {
        Two,
        Three,
        Four,
        Five,
        Six,
        Seven,
        Eight,
        Hine,
        Ten,
        J,
        O,
        K,
        A,
    };

    int Value;

    bool bMapMosition = 1; //(1 - face up 0 - shirt up)

    void GetSuit()
    {
        int iSuit = rand() % 3;
        switch (iSuit)
        {
        case Worms:
            stSuit = "Worms";
            break;
        case Diamonds:
            stSuit = "Diamonds";
            break;
        case Clubs:
            stSuit = "Clubs";
            break;
        case Peaks:
            stSuit = "Peaks";
            break;
        default:
            break;
        }
    }

    void GetMapValue()
    {
        int iMapValue = rand() % 12;

        switch (iMapValue)
        {
        case Two:
            stMapValue = "Two";
            Value = 2;
            break;
        case Three:
            stMapValue = "Three";
            Value = 3;
            break;
        case Four:
            stMapValue = "Four";
            Value = 4;
            break;
        case Five:
            stMapValue = "Five";
            Value = 5;
            break;
        case Six:
            stMapValue = "Six";
            Value = 6;
            break;
        case Seven:
            stMapValue = "Seven";
            Value = 7;
            break;
        case Eight:
            stMapValue = "Eight";
            Value = 8;
            break;
        case Hine:
            stMapValue = "Hine";
            Value = 9;
            break;
        case Ten:
            stMapValue = "Ten";
            Value = 10;
            break;
        case J:
            stMapValue = "J";
            Value = 10;
            break;
        case O:
            stMapValue = "O";
            Value = 10;
            break;
        case K:
            stMapValue = "K";
            Value = 10;
            break;
        case A:
            stMapValue = "A";
            Value = 1;
            break;
        default:
            break;
        }
    }

public:
    Card()
    {
        GetSuit();
        GetMapValue();
    }

    bool Flip()
    {
        if (bMapMosition == 1)
        {
            std::cout << "Карта перевернута рубашкой вверх\n";
            return bMapMosition = 0;
        }
        else
        {
            std::cout << "Карта перевернута лицом вверх\n";
            return bMapMosition = 1;
        }
    }

    friend bool Flip(Card& c)
    {
        if (c.Flip() == 1)
        {
            std::cout << "XX\n";
            std::cout << c.stSuit;
        }
        else
        {
            std::cout << c.stMapValue;
            std::cout << c.stSuit;
        }
    }

    void GetInfoCard() const
    {
        std::cout << "Значение: " << stMapValue;
        std::cout << "\tМасть: " << stSuit;
    }

    int GetValue() const
    {
        return Value;
    }
};

class Hand
{
    std::vector <Card*> vCard;

public:
    void Add()
    {
        vCard.push_back(new Card());
    }

    void Clear()
    {
        vCard.clear();
    }

    int GetValue() const
    {
        int iCounter = 0;

        for (int i = 0; i < vCard.size(); i++)
        {
            iCounter += vCard[i]->GetValue();
        }

        return iCounter;
    }

    void GetInfoCardBoard()
    {
        std::cout << "Всего карт:" << vCard.size();

        for (int i = 0; i < vCard.size(); i++)
        {
            std::cout << "\n";
            vCard[i]->GetInfoCard();
        }
    }
};
//5
class GenericPlayer : public Hand
{
    std::string stName;

public:
    GenericPlayer(std::string stName)
    {
        this->stName = stName;
    }

    virtual bool IsHitting() {}

    bool IsBoosted()
    {
        Hand h;
        return (h.GetValue() > 21) ? 1 : 0;
    }

    void Bust()
    {
        std::cout << stName << "\tперебор!\n";
    }

    std::string GetName() const
    {
        return this->stName;
    }

    friend bool Flip(GenericPlayer& g, Hand& h)
    {
        std::cout << g.stName << "\n";

        std::cout << "Сумма очков: " << h.GetValue();
    }
};

//3
class Player : public GenericPlayer
{
    GenericPlayer& p;

public:
    virtual bool isHitting() const
    {
        char a;
        std::cout << "Взять карту? (y/n) \n";
        std::cin >> a;

        return (a == 'y' || a == 'Y') ? 1 : 0;
    }

    void Win() const
    {
        std::cout << p.GetName() << " Выйграл!\n";
    }

    void Lose() const
    {
        std::cout << p.GetName() << " Проиграл!\n";
    }

    void Push() const
    {
        std::cout << p.GetName() << " Сыграл в ничью!\n";
    }
};

//4
class House : public GenericPlayer
{
    Hand& h;
public:
    virtual bool isHitting() const
    {
        if (h.GetValue() < 16)
        {
            h.Add();
            return 1;
        }
        else
        {
            return 0;
        }
    }

    bool FlipFirstCard() const
    {
        return 1;
    }
};

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