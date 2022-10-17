#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 600100;

int n, a[N], b[N], p[N], t[N << 2];
vector< int > ans;
void upd(int v, int tl, int tr, int pos, int val){
	if(tl == tr){
		t[v] = val;
		return;
	}
	int tm = (tl + tr) >> 1;
	if(pos <= tm)                     
		upd(v << 1, tl, tm, pos, val);
	else
		upd(v << 1 | 1, tm + 1, tr, pos, val);
	t[v] = max(t[v << 1], t[v << 1 | 1]);
}
int get(int v, int tl, int tr, int k){
	if(tl == tr)
		return t[v];
	int tm = (tl + tr) >> 1;
	if(k <= tm)
		return get(v << 1, tl, tm, k);
	return max(t[v << 1], get(v << 1 | 1, tm + 1, tr, k));
}
void solve(){
	for(int i = 0; i < 4 * N; i++)
		t[i] = 0;                
	for(int i = 1; i <= n; i++)
		p[b[i]] = i;
	for(int i = 1; i <= n; i++)
		if(a[i] < b[i])
			upd(1, 1, 2 * n, a[i], b[i]);
	int x = 2 * n;
	vector< int > cur;
	while(true){
		int bb = get(1, 1, 2 * n, x);
		if(bb == 0)
			break;
		cur.pb(p[bb]);
		upd(1, 1, 2 * n, a[p[bb]], 0);
	}
	if(ans.size() < cur.size())
		ans = cur;
}
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d%d", &a[i], &b[i]);
	solve();
	for(int i = 1; i <= n; i++)
		a[i] = 2 * n - a[i] + 1, b[i] = 2 *  n - b[i] + 1;
	solve();	
	printf("%d\n", ans.size());
	for(auto it : ans)
		printf("%d ", it);
	return 0;
}