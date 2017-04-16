// Query.cpp : 定义控制台应用程序的入口点。
//
/************************************************************************/
/* 需求：文本查询程序
（1）读取一个给定的文件
（2）在文件中查询一个单词，返回单词出现的次数以及所在行的列表（展示单词所在行的内容）
（3）要求如果一个单词在某行出现多次，此行只出现一次，行按照升序排列
*/
/************************************************************************/

/************************************************************************/
/*分析：
（1）读取文件 fstream getline（）按行读取;istringstream读取每一个单词;
（2）使用vector<string>保存文件，set按顺序不重复保存行号的集合，map保存单词和行号的set的对应关系
（3）使用一个类TextQuery来封装输入文件的操作，使用QueryResult来保存查询结果，两个类使用shared_ptr共享数据

*/
/************************************************************************/

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "TextQuery.h"
#include "QueryResult.h"

using namespace std;

void runQueries(ifstream &infile);
int main()
{
	ifstream infile("./querytext.txt");
	runQueries(infile);
	system("pause");
    return 0;
}
void runQueries(ifstream &infile)
{
	TextQuery tq(infile);
	QueryResult qr;
	while (1)
	{
		cout << "enter a word to look for,or q to quit: ";
		string s;
		if (!(cin >> s) || s == "q")
			break;
		qr.print(cout, tq.query(s));
	}
}
