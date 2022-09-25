#include <stdio.h>
#include <iostream>
#include <string.h>
#include <memory.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

typedef long long li;

inline li lambda(li x, li y) {
	return x >= 0 ? x / y : floor((double)x / y);
}

int main() {
	li a, b, x1, y1, x2, y2;
	cin >> a >> b >> x1 >> y1 >> x2 >> y2;
	a *= 2;
	b *= 2;
	//li len = abs(x2 - x1) + abs(y2 - y1) - 1;
	li res = 0;
	li resa = abs(lambda((x1 + y1), a) - lambda((x2 + y2), a));
	li resb = abs(lambda((x1 - y1), b) - lambda((x2 - y2), b));
	res = resa > resb ? resa : resb;

	cout << res;
}