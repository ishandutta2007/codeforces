#include "bits/stdc++.h"
using namespace std;
#define f first
#define s second
#define pb push_back
#define reset(a,b) memset(a,b,sizeof a);
#define ALL(x) x.begin(),x.end()
 
template <typename T>
void cetak(T t){cout << t << ')' << endl;}
template <typename T, typename... V>
void cetak(T t, V... v) {cout << t; if (sizeof...(v)) cerr << ", "; cetak(v...);}
 
#define debug(x...) cout<< '(' << #x << ") = ("; cetak(x) 
#define sz(x) (int)(x.size())
#define lt(x) (int)(x.length())

const int MOD = 1e9 + 7;
const int mx = 1e5 + 10;

struct tree{
	int n;
	vector<vector<int>> P;
	vector<vector<int>> g;
	vector<int> level;
	tree(int N){
		n = N;
		P.resize(n, vector<int>(13, 0));
		g.resize(n);
		level.resize(n, 0);
		for(int i = 1; i < n; i++){
			cin >> P[i][0];
			P[i][0] -= 1;
			g[P[i][0]].pb(i);
		}
		dfs(0);
		for(int i = 1; i < 13; i++) for(int j = 0; j < n; j++)
			P[j][i] = P[P[j][i - 1]][i - 1];
	}
	void dfs(int now){
		for(int i : g[now]){
			level[i] = level[now] + 1;
			dfs(i);
		}
	}
	int findLCA(int p, int q){
		if(level[p] > level[q]) swap(p, q);
		for(int i = 12; i >= 0; i--){
			if(level[q] - level[p] >= (1 << i)) q = P[q][i];
		}
		if(p == q) return p;
		for(int i = 12; i >= 0; i--){
			if(P[p][i] != P[q][i]){
				q = P[q][i];
				p = P[p][i];
			}
		}
		return P[p][0];
	}
};

vector<int> x, y;
int dep[1003][1003][2], n;
int dp(int now, int tadi, int cur, tree &A, tree &B){
	if(now == n) return 0;
	int &ret = dep[now][tadi][cur];
	if(ret != -1) return ret;
	ret = 0;
	if(now == 0){
		ret = dp(now + 1, n, 0, A, B) + A.level[x[now]];
		ret = min(ret, dp(now + 1, n, 1, A, B) + B.level[y[now]]);
		return ret;
	}
	if(cur == 0){
		// tadi ngambil A
		// mau ngambil A lagi
		int par = A.findLCA(x[now - 1], x[now]);
		// if(now == 1 && tadi == 4 && cur == 0){
		// 	debug(par, A.level[x[now]], A.level[par], x[now], x[now - 1], par);
		// }
		ret = dp(now + 1, tadi, 0, A, B) + A.level[x[now]] - A.level[par];

		// mau ngambil B
		if(tadi == n){
			ret = min(ret, dp(now + 1, now - 1, 1, A, B) + B.level[y[now]]);
		}
		else{
			par = B.findLCA(y[tadi], y[now]);
			ret = min(ret, dp(now + 1, now - 1, 1, A, B) + B.level[y[now]] - B.level[par]);
		}
	}
	else{
		// tadi ngambil B
		// mau ngambil B lagi
		int par = B.findLCA(y[now - 1], y[now]);
		ret = dp(now + 1, tadi, 1, A, B) + B.level[y[now]] - B.level[par];

		// mau ngambil A
		if(tadi == n){
			ret = min(ret, dp(now + 1, now - 1, 0, A, B) + A.level[x[now]]);
		}
		else{
			par = A.findLCA(x[tadi], x[now]);
			ret = min(ret, dp(now + 1, now - 1, 0, A, B) + A.level[x[now]] - A.level[par]);
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a;
	cin >> n;
	cin >> a;
	tree A(a);
	x.resize(n), y.resize(n);
	for(int i = 0; i < n; i++){
		cin >> x[i];
		x[i] -= 1;
	}
	int b;
	cin >> b;
	tree B(b);
	for(int i = 0; i < n; i++){
		cin >> y[i];
		y[i] -= 1;
	}
	reset(dep, -1);
	cout << a - 1 + b - 1 - dp(0, n, 0, A, B) << endl;
}