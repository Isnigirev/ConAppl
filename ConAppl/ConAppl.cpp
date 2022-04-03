#include <iostream>

using namespace std;

/*
Во всех остальных классах переопределить эту функцию, исходя из геометрических формул нахождения площади.
*/

class Figure
{
    
public:
    Figure ()
    {
        
    }

    virtual area()
    {

    }
};

class Parallelogram : public Figure
{
public:
    Parallelogram()
    {

    }
};

class Circle : public Figure
{
public:
    Circle ()
    {
        
    }
};

class Rectangle: public Parallelogram
{
public:
    Rectangle()
    {

    }
};

class Square : public Parallelogram
{
public:
    Square()
    {

    }
};

class Rhombus : public Parallelogram
{
public:
    Rhombus()
    {

    }
};

int main()
{
    setlocale(LC_ALL, "Ru");


    return 0;
}   