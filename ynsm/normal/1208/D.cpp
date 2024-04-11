#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

ll t[N << 2], mn[N << 2], s[N];
int n, p[N];
void upd(int v, int tl, int tr, int l, int r, int k){
	if(r < tl || tr < l || l > r)
		return;
	if(l <= tl && tr <= r){
		t[v] += k;
		mn[v] += k;
		return;
	}
	int tm = (tl + tr) >> 1;
	upd(v << 1, tl, tm, l, r, k);
	upd(v << 1 | 1, tm + 1, tr, l, r, k);
	mn[v] = min(mn[v << 1], mn[v << 1 | 1]) + t[v];
}
int get(int v, int tl, int tr, ll k){
	if(tl == tr)
		return tl;
	int tm = (tl + tr) >> 1;
	if(mn[v << 1 | 1] + t[v] <= k)
		return get(v << 1 | 1, tm + 1, tr, k - t[v]);
	return get(v << 1, tl, tm, k - t[v]);
}
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%lld", &s[i]);
	for(int i = 1; i <= n; i++)
		upd(1, 1, n, i + 1, n, i);
	for(int i = n; i >= 1; i--){
		p[i] = get(1, 1, n, s[i]);
		upd(1, 1, n, p[i] + 1, n, -p[i]);
	}
	for(int i = 1; i <= n; i++)
		printf("%d ", p[i]);
	return 0;
}