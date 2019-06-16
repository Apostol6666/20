#ifndef HEAD_H
#define HEAD_H

struct Point {
	double x, y;
};

struct Triangle {
	Point koor[3];
};

int countPoints(const char* fileName);
bool readPoints(const char* fileName, Point* allpoints, int maxPoint);
bool WriteRezult(const char* outFile, Triangle &rez);

#endif
