#include <stdio.h>
#include <iostream>
#include <math.h>
#include <numeric>
#include <vector>
#include <map>
#include <functional>
#include <stdio.h>
#include <array>
#include <algorithm>
#include <string>
#include <assert.h>
#include <stdio.h>
#include <queue>
#include<iomanip>
using namespace std;

long long int kaijou(long long int a, long long int b) {
	long long int ans = 1;
	for (int i = 0; i < b; ++i) {
		ans *= a;
	}
	return ans;
}

const long  double pi = acos(long double(-1.0));

int main() {

	long double n, r, v;
	cin >> n >> r >> v;
	for (int i = 0; i < n; ++i) {
		long double s, f;
		cin >> s >> f;
		long double kaiten = (long double(f - s)) / (pi*r * 2.0);
		int kakuteikaiten = int(kaiten);
		long double nokorikaiten = kaiten - kakuteikaiten;

		long double amax = pi+1e-14;
		long double amin = 0-1e-14;
		long double distance;
		while (amax - amin > 7e-16) {
			long double m = (amax + amin) / 2;
			distance = r*(2.0*pi - 2 * m) + 2 * r*sin(m);
			long double k= nokorikaiten * 2 * r*pi;
			if (distance > nokorikaiten * 2 * r*pi) {
				amin = m;
			}
			else {
				amax = m;
			}
		}


		long double kakudo = 2 * pi - 2 * amax;
		long double thistime = r *kakudo / v;
		cout << setprecision(12) << (long double(kakuteikaiten) * 2.0 * pi*r) / v + thistime << endl;

	}
	return 0;
}