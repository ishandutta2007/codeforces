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

const int N = 3e5 + 10;

int T, n, m, p[N], ct[N];
int fa[N];

int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);}
void con(int x, int y) {
	if (find(x) != find(y))
		fa[fa[x]] = fa[y];
}

int check(int x) {
	for (int i = 1; i <= n; i++) fa[i] = i;
	for (int i = 1; i <= n; i++) {
		int a = (p[i] + x - 1) % n + 1;
		con(a, i);
	}
	int ct = n;
	for (int i = 1; i <= n; i++)
		if (find(i) == i) ct--;
	return ct <= m;
}

int main() {
	for (scanf("%d", &T); T; T--) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
			read(p[i]), ct[i] = 0;
		for (int i = 1; i <= n; i++) {
			if (p[i] <= i) ct[i - p[i]]++;
			else ct[n - (p[i] - i)]++;
		}
		vector <int> ans;
		for (int i = 0; i < n; i++)
			if (ct[i] >= n / 3)
				if (check(i))
					ans.push_back(i);
		print((int)ans.size(), ' ');
		for (int i = 0; i < ans.size(); i++)
			print(ans[i], ' ');
		puts("");
	}
	return 0;
}