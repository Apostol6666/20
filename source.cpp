#include "pch.h"
#include <iostream>
#include "head.h"
#include "geometry.h"
#include <fstream>

using namespace std;

int countPoints(const char* fileName)
{
	ifstream in(fileName);
	if (!in.is_open()) return -1;
	double x, y;
	int i;
	for (i = 0; ; i++)
	{
		in >> x >> y;
		if (in.fail()) break;
	}
	i -= 1;
	return i;
}

bool readPoints(const char* fileName, Point* allpoint, int kpoint)
{
	ifstream in(fileName);
	// Файл не открыт
	if (!in.is_open()) return -1;

	for (int i = 0; i < kpoint; i++)
	{
		in >> allpoint[i].x;
		in >> allpoint[i].y;
		if (in.fail())
			return false;
	}
	return true;
}

bool WriteRezult(const char* outFile, Triangle &rez) {

	ofstream out(outFile);
	if (!out.is_open()) return -1;

	cout << "Наибольшое количество точек содержит треугольник с вершинами :" << endl;
	for (int i = 0; i < 3; i++) {
		out << " точка "<< i << " : "<< rez.koor[i].x <<" ; " << rez.koor[i].y << endl; 
	}
	return true;
}
