#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
const int INF = 1000000000;

#define fr first
#define sc second

int n;
vector<int> G[200010];

int dist[2][200010];
bool used[200010];
queue<int> que;
void dijkstra(int v,int t){
	for(int i = 0 ; i < 200010 ; i ++){
		dist[t][i] = INF;
		used[i] = false;
	}
	dist[t][v] = 0;
	que.push(v);
	while(!que.empty()){
		int w = que.front(); que.pop();
		if(used[w])continue;
		used[w] = true;
		for(int i = 0 ; i < G[w].size() ; i ++){
			if(dist[t][G[w][i]] > dist[t][w]+1){
				dist[t][G[w][i]] = dist[t][w]+1;
				que.push(G[w][i]);
			}
		}
	}
}

int main(){
	int m,k;
	scanf("%d%d%d",&n,&m,&k);
	static int a[200010];
	for(int i = 0 ; i < k ; i ++){
		scanf("%d",&a[i]);
	}
	for(int i = 0 ; i < m ; i ++){
		int x,y;
		scanf("%d%d",&x,&y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dijkstra(1,0);
	dijkstra(n,1);
	
	vector<P> vec;
	for(int i = 0 ; i < k ; i ++){
		vec.push_back(P(dist[0][a[i]],dist[1][a[i]]));
	}
	sort(vec.begin(),vec.end());
	
	int ret = 0;
	for(int i = 0 ; i+1 < vec.size() ; i ++){
		if(vec[i].sc < vec[i+1].sc){
			cout << dist[0][n] << endl;
			return 0;
		}
		else {
			ret = max ( ret , min( dist[0][n] , vec[i].fr+vec[i+1].sc+1 ) );
		}
	}
	cout << ret << endl;
}