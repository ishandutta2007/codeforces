#include <bits/stdc++.h>
using namespace std;

int t, n, m;

int main() {
	for(scanf("%d", &t); t; --t) {
		scanf("%d%d", &n, &m);
		printf("%d\n", (n * m + 1) / 2);
	}
	return 0;
}