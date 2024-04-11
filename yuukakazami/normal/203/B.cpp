#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;

bool map[1100][1100] = { };

bool check(int r, int c) {
	if (r < 0 || c < 0)
		return false;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (!map[i + r][j + c])
				return false;
		}
	}
	return true;
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		map[x][y] = true;
		for (int a = 0; a < 3; ++a) {
			for (int b = 0; b < 3; ++b) {
				if (check(x - a, y - b)) {
					printf("%d\n", i + 1);
					return 0;
				}
			}
		}
	}
	puts("-1");
	return 0;
}