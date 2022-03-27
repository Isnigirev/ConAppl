#include <iostream>
#include <cstdint>

using namespace std;

class Power 
{
    int iVoltage = 12;
    int iDegree = 2;

public:
    void SetVoltageAndDegree(int iVoltage = 12, int iDegree = 2)
    {
        this->iVoltage = iVoltage;
        this->iDegree = iDegree;
    }

    void Calculate()
    {
        std::cout << this->iVoltage * this->iDegree << std::endl;
    }
};

class RGBA 
{
private:
    std::uint8_t m_red = 0;
    std::uint8_t m_green = 0;
    std::uint8_t m_blue = 0;
    std::uint8_t m_alpha = 0;

public:
    RGBA (int m_red, int m_green, int m_blue, int m_alpha)
    {
        this->m_red = m_red;
        this->m_green = m_green;
        this->m_blue = m_blue;
        this->m_alpha = m_alpha;
    }

    void print()
    {
        std::cout << "red: " << int(this->m_red) << "\tgreen: " << int(this->m_green)
                  << "\nblue: "<< int(this->m_blue) << "\talpha: " << int(this->m_alpha) << std::endl;
    }
};

class Stack
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

    Power one;
    one.SetVoltageAndDegree();
    one.Calculate();

    cout << endl;

    RGBA rgba(5,2,4,8);
    rgba.print();

    cout << endl;

    Stack stack;
    stack.reset();
    stack.print();

    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();
    stack.print();

    return 0;
}   