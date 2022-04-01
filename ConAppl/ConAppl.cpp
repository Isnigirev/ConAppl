#include <iostream>

using namespace std;

class Figure
{

};

class Parallelogram : public Figure
{

};

class Circle : public Figure
{

};

class Rectangle: public Parallelogram
{

};

class Square : public Parallelogram
{

};

class Rhombus : public Parallelogram
{

};



int main()
{
    setlocale(LC_ALL, "Ru");


    return 0;
}   