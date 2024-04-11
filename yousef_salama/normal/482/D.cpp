#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int MOD = 1000000007;

int n, pi;
vector <int> G[MAXN];

pair <int, int> solve(int u){
	pair <int, int> r = {0, 2};

	int x = 1;
	pair <int, int> y = {0, 1};

	for(int v : G[u]){
		pair <int, int> q = solve(v);
		r = {(1LL * r.first * (1 + q.first) + 1LL * r.second * q.second) % MOD,
			 (1LL * r.second * (1 + q.first) + 1LL * r.first * q.second) % MOD};

		x = (1LL * x * (1 + q.first)) % MOD;
		y = {(y.first + 1LL * y.second * q.second) % MOD,
			 (y.second + 1LL * y.first * q.second) % MOD};
	}

	r = {(r.first - y.first + MOD) % MOD, (r.second - x + MOD) % MOD};
	return r;
}
int main(){
	scanf("%d", &n);
	for(int i = 1; i < n; i++){
		scanf("%d", &pi);
		G[pi - 1].push_back(i);
	}

	pair <int, int> r = solve(0);
	printf("%d\n", (r.first + r.second) % MOD);

	return 0;
}