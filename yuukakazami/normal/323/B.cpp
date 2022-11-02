#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

const int MAX_N = 1000 + 1;
int a[MAX_N][MAX_N], n;

int main() {
	cin >> n;
	if (n == 4) {
		puts("-1");
		return 0;
	}

	for (int i = 0; i < n; ++i) {
		a[i][(i + 1) % n] = 1;
	}

	for (int i = 0; i < n; ++i) {
		for (int j = i + 2; j < n; ++j) {
			if (i == 0 && j == n - 1)
				continue;
			if ((i - j) % 2 == 0)
				a[i][j] = 1;
			else
				a[j][i] = 1;
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			printf("%d ", a[i][j]);
		}
		puts("");
	}
	return 0;
}