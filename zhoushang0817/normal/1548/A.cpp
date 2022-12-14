#include <stdio.h>
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define puu pair<ull,ull>
#define fi first
#define se second
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define mset(a, b) memset(a, b, sizeof a)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

template <typename T>
void ckmin(T &A, T B) {A = A < B ? A : B;}
template <typename T>
void ckmax(T &A, T B) {A = A > B ? A : B;}

inline void read(int &x) {scanf("%d", &x);}
inline void print(int x) {printf("%d", x);}
inline void print(int x, char c) {printf("%d%c", x, c);}
inline void read(long long &x) {scanf("%lld", &x);}
inline void print(long long x) {printf("%lld", x);}
inline void print(long long x, char c) {printf("%lld%c", x, c);}

const int N = 2e5 + 10;

int n, m, q;

set <int> s[N];

int ans = 0;

void make(int x, int y) {
	if (x < y) swap(x, y);
	if (s[y].size() == 0) ans--;
	s[y].insert(x);
}

void Del(int x, int y) {
	if (x < y) swap(x, y);
	s[y].erase(s[y].find(x));
	if (s[y].size() == 0) ans++;
}

int main() {
	read(n), read(m), ans = n;
	for (int i = 1, a, b; i <= m; i++)
		read(a), read(b), make(a, b);
	read(q);
	while (q--) {
		int op, u, v; read(op);
		if (op == 1) read(u), read(v), make(u, v);
		else if (op == 2) read(u), read(v), Del(u, v);
		else printf("%d\n", ans);
	}
	return 0;
}