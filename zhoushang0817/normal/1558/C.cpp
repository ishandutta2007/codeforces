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

int T, n, a[3000];

int main() {
	for (read(T); T; T--) {
		read(n);
		for (int i = 1; i <= n; i++)
			read(a[i]);
		vector <int> ans; int flag = 1;
		for (int i = n; i >= 3; i -= 2) {
			int s1 = 0, s2 = 0;
			for (int j = 1; j <= n; j++) {
				if (a[j] == i) s1 = j;
				if (a[j] == i - 1) s2 = j;
			}
			if (s1 % 2 != 1 || s2 % 2 != 0) flag = 0;
			if (flag == 0) break;
			if (s1 != 1) {
				reverse(a + 1, a + s1 + 1);
				ans.pb(s1);
				if (s2 < s1) s2 = s1 - s2 + 1;
				s1 = 1;
			}
			if (s2 != 2) {
				reverse(a + 1, a + s2);
				ans.pb(s2 - 1);
				s1 = s2 - 1;
			}
			if (s1 != 1) {
				reverse(a + 1, a + s2 + 2);
				ans.pb(s2 + 1);
				reverse(a + 1, a + 4);
				ans.pb(3);
			}
			reverse(a + 1, a + i + 1);
			ans.pb(i);
		}
		if (flag == 0) puts("-1");
		else {
			print((int)ans.size(), '\n');
			for (int i : ans) print(i, ' '); puts("");
		}
	}
	return 0;
}