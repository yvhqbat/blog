/** 模板方法模式 */

#include <iostream>
using namespace std;

/*
实现了一个模板方法, 定义了算法的骨架,
具体子类将重定义PrimitiveOperation以
实现一个算法的步骤.
*/
class AbstractClass
{
public:
    void TemplateMethod()
    {
        cout<<"do something ..."<<endl;
        PrimitiveOperation1();
        cout<<"do something else ..."<<endl;
        PrimitiveOperation2();
        cout<<"do something last ..."<<endl;
    }

private:
    virtual void PrimitiveOperation1() = 0;
    virtual void PrimitiveOperation2() = 0;
};


/*
实现了PrimitiveOperation
以完成算法中与特定子类相关的步骤.
*/
class ConcreteClassA : public AbstractClass
{
private:
    void PrimitiveOperation1() override
    {
        cout<<"具体类A方法1实现."<<endl;
    }

    void PrimitiveOperation2() override
    {
        cout<<"具体类A方法2实现."<<endl;
    }
};

class ConcreteClassB : public AbstractClass
{
private:
    void PrimitiveOperation1() override
    {
        cout<<"具体类B方法1实现."<<endl;
    }

    void PrimitiveOperation2() override
    {
        cout<<"具体类B方法2实现."<<endl;
    }
};

/*
模板方法模式是通过把不变的行为搬移到超类, 去除子类中的重复代码来体现它的优势.

模板方法模式就是提供了一个很多好的代码复用平台.

当不变的和可变的行为在方法的子类实现中混合在一起的时候,不变的行为就会在子类中重复出现.
我们通过模板方法模式把这些行为搬移到单一的地方,这样就帮助子类摆脱重复的不变行为的纠缠.
*/
/* 测试 */
int main()
{
    AbstractClass *p=new ConcreteClassA();
    p->TemplateMethod();

    AbstractClass *q=new ConcreteClassB();
    q->TemplateMethod();

    return 0;
}
