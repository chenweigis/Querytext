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
	//initializer_list<string> list{",","."};//string.find���ܽ���һ��initializer_list��Ҫ�õĻ�ֻ���Լ�����
	while (getline(infile,line))
	{
		if (data==nullptr)//��ʼ״̬�£�ָ��Ϊ��ʱ��vecotr���󲻴��ڣ���vector�Ĳ����������쳣��PS:�жϵ���Ҫ��;
		{
			data = make_shared<vector<string>>();
		}
		data->push_back(line);
		istringstream iss(line);
		while (iss >> word)
		{
			//�����ʺ�����š�,����.������ʶ��Ϊ������������
			if (word.find(",") != string::npos)
			{
				word = word.substr(0, word.find(","));
			}
			if (word.find(".") != string::npos)
			{
				word = word.substr(0, word.find("."));
			}
			if (word_ln.find(word) == word_ln.end())//��ǰ���ʲ���map��
			{
				set<line_no> linenum;
				linenum.insert(data->size());
				word_ln[word] = linenum;
			}
			else
				word_ln[word].insert(data->size());//set�в��뵱ǰ�к�
			
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
