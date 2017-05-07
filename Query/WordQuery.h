#pragma once
#include "Query_base.h"
#include <string>
#include "TextQuery.h"
using namespace std;
class WordQuery :
	public Query_base
{

	friend class Query;//������Ԫ���Ա�Query����WordQuery�Ĺ��캯��

	WordQuery(const string &str) :query_word(str) {}

	QueryResult eval(const TextQuery &t) const
	{
		TextQuery *temp = const_cast<TextQuery *>(&t);//const�����ܷ��ʵ��÷�const��Ա�������˴�����ǿ��ת��
		return temp->query(query_word);
	}
	string rep() const { return query_word; }//���ص�ǰ��ѯ�ĵ���

	//~WordQuery();//�ϳɰ汾������ʹ��

private:
	string query_word;


};

