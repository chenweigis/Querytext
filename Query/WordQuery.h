#pragma once
#include "Query_base.h"
#include <string>
#include "TextQuery.h"
using namespace std;
class WordQuery :
	public Query_base
{
private:
	friend class Query;//������Ԫ���Ա�Query����WordQuery�Ĺ��캯��,��Ϊ���캯��Ϊ˽�У������Ǽ�����ͷ�ļ��У�Ҳ�޷�ͨ���������

	WordQuery(const string &str) :query_word(str) {}

	QueryResult eval(const TextQuery &t) const
	{
		//const�����ܷ��ʵ��÷�const��Ա�������˴�����ǿ��ת��
		TextQuery *temp = const_cast<TextQuery *>(&t);
		
		return temp->query(query_word);
	}
	string rep() const { return query_word; }//���ص�ǰ��ѯ�ĵ���

	//~WordQuery();//�ϳɰ汾������ʹ��

private:
	string query_word;


};

