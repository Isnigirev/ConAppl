#include <iostream>
#include <vector>

using namespace std;

//1 

//template <typename T>
//
//class Pair1
//{
//    T one;
//    T two;

//public:
//    Pair1(T first, T second)
//    {
//        one = first;
//        two = second;
//    }

//    T first() const
//    {
//        return one;
//    }

//    T second() const
//    {
//        return two;
//    }
//};

//2
    
//template <typename T1, typename T2>
//class Pair
//{
//    T1 one;
//    T2 two;

//public:
//    Pair(T1 first, T2 second)
//    {
//        one = first;
//        two = second;
//    }

//    T1 first() const
//    {
//        return one;
//    }

//    T2 second() const
//    {
//        return two;
//    }
//};

//3

//template <typename T3>
//class StringValuePair : public Pair <std::string, T3>
//{
//public:
//    StringValuePair(std::string first, T3 second) : Pair <std::string, T3> (first, second) {}
//};

//4

/*Создать класс Card, описывающий карту в игре БлэкДжек. 
* 
У этого класса должно быть три поля: масть, 
значение карты и положение карты (вверх лицом или рубашкой). 

Сделать поля масть и значение карты типом перечисления (enum). 

Положение карты - тип bool. Также в этом классе должно быть два метода:
метод Flip(), который переворачивает карту, т.е. если она была рубашкой вверх, то он ее поворачивает лицом вверх, и наоборот.
метод GetValue(), который возвращает значение карты, пока можно считать, что туз = 1.*/
    
class Card
{
    enum Suit
    {
        Worms,
        Diamonds,
        Clubs,
        Peaks
    };

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

    bool stMapMosition; //(1 - face up 0 - shirt up)

public:
    bool Flip(bool stMapMosition)
    {
        if (stMapMosition == 1)
        {
            std::cout << "Карта перевернута рубашкой вверх\n";
            return stMapMosition = 0;
        }
        else
        {
            std::cout << "Карта перевернута лицом вверх\n";
            return stMapMosition = 1;
        }
    }

    const int GetValue(int a) //Временная переменная
    {
        switch (a)
        {
        case Two:
            return 2;
        case Three:
            return 3;
        case Four:
            return 4;
        case Five:
            return 5;
        case Six:
            return 6;
        case Seven:
            return 7;
        case Eight:
            return 8;
        case Hine:
            return 9;
        case Ten:
            return 10;
        case J:
            return 10;
        case O:
            return 10;
        case K:
            return 10;
        case A:
            return 1;
        default:
            break;
        }
    }
};

/*Реализовать класс Hand, который представляет собой коллекцию карт. 

В классе будет одно поле: 
вектор указателей карт (удобно использовать вектор, т.к. это по сути динамический массив, 
а тип его элементов должен быть - указатель на объекты класса Card). 

Также в классе Hand должно быть 3 метода:
• метод Add, который добавляет в коллекцию карт новую карту, соответственно он принимает в качестве параметра указатель на новую карту
• метод Clear, который очищает руку от карт
• метод GetValue, который возвращает сумму очков карт руки (здесь предусмотреть возможность того, что туз может быть равен 11).*/

class Hand
{
    vector <Card> vCard;

public:
    void Add(Card)
    {
        vCard;
    }

    void Clear()
    {
        vCard << clear;   
    }

    void GetValue()
    {
            
    }
};


/*
Согласно иерархии классов, которая представлена в методичке к уроку 3, от класса Hand наследует класс GenericPlayer, 
который обобщенно представляет игрока, ведь у нас будет два типа игроков - человек и компьютер. 

Создать класс GenericPlayer, в который добавить поле name - имя игрока. Также добавить 3 метода:
• IsHitting() - чисто виртуальная функция, возвращает информацию, нужна ли игроку еще одна карта.
• IsBoosted() - возвращает bool значение, есть ли у игрока перебор
• Bust() - выводит на экран имя игрока и объявляет, что у него перебор.
*/   

    class GenericPlayer : public Hand
    {
        std::string stName;

    public:
        GenericPlayer(std::string stName)
        {
            this->stName = stName;
        }

        virtual bool IsHitting() 
        {
            char a;
            std::cout << "Взять карту? (y/n) \n";
            cin >> a;

            return (a == 'y' || a == 'Y') ? 1 : 0;
        }

        bool IsBoosted() 
        {
            
        }

        void Bust() 
        {
            std::cout << stName << "\tперебор!\n";
        }
    };

int main()
{
    setlocale(LC_ALL, "Ru");

//1

    //Pair1 <int> p1(6, 9);
    //cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';
    //
    //const Pair1 <double> p2(3.4, 7.8);
    //cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

    /*
    Pair: 6 9
    Pair: 3.4 7.8
    */

//2

    //Pair<int, double> p1(6, 7.8);
    //cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    //const Pair<double, int> p2(3.4, 5);
    //cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
        
    /*
    Pair: 6 7.8
    Pair: 3.4 5
    */

//3

    //StringValuePair <int> svp("Amazing", 7);
    //cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

    return 0;
}   