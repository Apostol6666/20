#include "pch.h"
#include <iostream>
#include "head.h"

using namespace std;

int Calc(Triangle &tr, Point &pr) {
	int znak = 0;
	int j[3] = { 2, 3, 1 };
	for (int i = 0; i < 3; i++) {
		int k = (tr.koor[i].x - pr.x)*(tr.koor[j[i]].y - tr.koor[i].y) - (tr.koor[j[i]].x - tr.koor[i].x)*(tr.koor[i].y - pr.y);
		if (k < 0) { znak -= 1; }
		else k += 1;
	}
	if ((znak == -3) || (znak == 3)) return 1;
}


int Start(Triangle &t, Point*allpoint, int kpoint) {
	int l[5] = { kpoint - 3, kpoint - 2, kpoint - 1, 0, 1 };
	int first = 0;
	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < 3; i++) {
			t.koor[i] = allpoint[l[j]];
			j++;
		}
		for (int gg = 0; gg < kpoint - gg; gg++) {
			if (j == 0) first = Calc(t, allpoint[gg]);
			if (first < Calc(t, allpoint[gg])) {
				first = Calc(t, allpoint[gg]);
			}
		}
	}
	return first;
}

void clearPoint(Point& p)
{
	p.x = p.y = 0.0;
}

void clearTriangle(Triangle& tr)
{
	for (int i = 0; i < 3; i++)
		clearPoint(tr.koor[i]);
}


void Select(Point *allpoint, Triangle &re, int kpoint) {


	Triangle triangle;
	Point point;

	int first = 0, second = 0;

	first = Start(triangle, allpoint, kpoint);

	for (int i = 0; i < kpoint; i++) {
		triangle.koor[0] = allpoint[i];
		for (int j = i + 1; j < kpoint; j++) {
			triangle.koor[1] = allpoint[j];
			for (int g = j + 1; g < kpoint; g++) {
				triangle.koor[2] = allpoint[g];
				for (int gg = 0; g < kpoint; gg++) {
					if ((gg == i) || (gg == j) || (gg == g)) gg++;
					point = allpoint[gg];
					if (Calc(triangle, point)==1) second ++;
				}
				if (second > first) {
					first = second;
					re = triangle;
				}

			}
		}
	}
	for (int i = 0; i < 3; i++)
		clearTriangle(triangle);
}
