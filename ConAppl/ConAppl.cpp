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

class Car
{
    std::string stCompany;
    std::string stModel;

public:
    Car (std::string stCompany = "Neer", std::string stModel = "2b")
    {
        this->stCompany = stCompany;
        this->stModel = stModel;
    }

    virtual void GetInfoCompanyAndModel()
    {
        std::cout << "Company: " << stCompany << std::endl;
        std::cout << "Model: " << stModel << std::endl;
    }
};

class PassangeCar : public Car
{
    int iDoor = 0;
    int iEar = 0;
    double dEngineCapacity = 0;

public:
    PassangeCar(std::string stCompany = "Neer", std::string stModel = "2b",int iDoor = 4, int iEar = 4, double dEngineCapacity = 0.0)
                : Car (stCompany = "Neer", stModel = "2b")
    {
        this->iDoor = iDoor;
        this->iEar = iEar;
        this->dEngineCapacity = dEngineCapacity;
    }

    virtual void GetInfo()
    {
        std::cout << "Doors: " << iDoor << std::endl;
        std::cout << "Ears: " << iEar << std::endl;
        std::cout << "Engine: " << dEngineCapacity << std::endl;
    }
};

class Bus : public Car
{
    int iDoor = 0;
    int iEar = 0;
    double dEngineCapacity = 0;

public:
    Bus(std::string stCompany = "Neer", std::string stModel = "2b", int iDoor = 4, int iEar = 4, double dEngineCapacity = 0.0)
        : Car(stCompany = "Neer", stModel = "2b")
    {
        this->iDoor = iDoor;
        this->iEar = iEar;
        this->dEngineCapacity = dEngineCapacity;
    }

    virtual void GetInfo()
    {
        std::cout << "Doors: " << iDoor << std::endl;
        std::cout << "Ears: " << iEar << std::endl;
        std::cout << "Engine: " << dEngineCapacity << std::endl;
    }
};

class Minivan : public PassangeCar, public Bus
{
    int iDoor = 0;
    int iEar = 0;
    double dEngineCapacity = 0;

public: 
    Minivan(std::string stCompany = "Neer", std::string stModel = "2b", int iDoor = 4, int iEar = 4, double dEngineCapacity = 0.0)
        : PassangeCar(stCompany = "Neer", stModel = "2b")
    {
        this->iDoor = iDoor;
        this->iEar = iEar;
        this->dEngineCapacity = dEngineCapacity;
    }

    virtual void GetInfo()
    {
        std::cout << "Doors: " << iDoor << std::endl;
        std::cout << "Ears: " << iEar << std::endl;
        std::cout << "Engine: " << dEngineCapacity << std::endl;
    }
};

//3

class Fraction
{
    int iNumerator;
    int iDenominator;

public:
    Fraction(int iNumerator, int iDenominator)
    {
        this->iNumerator = iNumerator;

        if (iDenominator == 0)
        {
            do
            {
                std::cout << "Ошибка знаменатель равен 0!" << std::endl;
                std::cout << "Введите чило повторно" << std::endl;

                cin >> iDenominator;

            } while (iDenominator != 0);

            this->iDenominator = iDenominator;
        }
        else
        {
            this->iDenominator = iDenominator;
        }
    }

    void operator -- (const Fraction &f)
    {
        
    }

};

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

    cout << "2-> " << endl;

    //2

    PassangeCar B2("Neer", "B2", 4, 4, 2);
    B2.GetInfoCompanyAndModel();
    B2.GetInfo();
    Bus PassangeBus("Neer", "PassangeBus", 3, 4, 4);
    PassangeBus.GetInfoCompanyAndModel();
    PassangeBus.GetInfo();
    Minivan Mv("Neer", "Mv", 4, 4, 3);
    Mv.GetInfo();

    cout << "3-> " << endl;

    //3




    return 0;
}   