#include <iostream>

void Test(int iNum)
{
    int iCounter = 1;

    for (int i = 2; i <= iNum; i++)
    {
        if (iNum % i == 0)
        {
            iCounter++;
        }
    }
    if (iCounter > 2)
    {
        std::cout << iNum << "- не является" << std::endl;
    }
    else
    {
        std::cout << iNum << "- является" << std::endl;
    }

}

int main()
{
    setlocale(LC_ALL, "Ru");

    std::cout << "Введите число для проверки является ли число простым:" << std::endl;

    int iNum = 0;

    std::cin >> iNum;

    if (iNum < 2)
    {
        std::cout << "Данное число не является простым" << std::endl;
    }
    else
    {
        Test(iNum);
        Test(12313);
        Test(1123);
        Test(1111);
        Test(2);
        Test(3);
        Test(4);
        Test(123*555);
    }
 
    return 0;
}   