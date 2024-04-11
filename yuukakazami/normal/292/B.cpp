#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include <vector>
using namespace std;

const int MAX_N = int(1e5) + 10;

int cnt[MAX_N];
int deg[MAX_N], n, m;

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a, --b;
		deg[a]++, deg[b]++;
	}

	for (int i = 0; i < n; ++i) {
		cnt[deg[i]]++;
	}

	if (cnt[2] == n) {
		puts("ring topology");
		return 0;
	}

	if (cnt[2] == n - 2 && cnt[1] == 2) {
		puts("bus topology");
		return 0;
	}
	if (cnt[1] == n - 1) {
		puts("star topology");
		return 0;
	}
	puts("unknown topology");
}