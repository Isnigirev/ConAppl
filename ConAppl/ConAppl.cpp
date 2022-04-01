#include <iostream>

using namespace std;

//3 Класса
//Базовый класс Black Jeck
//Производные классы Gamer и Croupier

class Black Jeck
{
    int iArr[10];
    int iCursor = 0;

public:
    void reset()
    {
        for (int i = 0; i < 10; i++)
        {
            iArr[i] = 0;
        }

        iCursor = 0;
    }

    bool push(int a)
    {
        if (iCursor >= 10)
        {
            std::cout << "Стек переполнен" << std::endl;
            return false;
        }
        else
        {
            iArr[iCursor++] = a;
            return true;
        }
    }

    void pop() 
    {
        if (iCursor < 0)
        {
            std::cout << "В стеке не осталось элементов для высвобождения" << std::endl;
        }
        else
        {
            iArr[--iCursor] = 0;
        }
    }

    void print()
    {
        std::cout << "(";

        for (int i = 0; i < iCursor; i++)
        {
            std::cout << iArr[i];
        }

        std::cout << ")" << std::endl;
    }
};

int main()
{
    setlocale(LC_ALL, "Ru");


    return 0;
}   