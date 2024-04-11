#include <bits/stdc++.h>
using namespace std;
#define rg register
#define fu(i, a, b) for(rg int i = a, I = (b) + 1; i < I; ++i)
#define fd(i, a, b) for(rg int i = a, I = (b) - 1; i > I; --i)
#define go(u) for(rg int i = head[u], v = to[i], w = val[i]; i; i = nxt[i], v = to[i], w = val[i])
typedef pair<int, int> P;
typedef long long ll;
template <class T>
inline void read(T &x) {
	x = 0; T f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') f = ch == '-' ? -1 : 1, ch = getchar();
	while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
	x *= f;
} 
template <class T>
inline void print(T x) {
	if(x > 9) print(x / 10);
	putchar(x % 10 + 48);
}
template <class T> 
inline void ckmax(T &a, T b) {a = max(a, b);}
template <class T>
inline void ckmin(T &a, T b) {a = min(a, b);}
 
const int N = 100005;
int n, q, x, y, cnt;
bool a[2][N];
 
int main() {
	read(n), read(q);
	fu(i, 1, q) {
		read(x), read(y); x--;
		a[x][y] ^= 1;
		if(a[x][y] == 1) {
			cnt += a[x ^ 1][y - 1] + a[x ^ 1][y] + a[x ^ 1][y + 1];
			puts(cnt ? "no" : "yes");
		}
		else {
			cnt -= a[x ^ 1][y - 1] + a[x ^ 1][y] + a[x ^ 1][y + 1];
			puts(cnt ? "no" : "yes");
		}
	}
	return 0;
}