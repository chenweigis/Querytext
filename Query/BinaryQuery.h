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
	//此抽象类未定义eval,继承基类的eval,未实现纯虚函数，此处任然为一个抽象基类
	string rep() const 
	{
		return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
	}
	
	virtual ~BinaryQuery();

	Query lhs,rhs;
	string opSym;//操作符名称
};

