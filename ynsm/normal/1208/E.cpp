#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)1e6 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

int n, q, k, a[N], p[N];
ll ans;
vector< pair<pii, pii> > upd, del;
set< pii > st[N];
bool cmp(int i, int j){
	return a[i] > a[j];
}
void ad(int j, pii val){
	if(!st[j].empty())
		ans += st[j].begin() -> f;
	st[j].insert(val);
	ans -= st[j].begin() -> f;	
}
void de(int j, pii val){
	ans += st[j].begin() -> f;
	st[j].erase(val);
	if(!st[j].empty())
		ans -= st[j].begin() -> f;	
}

int main()
{
	scanf("%d%d", &q, &n);
	for(int j = 1; j <= q; j++){
		scanf("%d", &k);
		for(int i = 1; i <= k; i++){
			scanf("%d", &a[i]);
			p[i] = i;
		}
		sort(p + 1, p + 1 + k, cmp);
		if(k < n){                
        	upd.pb({{1, j}, {0, 0}});
        	del.pb({{n - k, j}, {0, 0}});
        	
        	upd.pb({{k + 1, j}, {0, k + 1}});
        	del.pb({{n, j}, {0, k + 1}});
        }
		for(int ii = 1; ii <= k; ii++){
			int i = p[ii];       
			upd.pb({{i, j}, {-a[i], i}});
			del.pb({{n - k + i, j}, {-a[i], i}});
		}
	}
	sort(upd.begin(), upd.end());
	sort(del.begin(), del.end());
	for(int i = 1, j = 0, q = 0; i <= n; i++){
		while(j < upd.size() && upd[j].f.f == i){
			ad(upd[j].f.s, upd[j].s);
			j++;
		}		
		printf("%lld ", ans);
		while(q < del.size() && del[q].f.f == i){
			de(del[q].f.s, del[q].s);
			q++;
		}		
	}
	return 0;
}