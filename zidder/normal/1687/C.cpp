#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <functional>

using namespace std;

const int N = 200015;

bool ST[4*N];

void _sett(int x, int l, int r, int v=1){
	if (l + 1 == r) {
		ST[v] = false;
		return;
	}
	int m = (l + r) / 2;
	if (x < m) _sett(x, l, m, 2*v);
	else _sett(x, m, r, 2*v+1);
	ST[v] = ST[v*2] || ST[v*2+1];
}

int _gett(int ql, int qr, int l, int r, int v=1){
	if (ql >= r || qr <= l) return -1;
	if (!ST[v]) return -1;
	if (l + 1 == r) {
		return l;
	}
	int m = (l + r) / 2;
	int lv = _gett(ql, qr, l, m, 2*v);
	if (lv != -1) return lv;
	return _gett(ql, qr, m, r, 2*v+1);
}

void solve(int test_ind){
	int n, m;
	cin >> n >> m;
	for (int i=0;i<4*(n+5);++i) ST[i] = true;
	vector<long long> a(n), b(n);
	for (long long &i: a) scanf("%lld", &i);
	for (long long &i: b) scanf("%lld", &i);
	for (int i=0;i<n;++i) a[i] -= b[i];
	vector<long long> p(n+1);
	for (int i=0;i<n;++i) p[i+1] = p[i] + a[i];
	vector<pair<int, int> > lr(m);
	for (int i=0;i<m;++i) scanf("%d%d", &lr[i].first, &lr[i].second);
	for (int i=0;i<m;++i) lr[i].first--;
	vector<vector<int> > g(n+1);
	for (int i=0;i<m;++i) g[lr[i].first].push_back(lr[i].second);
	for (int i=0;i<m;++i) g[lr[i].second].push_back(lr[i].first);
	function<void(int)> sett = [&](int x){
		_sett(x, 0, n+1);
		p[x] = 0;
		for (int j: g[x]) {
			if (p[j] == 0) {
				if (x < j) {
					int g = _gett(x, j, 0, n+1);
					while (g!=-1) {
						sett(g);
						g = _gett(x, j, 0, n+1);
					}
				} else {
					int g = _gett(j, x, 0, n+1);
					while (g!=-1) {
						sett(g);
						g = _gett(j, x, 0, n+1);
					}
				}
			}
		}
	};
	vector<int> q;
	for (int i=0;i<=n;++i) if (p[i] == 0) q.push_back(i);
	for (int i: q) sett(i);
	for (int i=0;i<=n;++i) if (p[i]){	cout << "NO" << endl; return;}
	cout << "YES" << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}