#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 200500;

int n, a[N], b[N], p[N], t[N << 2];
ll ans;
vector< int > v;
map<int, int> mt;
bool cmp(int i, int j){
	return b[i] > b[j] || (b[i] == b[j] && a[i] < a[j]);
}
void upd(int v, int tl, int tr, int pos){
	if(tl == tr){
		t[v] = 1;
		return;
	}
	int tm = (tl + tr) >> 1;
	if(pos <= tm)
    	upd(v << 1, tl, tm, pos);
	else
		upd(v << 1 | 1, tm + 1, tr, pos);
	t[v] = t[v << 1] + t[v << 1 | 1];
}
int get(int v, int tl, int tr, int l, int r){
	if(r < tl || tr < l || l > r) 
		return 0;
	if(l <= tl && tr <= r)
		return t[v];
	int tm = (tl + tr) >> 1;
	return get(v << 1, tl, tm, l, r) + get(v << 1 | 1, tm + 1, tr, l, r);
}
int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d%d", &a[i], &b[i]);
		p[i] = i;
		v.pb(a[i]);
	}
	sort(v.begin(), v.end());
	for(int i = 0; i < n; i++)
		mt[v[i]] = i + 1;
	sort(p, p + n, cmp);
	for(int i = 0; i < n; i++)
		a[i] = mt[a[i]];
	for(int i = 0, j = 0; i < n; i = j){
		while(j < n && b[p[i]] == b[p[j]])
			j++;
		for(int q = i; q < j; q++)
			upd(1, 1, n, a[p[q]]);
		for(int q = i; q < j; q++){
			int x, y;
			if(q == i)                       
				x = get(1, 1, n, 1, a[p[q]]);
			else
				x = get(1, 1, n, a[p[q - 1]] + 1, a[p[q]]);
			y = get(1, 1, n, a[p[q]], n);
            ans += 1ll * x * y;
		}
	}
	printf("%lld", ans);
	return 0;
}