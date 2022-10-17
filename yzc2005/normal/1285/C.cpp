#include <bits/stdc++.h>
using namespace std;
#define rg register
#define fu(i, a, b) for(rg int i = a; i <= b; ++i)
#define fd(i, a, b) for(rg int i = a; i >= b; --i)
#define go(u) for(rg int i = head[u], v = to[i]; i; i = nxt[i], v = to[i])
typedef long long ll;
const int N = 1000010;

ll n, nn, p[N], q[N], a, b, ans = 1e18;
int cnt;

inline ll pow(ll x, ll y) {ll ret = 1; fu(i, 1, y) ret *= x; return ret;}

void dfs(int pos, ll x, ll y) {
	if(pos == cnt + 1) {
		if(max(x, y) < ans) ans = max(x, y), a = x, b = y;
		return;
	}
	dfs(pos + 1, x * pow(p[pos], q[pos]), y);
	dfs(pos + 1, x, y * pow(p[pos], q[pos]));
}

int main() {
	scanf("%lld", &n); nn = n;
	for(ll i = 2; i * i <= nn; ++i) {
		if(n % i == 0) {
			p[++cnt] = i;
			while(n % i == 0) q[cnt]++, n /= i;
		}	 
	}
	if(n > 1) p[++cnt] = n, q[cnt] = 1;
	dfs(1, 1, 1);
	printf("%lld %lld\n", a, b);
}