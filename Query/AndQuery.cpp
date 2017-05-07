#include "stdafx.h"
#include "AndQuery.h"
#include <algorithm>
#include <iterator>
//#include "QueryResult.h"

//AndQuery::AndQuery()
//{
//}


//AndQuery::~AndQuery()
//{
//}

QueryResult AndQuery::eval(const TextQuery &text) const
{
	auto left = lhs.eval(text);
	auto right = rhs.eval(text);
	auto ret_lines = make_shared<set<line_no>>();
	set_intersection(left.begin(), left.end(), right.begin(), right.end(), inserter(*ret_lines, ret_lines->begin()));
	return QueryResult(rep(), ret_lines->size(), *ret_lines, left.get_file());
}