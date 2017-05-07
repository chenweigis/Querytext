#include "stdafx.h"
#include "TextQuery.h"
#include <initializer_list>
using namespace std;


TextQuery::TextQuery()
{
}

TextQuery::TextQuery(ifstream &infile)
{
	string line,word;
	//initializer_list<string> list{",","."};//string.find不能接受一个initializer_list，要用的话只能自己重载
	while (getline(infile,line))
	{
		if (data==nullptr)//初始状态下，指针为空时，vecotr对象不存在，对vector的操作会引发异常，PS:判断的重要性;
		{
			data = make_shared<vector<string>>();
		}
		data->push_back(line);
		istringstream iss(line);
		while (iss >> word)
		{
			//处理单词后面跟着“,”“.”不能识别为独立单词问题
			if (word.find(",") != string::npos)
			{
				word = word.substr(0, word.find(","));
			}
			if (word.find(".") != string::npos)
			{
				word = word.substr(0, word.find("."));
			}
			if (word_ln.find(word) == word_ln.end())//当前单词不在map中
			{
				set<line_no> linenum;
				linenum.insert(data->size());
				word_ln[word] = linenum;
			}
			else
				word_ln[word].insert(data->size());//set中插入当前行号
			
		}
	}
}

QueryResult TextQuery::query(const string &s)
{
	
	if (word_ln.find(s) == word_ln.end())
	{
		set<line_no> s_nll;
		shared_ptr<vector<string>> data_null;
		QueryResult qr(s, 0, s_nll, data_null);
		return qr;
	}
		
	else
	{
		QueryResult qr(s, word_ln[s].size(), word_ln[s], data);
		return qr;
	}
	
}
TextQuery::~TextQuery()
{
}
