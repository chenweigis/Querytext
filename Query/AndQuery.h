#pragma once
#include "BinaryQuery.h"
class AndQuery :
	public BinaryQuery
{
	friend Query operator&(const Query&, const Query&);//��Ҫ����AndQuery�Ĺ��캯��

	AndQuery(const Query& left,const Query& right):BinaryQuery(left,right,"&"){}

	QueryResult eval(const TextQuery&) const;

	//~AndQuery();

};

