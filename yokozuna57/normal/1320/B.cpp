#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;

#define fr first
#define sc second

const int INF = 1000000000;

int main(){
	static int n,m;
	static vector<int> G[200010];
	static vector<int> rG[200010];
	static int k;
	static int p[200010];
	scanf("%d%d",&n,&m);
	for(int i = 0 ; i < m ; i ++){
		int u,v;
		scanf("%d%d",&u,&v);
		G[v].push_back(u);
		rG[u].push_back(v);
	}
	scanf("%d",&k);
	for(int i = 0 ; i < k ; i ++){
		scanf("%d",&p[i]);
	}
	
	static int dist[200010];
	static bool used[200010];
	static queue<int> que;
	for(int i = 0 ; i < 200010 ; i ++){
		dist[i] = INF;
		used[i] = false;
	}
	dist[p[k-1]] = 0;
	que.push(p[k-1]);
	while(!que.empty()){
		int v = que.front(); que.pop();
		if(used[v])continue;
		used[v] = true;
		for(int u: G[v]){
			if(dist[u] > dist[v]+1){
				dist[u] = dist[v]+1;
				que.push(u);
			}
		}
	}
	
	int ret[2] = { k-1 , 0 };
	for(int i = 0 ; i+1 < k ; i ++){
		if(dist[p[i]] == dist[p[i+1]]+1){
			ret[0] --;
		}
	}
	for(int i = 0 ; i+1 < k ; i ++){
		bool b = false;
		for(int v: rG[p[i]]){
			if(v == p[i+1])continue;
			if(dist[p[i]] == dist[v]+1)b = true;
		}
		if(b)ret[1] ++;
	}
	cout << ret[0] << " " << ret[1] << endl;
}