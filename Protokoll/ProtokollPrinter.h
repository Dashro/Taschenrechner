#pragma once

#include <QtWidgets>
#include <QObject>

#include "ProtokollItem.h"

class CProtokoll;

class CProtokollPrinter : public QObject
{

	Q_OBJECT


public:
	CProtokollPrinter();
	CProtokollPrinter(QTableView *TableView_);
	~CProtokollPrinter();

	void setProtokollWidget(QTableView *TableView_);
	void PrintProtokollItem(CProtokollItem *ProtokollItem);

private:
	QTableView *TableView;
	QStandardItemModel *model;

};

