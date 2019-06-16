#ifndef HEAD_H
#define HEAD_H

void Select(Point *allpoint, Triangle &re, int kpoint);

int Calc(Triangle &tr, Point &pr);
int Start(Triangle &t, Point* allpoint, int kpoint);


void clearPoint(Point& p);
void clearTriangle(Triangle& tr);

#endif
