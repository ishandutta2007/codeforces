#include <bits/stdc++.h>
using namespace std;
#define mem(a, x) memset(a, x, sizeof(a))
#define fu(i, a, b) for(int i = a, I = (b) + 1; i < I; ++i)
#define fd(i, a, b) for(int i = a, I = (b) - 1; i > I; --i)
template <class T> inline void ckmax(T &a, T b) {if(a < b) a = b;}
template <class T> inline void ckmin(T &a, T b) {if(a > b) a = b;}

int t, n, k;

int main() {
	for(scanf("%d", &t); t; --t) {
		scanf("%d%d", &n, &k);
		if((n & 1) ^ (k & 1)) {
			puts("NO");
			continue;
		}
		long long m = 1ll * k * k;
		puts(n >= m ? "YES" : "NO");
	}
}