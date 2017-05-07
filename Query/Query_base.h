#pragma once
#include <string>
#include "TextQuery.h"
#include "QueryResult.h"
using namespace std;

/************************************************************************/
/* 基类，抽象类，定义Query的基本操作，虚函数实现多态，统一调用接口                                                                     */
/************************************************************************/
class Query_base
{
	friend class Query;//Query作为Query_base的友元类，需要访问Quert_base的私有成员
protected:
	//Query_base();
	using line_no = TextQuery::line_no;//vector<string>::size_type
	virtual ~Query_base()=default;


	
private://定义为私有，不能被用户访问，封装//private不能被继承，怎么实现的多态？
		//答：多态性与将实现多态的函数的访问限定符没有任何关系
		//private 函数仍然可以实现多态，它的指针仍然位于vtbl中
		//只不过该函数的多态一般只能在基类的内部由其他非虚函数调用该函数的时候反映出来
	virtual QueryResult eval(const TextQuery&) const = 0;//返回与当前Query匹配的QueryResult
	virtual string rep() const = 0;//一个查询的string,对应到每一行的数据
};

