#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

int test, d;

int main() {
	scanf("%d", &test);
	while (test--) {
		scanf("%d", &d);
		double delta = d * d - 4 * d;
		if (delta < -1e-9) {
			printf("N\n");
			continue;
		}
		
		if (delta < 1e-9) {
			double a = d * 0.5;
			double b = d - a;
			if (a > -1e-9 && b > -1e-9) {
				printf("Y %.10f %.10f\n", fabs(a), fabs(b));
			} else {
				printf("N\n");
			}
		} else {
			delta = sqrt(delta);
			double a = (d + delta) * 0.5;
			double b = d - a;
			if (a > -1e-9 && b > -1e-9) {
				printf("Y %.10f %.10f\n", fabs(a), fabs(b));
			} else {
				double a = (d - delta) * 0.5;
				double b = d - a;
				if (a > -1e-9 && b > -1e-9) {
					printf("Y %.10f %.10f\n", fabs(a), fabs(b));
				} else {
					printf("N\n");
				}
			}
		}
	}
	
	return 0;
}