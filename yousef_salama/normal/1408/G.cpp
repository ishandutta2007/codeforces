#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int MAXN = 1505;

int main(){
	int n;
	scanf("%d", &n);
	
	vector < vector <int> > a(n, vector <int> (n, 0));
	vector < pair <int, pair <int, int> > > e;
	
	for(int i = 0; i < n; i++)
	for(int j = 0; j < n; j++){
		scanf("%d", &a[i][j]);
		if(i < j)e.push_back({a[i][j], {i, j}});
	}
	sort(e.begin(), e.end());
	
	vector <int> p(n), cedges(n, 0);
	vector < vector <int> > nodes(n), comp(n);
	int nnodes = n;
	
	for(int i = 0; i < n; i++){
		p[i] = i;
		nodes[i].push_back(i);
		comp[i].push_back(i);
	}
	
	vector < vector <int> > g(n);
	
	for(auto edge : e){
		int u = p[edge.second.first], v = p[edge.second.second];
		if(u == v){
			cedges[u]++;
		}else{
			if(comp[u].size() > comp[v].size())swap(u, v);
			
			cedges[v] = cedges[v] + cedges[u] + 1;
			for(int z : nodes[u])nodes[v].push_back(z);
			for(int z : comp[u]){
				p[z] = v;
				comp[v].push_back(z);
			}
			nodes[u].clear();
			comp[u].clear();
		}
		
		if(cedges[v] == (int)comp[v].size() * ((int)comp[v].size() - 1) / 2){
			g.push_back(vector <int> ());
			for(int z : nodes[v])
				g[nnodes].push_back(z);
			nodes[v].clear();
			nodes[v].push_back(nnodes);
			nnodes++;
		}
	}
	
	vector < vector <long long> > dp(nnodes);
	
	for(int i = 0; i < nnodes; i++){
		if(g[i].empty()){
			dp[i] = {0, 1};
		}else{
			dp[i] = {1};
			for(int j : g[i]){
				dp[i].resize((int)dp[i].size() + (int)dp[j].size() - 1, 0);
				for(int k = (int)dp[i].size() - 1; k >= 0; k--){
					dp[i][k] = 0;
					for(int k2 = 1; k2 < min(k + 1, (int)dp[j].size()); k2++)
						dp[i][k] = (dp[i][k] + dp[i][k - k2] * dp[j][k2]) % MOD;
				}
			}
			dp[i][1] = (dp[i][1] + 1) % MOD;
		}
	}
	
	for(int i = 1; i <= n; i++){
		if(i > 1)printf(" ");
		printf("%lld", dp[nnodes - 1][i]);
	}
	printf("\n");
	
	return 0;
}