#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
void add(int &a, int b) {(a += b) >= mod && (a -= mod);}
int Add(int a, int b) {return add(a, b), a;}
void mul(int &a, int b) {a = 1ll * a * b % mod;}
int Mul(int a, int b) {return 1ll * a * b % mod;}
const int N = 5005;
int n, m, s[N], c[N], f[N], g[N], pos[N];
vector<int> a[N], l, r, L, R;
bool chosen[N];

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) cin >> c[i];
	for(int i = 1, f, h; i <= m; ++i) {
		cin >> f >> h;
		a[f].push_back(h);
	}
	chosen[0] = 1; for(int i = 0; i <= n; ++i) f[i] = 1;
	for(int t = 1; t <= n; ++t) {
		if(a[t].empty()) continue;
		int m = a[t].size(); l.resize(m), r.resize(m);
		for(int i = 1; i <= n; ++i) s[i] = (c[i] == t);
		for(int i = 1; i <= n; ++i) s[i] += s[i - 1];
		for(int i = s[n] + 1; i <= n; ++i) pos[i] = n + 1;
		for(int i = n; i; --i) pos[s[i]] = i;
		for(int i = 0; i < m; ++i) l[i] = pos[a[t][i]];
		for(int i = 1; i <= n; ++i) s[i] = (c[i] == t);
		for(int i = n; i; --i) s[i] += s[i + 1];
		for(int i = s[1] + 1; i <= n; ++i) pos[i] = 0;
		for(int i = 1; i <= n; ++i) pos[s[i]] = i;
		for(int i = 0; i < m; ++i) r[i] = pos[a[t][i]];
		for(int i = 0; i <= n; ++i) {
			bool flag = 0, delta;
			L.clear(), R.clear();
			for(int j = 0; j < m; ++j) {
				if(l[j] == i) flag = 1, delta = r[j] > i;
				if(l[j] <= i) L.push_back(j);
				if(r[j] > i) R.push_back(j);
			}	
			if(L.empty() && R.empty()) continue;
			if(flag) {
				chosen[i] = 1;
				int ways = R.size() - delta;
				if(ways) g[i] += 2, mul(f[i], ways);
				else g[i] += 1;
			} else {
				int ways = L.size() * R.size();
				for(auto j : L) ways -= (r[j] > i);
				if(ways) g[i] += 2, mul(f[i], ways);
				else g[i] += 1, mul(f[i], L.size() + R.size());
			}
		}
	}
	int x = *max_element(g, g + n + 1), y = 0;
	for(int i = 0; i <= n; ++i) if(chosen[i] && g[i] == x) add(y, f[i]);
	cout << x << ' ' << y << '\n';
	return 0; 
}