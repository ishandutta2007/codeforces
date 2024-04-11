#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<double, int> pdi;

const int L = 1<<16;
const int MX = 55;

int N, K;
int G[MX][MX];
int T[MX][MX];
int cnt[MX];
vector<int> GG[MX];

int dfs(int x, int p, vector<int> &L){
	for(int c : GG[x]){
		if( c == p ) continue;
		cnt[x] += dfs(c, x, L);
	}
	if( GG[x].size() == 1 ) L.push_back(x);
	return cnt[x];
}

int main()
{
	scanf("%d", &N);
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++) G[i][j] = 1e9;
		G[i][i] = 0;
	}
	for(int i = 1; i < N; i++){
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		GG[a].push_back(b);
		GG[b].push_back(a);
		G[a][b] = G[b][a] = c;
	}
	for(int k = 1; k <= N; k++){
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= N; j++){
				G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
			}
		}
	}

	vector<int> leaf;
	for(int i = 1; i <= N; i++) if( GG[i].size() == 1 ) leaf.push_back(i);

	int K, S;
	scanf("%d%d", &S, &K);
	for(int i = 1; i <= K; i++){
		int a;
		scanf("%d", &a);
		cnt[a]++;
	}
	for(int k = 1; k <= K; k++){
		for(int i = 1; i <= N; i++){
			priority_queue<pii> Q;
			int v[MX] = {};
			for(int c : leaf){
				if( i != c ) Q.emplace(T[k-1][c] + G[i][c], c), v[c] = 1;
			}
			pii p;
			for(int t = 1; t <= k; t++){
				p = Q.top(); Q.pop();
				int x = p.second, &w = v[x];
				w++;
				if( k >= w ) Q.emplace(T[k-w][x] + G[i][x], x);
			}
			T[k][i] = p.first;
		}
	}

	int ans = 1e9;
	for(int r : GG[S]){
		vector<int> L;
		int q = dfs(r, S, L);
		if( q == 0 ) continue;
		
		priority_queue<pii> Q;
		int v[MX] = {};
		for(int c : L) Q.emplace(T[K-1][c] + G[S][c], c), v[c] = 1;
		pii p;
		for(int t = 1; t <= q; t++){
			p = Q.top(); Q.pop();
			int x = p.second, &w = v[x];
			w++;
			if( K >= w ) Q.emplace(T[K-w][x] + G[S][x], x);
		}
		ans = min(ans, p.first);
	}
	printf("%d\n", ans);
}