#include <bits/stdc++.h>
using namespace std;
#define mem(a, x) memset(a, x, sizeof(a))
#define fail puts("NO"), exit(0)
typedef long long ll;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
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

int t, n, x, y;

int main() {
	for(rd(t); t; --t) {
		rd(n), rd(x), rd(y); 
		printf("%d %d\n", max(1, min(n, x + y + 1 - n)), min(n, x + y - 1));
	}
	return 0;
}