#include <bits/stdc++.h>
using namespace std;

const int N = 9;

int n, m, cnt[1 << N], c1[1 << N], c2[1 << N], id1[1 << N], id2[1 << N];

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 1, k, a, s; i <= n; ++i) {
		cin >> k;
		s = 0;
		while(k--) cin >> a, s |= 1 << (a - 1);
		++cnt[s];
	}
	for(int i = N - 1; ~i; --i) 
		for(int s = 0; s < 1 << N; ++s)
			if(s >> i & 1) cnt[s] += cnt[s ^ (1 << i)];
	memset(c1, 0x3f, sizeof(c1));
	memset(c2, 0x3f, sizeof(c2));
	for(int i = 1, k, a, s, c; i <= m; ++i) {
		cin >> c >> k;
		s = 0;
		while(k--) cin >> a, s |= 1 << (a - 1);
		if(c < c1[s]) c2[s] = c1[s], id2[s] = id1[s], c1[s] = c, id1[s] = i;
		else if(c < c2[s]) c2[s] = c, id2[s] = i;
	}
	int ans1, ans2, mx = 0, mc = INT_MAX;
	for(int s = 0; s < 1 << N; ++s)	
		for(int t = 0; t < 1 << N; ++t) {
			if(s != t) {
				if(!id1[s] || !id1[t]) continue;
				if(mx > cnt[s | t]) continue;
				if(mx == cnt[s | t] && mc < c1[s] + c1[t]) continue;
				mx = cnt[s | t], mc = c1[s] + c1[t], ans1 = id1[s], ans2 = id1[t];
			} else {
				if(!id1[s] || !id2[s]) continue;
				if(mx > cnt[s]) continue;
				if(mx == cnt[s] && mc < c1[s] + c2[s]) continue;
				mx = cnt[s], mc = c1[s] + c2[s], ans1 = id1[s], ans2 = id2[s];
			}
		}
	cout << ans1 << " " << ans2 << endl;
	return 0;
			
}