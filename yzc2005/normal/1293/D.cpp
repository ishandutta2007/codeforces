#include <bits/stdc++.h>
using namespace std;
#define rg register
#define fu(i, a, b) for(rg int i = a, I = (b) + 1; i < I; ++i)
#define fd(i, a, b) for(rg int i = a, I = (b) - 1; i > I; --i)
#define go(u) for(rg int i = head[u], v = to[i], w = val[i]; i; i = nxt[i], v = to[i], w = val[i])
typedef pair<int, int> P;
typedef long long ll;
template <class T> inline void read(T &x) {
	x = 0; T f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') f = ch == '-' ? -1 : 1, ch = getchar();
	while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
	x *= f;
} 
template <class T> inline void print(T x) {
	if(x > 9) print(x / 10);
	putchar(x % 10 + 48);
}
template <class T> inline void ckmax(T &a, T b) {a = max(a, b);}
template <class T> inline void ckmin(T &a, T b) {a = min(a, b);}

ll xs, ys, t, x[100], y[100], ax, bx, ay, by;
inline ll myabs(ll x) {return x > 0 ? x : -x;}
inline ll dis(ll x1, ll y1, ll x2, ll y2) {return myabs(x1 - x2) + myabs(y1 - y2);}

int main() {
	read(x[1]), read(y[1]), read(ax), read(ay), read(bx), read(by);
	read(xs), read(ys), read(t);
	int cnt = 1;
	while(1) {
		++cnt;
		x[cnt] = ax * x[cnt - 1] + bx;
		y[cnt] = ay * y[cnt - 1] + by;
		if(max(x[cnt], y[cnt]) > 2e16) break;
	}
	int ans = 0;
	fu(i, 1, cnt) {
		if(t < dis(xs, ys, x[i], y[i])) continue;
		ckmax(ans, 1);
		t -= dis(xs, ys, x[i], y[i]); 
		ll tmp = t;
		fd(k, i - 1, 1) {
			tmp -= dis(x[k], y[k], x[k + 1], y[k + 1]);
			if(tmp < 0) break;
			ckmax(ans, i - k + 1);
			ll tmpp = tmp - dis(x[i], y[i], x[k], y[k]);
			fu(j, i + 1, cnt) {
				tmpp -= dis(x[j], y[j], x[j - 1], y[j - 1]);
				if(tmpp < 0) break;
				ckmax(ans, j - k + 1);
			}	
		} 
		tmp = t;
		fu(k, i + 1, cnt) {
			tmp -= dis(x[k], y[k], x[k - 1], y[k - 1]);
			if(tmp < 0) break;
			ckmax(ans, k - i + 1);
			ll tmpp = tmp - dis(x[i], y[i], x[k], y[k]);
			fd(j, i - 1, 1) {
				tmpp -= dis(x[j], y[j], x[j + 1], y[j + 1]);
				if(tmpp < 0) break;
				ckmax(ans, k - j + 1);
			}
		}
		t += dis(xs, ys, x[i], y[i]);
	}
	printf("%d\n", ans);
	return 0;
}