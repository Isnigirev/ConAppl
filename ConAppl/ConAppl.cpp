#include <iostream>

using namespace std;

//1

class Figure
{

public:
    Figure ()
    {
        
    }

    virtual void area()
    {
        
    }
};

class Parallelogram : public Figure
{
    float fLength = 0; // длина 
    float fHeight = 0; // высоты

public:
    Parallelogram (float fLength = 0, float fHeight = 0)
    {
        this->fLength = fLength;
        this->fHeight = fHeight;
    }

    virtual void area()
    {
        std::cout << "S Parallelogram = " << fLength * fHeight << std::endl;
    }
};

class Circle : public Figure
{
    const float fPI = 3.14;
    float fRadius;              //радиус

public:
    Circle (float fLength)
    {
        fRadius = fLength / 2;
    }

    virtual void area()
    {
        std:: cout << "S Circle = " << fPI * (fRadius * fRadius) << std::endl;
    }
};

class Rectangle: public Parallelogram
{
    float fLength = 0;
    float fWidth = 0;

public:
    Rectangle(float fLength = 0, float fWidth = 0)
    {
        this->fLength = fLength;
        this->fWidth = fWidth;
    }

    virtual void area()
    {
        std::cout << "S Rectangle = " << fLength * fWidth << std::endl;
    }
};

class Square : public Parallelogram
{
    float fSide = 0;

public:
    Square(float fSide = 0)
    {
        this->fSide = fSide;
    }

    virtual void area()
    {
        std::cout << "S Square = " << fSide * fSide << std::endl;
    }
};

class Rhombus : public Parallelogram
{
    float fDiagonalA = 0;
    float fDiagonalB = 0;

public:
    Rhombus(float fDiagonalA = 0, float fDiagonalB = 0)
    {
        this->fDiagonalA = fDiagonalA;
        this->fDiagonalB = fDiagonalB;
    }

    virtual void area()
    {
        std::cout << "S Rhombus = " << (fDiagonalA * fDiagonalB) / 2 << std::endl;
    }
};

//2

int main()
{
    setlocale(LC_ALL, "Ru");

    //1

    Circle c (5);
    Parallelogram p(3, 4);
    Rectangle rec(2, 5);
    Square s(4);
    Rhombus rh(4, 4);

    c.area();
    p.area();
    rec.area();
    s.area();
    rh.area();

    //2



    return 0;
}   