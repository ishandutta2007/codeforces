#include <bits/stdc++.h>
using namespace std;
#define mem(a, x) memset(a, x, sizeof(a))
#define fu(i, a, b) for(int i = a, I = (b) + 1; i < I; ++i)
#define fd(i, a, b) for(int i = a, I = (b) - 1; i > I; --i)
template <class T> inline void rd(T &x) {
    x = 0; T f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') f = ch == '-' ? -1 : 1, ch = getchar();
    while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    x *= f;
} 
template <class T> inline void ckmax(T &a, T b) {if(a < b) a = b;}
template <class T> inline void ckmin(T &a, T b) {if(a > b) a = b;}

int t, n, k, c, f[100];
long long a;

int main() {
	for(rd(t); t; --t) {
		rd(n), rd(k);
		mem(f, 0);
		fu(i, 1, n) {
			c = 0, rd(a);
			while(a) f[++c] += a % k, a /= k;
		}
		bool flg = 1;
		fu(i, 1, 99) if(f[i] > 1) {
			flg = 0;
			puts("NO");
			break;
		}
		if(flg) puts("YES");
	}
	return 0;
}