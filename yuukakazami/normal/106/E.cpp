#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int n;
double v[100][3];
int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> v[i][j];
		}
	}
	double c[3] = { 0 };
	double dt = 1;
	for (int iter = 0; iter < 100000; ++iter) {
		int w;
		double maxd = -1;
		for (int i = 0; i < n; ++i) {
			double d = 0;
			for (int j = 0; j < 3; ++j) {
				d += (c[j] - v[i][j]) * (c[j] - v[i][j]);
			}
			if (d > maxd) {
				maxd = d;
				w = i;
			}
		}
		for (int j = 0; j < 3; ++j) {
			c[j] += dt * (v[w][j] - c[j]);
		}
		dt *= 0.999;
	}
	for (int j = 0; j < 3; ++j) {
		printf("%0.10lf ", c[j]);
	}
	return 0;
}