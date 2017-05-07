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
	auto result = query.eval(text);//动态调用到WordQuery?
	auto ret_lines = make_shared<set<line_no>>();
	auto beg = result.begin(), end = result.end();
	auto sz = result.get_file()->size();
	for (size_t n = 0; n != sz; ++n)
	{
		if (beg == end || *beg != n)//查找的结果为空或者 查询到的结果不为n，则把n插入到ret_lines作为~的行号
		{
			ret_lines->insert(n);
		}
		else if (beg != end)
			++beg;
	}
	return QueryResult(rep(), ret_lines->size(), *ret_lines, result.get_file());


}
