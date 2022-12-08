#include<stdio.h>
#include<assert.h>
#include<vector>
#include<string.h>
#include<algorithm>
#include<memory.h>
#include<cmath>
#include<string>
#include<iostream>
#include<set>
#include<unordered_set>
#include<map>
#include<queue>
#include<functional>
#include<list>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double, double> pdd;
typedef tuple<int,int,int> t3;

const int MX = 1<<19;
const int MM = 1000000007;

t3 D[MX];
pii U[MX];

struct node{
	int v, mx;
	ll tot;
};

struct Tree{
	node t[MX*2];
	void pushdown(int n, ll d){
		if( n >= MX ) return;
		if(t[n].v){
			t[n*2].v = t[n*2+1].v = t[n*2].mx = t[n*2+1].mx = t[n].v;
			t[n*2].tot = t[n*2+1].tot = (ll)d/2 * t[n].v;
			t[n].v = 0;
		}
	}
	void update(int l, int r, int v, int n = 1, int s = 0, int e = MX-1){
		pushdown(n, e-s+1);
		if( l <= s && e <= r ){
			t[n].v = t[n].mx = v;
			t[n].tot = (ll)(e-s+1) * v;
		}
		else if( r < s || e < l );
		else{
			int m = (s+e) / 2;
			update(l, r, v, n*2, s, m);
			update(l, r, v, n*2+1, m+1, e);
			t[n].v = 0; t[n].tot = t[n*2].tot + t[n*2+1].tot;
			t[n].mx = max(t[n*2].mx, t[n*2+1].mx);
		}
	}
	int lower_bound(int v, int n = 1, int s = 0, int e = MX-1){
		if( s == e ) return s;
		pushdown(n, e-s+1);

		int m = (s+e) / 2;
		if( t[n*2+1].mx >= v ) return lower_bound(v, n*2+1, m+1, e);
		else return lower_bound(v, n*2, s, m);
	}
	ll total(int l, int r, int n = 1, int s = 0, int e = MX-1){
		pushdown(n, e-s+1);

		if( l <= s && e <= r ) return t[n].tot;
		else if( r < s || e < l ) return 0;
		else{
			int m = (s+e) / 2;
			return total(l, r, n*2, s, m) + total(l, r, n*2+1, m+1, e);
		}
	}
} tree;

int main()
{
	int N, a, b, c, p, q, r;
	scanf("%d%d%d%d", &N, &p, &q, &r);
	for(int i = 1; i <= N; i++){
		scanf("%d%d%d", &a, &b, &c);
		D[i] = tie(a, b, c);
	}
	sort(D+1, D+N+1);
	U[N+1] = pii(1, 1);
	for(int i = N; i >= 1; i--){
		tie(a, b, c) = D[i];
		U[i].first = max(U[i+1].first, b+1);
		U[i].second = max(U[i+1].second, c+1);
	}
	ll ans = 0, prv = 0;
	for(int i = 1; i <= N+1; i++){
		int x, y, z;
		tie(x, y, z) = D[i];
		if( i == N+1 ) x = p;
		int b = U[i].first, c = U[i].second;
		int t = tree.lower_bound(c);
		//		printf("%lld\n", tree.total(b, t));
		ll cur = (ll)(q-b+1) * (r-c+1);
		if( b <= t ) cur += -tree.total(b, t) + (ll)(t-b+1) * (c-1);
		//		printf("%d %d %d %d %lld %d\n", b, c, t, q, cur, x - prv);
		ans += cur * (x - prv);
		prv = x;

		t = tree.lower_bound(z);
		if( t+1 > y ) continue;
		tree.update(t+1, y, z);
		//		printf("update %d %d %d\n", t, y, z);
	}
	printf("%lld\n", ans);
}