#pragma once
#include <QtCore>
#include <QPair>
#include <QList>
#include <QObject>

//Berechnet alle Grundrechenarten (+-*/) mit Punkt vor Strich Regel


class CGrundrechenarten : public QObject
{
	Q_OBJECT

public:
	CGrundrechenarten(QString *Eingabe_ = 0);
	~CGrundrechenarten();


	void setEingabe(QString *Eingabe_);
	QString Calculate_Basic();


private:
	QString								*Eingabe;
	QList < QPair< QString, QString > > *OperatorList;
	QList <QString>						*NumList;

	void generateOperatorList(QList < QString > Operators);
	void generateNumList();

	

	double calculate_Times(double Num1, double Num2);
	double calculate_Divided(double Num1, double Num2);
	double calculate_Plus(double Num1, double Num2);
	double calculate_Minus(double Num1, double Num2);

	QString calculate_Times(QString Num1, QString Num2);
	QString calculate_Divided(QString Num1, QString Num2);
	QString calculate_Plus(QString Num1, QString Num2);
	QString calculate_Minus(QString Num1, QString Num2);

};

