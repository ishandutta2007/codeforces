#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = (int)4e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;
         

vector< pii > v[N];
int n, q, a[N], T[N << 2], u[N << 2], ans[N];
pii t[N << 2];
int sum (int r)
{
	int result = 0;
	for (; r >= 0; r = (r & (r+1)) - 1)
		result += T[r];
	return result;
}

void inc (int i)
{
	for (; i < N; i = (i | (i+1)))
		T[i]++;
}

int sum (int l, int r)
{
	return sum (r) - sum (l-1);
}

void f(int v, int tl, int tr, int pos, int val){
	if(tl == tr){
		t[v].f = val;
		t[v].s = tl;
		u[v] = 0;
		return;
	}
	int tm = (tl + tr) >> 1;
	if(pos <= tm)
		f(v << 1, tl, tm, pos, val + u[v]);
	else
		f(v << 1 | 1, tm + 1, tr, pos, val + u[v]);
	t[v] = min(t[v << 1], t[v << 1 | 1]);
	t[v].f -= u[v];
}
void g(int v, int tl, int tr, int l, int r){
	if(r < tl || tr < l)
		return;
	if(l <= tl && tr <= r){
		t[v].f--;
		u[v]++;
		return;
	}	
	int tm = (tl + tr) >> 1;
	g(v << 1, tl, tm, l, r);
	g(v << 1 | 1, tm + 1, tr, l, r);
	t[v] = min(t[v << 1], t[v << 1 | 1]);
	t[v].f -= u[v];
}
int main()
{
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for(int i = 1; i <= q; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		v[x + 1].pb({n - y, i});
	}
	for(int i = 1; i <= n; i++)
		f(1, 1, n, i, inf);
	for(int i = n; i >= 1; i--){
		int need = i - a[i];
		if(need >= 0)
			f(1, 1, n, i, need);
		while(t[1].f <= 0){
			int ind = t[1].s;
			g(1, 1, n, ind, n);
			f(1, 1, n, ind, inf);
		    inc(ind);
		}
		for(auto it : v[i]){
			int r = it.f;
			int ind = it.s;
			ans[ind] = sum(i, r);	
		}
	}
	for(int i = 1; i <= q; i++)
		printf("%d\n", ans[i]);
}