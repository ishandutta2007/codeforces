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
 
ll exgcd(ll a , ll b , ll &x , ll &y) {
	if(b == 0) return x = 1 , y = 0, a;
	ll g = exgcd(b , a % b , y , x);
	return y -= (a / b) * x, g;
}
 
ll gcd(ll x ,  ll y) {
	if(y == 0) return x;
	return gcd(y , x % y);
}
 
const int N = 500010;
 
int n, m;
ll k;
int a[2][N], p[N], t[N];
map <int, int> f;
ll len;
 
int check(ll mid) {
	ll ret = 0;
	for (int i = 1; i <= n; i++) {
		ret += mid / len * (len / n - (t[i] != -1));
		ll tmp = mid % len - i;
		if (tmp < 0) continue;
		ret += 1 + tmp / n;
		if (tmp / n >= t[i] && t[i] != -1) ret--;
	}
	return ret >= k;
}
 
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[0][i];
	for (int i = 1; i <= m; i++)
		cin >> a[1][i];
	if (n < m) swap(n, m), swap(a[0], a[1]);
	for (int i = 1; i <= m; i++) f[a[1][i]] = i;
	for (int i = 1; i <= n; i++) p[i] = f[a[0][i]], t[i] = -1;
	for (int i = 1; i <= n; i++) {
		ll x, y;
		if (!p[i]) continue;
		ll d = ((p[i] - i) + m) % m, g = exgcd(n - m, m, x, y);
		if (d % g != 0) continue;
		x *= d / g, x = (x % (m/g) + (m/g)) % (m/g);
		t[i] = x;
	}
	len = 1ll * n * m / gcd(n, m);
	ll l = 0, r = 1e18 + 1;
	
	while (l < r) {
		ll mid = (l + r) >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1; 
	}
	cout << l << endl;
	 
	return 0;
}