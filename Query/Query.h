#pragma once
#include "Query_base.h"
#include "WordQuery.h"
#include <iostream>
#include <memory>
using namespace std;

/*
接口类，为用户提供创建抽象类的接口（抽象类不能直接创建对象，不友好），通过接口类友好的实现多态
*/
class Query
{
//public:
//	Query() :q(nullptr) {}
//	~Query();

	friend Query operator~(const Query&);	//为什么定义成友元:见实现部分说明
	friend Query operator&(const Query&, const Query&);
	friend Query operator|(const Query&, const Query&);

	friend ostream& operator << (ostream &os, const Query &query);

public:
	Query(const string &str) :q(new WordQuery(str)) {}//接收string的构造构造函数
	//实现时使用WordQuery的构造函数来创建

	//接口函数，调用对Query_base的操作
	QueryResult eval(const TextQuery &t) const//此函数不会改变对象内容，所以采用const函数
	{
		//动态绑定，调用哪个eval取决于q指向哪个对象
		return q->eval(t);//Query_base是抽象类，eval是私有函数，如何访问到的？//通过友元类，将Query声明为Query_base的友元
	}
	string rep() const { return q->rep(); }
	
	
private:
	Query(shared_ptr<Query_base> query) :q(query) {}//使用Query_base的shared_ptr构造一个Query对象
	shared_ptr<Query_base> q;

	//在此函数中唯一的成员是q，一个shared_ptr，无须再定义拷贝、赋值、移动构造函数以及析构函数
	//默认的已经完全可以完成这些操作


};

