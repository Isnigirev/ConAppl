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
    bool GetCart(char cCardDeck[])
    {
        int i = 0;

        do
        {
            if (cCardDeck[i] != 0)
            {
                cSteck[iCursor++] = cCardDeck[i];
                return true;
            }
            else
            {
                i++;
            }

        } while (i >= 56);

        return false;
    }

    int SummPoint()
    {
        for (int i = 0; i < iCursor; i++)
        {
            this->iSummPoint += this->cSteck[i];
        }

        return this->iSummPoint;
    }

    void SummCash(int iCash)
    {
        this->iSummCash += iCash;
    }

    int ReturnCash (int iCash)
    {
        return iCash = this->iSummCash;
    }
};

class Croupier : public BlackJeck {};

class Gamer : public BlackJeck
{
    std::string stName;

public:
    std::string GetName(std::string stName)
    {
        this->stName = stName;
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
        
    cin >> stName;
    g.GetName(stName);

    cout << "\nВведите начальную ставку " << endl;

    cin >> iCash;
    c.SummCash (iCash);

    g.


    do
    {
        



    } while (true);

    return 0;
}   