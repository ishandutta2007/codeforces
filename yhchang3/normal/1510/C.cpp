#include<bits/stdc++.h>
using namespace std;
#define eb emplace_back
const int N = 100100;
vector<pair<int,int>> e[N], orig, T[N];
int pa[N], pe[N], dep[N], vis[N], deg[N];
vector<bool> bad;
void clean(int n) {
	for(int i=1;i<=n;i++)
		vector<pair<int,int>>().swap(e[i]), pa[i] = pe[i] = -1, vis[i] = false, deg[i] = 0;
}

void init(int x,int p) {
	pa[x] = p;
	dep[x] = dep[p] + 1;
	for(auto [y, id] : e[x])
		if(y != p && !bad[id]) {
			if(pa[y] == -1) {
				pe[y] = id;
				init(y, x);
			}
			else if(dep[y] < dep[x]){
				bad[id] = true;
				int z = x;
				while(z != y) {
					bad[pe[z]] = true;
					z = pa[z];
				}
			}
		}
}
void elim(int x) {
	vis[x] = 1;
	for(auto [y, id] : e[x])
		if(!vis[y]) {
			elim(y);
			if(vis[x] == 1 && deg[x] % 2 == 1 && vis[y] == 1 && deg[y] % 2 == 1) {
				bad[id] = true;
				vis[x] = vis[y] = 2;
			}
		}
}

int dfs(int x) {
	deg[x]--;
	for(auto [y, id] : e[x])
		if(!bad[id]) {
			bad[id] = true;
			deg[y]--;
			if(deg[y] % 2 == 0)
				return y;
			return dfs(y);
		}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	while(cin >> n >> m) {
		if(n == 0)	break;
		orig.clear();
		clean(n);
		while(m--) {
			int k;
			cin >> k;
			int p, q;
			cin >> p;
			for(int i=1;i<k;i++)
				cin >> q, orig.eb(p, q), e[p].eb(q, orig.size() - 1), e[q].eb(p, orig.size() - 1), p = q;
		}
		bad = vector<bool>(orig.size());
		init(1, 0);
		for(int i=1;i<=n;i++)
			vector<pair<int,int>>().swap(e[i]);
		for(int i=0;i<orig.size();i++)
			if(!bad[i]) {
				auto &[p, q] = orig[i];
				e[p].eb(q, i), e[q].eb(p, i);
				deg[p] ++, deg[q]++;
			}
		for(int i=1;i<=n;i++)
			if(!vis[i])
				elim(i);
		for(int i=1;i<=n;i++)
			vector<pair<int,int>>().swap(e[i]), deg[i] = vis[i] = 0;
		for(int i=0;i<orig.size();i++)
			if(!bad[i]) {
				auto &[p, q] = orig[i];
				e[p].eb(q, i), e[q].eb(p, i);
				deg[p] ++, deg[q]++;
			}
		vector<pair<int,int>> ans;
		for(int i=1;i<=n;i++)
			if(deg[i] & 1)
				ans.eb(i, dfs(i));
		cout << ans.size() << '\n';
		for(auto [p, q]:ans)
			cout << p << ' ' << q << '\n';
	}
}