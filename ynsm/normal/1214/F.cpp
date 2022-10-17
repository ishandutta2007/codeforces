#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 1e6 + 10000, M = 1e6 + 100, K = 5e5;
const ll INF = 1e18;


int n, m, k, bal[N], cur;
pair<int, pii> v[N];
ll t[N << 2];
void upd(int v, int tl, int tr, int pos, int val){
	t[v] += val;
	if(tl == tr)
		return;
	int tm = (tl + tr) >> 1;
	if(pos <= tm)
    	upd(v << 1, tl, tm, pos, val);
	else
		upd(v << 1 | 1, tm + 1, tr, pos, val);
}
ll get(int v, int tl, int tr, int l, int r){
	if(r < tl || tr < l || l > r)
		return 0;
	if(l <= tl && tr <= r)
		return t[v];
	int tm = (tl + tr) >> 1;
	return get(v << 1, tl, tm, l, r) + get(v << 1 | 1, tm + 1, tr, l, r);
}

void add(int i){
	if(v[i].s.f == 1)
		upd(1, 1, M, bal[i] - 1 + K, -v[i].f);
	else
		upd(1, 1, M, bal[i] + K, v[i].f);
}
void del(int i){
	if(v[i].s.f == 1)
		upd(1, 1, M, bal[i] - 1 + K, v[i].f);
	else
		upd(1, 1, M, bal[i] + K, -v[i].f);
}
int main()
{
	scanf("%d%d", &m, &n);       
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		v[k++] = {x - 1, {1, i}};
		v[k++] = {x - 1 + m, {1, i}};
	}
    for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		v[k++] = {x - 1, {-1, i}};
		v[k++] = {x - 1 + m, {-1, i}};
	}
	sort(v, v + k);
	for(int i = 0; i < k; i++){
		bal[i] = v[i].s.f;
		if(i > 0)
			bal[i] += bal[i - 1];
	}
	pll ans = {INF, INF};
	for(int i = 0, j = 0; i < n + n; i++){
		while(j < i + n + n){
			add(j);
			j++;
		}
		ans = min(ans, {get(1, 1, M, cur + K, M) - get(1, 1, M, 1, cur + K - 1), i}); 
		del(i);
		cur += v[i].s.f;
	}
    printf("%lld\n", ans.f);
    vector< pii > vv;
    for(int i = ans.s, j = ans.s; vv.size() < n; i++){
    	if(v[i].s.f == -1)
    		continue;
		while(v[j].s.f == 1)
			j++;
		vv.pb({v[i].s.s, v[j].s.s});
		j++;	
    }
    sort(vv.begin(), vv.end());
    for(auto it : vv)
    	printf("%d ", it.s + 1);
	return 0;
}