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
	//query是Query对象，编译时绑定调用Query的eval,通过Query_base类的指针指向一个虚函数：eval，实现多态调用
	//调用哪一个eval取决于指针指向哪个对象
	//这里的指针指向的WordQuery(Query接受string类型的构造函数分配内存使用的是WordQuery)
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
