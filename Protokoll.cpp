#include "Protokoll.h"


CProtokoll::CProtokoll()
{
	ProtokollItemList = new QList < CProtokollItem* > ;
	ProtokollPrinterList = new QList < CProtokollPrinter* > ;
}

CProtokoll* CProtokoll::Instance = 0;

CProtokoll* CProtokoll::Signleton()
{
	if (!Instance)
	{
		Instance = new CProtokoll();
	}
	return Instance;
}

void CProtokoll::addNewProtokollPrinter(CProtokollPrinter *ProtokollPrinter)
{
	ProtokollPrinterList->append(ProtokollPrinter);
}

void CProtokoll::addNewProtokollItem(CProtokollItem *ProtokollItem)
{
	ProtokollItemList->append(ProtokollItem);

	for (int i = 0; i < ProtokollPrinterList->size(); i++)
	{
		ProtokollPrinterList->at(i)->PrintProtokollItem(ProtokollItem);
	}

}
