#include "ProtokollPrinter.h"


CProtokollPrinter::CProtokollPrinter(QTableView *TableView_)
{
	TableView = TableView_;

	model = new QStandardItemModel(1, 2, this);

	TableView->setModel(model);
	TableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
	TableView->horizontalHeader()->setDefaultAlignment(Qt::AlignRight);
}


CProtokollPrinter::CProtokollPrinter()
{
}

CProtokollPrinter::~CProtokollPrinter()
{
}


void CProtokollPrinter::setProtokollWidget(QTableView *TableView_)
{
	TableView = TableView_;

	TableView->setModel(model);
}

void CProtokollPrinter::PrintProtokollItem(CProtokollItem *ProtokollItem)
{
	static int rowCount = 0;

	model->setItem(rowCount, 0, new QStandardItem(ProtokollItem->claculation()));
	QStandardItem *temp = new QStandardItem(QString("\n%1").arg(ProtokollItem->result()));
	temp->setTextAlignment(Qt::AlignRight);
	model->setItem(rowCount, 1, temp);

	rowCount++;

}