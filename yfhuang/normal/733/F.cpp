#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

struct edge{
	int to,w,c;
	edge(int t = 0,int W = 0,int C = 0):to(t),w(W),c(C){}
};

const int maxn = 2e5 + 5;

struct E{
	int u,v,cost,weight;
	int id;
	bool operator < (const E & rhs) const{
		return weight < rhs.weight;
	}
};

vector<edge> G[maxn];
int root;
int par[20][maxn];
int dis[20][maxn];
int depth[maxn];

E e[maxn];

int n,m;
int fa[maxn];

int Find(int x){
	return x == fa[x] ? x : fa[x] = Find(fa[x]);
}

void addedge(int i){
	int u = e[i].u;
	int v = e[i].v;
	G[u].push_back(edge(v,e[i].weight,e[i].cost));
	G[v].push_back(edge(u,e[i].weight,e[i].cost));
}

void dfs(int u,int fa,int weight,int d){
	par[0][u] = fa;
	dis[0][u] = weight;
	depth[u] = d;
	for(int i = 0;i < G[u].size();i++){
		if(G[u][i].to!= fa) dfs(G[u][i].to,u,G[u][i].w,d + 1);
	}
}

bool vis[maxn];

void init(){
	root = 1;
	dfs(root,-1,-1,0);
	for(int k = 0;k + 1 < 20;k++){
		for(int v = 1;v <= n;v++){
			if(par[k][v] < 0){ par[k + 1][v] = -1,dis[k + 1][v] = dis[k][v];}
			else{
				par[k + 1][v] = par[k][par[k][v]];
				dis[k + 1][v] = max(dis[k][v],dis[k][par[k][v]]);
			}
		}
	}
}

int lca(int u,int v){
	int ans = 0;
	if(depth[u] > depth[v]) swap(u,v);
	for(int k = 0;k < 20;k++){
		if((depth[v] - depth[u]) >> k & 1){
			ans = max(ans,dis[k][v]);
			v = par[k][v];
		}
	}
	if(u == v) return ans;
	for(int k = 19;k >= 0;k--){
		if(par[k][u] != par[k][v]){
			ans = max(ans,dis[k][u]);
			u = par[k][u];
			ans = max(ans,dis[k][v]);
			v = par[k][v];
		}
	}
	return ans;
}

int main(){
	cin >> n >> m;
	for(int i = 1;i <= m;i++) scanf("%d",&e[i].weight);
	for(int i = 1;i <= m;i++) scanf("%d",&e[i].cost);
	for(int i = 1;i <= m;i++) scanf("%d%d",&e[i].u,&e[i].v),e[i].id = i;
	int S;
	cin >> S;
	memset(dis,0,sizeof(dis));
	memset(vis,false,sizeof(vis));
	sort(e + 1,e + 1 + m);
	for(int i = 1;i <= n;i++) fa[i] = i;
	long long sum = 0;
	long long ans;
	int minc = 2e9;
	for(int i = 1;i <= m;i++){
		int fx = Find(e[i].u);
		int fy = Find(e[i].v);
		if(fx == fy) continue;
		addedge(i);
		sum += e[i].weight;
		fa[fx] = fy;
		vis[i] = true;
		minc = min(minc,e[i].cost);
	}
	init();
	ans = sum - S / (long long) minc;
	int cas = 0;
	for(int i = 1;i <= m;i++){
		if(vis[i]) continue;
		int u = e[i].u;
		int v = e[i].v;
		minc = lca(u,v);
		//ans = min(ans,(sum - minc + e[i].weight) - (long long) S / (long long) e[i].cost);
		if(ans > (sum - minc + e[i].weight) - (long long) S / (long long) e[i].cost){
			cas = i;
			ans = (sum - minc + e[i].weight) - (long long) S / (long long) e[i].cost;
		}
	}
	//cout << ans << endl;
	long long xxx  = 0;
	if(cas == 0){
		xxx = 0;
		minc = 2e9;
		int kas = -1;
		for(int i = 1;i <= m;i++){
			if(vis[i]){
				if(minc > e[i].cost){
					kas = i;
					minc = e[i].cost;
				}
				//j++;
				//minc = min(minc,e[i].cost);
				//printf("%d ",e[i].id);
				//if(j == n - 1) printf("%d\n",e[i].weight - S / minc);
				//else printf("%d\n",e[i].weight);
			}
		}
		for(int i = 1;i <= m;i++){
			if(vis[i]){
				if(i == kas){
					//printf("%d %d\n",e[i].id,e[i].weight - S / minc);
					xxx += e[i].weight - S / minc;
				}else{
					//printf("%d %d\n",e[i].id,e[i].weight);
					xxx += e[i].weight;
				}
			}
		}
	}else{
		xxx = 0;
		for(int i = 1;i <= n;i++) fa[i] = i;
		//printf("%d %d\n",e[cas].id,e[cas].weight - S / e[cas].cost);
		xxx += e[cas].weight - S / e[cas].cost;
		int u = e[cas].u;
		int v = e[cas].v;
		fa[u] = v;
		for(int i = 1;i <= m;i++) if(i != cas){
			int fx = Find(e[i].u);
			int fy = Find(e[i].v);
			if(fx == fy) continue;
			fa[fx] = fy;
			//printf("%d %d\n",e[i].id,e[i].weight);
			xxx += e[i].weight;
		}
	}
	cout << xxx << endl;
	if(cas == 0){
		xxx = 0;
		minc = 2e9;
		int kas = -1;
		for(int i = 1;i <= m;i++){
			if(vis[i]){
				if(minc > e[i].cost){
					kas = i;
					minc = e[i].cost;
				}
				//j++;
				//minc = min(minc,e[i].cost);
				//printf("%d ",e[i].id);
				//if(j == n - 1) printf("%d\n",e[i].weight - S / minc);
				//else printf("%d\n",e[i].weight);
			}
		}
		for(int i = 1;i <= m;i++){
			if(vis[i]){
				if(i == kas){
					printf("%d %d\n",e[i].id,e[i].weight - S / minc);
					//xxx += e[i].weight - S / minc;
				}else{
					printf("%d %d\n",e[i].id,e[i].weight);
					//xxx += e[i].weight;
				}
			}
		}
	}else{
		xxx = 0;
		for(int i = 1;i <= n;i++) fa[i] = i;
		printf("%d %d\n",e[cas].id,e[cas].weight - S / e[cas].cost);
		//xxx += e[cas].weight - S / e[cas].cost;
		int u = e[cas].u;
		int v = e[cas].v;
		fa[u] = v;
		for(int i = 1;i <= m;i++) if(i != cas){
			int fx = Find(e[i].u);
			int fy = Find(e[i].v);
			if(fx == fy) continue;
			fa[fx] = fy;
			printf("%d %d\n",e[i].id,e[i].weight);
			//xxx += e[i].weight;
		}
	}
	return 0;
}