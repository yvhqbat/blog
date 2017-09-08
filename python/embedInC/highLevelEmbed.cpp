/*************************************************************************
	> File Name: highLevelEmbed.cpp
	> Author: ld
	> Mail: yvhqbat@126.com 
	> Created Time: 2017年08月31日 星期四 23时18分09秒
 ************************************************************************/

#include<iostream>
using namespace std;

#include <Python.h>

int main(int argc, char **argv)
{
    
	wchar_t* program = Py_DecodeLocale(argv[0], NULL);
	if(program == NULL)
	{
		cout<<"error: can't decode argv[0]."<<endl;
		return 1;
	}
	Py_SetProgramName(program);
	Py_Initialize();
	PyRun_SimpleString("from time import time, ctime\n"
			"print('today is ',ctime(time()))\n");
	if(Py_FinalizeEx()<0)
	{
		return 120;
	}
	PyMem_RawFree(program);
	std::cout<<"hello world."<<std::endl;
	return 0;
}
