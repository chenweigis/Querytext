#pragma once
#include <string>
#include "TextQuery.h"
#include "QueryResult.h"
using namespace std;

/************************************************************************/
/* 抽象类，定义Query的基本操作，用来实现多态，统一调用接口                                                                     */
/************************************************************************/
class Query_base
{
	friend class Query;
public:
	//Query_base();
	using line_no = TextQuery::line_no;//vector<string>::size_type
	virtual ~Query_base()=default;

private://定义为私有，不能被用户访问，封装
	virtual QueryResult eval(const TextQuery&) const = 0;//返回与当前Query匹配的QueryResult
	virtual string rep() const = 0;//一个查询的string,对应到每一行的数据
};

