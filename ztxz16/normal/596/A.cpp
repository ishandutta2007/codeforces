#include <map>
#include <set>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int x[16], y[16];
int n;

int main() {
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &x[i], &y[i]);
	}

	int x1 = x[1], x2 = x[1], y1 = y[1], y2 = y[1];
	for (int i = 2; i <= n; i++) {
		x1 = min(x[i], x1);
		x2 = max(x[i], x2);
		y1 = min(y[i], y1);
		y2 = max(y[i], y2);
	}

	if (x1 == x2 || y1 == y2) {
		printf("-1\n");
	} else {
		printf("%d\n", (x2 - x1) * (y2 - y1));
	}
	
	return 0;
}