
#include <iostream>
#include <string>
using namespace std;


/* barbecuer
*/
class Receiver
{
public:
    void BakeMutton()
    {
        cout<<"bake mutton"<<endl;
    }
    void BakeChickenWing()
    {
        cout<<"bake chicken wing"<<endl;
    }

    /* 添加的命令 */
    void SetName(string strName)
    {
        m_strName = strName;
    }
    void PrintName()
    {
        cout<<"my name is "<<m_strName<<endl;
    }
private:
    //可添加一些执行命令需要的参数
    int     m_nId;
    string  m_strName;
};


/* Command 接口类
 */
class Command
{
public:
    /* 构造函数 */
    Command(Receiver *pReceiver)
        : m_pReceiver(pReceiver)
    {
    }

    /* 执行命令接口 */
    virtual void Execute() = 0;
//private:
protected:
    Receiver *m_pReceiver;  //接收者
};

/* 具体命令类, 1 bake mutton command */
class ConcreteCommandA : public Command
{
public:
    ConcreteCommandA(Receiver *pReceiver)
        : Command(pReceiver)
    {
        //m_pReceiver = pReceiver;
    }

    void Execute() override
    {
        m_pReceiver->BakeMutton();
    }
};

/* 具体命令类, 1 bake chicken command */
class ConcreteCommandB : public Command
{
public:
    ConcreteCommandB(Receiver *pReceiver)
        : Command(pReceiver)
    {
        //m_pReceiver = pReceiver;
    }

    void Execute() override
    {
        m_pReceiver->BakeChickenWing();
    }
};

/* 具体命令类, 1 bake chicken command */
class ConcreteCommandC : public Command
{
public:
    ConcreteCommandC(Receiver *pReceiver)
        : Command(pReceiver)
    {
        //m_pReceiver = pReceiver;
    }

    void Execute() override
    {
        m_pReceiver->PrintName();
    }
};

/* waiter */
class Invoker
{
public:
    void SetCommand(Command *pCommand)
    {
        m_pCommand = pCommand;
    }

    void ExecuteCommand()
    {
        m_pCommand->Execute();
    }
private:
    Command *m_pCommand;
    //vector<Command *>p_commandList; //这里相当于一个命令对象队列
};

/* 测试 */
int main()
{
    Receiver *pReceiver=new Receiver();
    Command *pCommand1=new ConcreteCommandA(pReceiver);
    Command *pCommand2=new ConcreteCommandB(pReceiver);
    Command *pCommand3=new ConcreteCommandC(pReceiver);
    Invoker *pInvoker=new Invoker();

    pReceiver->SetName("liudong");

    pInvoker->SetCommand(pCommand1);
    pInvoker->ExecuteCommand();

    pInvoker->SetCommand(pCommand2);
    pInvoker->ExecuteCommand();

    pInvoker->SetCommand(pCommand3);
    pInvoker->ExecuteCommand();

    return 0;
}
