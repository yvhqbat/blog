
## boost::static_assert.hpp
编译时断言：


## boost::less_than_comparable<T>
小于号的模板类
```
#include <boost/operators.hpp>
```

## copyable
```
class Copyable
{
};
```

## boost::noncopyable

## 拷贝控制
copy control 是拷贝 stack a; stack b = a; 和赋值 stack b; b = a; 的合称。

当拷贝一个 ADT 时会发生什么？
比方说拷贝一个 stack，是不是应该把它的每个元素按值拷贝到新 stack？

如果语言支持显示控制对象的生命期（比方说C++的确定性析构），而 ADT 用到了动态分配的内存，那么 copy control 更为重要，不然如何防止访问已经失效的对象？

由于 C++ class 是值语义，copy control 是实现深拷贝的必要手段。而且 ADT 用到的资源只涉及动态分配的内存，所以深拷贝是可行的。
相反，object-based 编程风格中的 class 往往代表某样真实的事物（Employee、Account、File 等等），深拷贝无意义。

C 语言没有 copy control，也没有办法防止拷贝，一切要靠程序员自己小心在意。FILE* 可以随意拷贝，但是只要关闭其中一个 copy，其他 copies 也都失效了，跟空悬指针一般。整个 C 语言对待资源（malloc 得到的内存，open() 打开的文件，socket() 打开的连接）都是这样，用整数或指针来代表（即“句柄”）。而整数和指针类型的“句柄”是可以随意拷贝的，很容易就造成重复释放、遗漏释放、使用已经释放的资源等等常见错误。这方面 C++ 是一个显著的进步，boost::noncopyable 是 boost 里最值得推广的库。
一个类继承自`boost::noncopyable`，则该类也不可拷贝。

```
#ifndef BOOST_NONCOPYABLE_HPP_INCLUDED  
#define BOOST_NONCOPYABLE_HPP_INCLUDED  

namespace boost {  

	//  Private copy constructor and copy assignment ensure classes derived from  
	//  class noncopyable cannot be copied.  

	//  Contributed by Dave Abrahams  

	namespace noncopyable_  // protection from unintended ADL  
	{  
		  class noncopyable  
			    {  
					   protected:  
						         noncopyable() {}  
								       ~noncopyable() {}  
									      private:  // emphasize the following members are private  
									         noncopyable( const noncopyable& );  
											       const noncopyable& operator=( const noncopyable& );  
												     };  
	}  

	typedef noncopyable_::noncopyable noncopyable;  

} // namespace boost  

#endif  // BOOST_NONCOPYABLE_HPP_INCLUDED  
```

## 原子性操作
std::atomic

原子性操作可以实现无锁队列。
详见：

## volatile关键字
volatile,防止编译器对代码进行优化。
当要使用volatile声明的变量的值时，系统总是从它所在的内存读取数据，而不是使用保存在寄存器中的备份。即使它前面的指令刚刚从该处读取过数据。而且读取的数据立刻被保存。


## 编译选项
```
-Wall			// 大部分警告   
-Wextra			// 一些额外的警告  
-Werror			// 当出现警告时转为错误，停止编译  
-Wconversion		// 一些可能改变值的隐式转换，给出警告。  
-Wno-unused-parameter	// 函数中出现未使用的参数，不给出警告。  
-Wold-style-cast		// C风格的转换，给出警告  
-Woverloaded-virtual	// 如果函数的声明隐藏住了基类的虚函数，就给出警告。  
-Wpointer-arith		// 对函数指针或者void *类型的指针进行算术操作时给出警告  
-Wshadow		// 当一个局部变量遮盖住了另一个局部变量，或者全局变量时，给出警告。  
-Wwrite-strings		// 规定字符串常量的类型是const char[length],因此,把这样的地址复制给 non-const char *指针将产生警告.这些警告能够帮助你在编译期间发现企图写入字符串常量 的代码  
-march=native		// 指定cpu体系结构为本地平台  

```

## 类型转换
`#include "type.h"`
主要是定义了几个类型转换的包装。  
所以，编码中使用C++风格的类型转换。

知识点：
指向基类的指针能够向下转型的前提是，指针实际上指向派生类对象。


## C/C++类型转换

Q:什么是C风格转换？什么是`static_cast`, `dynamic_cast` 以及 `reinterpret_cast`？区别是什么？为什么要注意？

A:转换的含义是通过改变一个变量的类型为别的类型从而改变该变量的表示方式。为了类型转换一个简单对象为另一个对象你会使用传统的类型转换操作符。比如，为了转换一个类型为doubole的浮点数的指针到整型：
```
int i;
double d;

i = (int) d;
或者：

i = int (d);
```
对于具有标准定义转换的简单类型而言工作的很好。然而，这样的转换符也能不分皂白的应用于类（class）和类的指针。ANSI-C++标准定义了四个新的转换符：'reinterpret_cast', 'static_cast', 'dynamic_cast' 和 'const_cast'，目的在于控制类(class)之间的类型转换。
代码:
```
reinterpret_cast<new_type>(expression)
dynamic_cast<new_type>(expression)
static_cast<new_type>(expression)
const_cast<new_type>(expression)
```

###	1. reinterpret_cast

'reinterpret_cast'转换一个指针为其它类型的指针。它也允许从一个指针转换为整数类型。反之亦然。  
这个操作符能够在非相关的类型之间转换。操作结果只是简单的从一个指针到别的指针的值的二进制拷贝。在类型之间指向的内容不做任何类型的检查和转换。

如果情况是从一个指针到整型的拷贝，`内容的解释是系统相关的`，所以任何的实现都不是方便的。一个转换到足够大的整型能够包含它的指针是能够转换回有效的指针的。

代码:
```
class A {};
class B {};

A * a = new A;
B * b = reinterpret_cast<B *>(a);
```

'reinterpret_cast'就像传统的类型转换一样对待所有指针的类型转换。

### 2. static_cast

'static_cast'允许执行任意的隐式转换和相反转换动作。（即使它是不允许隐式的）

应用到类的指针上，意思是说它允许子类类型的指针转换为父类类型的指针（这是一个有效的隐式转换），同时，也能够执行相反动作：转换父类为它的子类。

在这最后例子里，被转换的父类没有被检查是否与目的类型相一致。
代码：

```
class Base {};
class Derived : public Base {};

Base *a    = new Base;
Derived *b = static_cast<Derived *>(a);
```

'static_cast'除了操作类型指针，也能用于执行类型定义的显式的转换，以及基础类型之间的标准转换:

代码:  
```
double d = 3.14159265;
int    i = static_cast<int>(d);
```

### 3. dynamic_cast

'dynamic_cast'只用于对象的指针和引用。当用于多态类型时，它允许任意的隐式类型转换以及相反过程。不过，与static_cast不同，在后一种情况里（注：即隐式转换的相反过程），dynamic_cast会检查操作是否有效。也就是说，它会检查转换是否会返回一个被请求的有效的完整对象。
检测在运行时进行。如果被转换的指针不是一个被请求的有效完整的对象指针，返回值为NULL.
代码：  
```
class Base { virtual dummy() {} };
class Derived : public Base {};

Base* b1 = new Derived;
Base* b2 = new Base;

Derived* d1 = dynamic_cast<Derived *>(b1);          // succeeds
Derived* d2 = dynamic_cast<Derived *>(b2);          // fails: returns 'NULL'
```

如果一个`引用类型`执行了类型转换并且这个转换是不可能的，一个`bad_cast`的异常类型被抛出：
代码:
```
class Base { virtual dummy() {} };
class Derived : public Base { };

Base* b1 = new Derived;
Base* b2 = new Base;

Derived d1 = dynamic_cast<Derived &*>(b1);          // succeeds
Derived d2 = dynamic_cast<Derived &*>(b2);          // fails: exception thrown
```

### 4. const_cast

这个转换类型操纵传递对象的const属性，或者是设置或者是移除：
代码:
```
class C {};

const C *a = new C;

C *b = const_cast<C *>(a);
```

其它三种操作符是不能修改一个对象的常量性的。
注意：'const_cast'也能改变一个类型的volatile qualifier。
```
