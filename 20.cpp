#include "pch.h"
#include <iostream>
#include "head.h"
#include "geometry.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	const char* inFileName = "point.txt";
	const char* outFileName = "rezult.txt";
	int kpoint = countPoints(inFileName);


	if (kpoint <= 0)
	{
		cout << "Входной файл не существует" << endl;
		return -2;
	}

	else if (kpoint < 3)
	{
		cout << "Входной файл слишком мал" << endl;
		return -3;
	}

	Point* allpoint = new Point[kpoint]; //Массив всех точек

	if (!readPoints(inFileName, allpoint, kpoint))
	{
		cout << "Неизвестная ошибка при вводе точек " << endl;
		return -3;
	}

	Triangle rezult;

	Select(allpoint, rezult, kpoint);

	if (!WriteRezult(outFileName, rezult)) {
		cout << "Неизвестная ошибка при выводе точек";
	};

	return 0;
}
