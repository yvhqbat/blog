#include <iostream>
using namespace std;

/****************SubSystem Classes*************************/
class SubSystemOne
{
public:
    void MethodOne()
    {
        cout<<"this is SubSystemOne."<<endl;
    }
};

class SubSystemTwo
{
public:
    void MethodTwo()
    {
        cout<<"this is SubSystemTwo."<<endl;
    }
};

class SubSystemThree
{
public:
    void MethodThree()
    {
        cout<<"this is SubSystemThree."<<endl;
    }
};


/*******************Facade Class*******************/
class Facade
{
public:
    void MethodA()
    {
        m_subsystemOne.MethodOne();
        m_subsystemThree.MethodThree();
    }

    void MethodB()
    {
        m_subsystemTwo.MethodTwo();
        m_subsystemThree.MethodThree();
        m_subsystemOne.MethodOne();
    }
private:
    SubSystemOne    m_subsystemOne;
    SubSystemTwo    m_subsystemTwo;
    SubSystemThree  m_subsystemThree;
};

/********测试************/
int main()
{
    Facade *pFacade = new Facade();
    pFacade->MethodA();
    pFacade->MethodB();
    return 0;
}
