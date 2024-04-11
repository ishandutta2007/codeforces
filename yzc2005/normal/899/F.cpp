#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, q, l, r, p;
set <int> s[256];
set <pair<int, int> > ans;
char a[N], c;

struct FenwickTree {
	int s[N];
	inline void add(int p, int v) {
		for(; p <= n; p += p & -p) s[p] += v;
	}
} T;

inline int get(int x) {
	int res = 0;
	for(int k = 17; ~k; --k) {
		if((res | (1 << k)) > n) continue;
		if(x <= T.s[res | (1 << k)]) continue;
		x -= T.s[res |= 1 << k]; 
	}
	return res + 1;
}

int main() {
	scanf("%d%d", &n, &q);
	scanf("%s", a + 1);
	for(int i = 1; i <= n; ++i) T.add(i, 1);
	for(int i = 1; i <= n; ++i) s[(int)a[i]].insert(i);
	while(q--) {
		scanf("%d %d %c", &l, &r, &c), p = (int)c;
		l = get(l), r = get(r);
		set<int>::iterator L = lower_bound(s[p].begin(), s[p].end(), l), R = upper_bound(s[p].begin(), s[p].end(), r);
		for(set<int>::iterator it = L; it != R; ++it) T.add(*it, -1);
		s[p].erase(L, R); 
	} 
	for(int i = 0; i < 255; ++i) for(set<int>::iterator it = s[i].begin(); it != s[i].end(); ++it) ans.insert(make_pair(*it, i));
	for(set<pair<int, int> >::iterator it = ans.begin(); it != ans.end(); ++it) putchar(it -> second);
	return 0;
}