#pragma once
#include <QtCore>
#include <QObject>

class CProtokoll;

class CProtokollItem : public QObject
{

	Q_OBJECT


public:
	CProtokollItem(QPair < QString, QString > ProtokollItem_);
	CProtokollItem(QString claculation, QString result);
	~CProtokollItem();

	QString claculation();
	QString result();

private:
	QPair < QString, QString> ProtokollItem;
};

