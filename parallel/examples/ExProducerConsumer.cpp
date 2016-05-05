#include <iostream>
#include <thread>
using namespace std;

volatile bool m_flag = false;
volatile int maxVal = 20;

void producer_func(std::function<bool()> exitCondition, std::function<void()> calculation)
{
    while(1)
    {
        while(m_flag);
        if(exitCondition())
        {
            m_flag = true;
            return;
        }
        calculation();
        m_flag= true;
    }
}

void consumer_func(std::function<bool()> exitCondition, std::function<void()> calculation)
{
    while(1)
    {
        while(!m_flag);
        if(exitCondition())
        {
            m_flag = false;
            return;
        }
        calculation();
        m_flag= false;
    }
}

int main(int argc, char **argv)
{
    // prints numbers till lower limit
    const int lowerLimit = -10;
    auto exitCondition = [&]()->bool{return maxVal <= lowerLimit;};
    auto calculation = [&](){cout<<maxVal--<<endl;};
    std::thread producer(producer_func, exitCondition, calculation);
    std::thread consumer(consumer_func, exitCondition, calculation);

    producer.join();
    consumer.join();
    return 0;
}
