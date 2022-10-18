#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3005;

int n, ai, bi;
vector <int> G[MAXN];

int deg[MAXN];
vector < pair <int, int> > C[MAXN];

int nxt(int i, int p){
	for(int j : G[i])if(deg[j] == 2){
		if(j == p)continue;
		return j;
	}
	return -1;
}
double prob(int d){
	return 2.0 / d;
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d %d", &ai, &bi);

		G[ai].push_back(bi);
		G[bi].push_back(ai);

		deg[ai]++;
		deg[bi]++;
	}
	for(int i = 0; i < n; i++)
		C[i].push_back({i, 1});

	queue <int> q;
	for(int i = 0; i < n; i++)if(deg[i] == 1)
		q.push(i);

	double totalCost = n;
	while(!q.empty()){
		int u = q.front();
		q.pop();

		for(int v : G[u]){
			if(deg[v] == 1)continue;

			deg[v]--;
			if(deg[v] == 1)q.push(v);

			for(pair <int, int> a : C[v])
			for(pair <int, int> b : C[u]){
				int d = a.second + b.second;
				totalCost += prob(d);
			}

			for(pair <int, int> b : C[u])C[v].push_back({b.first, b.second + 1});
		}
	}

	int cycleSize = 0;
	for(int i = 0; i < n; i++)
		cycleSize += (deg[i] == 2);

	for(int i = 0; i < n; i++)if(deg[i] == 2){
		int v = nxt(i, i), p = i, vd = 0;

		while(v != i){
			if(i < v){
				for(pair <int, int> a : C[i])
				for(pair <int, int> b : C[v]){
					int d = a.second + b.second + vd;
					int d2 = a.second + b.second + (cycleSize - vd - 2);
					int ud = a.second + b.second + cycleSize - 2;

					totalCost += prob(d);
					totalCost += prob(d2);
					totalCost -= prob(ud);
				}
			}

			int nv = nxt(v, p);
			p = v;
			v = nv;
			vd++;
		}
	}
	printf("%.15f\n", totalCost);

	return 0;
}