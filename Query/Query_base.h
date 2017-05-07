#pragma once
#include <string>
#include "TextQuery.h"
#include "QueryResult.h"
using namespace std;

/************************************************************************/
/* �����࣬����Query�Ļ�������������ʵ�ֶ�̬��ͳһ���ýӿ�                                                                     */
/************************************************************************/
class Query_base
{
	friend class Query;
public:
	//Query_base();
	using line_no = TextQuery::line_no;//vector<string>::size_type
	virtual ~Query_base()=default;

private://����Ϊ˽�У����ܱ��û����ʣ���װ
	virtual QueryResult eval(const TextQuery&) const = 0;//�����뵱ǰQueryƥ���QueryResult
	virtual string rep() const = 0;//һ����ѯ��string,��Ӧ��ÿһ�е�����
};

