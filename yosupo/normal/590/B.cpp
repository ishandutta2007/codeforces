#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <valarray>
#include <array>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <complex>
#include <random>

using namespace std;
typedef long long ll;

typedef double R;
typedef complex<R> P;

int main() {
	P s, g;
	R x, y;
	cin >> x >> y;
	s = P(x, y);
	cin >> x >> y;
	g = P(x, y);

	g -= s;
	s = P(0, 0);


	R v, t;
	cin >> v >> t;
	P w1, w2;
	cin >> x >> y;
	w1 = P(x, y);
	cin >> x >> y;
	w2 = P(x, y);


	if (abs(g - w1 * t) <= v * t) {
		// g -> -w1
		R a = -w1.real(), b = -w1.imag();
		x = g.real(), y = g.imag();
		R r1 = ((a*x + b*y) - sqrt(pow(a*x + b*y, 2.0) + (v*v - (a*a + b*b)) * (x*x + y*y) )) / (v*v - (a*a + b*b));
		R r2 = ((a*x + b*y) + sqrt(pow(a*x + b*y, 2.0) + (v*v - (a*a + b*b)) * (x*x + y*y) )) / (v*v - (a*a + b*b));
		printf("%.20lf\n", (0 <= r1) ? r1 : r2);
	} else {
		// g - w1*t + w2*t -> -w2
		R a = -w2.real(), b = -w2.imag();
		x = g.real() - w1.real() * t + w2.real() * t, y = g.imag() - w1.imag() * t + w2.imag() * t;
		R r1 = ((a*x + b*y) - sqrt(pow(a*x + b*y, 2.0) + (v*v - (a*a + b*b)) * (x*x + y*y) )) / (v*v - (a*a + b*b));
		R r2 = ((a*x + b*y) + sqrt(pow(a*x + b*y, 2.0) + (v*v - (a*a + b*b)) * (x*x + y*y) )) / (v*v - (a*a + b*b));
		printf("%.20lf\n", (t <= r1) ? r1 : r2);
	}
    return 0;
}