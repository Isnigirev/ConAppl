#include <iostream>
#include <vector>
#include <algorithm>

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

class Card
{
    std::string stSuit;
    enum Suit
    {
        Worms = 1,
        Diamonds,
        Clubs,
        Peaks
    };

    std::string stMapValue;
    enum MapValue
    {
        Two = 1,
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

    bool bMapMosition = 0; //(1 - face up 0 - shirt up)

    void GetSuit(int iSuit)
    {
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

    void GetMapValue(int iMapValue)
    {
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
    Card(int iSuit, int iMapValue)
    {
        GetSuit(iSuit);
        GetMapValue(iMapValue);
    }

    friend std::ostream& operator<<(std::ostream& os, const Card& c)
    {
        if (c.bMapMosition == 1)
        {
            std::cout << "XX--";
            std::cout << "XX";
        }
        else
        {
            std::cout << c.stMapValue << "--";
            std::cout << c.stSuit;
        }
        return os;
    }

    void Flip()
    {
        (bMapMosition == 1) ? bMapMosition = 0 : bMapMosition = 1;
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
protected:
    std::vector <Card*> vCard;

public:
    void Add(Card *card) 
    { 
        vCard.push_back(new Card(*card)); 
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
            if (vCard[i]->GetValue() == 'A' && iCounter < 21)
            {
                iCounter += 11;
            }
            else
            {
                iCounter += vCard[i]->GetValue();
            }
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

class GenericPlayer : public Hand
{
    std::string stName;

    friend std::ostream& operator<<(std::ostream& os, const GenericPlayer& aGenericPlayer)
    {
        os << aGenericPlayer.stName << ":\t";

        std::vector<Card*>::const_iterator vCard;

        if (!aGenericPlayer.vCard.empty())
        {
            for (vCard = aGenericPlayer.vCard.begin(); vCard != aGenericPlayer.vCard.end(); ++vCard)
            {
                os << *(*vCard) << "\t";
            }
            if (aGenericPlayer.GetValue() != 0)
            {
                std::cout << "Сумма очков (" << aGenericPlayer.GetValue() << ")";
            }
        }
        else
        {
            os << "<empty>";
        }

        return os;
    }

public:
    GenericPlayer(const std::string& stName) : stName(stName) { }

    virtual bool IsHitting()
    {
        char a;
        std::cout << "Взять карту? (y/n) \n";
        std::cin >> a;

        return (a == 'y' || a == 'Y') ? 1 : 0;
    }

    bool IsBoosted()
    {
        return (GetValue() > 21) ? 1 : 0; //1 Перебор  
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
        h.GetInfoCardBoard();
        std::cout << "\nСумма очков: " << h.GetValue();
    }
};

class Player : public GenericPlayer
{

public:
    Player(const std::string& stName) : GenericPlayer(stName) { }

    bool IsHitting() override
    { 
        char a;
        std::cout << "Взять карту? (y/n) \n";
        std::cin >> a;

        return (a == 'y' || a == 'Y') ? 1 : 0;
    }

    void Win() const
    {
        std::cout << GetName() << " Выйграл!\n";
    }

    void Lose() const
    {
        std::cout << GetName() << " Проиграл!\n";
    }

    void Push() const
    {
        std::cout << GetName() << " Сыграл в ничью!\n";
    }
};

class House : public GenericPlayer
{
public:
    House() : GenericPlayer ("House") { }

    bool IsHitting() override
    {
        return (GetValue() < 16) ? 1 : 0;
    }

    void FlipFirstCard() const
    {
        if (!(vCard.empty()))
        {
            vCard.front()->Flip();
        }
        else
        {
            std::cout << "Карт больше нет!\n";
        }
    }
};

class Deck : public Hand
{    
    void Populate()
    {
        int iSuit = 1;
        
        Clear();

        for (int iMapValue = 1; iMapValue < 14; iMapValue++)
        {
            Add(new Card(iSuit, iMapValue));
            if (iSuit == 4 && iMapValue == 13)
            {
                break;
            }
            else if (iMapValue == 13)
            {
                iSuit++;
                iMapValue = 1;
            }
        }
    }

public:
    Deck() { Populate();}

    void Shuffle()
    {
        std::random_shuffle(vCard.begin(), vCard.end());
    }

    void Deal(Hand& aHand)
    {
       if (!vCard.empty())
       {
            aHand.Add(vCard.back());
            vCard.pop_back();
       }
       else
       {
            std::cout << "Карт больше нет!";
       }
    }

    void AddltionalCards(GenericPlayer& aGenerlcPlayer)
    {
        while (!(aGenerlcPlayer.IsBoosted()) && aGenerlcPlayer.IsHitting())
        {
            Deal(aGenerlcPlayer);
            
            if (aGenerlcPlayer.IsBoosted())
            {
                aGenerlcPlayer.Bust();
            }   
        }
    }
};

class Game
{
    Deck deck;
    House house;
    std::vector <Player> vPlayerName;

public:
    Game(const std::vector <std::string> vPlName)
    {
        std::vector<std::string>::const_iterator pName;

        for (pName = vPlName.begin(); pName != vPlName.end(); ++pName)
        {
            vPlayerName.push_back(Player(*pName));
        }

        deck.Shuffle();
    }

    void play()
    {
        std::vector<Player>::iterator vPlayer;

        for (int i = 0; i < 2; ++i)
        {
            for (vPlayer = vPlayerName.begin(); vPlayer != vPlayerName.end(); ++vPlayer)
            {
                deck.Deal(*vPlayer);
            }  

            deck.Deal(house);
        }

        house.FlipFirstCard();

        for (vPlayer = vPlayerName.begin(); vPlayer != vPlayerName.end(); ++vPlayer)
        {
            std::cout << *vPlayer << std::endl;
        }

        std::cout << house << std::endl;

        for (vPlayer = vPlayerName.begin(); vPlayer != vPlayerName.end(); ++vPlayer)
        {
            deck.AddltionalCards(*vPlayer);
        }

        house.FlipFirstCard();
        std::cout << house << std::endl;
        
        deck.AddltionalCards(house);

        if (house.IsBoosted())
        {
            for (vPlayer = vPlayerName.begin(); vPlayer != vPlayerName.end(); ++vPlayer)
            {
                if (!(vPlayer->IsBoosted()))
                {
                    vPlayer->Win();
                }
            }
        }
        else
        {
            for (vPlayer = vPlayerName.begin(); vPlayer != vPlayerName.end(); ++vPlayer)
            {
                if (!(vPlayer->IsBoosted()))
                {
                    if (vPlayer->GetValue() > house.GetValue())
                    {
                        vPlayer->Win();
                    }
                    else if (vPlayer->GetValue() < house.GetValue())
                    {
                        vPlayer->Lose();
                    }
                    else
                    {
                        vPlayer->Push();
                    }
                }
            }
        }

        for (vPlayer = vPlayerName.begin(); vPlayer != vPlayerName.end(); ++vPlayer)
        {
            vPlayer->Clear();
        }

        house.Clear();
    }
};


int main()
{
    setlocale(LC_ALL, "Ru");

    std::cout << "\tWelcome to Blackjack!\n";

    int numPlayers = 1;
    /*while (numPlayers < 1 || numPlayers > 7)
    {
        std::cout << "How many players? (1 - 7): ";
        std::cin >> numPlayers;
    }*/

    std::vector<std::string> names;
    std::string name;

    //for (int i = 0; i < numPlayers; ++i)
    //{
    //    std::cout << "Enter player name: ";
    //    std::cin >> name;
    //    names.push_back(name);
    //}
    names.push_back("11");
    std::cout << "\n";

    Game aGame(names);
    char again = 'y';
    while (again != 'n' || again != 'N')
    {
        aGame.play();
        std::cout << "\nDo you want to play again? (Y/N): ";
        std::cin >> again;
    }

    //1

 //   Ptr<Date> today (new Date(17, 04, 2022));

 //   std::cout << "Day: " << today->getDay() << std::endl;
 //   std::cout << "Month: " << today->getMonth() << std::endl;
 //   std::cout << "Year: " << today->getYear() << std::endl;
 //   std::cout << "today: " << *today << std::endl;

	//Ptr<Date> date;

 //   std::cout << "today is " << (today.isNull() ? "null\n" : "not null\n");
 //   std::cout << "date is " << (date.isNull() ? "null\n" : "not null\n");

 //   date = today;

 //   std::cout << "today is " << (today.isNull() ? "null\n" : "not null\n");
 //   std::cout << "date is " << (date.isNull() ? "null\n" : "not null\n");

 //   std::cout << "date: " << *date << std::endl;

 //   //2

	//Ptr<Date> date1(new Date(9, 01, 2022));
	//Ptr<Date> date2(new Date(10, 02, 2022));
	//Ptr<Date> date3(new Date(11, 03, 2022));

	//std::cout << *ComparesDates(date1, date2) << std::endl;

	//SwapDates(date2, date3);

	//std::cout << *ComparesDates(date1, date2) << std::endl;

	//3




    return 0;
}