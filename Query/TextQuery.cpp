#include "stdafx.h"
#include "TextQuery.h"


TextQuery::TextQuery()
{
}

TextQuery::TextQuery(ifstream &infile)
{
	string line,word;
	
	while (getline(infile,line))
	{
		if (data==nullptr)//��ʼ״̬�£�ָ��Ϊ��ʱ��vecotr���󲻴��ڣ���vector�Ĳ���������һ����PS:�жϵ���Ҫ��;
		{
			data = make_shared<vector<string>>(sizeof(line));
		}
		data->push_back(line);
		istringstream iss(line);
		while (iss >> word)
		{
			if (word_ln.find(word) == word_ln.end())//��ǰ���ʲ���map��
			{
				set<int> linenum;
				linenum.insert(data->size()-1);
				word_ln[word] = linenum;
			}
			else
				word_ln[word].insert(data->size()-1);//set�в��뵱ǰ�к�
			
		}
	}
}

QueryResult TextQuery::query(const string &s)
{
	
	if (word_ln.find(s) == word_ln.end())
	{
		set<int> s_nll;
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
