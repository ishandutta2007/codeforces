#include<bits/stdc++.h>
using namespace std;

int ksm(int x,int b,const int mod) {
	int res = 1;
	while(b) {
		if(b & 1)	res = 1LL * res * x % mod;
		b >>= 1;
		x = 1LL * x * x % mod;
	}
	return res;
}

struct DSU {
	vector<int> sz, p;
	DSU(int n) {
		sz.resize(n + 1), p.resize(n + 1);
		for(int i=0;i<=n;i++)
			sz[p[i] = i] = 1;
	}
	int F(int x) {
		return x == p[x] ? x : p[x] = F(p[x]);
	}
	bool U(int x,int y) {
		x = F(x), y = F(y);
		if(x == y)	return false;
		if(sz[x] < sz[y])	swap(x, y);
		sz[x] += sz[y];
		p[y] = x;
		return true;
	}
	int S(int x) {
		return sz[F(x)];
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	DSU D(n);
	for(int i=0,u,v;i<m;i++)
		cin >> u >> v, D.U(u, v);
	vector<int> sz;
	for(int i=1;i<=n;i++)
		if(D.F(i) == i) {
			sz.emplace_back(D.S(i));
		}
	if(sz.size() == 1) {
		cout << 1 % k << endl;
		return 0;
	}
	int res = ksm(n, sz.size() - 2, k);
	for(int x:sz)
		res = 1LL * x * res % k;
	cout << res << endl;
}