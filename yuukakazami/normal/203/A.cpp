#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;

int main() {
	int x, t, a, b, da, db;
	cin >> x >> t >> a >> b >> da >> db;
	if (x == 0) {
		puts("YES");
		return 0;
	}
	for (int i = 0; i < t; ++i) {
		for (int j = 0; j < t; ++j) {
			int c = a - da * i + b - db * j;
			if (c == x || a - da * i == x || b - db * j == x) {
				puts("YES");
				return 0;
			}
		}
	}
	puts("NO");
	return 0;
}