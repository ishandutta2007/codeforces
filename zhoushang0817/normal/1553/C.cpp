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

int T, ans = 10; char s[12];
int t[12];

int check(int x) {
	if (x == 0) return 0;
	int c[2] = {0}, lst[2] = {0};
	for (int i = 1; i <= x; i++)
		c[i % 2] += t[i];
	for (int i = x + 1; i <= 10; i++)
		lst[i % 2]++;
	if (c[1] > c[0] + lst[0] || c[0] > c[1] + lst[1])
		return ans = min(ans, x), 1;
	return 0;
}

void dfs(int x) {
	if (check(x - 1)) return;
	if (x == 11) return;
	if (s[x] == '1') {
		t[x] = 1;
		dfs(x + 1);
	}
	else if (s[x] == '0') {
		t[x] = 0;
		dfs(x + 1);
	}
	else {
		t[x] = 1;
		dfs(x + 1);
		t[x] = 0;
		dfs(x + 1);
	}
}

int main() {
	for (scanf("%d", &T); T; T--) {
		scanf("%s", s + 1);
		ans = 10, dfs(1);
		printf("%d\n", ans);
	}
	return 0;
}