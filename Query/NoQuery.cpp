#include "stdafx.h"
#include "NoQuery.h"


//NoQuery::NoQuery()
//{
//}


NoQuery::~NoQuery()
{
}
QueryResult NoQuery::eval(const TextQuery& text) const
{
	auto result = query.eval(text);//��̬���õ�WordQuery?
	auto ret_lines = make_shared<set<line_no>>();
	auto beg = result.begin(), end = result.end();
	auto sz = result.get_file()->size();
	for (size_t n = 0; n != sz; ++n)
	{
		if (beg == end || *beg != n)//���ҵĽ��Ϊ�ջ��� ��ѯ���Ľ����Ϊn�����n���뵽ret_lines��Ϊ~���к�
		{
			ret_lines->insert(n);
		}
		else if (beg != end)
			++beg;
	}
	return QueryResult(rep(), ret_lines->size(), *ret_lines, result.get_file());


}
