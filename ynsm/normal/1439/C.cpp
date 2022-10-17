#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = 200100, LOG = 30, inf = 1e9;

int n, q, a[N], mn[N << 2], mx[N << 2], u[N << 2], S, ans;
ll t[N << 2];
void build(int v, int tl, int tr){
	if(tl == tr){
		t[v] = a[tl];
		mn[v] = mx[v] = a[tl];
		return;
	}
	int tm = (tl + tr) >> 1;
	build(v << 1, tl, tm);
	build(v << 1 | 1, tm + 1, tr);
	t[v] = t[v << 1] + t[v << 1 | 1];
	mn[v] = min(mn[v << 1], mn[v << 1 | 1]);
	mx[v] = max(mx[v << 1], mx[v << 1 | 1]);
}
void push(int v, int tl, int tr){
	if(u[v]){                            
		u[v << 1] = mn[v << 1] = mx[v << 1] = u[v];
		u[v << 1 | 1] = mn[v << 1 | 1] = mx[v << 1 | 1] = u[v];
		t[v << 1] = 1ll * u[v] * ((tl + tr) / 2 - tl + 1);
		t[v << 1 | 1] = 1ll * u[v] * (tr - (tl + tr) / 2);
		u[v] = 0;
	}
}
void upd(int v, int tl, int tr, int x, int y){
	if(x < tl || mn[v] >= y)
		return;
	if(tr <= x && mx[v] <= y){
		t[v] = 1ll * y * (tr - tl + 1);
		mn[v] = mx[v] = y;
		u[v] = y;
		return;
	}
	push(v, tl, tr);
	int tm = (tl + tr) >> 1;
	upd(v << 1, tl, tm, x, y);
	upd(v << 1 | 1, tm + 1, tr, x, y);
	t[v] = t[v << 1] + t[v << 1 | 1];
	mn[v] = min(mn[v << 1], mn[v << 1 | 1]);
	mx[v] = max(mx[v << 1], mx[v << 1 | 1]);
}
void get(int v, int tl, int tr, int x){
	if(tr < x || mn[v] > S)
		return;
	if(x <= tl && t[v] <= S){
		S -= t[v];
		ans += tr - tl + 1;
		return;
	}
	push(v, tl, tr);
	int tm = (tl + tr) >> 1;
	get(v << 1, tl, tm, x);
	get(v << 1 | 1, tm + 1, tr, x);
}
int main()
{
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);	
	build(1, 1, n);
	while(q--){
		int t, x, y;
		scanf("%d%d%d", &t, &x, &y);
		if(t == 1){
			upd(1, 1, n, x, y);
		}else{
			ans = 0;
			S = y;
			get(1, 1, n, x);		
			printf("%d\n", ans);		
		}
	}
}