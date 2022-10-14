#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 100005;
const int MAXM = 100005;
const int LN = 18;
 
int N, M, K, cur, A[MAXN], LVL[MAXN], DP[LN][MAXN], TP[MAXN];
int BL[MAXN << 1], ID[MAXN << 1], VAL[2][MAXN];
ll ANS[MAXM];
int d[MAXN], l[MAXN], r[MAXN];
bool VIS[MAXN];
vector < int > adjList[MAXN];
 
struct query{
	int id, l, r, lc;
	bool operator < (const query& rhs){
		return (BL[l] == BL[rhs.l]) ? (r < rhs.r) : (BL[l] < BL[rhs.l]);
	}
}Q[MAXM];
 
// Set up Stuff
void dfs(int u, int par){
	l[u] = ++cur; 
	ID[cur] = u;
	for (int i = 1; i < LN; i++) DP[i][u] = DP[i - 1][DP[i - 1][u]];
	for (int i = 0; i < adjList[u].size(); i++){
		int v = adjList[u][i];
		if (v == par) continue;
		LVL[v] = LVL[u] + 1;
		DP[0][v] = u;
		dfs(v, u);
	}
	r[u] = ++cur; ID[cur] = u;
}
 
// Function returns lca of (u) and (v)
inline int lca(int u, int v){
	if (LVL[u] > LVL[v]) swap(u, v);
	for (int i = LN - 1; i >= 0; i--)
		if (LVL[v] - (1 << i) >= LVL[u]) v = DP[i][v];
	if (u == v) return u;
	for (int i = LN - 1; i >= 0; i--){
		if (DP[i][u] != DP[i][v]){
			u = DP[i][u];
			v = DP[i][v];
		}
	}
	return DP[0][u];
}
 
inline void check(int x, ll& res){
	// If (x) occurs twice, then don't consider it's value 
	if (VIS[x]) {
    --VAL[TP[x]][A[x]];
    res -= VAL[1-TP[x]][A[x]]; 
  }
	else {
    res += VAL[1-TP[x]][A[x]]; 
    ++VAL[TP[x]][A[x]];
  }
	VIS[x] ^= 1;
}
 
void compute(){
	
	// Perform standard Mo's Algorithm
	int curL = Q[0].l, curR = Q[0].l - 1;
  ll res = 0;
	
	for (int i = 0; i < M; i++){
		
		while (curL < Q[i].l) check(ID[curL++], res);
		while (curL > Q[i].l) check(ID[--curL], res);
		while (curR < Q[i].r) check(ID[++curR], res);
		while (curR > Q[i].r) check(ID[curR--], res);
		
		int u = ID[curL], v = ID[curR];
		
		// Case 2
		if (Q[i].lc != u and Q[i].lc != v) check(Q[i].lc, res);
		
		ANS[Q[i].id] = res;
		
		if (Q[i].lc != u and Q[i].lc != v) check(Q[i].lc, res);
	}
 
	for (int i = 0; i < M; i++) printf("%lld\n", ANS[i]);
}
 
int main(){
 
	int u, v, x;
	
	while (scanf("%d", &N) != EOF){
		
		// Cleanup
		cur = 0;
		memset(VIS, 0, sizeof(VIS));
		memset(VAL, 0, sizeof(VAL));
		for (int i = 1; i <= N; i++) adjList[i].clear();
		
		// Inputting Values
		for (int i = 1; i <= N; i++) scanf("%d", &TP[i]);
		for (int i = 1; i <= N; i++) scanf("%d", &A[i]);
		memcpy(d + 1, A + 1, sizeof(int) * N);
		
		// Compressing Coordinates
		sort(d + 1, d + N + 1);
		K = unique(d + 1, d + N + 1) - d - 1;
		for (int i = 1; i <= N; i++) A[i] = lower_bound(d + 1, d + K + 1, A[i]) - d;
		
		// Inputting Tree
		for (int i = 1; i < N; i++){
			scanf("%d %d", &u, &v);
			adjList[u].push_back(v);
			adjList[v].push_back(u);
		}

    scanf("%d", &M);
		
		// Preprocess
		DP[0][1] = 1;
		dfs(1, -1);
		int size = sqrt(cur);
		
		for (int i = 1; i <= cur; i++) BL[i] = (i - 1) / size + 1;
		
		for (int i = 0; i < M; i++){
			scanf("%d %d", &u, &v);
			Q[i].lc = lca(u, v);
			if (l[u] > l[v]) swap(u, v);
			if (Q[i].lc == u) Q[i].l = l[u], Q[i].r = l[v];
			else Q[i].l = r[u], Q[i].r = l[v];
			Q[i].id = i;
		}
 
		sort(Q, Q + M);
		compute();
	}
}