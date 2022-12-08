#include<stdio.h>
#include<assert.h>
#include<vector>
#include<string.h>
#include<algorithm>
#include<memory.h>
#include<cmath>
#include<string>
#include<iostream>
#include<set>
#include<unordered_set>
#include<map>
#include<queue>
#include<functional>
#include<list>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double, double> pdd;
typedef tuple<int,int,int> t3;

const int MX = 5005;
const int MM = 1000000007;

vector<int> G[MX];
int D[MX][2];

void merge(vector<pll> &X, vector<pll> &Y){
	vector<pll> Z(X.size() + Y.size() - 1, pll(1e18, 1e18));
	for(int i = 0; i < X.size(); i++){
		for(int j = 0; j < Y.size(); j++){
			Z[i+j].first = min(X[i].first + Y[j].first, Z[i+j].first);
			Z[i+j].second = min(X[i].second + Y[j].second, Z[i+j].second);
		}
	}
	for(int i = 0; i < Z.size(); i++) Z[i].second = min(Z[i].first, Z[i].second);
	swap(X, Z);
}

void dfs(int x, vector<pll> &T){
	T.emplace_back(0, 0);
	for(int c : G[x]){
		vector<pll> X;
		dfs(c, X);
		merge(T, X);
	}
	vector<pll> X;
	X.resize(T.size()+1, pll(1e18, 1e18));
	X[0] = pll(0, 0);
	X[T.size()] = pll(T.back().first + D[x][0], T.back().second + D[x][1]);
	for(int i = 1; i < T.size(); i++){
		X[i].first = min(T[i-1].first + D[x][0], T[i].first);
	}
	for(int i = 1; i < T.size(); i++){
		X[i].second = min(T[i-1].second + D[x][1], X[i].first);
	}
	swap(X, T);
}

int main()
{
	int N, d;
	scanf("%d%d", &N, &d);
	for(int i = 1; i <= N; i++){
		int a, b, c;
		if( i == 1 ) scanf("%d%d", D[i], D[i]+1);
		else{
			scanf("%d%d%d", D[i], D[i]+1, &c);
			G[c].push_back(i);
		}
		D[i][1] = D[i][0] - D[i][1];
	}
	vector<pll> T;
	dfs(1, T);
	for(int i = 0; i < T.size(); i++){
		if( T[i].second > d) return !printf("%d\n", i-1);
	}
	printf("%d\n", N);
}