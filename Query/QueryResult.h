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
	QueryResult();
	QueryResult(const string &word,unsigned int occur,set<int> lnum, shared_ptr<vector<string>> svp):
		m_word(word),m_occur(occur),m_lnum(lnum),m_svp(svp){}
	~QueryResult();


public:
	void print(ostream &os, QueryResult qr);
private:
	string m_word;
	unsigned int m_occur;
	set<int> m_lnum;
	shared_ptr<vector<string>> m_svp;
};

