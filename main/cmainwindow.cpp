#include "cmainwindow.h"


CMainWindow::CMainWindow(QWidget *parent)
: QMainWindow(parent)
{
	ui.setupUi(this);

	Eingabe = new QString;
	m_Grundrechenarten = new CGrundrechenarten();
	
	m_ProtokollPrinter = new CProtokollPrinter(ui.tV_Protokoll);
	CProtokoll::Signleton()->addNewProtokollPrinter(m_ProtokollPrinter);


	//========================================
	//Connects
	//========================================


	connect(ui.pBtn_0, SIGNAL(clicked()), this, SLOT(pushed_0()));
	connect(ui.pBtn_1, SIGNAL(clicked()), this, SLOT(pushed_1()));
	connect(ui.pBtn_2, SIGNAL(clicked()), this, SLOT(pushed_2()));
	connect(ui.pBtn_3, SIGNAL(clicked()), this, SLOT(pushed_3()));
	connect(ui.pBtn_4, SIGNAL(clicked()), this, SLOT(pushed_4()));
	connect(ui.pBtn_5, SIGNAL(clicked()), this, SLOT(pushed_5()));
	connect(ui.pBtn_6, SIGNAL(clicked()), this, SLOT(pushed_6()));
	connect(ui.pBtn_7, SIGNAL(clicked()), this, SLOT(pushed_7()));
	connect(ui.pBtn_8, SIGNAL(clicked()), this, SLOT(pushed_8()));
	connect(ui.pBtn_9, SIGNAL(clicked()), this, SLOT(pushed_9()));

	connect(ui.pBtn_Plus, SIGNAL(clicked()), this, SLOT(pushed_Plus()));
	connect(ui.pBtn_Minus, SIGNAL(clicked()), this, SLOT(pushed_Minus()));
	connect(ui.pBtn_Mal, SIGNAL(clicked()), this, SLOT(pushed_Mal()));
	connect(ui.pBtn_Geteilt, SIGNAL(clicked()), this, SLOT(pushed_Geteilt()));

	connect(ui.pBtn_Redo, SIGNAL(clicked()), this, SLOT(redo()));

	connect(ui.pBtn_Gleich, SIGNAL(clicked()), this, SLOT(Rechnen()));

	



}

CMainWindow::~CMainWindow()
{

}


//========================================
//Methoden
//========================================




//========================================
//Pushbutton Slots
//========================================

void CMainWindow::pushed_0()
{
	*Eingabe = ui.lE_Eingabe->text();
	Eingabe->push_back("0");
	ui.lE_Eingabe->setText(*Eingabe);
}

void CMainWindow::pushed_1()
{
	*Eingabe = ui.lE_Eingabe->text();
	Eingabe->push_back("1");
	ui.lE_Eingabe->setText(*Eingabe);
}

void CMainWindow::pushed_2()
{
	*Eingabe = ui.lE_Eingabe->text();
	Eingabe->push_back("2");
	ui.lE_Eingabe->setText(*Eingabe);
}

void CMainWindow::pushed_3()
{
	*Eingabe = ui.lE_Eingabe->text();
	Eingabe->push_back("3");
	ui.lE_Eingabe->setText(*Eingabe);
}

void CMainWindow::pushed_4()
{
	*Eingabe = ui.lE_Eingabe->text();
	Eingabe->push_back("4");
	ui.lE_Eingabe->setText(*Eingabe);
}

void CMainWindow::pushed_5()
{
	*Eingabe = ui.lE_Eingabe->text();
	Eingabe->push_back("5");
	ui.lE_Eingabe->setText(*Eingabe);
}

void CMainWindow::pushed_6()
{
	*Eingabe = ui.lE_Eingabe->text();
	Eingabe->push_back("6");
	ui.lE_Eingabe->setText(*Eingabe);
}

void CMainWindow::pushed_7()
{
	*Eingabe = ui.lE_Eingabe->text();
	Eingabe->push_back("7");
	ui.lE_Eingabe->setText(*Eingabe);
}

void CMainWindow::pushed_8()
{
	*Eingabe = ui.lE_Eingabe->text();
	Eingabe->push_back("8");
	ui.lE_Eingabe->setText(*Eingabe);
}

void CMainWindow::pushed_9()
{
	*Eingabe = ui.lE_Eingabe->text();
	Eingabe->push_back("9");
	ui.lE_Eingabe->setText(*Eingabe);
}

void CMainWindow::pushed_Plus()
{
	*Eingabe = ui.lE_Eingabe->text();
	Eingabe->push_back("+");
	ui.lE_Eingabe->setText(*Eingabe);
}

void CMainWindow::pushed_Minus()
{
	*Eingabe = ui.lE_Eingabe->text();
	Eingabe->push_back("-");
	ui.lE_Eingabe->setText(*Eingabe);
}

void CMainWindow::pushed_Mal()
{
	*Eingabe = ui.lE_Eingabe->text();
	Eingabe->push_back("*");
	ui.lE_Eingabe->setText(*Eingabe);
}

void CMainWindow::pushed_Geteilt()
{
	*Eingabe = ui.lE_Eingabe->text();
	Eingabe->push_back("/");
	ui.lE_Eingabe->setText(*Eingabe);
}



//========================================
//Sonstige Slots
//========================================

void CMainWindow::clear()
{
	*Eingabe = ui.lE_Eingabe->text();
	Eingabe->clear();
	ui.lE_Eingabe->setText(*Eingabe);
}

void CMainWindow::redo()
{	
	Eingabe->remove((Eingabe->size()-1), 1);
	ui.lE_Eingabe->setText(*Eingabe);
}

void CMainWindow::Rechnen()
{
	*Eingabe = ui.lE_Eingabe->text();
	
	QString temp = *Eingabe;

	m_Grundrechenarten->setEingabe(Eingabe);
	*Eingabe = m_Grundrechenarten->Calculate_Basic();
	
	CProtokoll::Signleton()->addNewProtokollItem(new CProtokollItem(temp, *Eingabe));

	ui.lE_Eingabe->setText(*Eingabe);
}