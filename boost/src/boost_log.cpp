/*************************************************************************
	> File Name: ./src/boost_log.cpp
	> Author: ld
	> Mail: yvhqbat@126.com 
	> Created Time: 2017年09月07日 星期四 23时25分45秒
 ************************************************************************/

#include<iostream>
using namespace std;
#include <boost/log/trivial.hpp>

int main(int, char*[])
{
	BOOST_LOG_TRIVIAL(trace) << "A trace severity message";
	BOOST_LOG_TRIVIAL(debug) << "A debug severity message";
	BOOST_LOG_TRIVIAL(info) << "An informational severity message";
	BOOST_LOG_TRIVIAL(warning) << "A warning severity message";
	BOOST_LOG_TRIVIAL(error) << "An error severity message";
	BOOST_LOG_TRIVIAL(fatal) << "A fatal severity message";

	
	return 0;
}
