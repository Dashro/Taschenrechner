#include "Grundrechenarten.h"


CGrundrechenarten::CGrundrechenarten(QString *Eingabe_)
	:Eingabe{ Eingabe_ }
{
	Eingabe = new QString;
	OperatorList = new QList < QPair< QString, QString > >;
	NumList = new QList <QString>;
}


CGrundrechenarten::~CGrundrechenarten()
{
}

//===========================================
//Methods
//===========================================

void CGrundrechenarten::setEingabe(QString *Eingabe_)
{
	Eingabe = Eingabe_;
}


QString CGrundrechenarten::Calculate_Basic()
{

	generateOperatorList(QList < QString > {"+", "-", "*", "/"} );
	generateNumList();

	while (OperatorList->size() != 0)
	{
		for (int i = 0; i < OperatorList->size(); i++)
		{
			if (OperatorList->at(i).first == QString("*"))
			{
				NumList->operator[](i) = calculate_Times(NumList->at(i), NumList->takeAt(i + 1));
				OperatorList->removeAt(i);
				break;
			}
			else if (OperatorList->at(i).first == QString("/"))
			{
				NumList->operator[](i) = calculate_Divided(NumList->at(i), NumList->takeAt(i + 1));
				OperatorList->removeAt(i);
				break;
			}
		}
		for (int i = 0; i < OperatorList->size(); i++)
		{
			if (OperatorList->at(i).first == QString("+"))
			{
				NumList->operator[](i) = calculate_Plus(NumList->at(i), NumList->takeAt(i + 1));
				OperatorList->removeAt(i);
				break;
			}
			else
			{
				NumList->operator[](i) = calculate_Minus(NumList->at(i), NumList->takeAt(i + 1));
				OperatorList->removeAt(i);
				break;
			}
		}
	}
	return NumList->takeAt(0);
}


void CGrundrechenarten::generateOperatorList(QList < QString > Operators)
{
	for (int i = 0; i < Eingabe->size(); i++)
	{
		for (int k = 0; k < Operators.size(); k++)
		{
			if (Eingabe->at(i) == Operators.at(k))
			{
				OperatorList->push_back(QPair<QString,QString>(Operators.at(k), QString("%1").arg(i)));
			}
		}
	}
}
void CGrundrechenarten::generateNumList()
{
	QString temp;

	for (int i = 0; i <= OperatorList->size(); i++)
	{
		if (i == 0)
		{
			for (int k = 0; k < OperatorList->at(i).second.toInt(); k++)
			{
				temp.push_back(Eingabe->at(k));
			}
		}
		else if (i == OperatorList->size())
		{
			for (int k = OperatorList->at(i - 1).second.toInt() + 1; k < Eingabe->size(); k++)
			{
				temp.push_back(Eingabe->at(k));
			}
		}
		else
		{
			for (int k = OperatorList->at(i - 1).second.toInt() + 1; k < OperatorList->at(i).second.toInt(); k++)
			{
				temp.push_back(Eingabe->at(k));
			}
		}
		NumList->push_back(temp);
		temp.clear();
	}

}



double CGrundrechenarten::calculate_Times(double Num1, double Num2)
{
	return Num1 * Num2;
}
double CGrundrechenarten::calculate_Divided(double Num1, double Num2)
{
	return Num1 / Num2;
}
double CGrundrechenarten::calculate_Plus(double Num1, double Num2)
{
	return Num1 + Num2;
}
double CGrundrechenarten::calculate_Minus(double Num1, double Num2)
{
	return Num1 - Num2;
}

QString CGrundrechenarten::calculate_Times(QString Num1, QString Num2)
{
	return QString("%1").arg(Num1.toDouble() * Num2.toDouble());
}
QString CGrundrechenarten::calculate_Divided(QString Num1, QString Num2)
{
	return QString("%1").arg(Num1.toDouble() / Num2.toDouble());
}
QString CGrundrechenarten::calculate_Plus(QString Num1, QString Num2)
{
	return QString("%1").arg(Num1.toDouble() + Num2.toDouble());
}
QString CGrundrechenarten::calculate_Minus(QString Num1, QString Num2)
{
	return QString("%1").arg(Num1.toDouble() - Num2.toDouble());
}