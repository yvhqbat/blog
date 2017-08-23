#include <iostream>
#include <functional>

class CClientManage
{
public:
    CClientManage(int nFirst, int nSecond):m_nFirst(nFirst),m_nSecond(nSecond){}

    int GetFirst()
    {
        return m_nFirst;
    }

    int GetSecond()
    {
        return m_nSecond;
    }

    void SetCallback(std::function<int(CClientManage*,int)> funCallback)
    {
        m_funCallback = funCallback;
    }

    void Call()
    {
        int result = m_funCallback(this, 13);
        std::cout<<result<<std::endl;
    }

private:
    int m_nFirst;
    int m_nSecond;
    std::function<int(CClientManage*,int)> m_funCallback;
};


int Func1(CClientManage *c, int nThird)
{
    return c->GetFirst()+c->GetSecond()+nThird;
}

class CCommand
{
public:
    static int Func(CClientManage *c, int nThird)
    {
        return c->GetFirst()+c->GetSecond()+nThird;
    }

    int Func2()
    {
        return c->GetFirst()+c->GetSecond()+nThird;
    }
};

int main()
{
    CClientManage c(3,5);
    c.SetCallback(Func1);
    c.Call();

    c.SetCallback(CCommand::Func);
    c.Call();

    c.SetCallback(std::mem_fn(&CCommand::Func2));
    c.Call();

    return 0;
}
