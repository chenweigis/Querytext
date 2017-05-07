#include "stdafx.h"
#include "QueryResult.h"


QueryResult::QueryResult()
{
}

QueryResult::~QueryResult()
{
}


void QueryResult::print(ostream &os, QueryResult qr)
{
	os << qr.m_word << " occurs " << qr.m_occur << " time" <<( (qr.m_occur > 1) ? "s" : "" )<< endl;
	auto it = qr.m_lnum.begin();
	for (size_t i=0;i<qr.m_occur;++i)
	{
		os << "(line " << *it << ") " << qr.m_svp->at(*it-1)<< endl;
		++it;
	}
}