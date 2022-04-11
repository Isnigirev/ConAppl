#include <iostream>
#include <vector>

using namespace std;

//1 

template <typename T>

class Pair1
{
    T one;
    T two;

public:
    Pair1(T first, T second)
    {
        one = first;
        two = second;
    }

    T first() const
    {
        return one;
    }

    T second() const
    {
        return two;
    }
};

//2

template <typename T1, typename T2>
class Pair
{
    T1 one;
    T2 two;

public:
    Pair(T1 first, T2 second)
    {
        one = first;
        two = second;
    }

    T1 first() const
    {
        return one;
    }

    T2 second() const
    {
        return two;
    }
};

//3

template <typename T3>
class StringValuePair : public Pair <std::string, T3>
{
public:
    StringValuePair(std::string first, T3 second) : Pair <std::string, T3>(first, second) {}
};

int main()
{
    setlocale(LC_ALL, "Ru");

    //1

    Pair1 <int> p1(6, 9);
    cout << "Pair1: " << p1.first() << ' ' << p1.second() << '\n';

    const Pair1 <double> p2(3.4, 7.8);
    cout << "Pair1: " << p2.first() << ' ' << p2.second() << '\n';

    /*
    Pair: 6 9
    Pair: 3.4 7.8
    */

    //2

    Pair <int, double> p3(6, 7.8);
    cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    const Pair <double, int> p4(3.4, 5);
    cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

    /*
    Pair: 6 7.8
    Pair: 3.4 5
    */

    //3

    StringValuePair <int> svp("Amazing", 7);
    cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

    return 0;
}