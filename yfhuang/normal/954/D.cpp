#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

int n,m,s,t;

const int maxn = 1005;

int dis[2][maxn];
bool G[maxn][maxn];

bool inq[maxn];
void bfs(int st,int id){
	memset(dis[id],0x3f,sizeof(dis[id]));
	dis[id][st] = 0;
	queue<int> q;
	q.push(st);
	inq[st] = true;
	while(!q.empty()){
		int u = q.front();q.pop();
		inq[u] = false;
		for(int i = 1;i <= n;i++){
			if(G[u][i]){
				if(dis[id][i] > dis[id][u] + 1){
					dis[id][i] = dis[id][u] + 1;
					if(!inq[i]){
						inq[i] = true;
						q.push(i);
					}
				}
			}
		}
	}
}

int main(){
	cin >> n >> m >> s >> t;
	for(int i = 1;i <= m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		G[u][v] = G[v][u] = true;
	}
	bfs(s,0);
	bfs(t,1);
	int D = dis[0][t];
	int cnt = 0;
	for(int i = 1;i <= n;i++){
		for(int j = i + 1;j <= n;j++){
			if(G[i][j]) continue;
			if(dis[0][i] + 1 + dis[1][j] < D || dis[0][j] + 1 + dis[1][i] < D)
	continue;
			cnt++;			
		}
	}
	cout << cnt << endl;
	return 0;
}