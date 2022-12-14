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

int T; 
char s[200010];
char s1[200010], s2[200010];

int main() {
	for (read(T); T; T--) {
		int n; read(n); scanf("%s", s + 1); int flag = 1;
		int c[2] = {0};
		for (int i = 1; i <= n; i++) c[s[i] - '0']++;
		if (c[0] % 2 == 1 || c[1] % 2 == 1) flag = 0;
		int t1 = 0, t2 = 0;
		for (int i = 1, cnt = 0; i <= n; i++) {
			if (s[i] == '1') {
				if ((++cnt) <= c[1] / 2) s1[i] = s2[i] = '(', t1++, t2++;
				else s1[i] = s2[i] = ')', t1--, t2--;
			}
			else {
				if (t1 == t2) {
					t1++, t2--;
					s1[i] = '(', s2[i] = ')'; 
				}
				else {
					t1--, t2++;
					s1[i] = ')', s2[i] = '(';
				}
			}
			if (t2 < 0 || t1 < 0) flag = 0;
		}
		if (flag) {
			puts("YES");
			for (int i = 1; i <= n; i++) printf("%c", s1[i]); puts("");
			for (int i = 1; i <= n; i++) printf("%c", s2[i]); puts("");
		}
		else puts("NO");
	}
	return 0;
}