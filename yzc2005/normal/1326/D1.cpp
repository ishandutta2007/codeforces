#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
const int P1 = 1e9 + 7, P2 = 1e9 + 9, base = 2333, N = 1e6 + 5;

int t, n, L1, R1, L2, R2;
P power[N];

inline P operator + (P p, int x) {return P((1LL * p.first * base + x) % P1, (1LL * p.second * base + x) % P2);}
inline P operator * (P p1, P p2) {return P((1LL * p1.first * p2.first) % P1, (1LL * p1.second * p2.second) % P2);}
inline P operator - (P p1, P p2) {return P((p1.first - p2.first + P1) % P1, (p1.second - p2.second + P2) % P2);}
inline P merge(P p1, P p2, int len) {return P((1LL * p1.first * power[len].first % P1 + p2.first) % P1, (1LL * p1.second * power[len].second % P2 + p2.second) % P2);}

struct HASH {
	char a[N];
	P s[N];
	inline void init() {for(int i = 1; i <= n; ++i) s[i] = s[i - 1] + a[i]; }
	inline P calc(int l, int r, bool rev) {
		if(rev) l = n - l + 1, r = n - r + 1, swap(l, r);
		return s[r] - s[l - 1] * power[r - l + 1];
	}
}s1, s2;

inline bool check(int mid) {
	for(int i = 0, l1 = 1, r1, l2, r2 = n; i <= mid; ++i) {
		r1 = i, l2 = n - (mid - i) + 1;
		if(merge(s1.calc(l1, r1, 0), s1.calc(l2, r2, 0), r2 - l2 + 1) == merge(s2.calc(l2, r2, 1), s2.calc(l1, r1, 1), r1 - l1 + 1)) {
			L1 = l1, R1 = r1, L2 = l2, R2 = r2;
			return 1;
		}
	} 
	return 0;
}

int main() {
	for(scanf("%d", &t); t; --t) {
		scanf("%s", s1.a + 1); n = strlen(s1.a + 1); 
		for(int i = 1; i <= n; ++i) s2.a[n - i + 1] = s1.a[i];
		power[0] = P(1, 1); for(int i = 1; i <= n; ++i) power[i] = power[i - 1] + 0;
		s1.init(), s2.init();
		for(int i = n; i; --i) if(check(i)) break;
		for(int i = L1; i <= R1; ++i) putchar(s1.a[i]);
		for(int i = L2; i <= R2; ++i) putchar(s1.a[i]);
		puts("");
	}
	return 0;
}