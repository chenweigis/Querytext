#pragma once
#include "Query_base.h"
#include "WordQuery.h"
#include <iostream>
#include <memory>
using namespace std;

/*
�ӿ��࣬Ϊ�û��ṩ����������Ľӿڣ������಻��ֱ�Ӵ������󣬲��Ѻã���ͨ���ӿ����Ѻõ�ʵ�ֶ�̬
*/
class Query
{
//public:
//	Query() :q(nullptr) {}
//	~Query();

	friend Query operator~(const Query&);	//Ϊʲô�������Ԫ:Ҫʹ��Query��˽�й��캯��
	friend Query operator&(const Query&, const Query&);
	friend Query operator|(const Query&, const Query&);

	friend ostream& operator << (ostream &os, const Query &query);

public:
	Query(const string &str) :q(new WordQuery(str)) {}//����string�Ĺ��칹�캯��
	//ʵ��ʱʹ��WordQuery�Ĺ��캯��������

	//�ӿں��������ö�Query_base�Ĳ���
	QueryResult eval(const TextQuery &t) const//�˺�������ı�������ݣ����Բ���const����
	{
		return q->eval(t);
	}
	string rep() const { return q->rep(); }
	
	
private:
	Query(shared_ptr<Query_base> query) :q(query) {}//ʹ��Query_base��shared_ptr����һ��Query����
	shared_ptr<Query_base> q;

	//�ڴ˺�����Ψһ�ĳ�Ա��q��һ��shared_ptr�������ٶ��忽������ֵ���ƶ����캯���Լ���������
	//Ĭ�ϵ��Ѿ���ȫ���������Щ����


};

