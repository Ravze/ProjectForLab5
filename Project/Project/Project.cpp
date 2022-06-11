#pragma warning(disable:4996)
#include <iostream>
using namespace std;

class Building
{
private:
	double Square;
	double Cost;
public:
	void Read();
	void Init(double s, double c);
	void Display();
	double AllCost();
};

void Building::Read()
{
	cout << "Введите площадь: "; cin >> Square;
	cout << "Введите стоимость 1 кв. метра: "; cin >> Cost;
}

void Building::Init(double s, double c)
{
	Square = s;
	Cost = c;
}

void Building::Display()
{
	cout << "Площадь - " << Square << " кв.м . Стоимость 1 кв. метра - " << Cost << endl;
}

double Building::AllCost()
{
	return Square * Cost;
}

class Company
{
private:
	Building Bl1;
	Building Bl2;
	Building Bl3;
	double AddCost;
	char Name[30];
public:
	void Init(const char* v1, double s1, double c1, double s2, double c2, double s3, double c3, double ad);
	void Display();
	void Read();
	Building FindMax();
	double FullCost();
};

void Company::Init(const char* v1, double s1, double c1, double s2, double c2, double s3, double c3, double ad)
{
	Bl1.Init(s1, c1);
	Bl2.Init(s2, c2);
	Bl3.Init(s2, c2);
	AddCost = ad;
	strcpy(Name, v1);
}

void Company::Display()
{
	cout << "Предприятие " << Name << endl;
	Bl1.Display();
	Bl2.Display();
	Bl2.Display();
	cout << "Дополнительные помещения сстоимостью - " << AddCost;
}

void Company::Read()
{
	double s, c;
	cout << "Введите название предприятия: "; cin >> Name;
	cout << "Введите информацию о зданиях" << endl;
	cout << "Первое здание" << endl;
	cout << "Введите площадь: "; cin >> s;
	cout << "Введите стоимость 1 кв. метра"; cin >> c;
	Bl1.Init(s, c);
	cout << "Второе здание" << endl;
	cout << "Введите площадь: "; cin >> s;
	cout << "Введите стоимость 1 кв. метра"; cin >> c;
	Bl2.Init(s, c);
	cout << "Третье здание" << endl;
	cout << "Введите площадь: "; cin >> s;
	cout << "Введите стоимость 1 кв. метра"; cin >> c;
	Bl3.Init(s, c);
}

double Company::FullCost()
{
	double f;
	f = Bl1.AllCost() + Bl2.AllCost() + Bl3.AllCost();
	f += AddCost;
	return f;
}

Building Company::FindMax()
{
	if (Bl1.AllCost() > Bl2.AllCost())
		if (Bl1.AllCost() > Bl3.AllCost())
			return Bl1;
		else
			return Bl3;
	else
		if (Bl2.AllCost() > Bl3.AllCost())
			return Bl2;
		else
			return Bl3;
}

int main()
{
	setlocale(LC_ALL, "RUS");
	Building a, b;
	a.Init(30, 120);
	a.Display();
	Company Company1;
	char* companyName = new char[64];
	strcpy(companyName, "АльтСтрой");
	Company1.Init(companyName, 60, 20, 70, 15, 50, 40, 110);
	Company1.Display();
	cout << endl << "Максимальное по прибыли здание" << endl;
	b = Company1.FindMax();
	b.Display();
	cout << endl;
	double FullProfit;
	FullProfit = Company1.FullCost();
	cout << "Полная прибыль: " << FullProfit << endl;
	return 0;
}