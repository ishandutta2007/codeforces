#include <bits/stdc++.h>

using namespace std;

const int N = int(3e5) + 99;

int n;
vector <int> g[N];
int d[N];
int dp[N][2];

void dfs(int v, int p){
	vector <int> d1;
	dp[v][1] = d[v] - 1;
	for(auto to : g[v]){
		if(to == p) continue;
		dfs(to, v);
		dp[v][0] = max(dp[v][0], dp[to][0]);
		if(g[to].size() > 1){
			d1.push_back(dp[to][1]);
			dp[v][1] = max(dp[v][1], d[v] + dp[to][1] - 1);	
		}
	}

	sort(d1.rbegin(), d1.rend());
	int x = d[v] + 1;
	for(int i = 0; i < 2; ++i)
		if(i < d1.size())
			x += d1[i];
    dp[v][0] = max(dp[v][0], x);
}

int main() {	
    int q;
    scanf("%d", &q);
    for(int qc = 0; qc < q; ++qc){
    	scanf("%d", &n);
    	for(int i = 0; i < n; ++i){
    	    g[i].clear();
    	    d[i] = 0;
    	    dp[i][0] = dp[i][1] = 0;
    	}
    	for(int i = 0; i < n - 1; ++i){
    		int u, v;
    		scanf("%d %d", &u, &v);
    		--u, --v;
    		g[u].push_back(v), g[v].push_back(u);
    	}
    
        if(n <= 2){
            printf("%d\n", n);
            continue;
        }
        
    	for(int v = 0; v < n; ++v){
    		//d[v] = 1;
    		//for(auto to : g[v])	
    		//	d[v] += g[to].size() == 1;
    		d[v] = g[v].size();
    	}
        
        int r = 1;
                
    	dfs(r, r);
    	printf("%d\n", dp[r][0]);
    }
	return 0;
}