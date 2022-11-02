#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

const int MAX_N = 1000 + 10;
int a[MAX_N][MAX_N], n;
int sumr[MAX_N], sumc[MAX_N];

int main() {
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", a[i] + j);
			if (i == j)
				ans ^= a[i][j];
		}
	}
	int Q;
	cin >> Q;
	for (int i = 0; i < Q; ++i) {
		int cmd, x;
		scanf("%d", &cmd);
		if (cmd == 1) {
			scanf("%d", &x);
			ans ^= 1;
		} else if (cmd == 2) {
			scanf("%d", &x);
			ans ^= 1;
		} else {
			printf("%d", ans);
		}
	}
	puts("");
}