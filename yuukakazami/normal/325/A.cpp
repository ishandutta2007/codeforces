#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
const int INF = ~0U >> 3;

int main() {
	int n;
	cin >> n;
	int xL = INF, xR = -INF, yL = INF, yR = -INF;
	int area = 0;
	for (int i = 0; i < n; ++i) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		area += (x2 - x1) * (y2 - y1);
		xL = min(xL, x1), xR = max(xR, x2);
		yL = min(yL, y1), yR = max(yR, y2);
	}

	if (area == (xR - xL) * (yR - yL) && (xR - xL) == (yR - yL))
		puts("YES");
	else
		puts("NO");
}