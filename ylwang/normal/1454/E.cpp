#include<bits/stdc++.h>
#define For(i, j, k) for(int i = (j); i <= (k); i++)
using namespace std;
inline int read() {
	int x = 0; char c = ' ';
	for(; !isdigit(c); c = getchar()) ;
	for(; isdigit(c); c = getchar()) x = x * 10 - '0' + c;
	return x;
}
#define int long long
const int MAXN = 2e5 + 5;
vector < pair < int, int > > e[MAXN];
int n, isc[MAXN], c[MAXN], ev[MAXN], tot, vis[MAXN];
stack < int > s;
void dfs(int u) {
	
	if(tot) return;
	vis[u] = 1; s.push(u); 
	for(auto it : e[u]) { int v = it.first, id = it.second;
		if(ev[id]) continue; ev[id] = 1;
		
		if(vis[v]) {
			
			while(s.size()) {
				int u = s.top(); s.pop(); 
				isc[c[++tot] = u] = 1;	if(u == v) return;
			} 
		}
		dfs(v);
	}
	if(s.size()) s.pop();
}

int get(int u, int fa) {
	int ans = 1;
	for(auto it : e[u]) { int v = it.first;
		if(!isc[v] && v != fa) ans += get(v, u);	
	}
	return ans;
}
signed main() {
	int T = read();
	while(T--) {
		n = read(); 
		For(i, 1, n) e[i].clear();
		For(i, 1, n) isc[i] = vis[i] = ev[i] = 0; tot = 0; while(s.size()) s.pop();
		For(i, 1, n) {
			int u = read(), v = read();
			e[u].push_back(make_pair(v, i)), e[v].push_back(make_pair(u, i));	
			assert(e[i].size() <= n);
		}
		
		dfs(1); int t = 0, ans = n * (n - 1);
		For(i, 1, tot) {
			t = get(c[i], 0), ans -= (t - 1) * (t) / 2;	
		}
		cout << ans << endl;
	}	
	
	return 0;
}