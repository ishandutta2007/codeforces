#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int _, n, x, a[N];

inline bool solve() {
	bool flg = 0;
	scanf("%d%d", &n, &x); a[n + 1] = 0;
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		if(a[i] == x) flg = 1, a[i] = 1;
		else a[i] = a[i] > x;
	}
	if(!flg) return 0;
	if(n == 1) return 1;
	for(int i = 1; i <= n - 1; ++i) 
		if(a[i] && (a[i + 1] || a[i + 2])) return 1;
	return 0;
}

int main() {
	for(scanf("%d", &_); _; --_) puts(solve() ? "yes" : "no");
	return 0;
}