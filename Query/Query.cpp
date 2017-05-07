#include "stdafx.h"
#include "Query.h"
#include <memory>
#include "NoQuery.h"
#include "AndQuery.h"
#include "OrQuery.h"
using namespace std;

//Query::Query()
//{
//}
//

//Query::~Query()
//{
//}

//NoQuery�Ĺ��캯����Query�Ĺ��캯����Query(shared_ptr<Query_base> query):q(query){}

//Ҫ����һ��Query���ͣ�Ҫ��һ��ָ��NoQuery��Query_base��ָ�룻������Ҫһ�����캯����
//��Query_base��ָ��NoQuery��ָ�뵽Query�Ĺ��캯����������캯����Ӧ�ñ��û�ʹ�ã����Զ���Ϊ˽��
//������������ز�����Ϊ��Ԫ������Ҳ����ʵ�֣����ǿ��������Ǻ�������
//����Ԫ��Ļ�������һ��this����һĿ������Ӱ�첻�󣬶�Ŀ������ֻ����һ�����������ΪĬ�ϣ��ɶ��Բ�
Query operator~(const Query &operand)
{
	return shared_ptr<Query_base>(new NoQuery(operand));
}
Query operator&(const Query &lhs, const Query &rhs)
{
	return shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}
Query operator|(const Query &lhs, const Query &rhs)
{
	return shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}
//��������������һ��������iostream�����Բ�����Ϊ��Ա�����������أ���Ա����Ĭ�ϵĵ�һ�����������ص�this
ostream& operator << (ostream &os, const Query &query)
{
	os << query.rep();//����ʱ��̬����
	return os;
}
