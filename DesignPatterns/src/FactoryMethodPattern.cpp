/*************************************************************************
	> File Name: FactoryMethodPattern.cpp
	> Author: ld
	> Mail: yvhqbat@126.com 
	> Created Time: 2017年08月22日 星期二 20时01分15秒
 ************************************************************************/

#include<iostream>
using namespace std;

class COperation
{
public:
	virtual double GetResult() = 0;

	void SetOperandFirst(double dOperandFirst)
	{
		m_dOperandFirst = dOperandFirst;
	}

	void SetOperandSecond(double dOperandSecond)
	{
		m_dOperandSecond = dOperandSecond;
	}

	double GetOperandFirst()
	{
		return m_dOperandFirst;
	}

	double GetOperandSecond()
	{
		return m_dOperandSecond;
	}

private:
	double m_dOperandFirst  = 0.0;
	double m_dOperandSecond = 0.0;
};

class COperationAdd : public COperation
{
public:
	double GetResult() override
	{
		//return COperation::m_dOperandFirst + COperation::m_dOperandSecond;
		return GetOperandFirst() + GetOperandSecond();
	}
	
private:

};

class COperationSub : public COperation
{
public:
	double GetResult() override
	{
		//return COperation::m_dOperandFirst - COperation::m_dOperandSecond;
		return GetOperandFirst() - GetOperandSecond();
	}

private:

};


/*
class COperationFactory
{
public:
	static COperation* CreateOperate(char cOperate)
	{
		COperation *pOperation = nullptr;
		switch(cOperate)
		{
			case '+':
				pOperation = new COperationAdd();
				break;
			case '-':
				pOperation = new COperationSub();
				break;
		}
		return pOperation;
	}
};
*/

class COperationFactory
{
public:
    virtual COperation* CreateOperation() = 0;
private:
};

class COperationFactoryAdd : public COperationFactory
{
public:
    COperation* CreateOperation() override
    {
        return new COperationAdd();
    }
};

class COperationFactorySub : public COperationFactory
{
public:
    COperation* CreateOperation() override
    {
        return new COperationSub();
    }
};


// add a new operation mul.
class COperationMul : public COperation
{
public:
    double GetResult() override
    {
        return GetOperandFirst()*GetOperandSecond();
    }
};

class COperationFactoryMul : public COperationFactory
{
public:
    COperation* CreateOperation()
    {
        return new COperationMul();
    }
};


int main(int argc, char **argv)
{
    /*COperation *pOperation = COperationFactory::CreateOperate('+');
    pOperation->SetOperandFirst(5);
    pOperation->SetOperandSecond(3);
    double result = pOperation->GetResult();
    std::cout<<result<<std::endl;
    */

    COperationFactory *pFactory = new COperationFactoryMul();
    //COperationFactory *pFactory = new COperationFactoryAdd();
    COperation *pOperation = pFactory -> CreateOperation();
    pOperation -> SetOperandFirst(13);
    pOperation -> SetOperandSecond(7);
    double result = pOperation -> GetResult();
    std::cout<<result<<std::endl;
    
        
    return 0;
}


