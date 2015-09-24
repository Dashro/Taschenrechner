#include "ProtokollItem.h"


CProtokollItem::CProtokollItem(QPair < QString, QString > ProtokollItem_)
{
	ProtokollItem = ProtokollItem_;

}


CProtokollItem::CProtokollItem(QString calculation, QString result)
{
	ProtokollItem.first = calculation;
	ProtokollItem.second = result;
}

CProtokollItem::~CProtokollItem()
{
}


QString CProtokollItem::claculation()
{
	return ProtokollItem.first;
}


QString CProtokollItem::result()
{
	return ProtokollItem.second;
}