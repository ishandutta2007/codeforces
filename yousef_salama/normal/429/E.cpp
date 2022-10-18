#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int n, L[MAXN], R[MAXN], p[2 * MAXN];

int t[2 * MAXN], C[4 * MAXN];
vector < pair <int, int> > G[2 * MAXN];

void color(int i){
	for(; t[i] < G[i].size(); t[i]++){
		if(C[G[i][t[i]].second] != -1)continue;

		C[G[i][t[i]].second] = i < G[i][t[i]].first;
		color(G[i][t[i]].first);
	}
}
int main(){
	scanf("%d", &n);

	vector <int> vx;
	for(int i = 0; i < n; i++){
		scanf("%d %d", &L[i], &R[i]);

		vx.push_back(L[i]);
		vx.push_back(++R[i]);
	}

	sort(vx.begin(), vx.end());
	vx.resize(unique(vx.begin(), vx.end()) - vx.begin());

	for(int i = 0; i < n; i++){
		int a = lower_bound(vx.begin(), vx.end(), L[i]) - vx.begin();
		int b = lower_bound(vx.begin(), vx.end(), R[i]) - vx.begin();

		p[a] ^= 1;
		p[b] ^= 1;

		G[a].push_back({b, i});
		G[b].push_back({a, i});
	}

	int m = n;
	for(int i = 0; i < vx.size(); i++)if(p[i]){
		for(int j = i + 1; j < vx.size(); j++)if(p[j]){
			p[i] ^= 1;
			p[j] ^= 1;

			G[i].push_back({j, m});
			G[j].push_back({i, m});
			m++;

			i = j;
			break;
		}
	}

	memset(C, -1, sizeof C);
	for(int i = 0; i < vx.size(); i++)
		color(i);

	for(int i = 0; i < n; i++){
		if(i > 0)printf(" ");
		printf("%d", C[i]);
	}

	return 0;
}