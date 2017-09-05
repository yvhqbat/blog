/**
   原型模式
   g++ -Wall -std=c++11 PrototypePattern.cpp -o PrototypePattern
*/

#include <string>
#include <iostream>
using namespace std;


/** @class Prototype
 *  @brief 原型类,声明一个克隆自身的接口
 */
class Prototype
{
public:
    virtual Prototype* Clone() = 0;
};

/** @class ConcretePrototypeA
 *  @brief 具体原型类,实现一个克隆自身的操作
 */
class ConcretePrototypeA : public Prototype
{
public:
    /* 构造函数 */
    ConcretePrototypeA()
    {
        std::cout<<"ConcretePrototypeA()"<<std::endl;
    }

    /* 克隆函数, 返回拷贝构造函数构造的对象 */
    Prototype* Clone() override
    {
        return new ConcretePrototypeA(*this);
    }

    /* 拷贝构造函数 */
    ConcretePrototypeA(const ConcretePrototypeA &other)
    {
        m_id = other.m_id;
        m_name = other.m_name;
    }

    void SetId(int id)
    {
        m_id = id;
    }
    void SetName(string name)
    {
        m_name = name;
    }

    void PrintData()
    {
        cout<<"id is "<<m_id<<endl;
        cout<<"name is "<<m_name<<endl;
    }

private:
    int m_id;
    string m_name;
};

/* client */
int main()
{
    ConcretePrototypeA *cpa=new ConcretePrototypeA();
    cpa->SetId(13);
    cpa->SetName("liudong");
    cpa->PrintData();

    ConcretePrototypeA *cpa2=(ConcretePrototypeA*)(cpa->Clone());
    cpa2->PrintData();

    return 0;
}
