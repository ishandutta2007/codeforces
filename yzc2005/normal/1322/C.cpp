#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fu(i, a, b) for(int i = a, I = (b) + 1; i < I; ++i)
#define fd(i, a, b) for(int i = a, I = (b) - 1; i > I; --i)
template <class T> inline void rd(T &x) {
    x = 0; T f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') f = ch == '-' ? -1 : 1, ch = getchar();
    while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    x *= f;
} 
 
const int N = 500005;
int T, n, m, u, v;
ll a[N], ans, w[N];
set <int> g[N];
map <set <int>, ll> s; 
 
int main() {
	for(rd(T); T; --T) {
		s.clear();
		rd(n), rd(m);
		fu(i, 1, n) rd(a[i]), g[i].clear();
		fu(i, 1, m) {
			rd(u), rd(v);
			g[v].insert(u);
		}
		fu(i, 1, n) if(g[i].size()) s[g[i]] += a[i];
		ans = 0; for(map <set <int>, ll>::iterator it = s.begin(); it != s.end(); ++it) ans = __gcd(ans, it -> second);
		printf("%lld\n", ans); 
	}
	return 0;
}