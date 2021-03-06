#pragma once
#include "Query_base.h"
#include "Query.h"
#include <string>
using namespace std;

/************************************************************************/
/* 抽象基类，继承自Query_base，保存操作两个运算对象的查询类型所需的数据                                                                     */
/************************************************************************/
class BinaryQuery :
	public Query_base
{
protected:
	BinaryQuery(const Query &l,const Query &r,string s):lhs(l),rhs(r),opSym(s){}

	/************************************************************************/
	/* 纯虚函数&&私有访问权限？
		Query_base中的eval是私有virtual private,
		private保证成员只能被类的成员函数访问，继承时实际上继承了，只是不能访问，
		纯虚函数既然被继承了，又没有实现，则BinaryQuery中也存在一个纯虚函数，也就是抽象类了
	*/
	/************************************************************************/
	//此抽象类未定义eval,继承基类的eval,未实现纯虚函数，此处任然为一个抽象基类
	string rep() const 
	{
		return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
	}
	
	virtual ~BinaryQuery();

	Query lhs,rhs;
	string opSym;//操作符名称
};

