#include "stdafx.h"
#include "Query.h"
#include <memory>
#include "NoQuery.h"
#include "AndQuery.h"
#include "OrQuery.h"
using namespace std;

//Query::Query()
//{
//}
//

//Query::~Query()
//{
//}

//NoQuery的构造函数，Query的构造函数：Query(shared_ptr<Query_base> query):q(query){}

//要返回一个Query类型，要是一个指向NoQuery的Query_base的指针；所以需要一个构造函数，
//从Query_base的指向NoQuery的指针到Query的构造函数，这个构造函数不应该被用户使用，所以定义为私有
//如果操作符重载不定义为友元函数，也可以实现，但是看起来不是很清晰；
//非友元版的话，含有一个this，对一目操作符影响不大，二目操作符只接受一个参数，左侧为默认，可读性差
Query operator~(const Query &operand)
{
	return shared_ptr<Query_base>(new NoQuery(operand));
}
Query operator&(const Query &lhs, const Query &rhs)
{
	return shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}
Query operator|(const Query &lhs, const Query &rhs)
{
	return shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}
//输入输出运算符第一个参数是iostream，所以不能作为成员函数进行重载，成员函数默认的第一个参数的隐藏的this
ostream& operator << (ostream &os, const Query &query)
{
	os << query.rep();//运行时动态调用
	return os;
}
