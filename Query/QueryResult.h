#pragma once
#include <vector>
#include <string>
#include <set>
#include <iostream>
#include <memory>
using namespace std;
class QueryResult
{
public:
	using line_no = vector<string>::size_type;
	QueryResult();
	QueryResult(const string &word, size_t occur,set<line_no> lnum, shared_ptr<vector<string>> svp):
		m_word(word),m_occur(occur),m_lnum(lnum),m_svp(svp){}
	~QueryResult();

	set<line_no>::iterator begin() { return m_lnum.begin(); }
	set<line_no>::iterator end() { return m_lnum.end(); }
	shared_ptr<vector<string>> get_file() { return m_svp; }

public:
	void print(ostream &os, QueryResult qr);
private:
	string m_word;
	size_t m_occur;
	set<line_no> m_lnum;
	shared_ptr<vector<string>> m_svp;
};

