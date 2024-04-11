#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)3e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

int n, L[N], l[N], r[N], dp[N], val[N], pref[N];
int t[N << 2];
void upd(int v, int tl, int tr, int pos, int val){
	t[v] = max(t[v], val);
	if(tl == tr)
		return;
	int tm = (tl + tr) >> 1;
	if(pos <= tm)
		upd(v << 1, tl, tm, pos, val);
	else
		upd(v << 1 | 1, tm + 1, tr, pos, val);
}
int get(int v, int tl, int tr, int l, int r){
	if(r < tl || tr < l || l > r)
		return 0;
	if(l <= tl && tr <= r)
		return t[v];
	int tm = (tl + tr) >> 1;
	return max(get(v << 1, tl, tm, l, r), get(v << 1 | 1, tm + 1, tr, l, r));
}
int main()
{
	int q;
	scanf("%d", &q);
	while(q--){
		scanf("%d", &n);
		
		for(int i = 1; i <= n; i++)
			L[i] = 0, l[i] = inf, r[i] = -inf;

		for(int i = 1; i <= n; i++){
			int x;
			scanf("%d", &x);
			l[x] = min(l[x], i);
            r[x] = max(r[x], i);
			val[i] = x;
		}
		int ans = 0;
		
		for(int i = 1, j = -1; i <= n; i++)
			if(l[i] <= r[i]){
				pref[i] = j;
				j = i;
				ans++;
			}

		for(int i = 1; i <= 4 * n; i++)
			t[i] = 0;

		for(int i = 1; i <= n; i++){
			if(l[val[i]] == i){
				dp[r[val[i]]] = 1;
				if(pref[val[i]] != -1)
                	dp[r[val[i]]] = max(dp[r[val[i]]], get(1, 1, n, pref[val[i]], pref[val[i]]) + 1);
			}
			if(r[val[i]] == i)
				upd(1, 1, n, val[i], dp[i]);
		}
		printf("%d\n", ans - t[1]);		
	}
	return 0;
}