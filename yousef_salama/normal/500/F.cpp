#include <bits/stdc++.h>
using namespace std;

const int MAXN = 4005;
const int MAXM = 8005;
const int MAXQ = 20005;

int n, p, c[MAXN], h[MAXN], t[MAXN], q, aj, bj;

vector <int> tree[4 * MAXM];
vector < pair <int, int> > evs[4 * MAXM];
int dp[30][MAXN], res[MAXQ];

void myset(int i, int L, int R, int u, int v, int j){
	if(v < L || R < u)return;
	if(u <= L && R <= v){
		tree[i].push_back(j);
		return;
	}
	
	int mid = (L + R) / 2;
	
	myset(2 * i, L, mid, u, v, j);
	myset(2 * i + 1, mid + 1, R, u, v, j);
}
void query(int i, int L, int R, int pos, int bj, int qi){
	if(L == R){
		evs[i].push_back(make_pair(bj, qi));
	}else{
		int mid = (L + R) / 2;
		
		if(pos <= mid)query(2 * i, L, mid, pos, bj, qi);
		else query(2 * i + 1, mid + 1, R, pos, bj, qi);
	}
}
void solve(int i, int L, int R, int depth){
	if(depth > 0){
		for(int j = 0; j < MAXN; j++)
			dp[depth][j] = dp[depth - 1][j];
	}
	
	for(int k : tree[i]){
		for(int j = MAXN - 1; j >= c[k]; j--)
			dp[depth][j] = max(dp[depth][j], dp[depth][j - c[k]] + h[k]);
	}
	
	for(pair <int, int> e : evs[i])
		res[e.second] = dp[depth][e.first];
	
	if(L != R){
		int mid = (L + R) / 2;
		
		solve(2 * i, L, mid, depth + 1);
		solve(2 * i + 1, mid + 1, R, depth + 1);
	}
}

int main(){
	scanf("%d %d", &n, &p);
	
	vector <int> vx;
	for(int i = 0; i < n; i++){
		scanf("%d %d %d", &c[i], &h[i], &t[i]);

		vx.push_back(t[i]);
		vx.push_back(t[i] + p);
	}
	vx.push_back(0);
	sort(vx.begin(), vx.end());
	vx.resize(unique(vx.begin(), vx.end()) - vx.begin());
	
	int m = vx.size();
	
	for(int i = 0; i < n; i++){
		int l = upper_bound(vx.begin(), vx.end(), t[i]) - vx.begin() - 1;
		int r = upper_bound(vx.begin(), vx.end(), t[i] + p - 1) - vx.begin() - 1;
		
		myset(1, 0, m - 1, l, r, i);
	}
	
	scanf("%d", &q);
	for(int i = 0; i < q; i++){
		scanf("%d %d", &aj, &bj);
		
		int pos = upper_bound(vx.begin(), vx.end(), aj) - vx.begin() - 1;
		query(1, 0, m - 1, pos, bj, i);
	}
	solve(1, 0, m - 1, 0);
	
	for(int i = 0; i < q; i++)
		printf("%d\n", res[i]);
	
	return 0;
}