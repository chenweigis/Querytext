#pragma once
#include "Query_base.h"
#include <string>
#include "Query.h"
using namespace std;

//从哪里体现取反的了
//通过在Query里重载操作符~，返回一个指向NoQuery的Query，
//Query的eval通过调用Query_base的eval（virtual）实现多态，调用到真正的NoQuery的eval函数
class NoQuery :
	public Query_base
{
	friend Query operator~(const Query&);
public:
	NoQuery(const Query &q):query(q){}
	QueryResult eval(const TextQuery&) const;
	string rep() const
	{
		return "~(" + query.rep() + ")";
	}


	~NoQuery();

private:
	Query query;
};

