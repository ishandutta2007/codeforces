#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e2 + 17, maxsq = sqrt(1e9);
const ll inf = 1e12;

int n, a[maxn], sz;
ll C, seg[maxn * 2 * maxsq];
int ceil(int n, int r){
	return (n + r - 1) / r;
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> C;
	seg[sz++] = 1;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		for(int j = 1; j * j <= a[i]; j++)
			seg[sz++] = j, seg[sz++] = ceil(a[i], j);
		C += a[i];
	}
	seg[sz++] = inf;
	sort(seg, seg + sz);
	sz = unique(seg, seg + sz) - seg;
	ll ans = 0;
	for(int i = 0; i < sz - 1; i++){
		int l = seg[i], r = seg[i + 1];
		ll cur = 0;
		for(int j = 0; j < n; j++)
			cur += ceil(a[j], l);
		ll d = C / cur;
		if(l <= d && ans < d)
			ans = d;
	}
	cout << ans << '\n';
	return 0;
}