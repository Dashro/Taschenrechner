#pragma once
#ifndef CPROTOKOLL_H
#define CPROTOKOLL_H

#include <QtCore>
#include <QObject>



#include "ProtokollItem.h"
#include "ProtokollPrinter.h"


class CProtokoll : QObject
{

	Q_OBJECT
		
public:
	static CProtokoll* Signleton();


	void addNewProtokollPrinter(CProtokollPrinter *ProtokollPrinter);
	void addNewProtokollItem(CProtokollItem *ProtokollItem);
	


private:
	QList < CProtokollItem*>		*ProtokollItemList;

	QList < CProtokollPrinter*>		*ProtokollPrinterList;

	static CProtokoll				*Instance;
	CProtokoll();
	CProtokoll(const CProtokoll&);
};



#endif