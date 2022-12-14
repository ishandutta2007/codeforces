#include<bits/stdc++.h>
using namespace std;

const int N = 1e7;

bitset<N + 1> isc;
int p[N + 1];
int a[200010];
int dp[200010][21], b[21][200010], c[N + 1];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	for(int i=1;i<=N;i++)
		p[i] = i;
	for(int i=2;i<=N;i++)
		if(!isc[i]) {
			long long base = 1LL * i * i;
			for(long long j=base;j<=N;j+=i) {
				isc[j] = true;
				if(j % base == 0)
					p[j] = p[j / base];
			}
		}
	int T;
	cin >> T;
	while(T--) {
		int n, k;
		cin >> n >> k;
		for(int i=1;i<=n;i++)
			cin >> a[i], a[i] = p[a[i]];
		for(int z=0;z<=k;z++) {
			int l = 1, cur = 0;
			auto add = [&](int x) {
				if(c[x] != 0)
					cur++;
				c[x]++;
			};
			auto del = [&](int x) {
				c[x]--;
				if(c[x] != 0)
					cur--;
			};
			for(int i=1;i<=n;i++) {
				add(a[i]);
				while(cur > z)
					del(a[l++]);
				b[z][i] = l;
			}
			while(l <= n)
				del(a[l++]);
		}
		for(int i=1;i<=n;i++)
			for(int z=0;z<=k;z++) {
				dp[i][z] = 1e9;
				for(int y=0;y<=z;y++) {
					dp[i][z] = min(dp[i][z], 1 + dp[b[y][i] - 1][z - y]);	
				}
			}
		cout << dp[n][k] << '\n';
	}
}