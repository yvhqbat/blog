

#include <iostream>
#include <list>
#include <string>
using namespace std;

/** @class CObserver
 *  @brief 抽象观察者
 */
class CObserver
{
public:
    virtual void Update() = 0;
};

class CObserverA : public CObserver
{
public:
    //CObserverA(CSubject *subject):m_subject(subject){}
    void Update() override
    {
        std::cout<<"this is observer 1."<<std::endl;
        //std::cout<<m_subject->Get()<<std::endl;
    }
private:
    //CSubject *m_subject;  ///< 可以是链表形式,就可观察多个subject.
};

class CObserverB : public CObserver
{
public:
    //SetSubject(CSubject *subject):m_subject(subject){}
    void Update() override
    {
        std::cout<<"this is observer 2."<<std::endl;
        //std::cout<<m_subject->Get()<<std::endl;
    }
private:
    //CSubject *m_subject;
};

/** @class CSubject
 *  @brief 抽象主题对象
 */
class CSubject
{
public:
    void Attach(CObserver* observer)
    {
        m_listObservers.push_back(observer);
    }

    void Detach(CObserver* observer)
    {
        m_listObservers.remove(observer);
    }

    void Notify()
    {
        for(auto ite=m_listObservers.begin();ite!=m_listObservers.end();ite++)
        {
            (*ite)->Update();
        }
    }

    virtual void ChangeState()=0;

private:
    std::list<CObserver*> m_listObservers;
};


class CSubjectOne : public CSubject
{
public:
    void ChangeState() override
    {
        std::cout<<"CSubjectOne something changed."<<std::endl;
        Notify();
    }
private:
};

class CSubjectTwo : public CSubject
{
public:
    void ChangeState() override
    {
        std::cout<<"CSubjectTwo something changed."<<std::endl;
        Notify();
    }
private:
};


int main()
{
    CSubject  *subject   =new CSubjectOne();
    CSubject  *subject   =new CSubjectTwo();
    CObserver *observerA =new CObserverA(/*subject*/);
    CObserver *observerB =new CObserverB(/*subject*/);
    subject->Attach(observerA);
    subject->Attach(observerB);
    subject->ChangeState();

    return 0;
}
