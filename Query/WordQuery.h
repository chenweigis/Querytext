#pragma once
#include "Query_base.h"
#include <string>
#include "TextQuery.h"
using namespace std;
class WordQuery :
	public Query_base
{
private:
	friend class Query;//声明友元，以便Query调用WordQuery的构造函数,因为构造函数为私有，即便是加载了头文件中，也无法通过对象调用

	WordQuery(const string &str) :query_word(str) {}

	QueryResult eval(const TextQuery &t) const
	{
		//const对象不能访问调用非const成员函数，此处进行强制转换
		TextQuery *temp = const_cast<TextQuery *>(&t);
		
		return temp->query(query_word);
	}
	string rep() const { return query_word; }//返回当前查询的单词

	//~WordQuery();//合成版本可满足使用

private:
	string query_word;


};

