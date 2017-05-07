#pragma once
#include "Query_base.h"
#include <string>
#include "Query.h"
using namespace std;

//����������ȡ������
//ͨ����Query�����ز�����~������һ��ָ��NoQuery��Query��
//Query��evalͨ������Query_base��eval��virtual��ʵ�ֶ�̬�����õ�������NoQuery��eval����
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

