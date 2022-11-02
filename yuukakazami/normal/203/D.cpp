#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
#include <cmath>
using namespace std;

double a, b, m;
double vx, vy, vz;

const double EPS = 1e-8;

double calc(double x, double vx, double lx, double rx) {
	if (fabs(vx) <= EPS)
		return 1e100;
	if (vx > 0)
		return (rx - x) / vx;
	else
		return (lx - x) / vx;
}

int main() {
	cin >> a >> b >> m;
	cin >> vx >> vy >> vz;

	double x = a / 2, y = m, z = 0;
	for (;;) {
		double tX = calc(x, vx, 0, a);
		double tY = calc(y, vy, 0, 1e100);
		double tZ = calc(z, vz, 0, b);
		double minT = min(tX, min(tY, tZ));
//		return 0;
		x += minT * vx, y += minT * vy, z += minT * vz;
//		cout << x << " " << y << " " << z << endl;
		if (fabs(y) <= EPS) {
			printf("%0.10lf %0.10lf\n", x, z);
			return 0;
		}
		bool ra = fabs(x) <= EPS || fabs(x - a) <= EPS;
		bool rb = fabs(z) <= EPS || fabs(z - b) <= EPS;
		if (ra)
			vx *= -1;
		if (rb)
			vz *= -1;
	}
	return 0;
}