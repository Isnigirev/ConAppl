#include <iostream>

using namespace std;

//3 Класса
//Базовый класс Black Jeck
//Производные классы Gamer и Croupier

class BlackJeck
{
    char cSteck[56] {};
    int iCursor = 0;
    int iSummCash = 0;
    int iSummPoint = 0;

public:
    char GetCart(char cCardDeck[])
    {
        for (int i = 0; i < 56; i++)
        {
            int b = rand () % 55;

            if (cCardDeck[b] != 0 && cCardDeck[b] != '0')
            {
                char c;

                cSteck[this->iCursor++] = cCardDeck[b];

                c = cCardDeck[b];
                
                cCardDeck[b] = 0;

                return c;
            }
        } 
    }

    int SummPoint()
    {
        
            if (cSteck[this->iCursor] == '1')
            {
                this->iSummPoint += 1;
            }
            else if (cSteck[i] == '2')
            {
                this->iSummPoint += 2;
            }
            else if (cSteck[i] == '3')
            {
                this->iSummPoint += 3;
            }
            else if (cSteck[i] == '4')
            {
                this->iSummPoint += 4;
            }
            else if (cSteck[i] == '5')
            {
                this->iSummPoint += 5;
            }
            else if (cSteck[i] == '6')
            {
                this->iSummPoint += 6;
            }
            else if (cSteck[i] == '7')
            {
                this->iSummPoint += 7;
            }
            else if (cSteck[i] == '8')
            {
                this->iSummPoint += 8;
            }
            else if (cSteck[i] == '9')
            {
                this->iSummPoint += 9;
            }
            else if (cSteck[i] == '10')
            {
                this->iSummPoint += 10;
            }
            else if (cSteck[i] == 'L' || cSteck[i] == 'V'|| cSteck[i] == 'K')
            {
                this->iSummPoint += 10;
            }
            else if (cSteck[i] == 'A')
            {
                this->iSummPoint += 11;
            }
        

        return this->iSummPoint;
    }

    int GetSummPoint()
    {
        return this->iSummPoint;
    }

    int SummCash(int &iCash)
    {
        this->iSummCash += iCash;

        return iCash = 0;
    }

    int GetCash (int iCash)
    {
        return iCash = this->iSummCash;
    }
};

class Croupier : public BlackJeck {};

class Gamer : public BlackJeck
{
    std::string stName;

public:
    void SetName(std::string stName)
    {
        this->stName = stName;
    }

    std::string GetName()
    {
        return this->stName;
    }
};

int main()
{
    setlocale(LC_ALL, "Ru");

    char cCardDeck[56]{ '1','2','3','4','5','6','7','8','9','10','L','K','V','A',
                    '1','2','3','4','5','6','7','8','9','10','L','K','V','A',
                    '1','2','3','4','5','6','7','8','9','10','L','K','V','A',
                    '1','2','3','4','5','6','7','8','9','10','L','K','V','A', };
    Gamer g;
    Croupier c;

    string stName;
    int iCash = 0;

    cout << "Введите имя " << endl;
        
    //cin >> stName;
    g.SetName(stName);

    cout << "\nВведите начальную ставку " << endl;

    //cin >> iCash;
    c.SummCash (iCash);

    cout << "Вы взяти карту " << g.GetCart(cCardDeck);
    cout << "\nВы взяти карту " << g.GetCart(cCardDeck);
    cout << "\nСумма Ваших очков " << g.SummPoint();

    cout << endl;

    if (g.GetSummPoint() == 21)
    {
        cout << g.GetName() << " Выйграл";

        g.GetCash(iCash);
    }
    else if (g.GetSummPoint() > 21) // Баг
    {
        cout << g.GetName() << " Проиграл";
    }
    else
    {
        int i = 0;

        do
        {
            if (i % 2 == 0)
            {
                cout << "\nКрупье взял карту " << c.GetCart(cCardDeck);

                cout << "\nСумма очков крупье " << c.SummPoint();
            }
            else
            {
                cout << "\nВзять карту? (y/n) " << endl;
                char c;
                cin >> c;

                if (c == 'y' || c == 'Y')
                {
                    cout << "\nВы взяти карту " << g.GetCart(cCardDeck);

                    cout << "\nСумма Ваших очков " << g.SummPoint();
                }
            }

            i++;

        } while (g.GetSummPoint() >= c.GetSummPoint() || c.GetSummPoint() >= g.GetSummPoint() 
                    || c.GetSummPoint() > 21 || g.GetSummPoint() > 21);
    }

    return 0;
}   