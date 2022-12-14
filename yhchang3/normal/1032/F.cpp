#include<bits/stdc++.h>
using namespace std;
 
const int mod = 998244353;
 
vector<int> e[300010];
int dp[300010][3];
void upd(int &x, int y){
	x += y;
	if(x >= mod)
		x -= mod;
}
 
void dfs(int u,int p){
	if(p != 0)
		e[u].erase(find(e[u].begin(), e[u].end(), p));
	dp[u][0] = dp[u][2] = 1;
	for(int v:e[u]){
		dfs(v, u);
		dp[u][0] = 1LL * dp[u][0] * (dp[v][0] + dp[v][1]) % mod;
		dp[u][2] = dp[u][2] * (2LL * dp[v][1] + dp[v][0]) % mod;
	}
	vector<int> l(e[u].size()), r(e[u].size());
	for(int i=0;i<l.size();i++)
		l[i] = i == 0 ? 1 : l[i-1] * (2LL * dp[e[u][i-1]][1] + dp[e[u][i-1]][0]) % mod;
	for(int i=(int) r.size() - 1;i>=0;i--)
		r[i] = i + 1 == r.size() ? 1 : r[i+1] * (2LL * dp[e[u][i+1]][1] + dp[e[u][i+1]][0]) % mod;
	for(int i=0;i<l.size();i++)
		upd(dp[u][1], 1LL * l[i] * r[i] % mod * dp[e[u][i]][2] % mod);
}
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i=1,u,v;i<n;i++)
		cin >> u >> v, e[u].emplace_back(v), e[v].emplace_back(u);
	dfs(1, 0);
	cout << (dp[1][0] + dp[1][1]) % mod << endl;
}