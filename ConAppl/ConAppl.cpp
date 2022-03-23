#include <iostream>
#include <cstdint>

using namespace std;

class Power 
{
    int iVoltage = 12;
    int iDegree = 2;

public:
    void SetVoltageAndDegree(int iVoltage, int iDegree)
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
public:
    exception Box(int m_red, int m_green, int m_blue, int m_alpha)
    {
        this->m_red = m_red;
        this->m_green = m_green;
        this->m_blue = m_blue;
        this->m_alpha = m_alpha;
        return this->m_red, this->m_green, this->m_blue, this->m_alpha;
    }   

private:
    std::uint8_t m_red = 0;
    std::uint8_t m_green = 0;
    std::uint8_t m_blue = 0;
    std::uint8_t m_alpha = 0;
};

int main()
{
    setlocale(LC_ALL, "Ru");

    Power one;
    one.SetVoltageAndDegree(15,2);
    one.Calculate();

    RGBA box;
    box.Box(12,2,4,20);

}   