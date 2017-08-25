/** @file   producer_consumer.cpp
 *  @brief  使用回调函数、多线程，实现生产者-消费者。
 *          糅合了(mutex, condition_variable, thread, functional, chrono)的使用.
 *  @author liudong11
 *  @date   20170825
 */
#include <list>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <iostream>
#include <functional>
#include <chrono>
using namespace std;

/* 前置声明 */
class CProducer;
class CConsumer;

/** @class CProducer
 *  @brief 通过回调函数,向CConsumer添加数据
 */
class CProducer
{
public:
	/* 设置生产者 */
	void SetConsumer(CConsumer* cConsumer)
	{
		m_cConsumer = cConsumer;
	}

	/* 设置接收数据的回调函数 */
	void SetReceiver(function<void(CConsumer*,int)> fn)
	{
		m_fn = fn;
	}

	/* 通过回调函数,向生产者提交数据 */
	void Submit(int data)
	{
		m_fn(m_cConsumer, data);
	}

private:
	CConsumer                       *m_cConsumer;
	function<void(CConsumer*, int)>  m_fn;
};

/** @class CConsumer
 *  @brief 消费者,接收CProducer发送来的数据,并在消费者线程中处理
 */
class CConsumer
{
public:
	/* 测试 */
	void Test()
	{
		m_thread = new thread(mem_fn(&CConsumer::Consumer),this);
		m_cProducer = new CProducer();
		m_cProducer->SetReceiver(mem_fn(&CConsumer::ReceiveData));
		m_cProducer->SetConsumer(this);
		for (int i = 0; i < 10; i++)
		{
			m_cProducer->Submit(i);
			this_thread::sleep_for(chrono::seconds(2));
		}
	}

	/* 析构函数 */
	~CConsumer(){
		if (m_thread != nullptr)
		{
			if (m_thread->joinable()){
				m_thread->join();
			}
		}
	}

	/* 接收数据 */
	void ReceiveData(const int &i)
	{
		unique_lock<mutex> Lock(m_mutex);
		m_list.push_back(i);
		m_condition.notify_one();
	}

	/* 消费者线程的初始函数 */
	void Consumer()
	{
		while (true)
		{
			unique_lock<mutex> uLock(m_mutex);
			m_condition.wait(uLock, [this](){return !this->IsEmpty();});
			cout << m_list.front() << endl;
			m_list.pop_front();
			/*
			auto ite = m_list.begin();
			while (ite != m_list.end())
			{
				cout << *ite << endl;
				ite = m_list.erase(ite);
			}*/
		}
	}

	/* 判断数据是否为空 */
	bool IsEmpty()
	{
		return m_list.empty();
	}
private:
	list<int>          m_list;
	CProducer*         m_cProducer;
	mutex              m_mutex;
	condition_variable m_condition;
	thread            *m_thread;
};



int main()
{
	CConsumer b;
	b.Test();

	return 0;
}

