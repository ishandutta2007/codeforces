#include <bits/stdc++.h>
using namespace std;

const int MAXN = 55;
const int MAXM = 1005;

int n, m, x, ai, bi, ci;

double w[MAXM], cw[MAXM];
int to[MAXM], opp[MAXM];
vector <int> G[MAXN];

bool vis[MAXN];
bool dfs(int u, double xi){
	vis[u] = true;
	if(u == n - 1)return true;

	for(int i : G[u])if(cw[i] >= xi){
		int v = to[i];
		if(vis[v])continue;

		if(dfs(v, xi)){
			cw[i] -= xi;
			cw[opp[i]] += xi;
			return true;
		}
	}
	return false;
}

bool check(double mid){
	memcpy(cw, w, sizeof w);

	int k = x;
	while(k--){
		memset(vis, false, sizeof vis);
		if(!dfs(0, mid))return false;
	}
	return true;
}
int main(){
	scanf("%d %d %d", &n, &m, &x);

	map < pair <int, int>, int> mp;
	int k = 0;

	for(int i = 0; i < m; i++){
		scanf("%d %d %d", &ai, &bi, &ci);
		ai--, bi--;

		if(mp.count({ai, bi}))w[mp[{ai, bi}]] += ci;
		else{
			w[k] += ci;

			G[ai].push_back(k);
			to[k] = bi;
			opp[k] = k + 1;
			mp[{ai, bi}] = k++;

			G[bi].push_back(k);
			to[k] = ai;
			opp[k] = k - 1;
			mp[{bi, ai}] = k++;
		}
	}

	double L = 0.0, R = 1000005;

	int itr = 60;
	while(itr--){
		double mid = (L + R) / 2;

		if(check(mid))L = mid;
		else R = mid;
	}

	printf("%.15f\n", L * x);

	return 0;
}