#pragma once
#include <string>
#include "TextQuery.h"
#include "QueryResult.h"
using namespace std;

/************************************************************************/
/* ���࣬�����࣬����Query�Ļ����������麯��ʵ�ֶ�̬��ͳһ���ýӿ�                                                                     */
/************************************************************************/
class Query_base
{
	friend class Query;//Query��ΪQuery_base����Ԫ�࣬��Ҫ����Quert_base��˽�г�Ա
protected:
	//Query_base();
	using line_no = TextQuery::line_no;//vector<string>::size_type
	virtual ~Query_base()=default;


	
private://����Ϊ˽�У����ܱ��û����ʣ���װ//private���ܱ��̳У���ôʵ�ֵĶ�̬��
		//�𣺶�̬���뽫ʵ�ֶ�̬�ĺ����ķ����޶���û���κι�ϵ
		//private ������Ȼ����ʵ�ֶ�̬������ָ����Ȼλ��vtbl��
		//ֻ�����ú����Ķ�̬һ��ֻ���ڻ�����ڲ����������麯�����øú�����ʱ��ӳ����
	virtual QueryResult eval(const TextQuery&) const = 0;//�����뵱ǰQueryƥ���QueryResult
	virtual string rep() const = 0;//һ����ѯ��string,��Ӧ��ÿһ�е�����
};

