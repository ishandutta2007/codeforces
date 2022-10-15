#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <functional>

using namespace std;

void solve(int test_ind){
	int n, m;
	cin >> n >> m;
	vector<vector<int> > par(30, vector<int>(n, -1));
	for (int i=0;i<30;++i) for (int j=0;j<n;++j) par[i][j] = j;
	vector<vector<bool>> zero(30, vector<bool>(n, false));
	vector<vector<int> > sz(30, vector<int>(n, 1));

	function<int(int, int)> dsu = [&](int u, int ind) -> int {
		if (par[ind][u] == u) return u;
		return par[ind][u] = dsu(par[ind][u], ind);
	};

	auto merge = [&](int a, int b, int ind) {
		a = dsu(a, ind);
		b = dsu(b, ind);
		if (a == b) return;
		if (sz[ind][a] < sz[ind][b]) swap(a, b);
		sz[ind][a] += sz[ind][b];
		par[ind][b] = a;
		zero[ind][a] = zero[ind][a] || zero[ind][b];
	};

	for (int i=0;i<m;++i){
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		u--;v--;
		for (int j=0;j<30;++j){
			if (w&(1<<j)){
				merge(u, v, j);
			}
		}
		if ((w&1)==0)
		for (int j=0;j<30;++j){
			zero[j][dsu(u, j)] = true;
			zero[j][dsu(v, j)] = true;
		}
	}

	int q;
	cin >> q;
	for (int i=0;i<q;++i){
		int u, v;
		scanf("%d%d", &u, &v);
		u--;v--;
		bool b = false;
		for (int j=29;j>=0;--j){
			if (dsu(u, j) == dsu(v, j)) {
				b = true;
				break;
			}
		}
		if (b) {
			printf("0\n");
		} else {
			for (int j=29;j>=1;--j) {
				if (zero[j][dsu(u, j)]) {
					b = true;
					printf("1\n");
					break;
				}
			}
			if (!b) printf("2\n");
		}
	}
}

int main(){
	int t=1;
	// cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}