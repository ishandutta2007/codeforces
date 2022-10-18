#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int t, n, a, b, da, db, ui, vi, dist[MAXN];
vector <int> g[MAXN];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d %d %d %d %d", &n, &a, &b, &da, &db);
		a--, b--;
		
		for(int i = 0; i < n; i++)
			g[i].clear();
		
		for(int i = 0; i < n - 1; i++){
			scanf("%d %d", &ui, &vi);
			ui--, vi--;
			
			g[ui].push_back(vi);
			g[vi].push_back(ui);
		}
		
		if(db <= 2 * da){
			printf("Alice\n");
			continue;
		}
		
		for(int i = 0; i < n; i++)dist[i] = -1;
		queue <int> q;
		
		q.push(b);
		dist[b] = 0;
		
		while(!q.empty()){
			int u = q.front();
			q.pop();
			
			for(int v : g[u]){
				if(dist[v] == -1){
					dist[v] = dist[u] + 1;
					q.push(v);
				}
			}
		}
		
		if(dist[a] <= da){
			printf("Alice\n");
			continue;
		}
		
		int z = max_element(dist, dist + n) - dist;
		
		for(int i = 0; i < n; i++)dist[i] = -1;
		
		q.push(z);
		dist[z] = 0;
		
		while(!q.empty()){
			int u = q.front();
			q.pop();
			
			for(int v : g[u]){
				if(dist[v] == -1){
					dist[v] = dist[u] + 1;
					q.push(v);
				}
			}
		}
		
		int diam = *max_element(dist, dist + n);
		
		if(diam <= 2 * da){
			printf("Alice\n");
			continue;
		}
		
		printf("Bob\n");
	}
	
	return 0;
}