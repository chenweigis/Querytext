// Query.cpp : �������̨Ӧ�ó������ڵ㡣
//
/************************************************************************/
/* �����ı���ѯ����
��1����ȡһ���������ļ�
��2�����ļ��в�ѯһ�����ʣ����ص��ʳ��ֵĴ����Լ������е��б�չʾ���������е����ݣ�
��3��Ҫ�����һ��������ĳ�г��ֶ�Σ�����ֻ����һ�Σ��а�����������
*/
/************************************************************************/

/************************************************************************/
/*������
��1����ȡ�ļ� fstream getline�������ж�ȡ;istringstream��ȡÿһ������;
��2��ʹ��vector<string>�����ļ���set��˳���ظ������кŵļ��ϣ�map���浥�ʺ��кŵ�set�Ķ�Ӧ��ϵ
��3��ʹ��һ����TextQuery����װ�����ļ��Ĳ�����ʹ��QueryResult�������ѯ�����������ʹ��shared_ptr��������

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
