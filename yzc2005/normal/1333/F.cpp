#include <bits/stdc++.h>
using namespace std;

const int N = 500005;
int cnt, pr[N], v[N], n;

inline void prework() {
	for(int i = 2; i <= n; ++i) {
		if(!v[i]) v[i] = i, pr[++cnt] = i;
		for(int j = 1; j <= cnt; ++j) {
			if(pr[j] * i > n) break;
			v[i * pr[j]] = pr[j];
			if(!(i % pr[j])) break;
		}
	}
} 

int main() {
	scanf("%d", &n);
	prework();
	for(int i = 2; i <= n; ++i) v[i] = i / v[i];
	sort(v + 2, v + n + 1);
	for(int i = 2; i <= n; ++i) printf("%d ", v[i]);
	return 0;
}