#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int MAXM = 200005;

int n, m, deg[MAXM];
vector <int> a[MAXN], G[MAXM];

int main(){
	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; i++){
		a[i].resize(m);
		for(int j = 0; j < m; j++)
			scanf("%d", &a[i][j]);
	}

	int s = m;
	for(int i = 0; i < n; i++){
		vector < pair <int, int> > p;
		for(int j = 0; j < m; j++)
			if(a[i][j] != -1)p.push_back({a[i][j], j});
		sort(p.begin(), p.end());

		for(int i = 0; i < p.size(); ){
			int j = i + 1;
			while(j < p.size() && p[j].first == p[i].first)j++;

			int k = j + 1;
			while(k < p.size() && p[k].first == p[j].first)k++;

			if(j < p.size()){
				for(int z = i; z < j; z++){
					G[p[z].second].push_back(s);
					deg[s]++;
				}
				for(int z = j; z < k; z++){
					G[s].push_back(p[z].second);
					deg[p[z].second]++;
				}
				s++;
				i = j;
			}else break;
		}
	}

	queue <int> q;
	for(int i = 0; i < s; i++)
		if(deg[i] == 0)q.push(i);

	vector <int> p;
	while(!q.empty()){
		int u = q.front();
		q.pop();

		if(u < m)p.push_back(u);

		for(int v : G[u]){
			deg[v]--;
			if(deg[v] == 0)q.push(v);
		}
	}

	if(p.size() < m)printf("-1\n");
	else{
		for(int i = 0; i < p.size(); i++){
			if(i > 0)printf(" ");
			printf("%d", p[i] + 1);
		}
		printf("\n");
	}


	return 0;
}