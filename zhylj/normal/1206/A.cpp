#include <bits/stdc++.h>

const int kMaxN = 942;

int n, a[kMaxN], m, b[kMaxN];
bool vis[kMaxN];

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) scanf("%d", a + i), vis[a[i]] = true;
	scanf("%d", &m);
	for(int i = 0; i < m; ++i) scanf("%d", b + i), vis[b[i]] = true;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			if(!vis[a[i] + b[j]]) {
				printf("%d %d", a[i], b[j]);
				return 0;
			}
	return 0;
}