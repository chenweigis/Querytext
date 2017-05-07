#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <fstream>
#include <sstream>
#include "QueryResult.h"
using namespace std;


class TextQuery
{
public:
	using line_no = vector<string>::size_type;//为了使代码更易读，定义一个类型成员来引用行号
	TextQuery();
	TextQuery(ifstream &infile);
	~TextQuery();

public:
	QueryResult query(const string &s);

private:
	shared_ptr<vector<string>> data;
	map<string, set<line_no>> word_ln;
};

