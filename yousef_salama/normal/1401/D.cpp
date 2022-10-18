#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int MAXM = 60005;
const int MOD = 1000000007;

int t, n, ui, vi, m, p[MAXM];
vector <int> g[MAXN];

vector <long long> w;
int prep(int u, int parent = -1){
	int r = 1;
	for(int v : g[u]){
		if(v == parent)continue;
		
		int c = prep(v, u);
		w.push_back(1LL * c * (n - c));
		r += c;
	}
	return r;
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 0; i < n; i++)
			g[i].clear();
			
		for(int i = 0; i < n - 1; i++){
			scanf("%d %d", &ui, &vi);
			ui--, vi--;
			
			g[ui].push_back(vi);
			g[vi].push_back(ui);
		}
		
		w.clear();
		prep(0);
	
		scanf("%d", &m);
		for(int i = 0; i < m; i++)
			scanf("%d", &p[i]);
		
		sort(w.rbegin(), w.rend());
		sort(p, p + m);
		reverse(p, p + m);
		
		for(int i = 0; i < m; i++)
			p[i] = p[i] % MOD;
		
		long long res = 0;
		for(int i = 0; i < n - 1; i++)
			res = (res + w[i]) % MOD;
		
		int j = 0;
		while(m - j > n - 1){
			res = (res + w[0] * (p[j] + MOD - 1)) % MOD;
			w[0] = w[0] * p[j] % MOD;
			j++;
		}
		
		for(int i = 0; i < n - 1 && j < m; i++){
			res = (res + w[i] * (p[j] + MOD - 1)) % MOD;
			j++;
		}
		printf("%lld\n", res);
	}
	return 0;
}