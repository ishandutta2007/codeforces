#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

struct state{
	int u, color, k, dist;
};
bool operator <(const state& a, const state& b){
	if(a.k != b.k)return a.k > b.k;
	return a.dist > b.dist;
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	
	vector < vector < pair <int, int> > > g(n);
	
	while(m--){
		int u, v;
		scanf("%d %d", &u, &v);
		u--, v--;
		
		g[u].push_back({v, 0});
		g[v].push_back({u, 1});
	}
	
	vector < vector < vector <state> > > d(n, vector < vector <state> > (2, vector <state>(20, {-1, -1, -1, -1})));
	vector < vector <bool> > vis(n, vector <bool> (2, false));
	priority_queue <state> q;
	
	d[0][0][0] = {0, 0, 0, 0};
	q.push({0, 0, 0, 0});
	
	while(!q.empty()){
		auto[u, color, k, dist] = q.top();
		q.pop();
		
		if(k >= 19){
			if(vis[u][color])continue;
			vis[u][color] = true;
		}
		
		for(pair <int, int> e : g[u]){
			state nu = {e.first, e.second, k + (color != e.second), dist + 1};
			if(nu.k < 19){
				if(d[nu.u][nu.color][nu.k].u == -1 || d[nu.u][nu.color][nu.k].dist > nu.dist){
					d[nu.u][nu.color][nu.k] = nu;
					q.push(nu);
				}
			}else{
				if(d[nu.u][nu.color][19].u == -1 || d[nu.u][nu.color][19].k > nu.k || (d[nu.u][nu.color][19].k == nu.k && d[nu.u][nu.color][19].dist > nu.dist)){
					d[nu.u][nu.color][19] = nu;
					q.push(nu);
				}
			}
		}
	}
	
	int mn = -1;
	for(int k = 0; k < 19; k++)
	for(int color = 0; color <= 1; color++){
		if(d[n - 1][color][k].u != -1){
			int val = (1 << k) - 1 + d[n - 1][color][k].dist;
			if(mn == -1 || mn > val)mn = val;
		}
	}
	
	
	
	if(mn == -1){
		int k, dist;
		if(d[n - 1][1][19].u == -1 || (d[n - 1][0][19].u != -1 && (d[n - 1][0][19].k < d[n - 1][1][19].k ||
		 (d[n - 1][0][19].k == d[n - 1][1][19].k && d[n - 1][0][19].dist < d[n - 1][1][19].dist)))){
			k = d[n - 1][0][19].k;
			dist = d[n - 1][0][19].dist;
		}else{
			k = d[n - 1][1][19].k;
			dist = d[n - 1][1][19].dist;
		}
		
		long long res = dist;
		for(int i = 0, r = 1; i < k; i++){
			res = (res + r) % MOD;
			r = r * 2LL % MOD;
		}
		printf("%lld\n", res);
	}else printf("%d\n", mn);
	
	
	return 0;
}