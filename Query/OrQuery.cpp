#include "stdafx.h"
#include "OrQuery.h"


//OrQuery::OrQuery()
//{
//}


//OrQuery::~OrQuery()
//{
//}
QueryResult OrQuery::eval(const TextQuery& text) const
{
	auto right = rhs.eval(text);//rhs,lhs 成员继承自BinaryQuery,返回的是一个QueryResult
	auto left = lhs.eval(text);
	auto ret_lines =make_shared<set<line_no>>(left.begin(), left.end());
	ret_lines->insert(right.begin(), right.end());
	return QueryResult(rep(), ret_lines->size(), *ret_lines, left.get_file());
}