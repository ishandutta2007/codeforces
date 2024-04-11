#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int n, m, a[MAXN];
vector <int> adj[MAXN];

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++){
		scanf("%d", &a[i]);
		a[i]--;
	}

	long long r = 0;
	for(int i = 0; i < m - 1; i++)
		r += abs(a[i + 1] - a[i]);

	for(int i = 0; i < m - 1; i++)if(a[i] != a[i + 1]){
		adj[a[i]].push_back(a[i + 1]);
		adj[a[i + 1]].push_back(a[i]);
	}

	long long mr = r;
	for(int i = 0; i < n; i++)if(!adj[i].empty()){
		sort(adj[i].begin(), adj[i].end());

		int x = adj[i][((int)adj[i].size() - 1) / 2];

		long long nr = r;
		for(int y : adj[i]){
			nr -= abs(i - y);
			nr += abs(x - y);
		}

		mr = min(mr, nr);
	}
	printf("%I64d\n", mr);

	return 0;
}