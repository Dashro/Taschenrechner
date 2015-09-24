#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H

#include <QStandardItemModel>
#include <qtableview.h>
#include <QtWidgets/QMainWindow>
#include <qstring.h>
#include <iostream>

#include "ui_cmainwindow.h"
#include "Grundrechenarten.h"
#include "Protokoll.h"


class CMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	CMainWindow(QWidget *parent = 0);
	~CMainWindow();



private slots:
	void pushed_0();
	void pushed_1();
	void pushed_2();
	void pushed_3();
	void pushed_4();
	void pushed_5();
	void pushed_6();
	void pushed_7();
	void pushed_8();
	void pushed_9();
	void pushed_Plus();
	void pushed_Minus();
	void pushed_Mal();
	void pushed_Geteilt();

	void clear();
	void redo();

	void Rechnen();


	

private:
	Ui::CMainWindowClass ui;

	CProtokollPrinter	*m_ProtokollPrinter;

	QString				*Eingabe;
	CGrundrechenarten	*m_Grundrechenarten;
};

#endif // CMAINWINDOW_H
