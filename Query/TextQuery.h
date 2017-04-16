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
	TextQuery();
	TextQuery(ifstream &infile);
	~TextQuery();

public:
	QueryResult query(const string &s);

private:
	shared_ptr<vector<string>> data;
	map<string, set<int>> word_ln;
};

