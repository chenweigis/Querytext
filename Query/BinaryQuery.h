#pragma once
#include "Query_base.h"
#include "Query.h"
#include <string>
using namespace std;

/************************************************************************/
/* ������࣬�̳���Query_base��������������������Ĳ�ѯ�������������                                                                     */
/************************************************************************/
class BinaryQuery :
	public Query_base
{
protected:
	BinaryQuery(const Query &l,const Query &r,string s):lhs(l),rhs(r),opSym(s){}
	//�˳�����δ����eval,�̳л����eval,δʵ�ִ��麯�����˴���ȻΪһ���������
	string rep() const 
	{
		return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
	}
	
	virtual ~BinaryQuery();

	Query lhs,rhs;
	string opSym;//����������
};

