#include<bits/stdc++.h>
using namespace std;

#define pii pair<long long int,long long int>
#define piii pair<pii,long long int>
const int MAXN = 300001;
const long long int INF = 1e18;
long long int dist[MAXN+1];
bool visit[MAXN+1];
vector<pii> edge[MAXN+1];//(to,weight)
priority_queue<piii,vector<piii>,greater<piii> > pq;//(dist[node],node)
map<pii,int> M;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		edge[u].push_back({v,w});
		edge[v].push_back({u,w});
		M[{u,v}]=M[{v,u}]=i;
	}
	int ans=min(k,n-1);
	cout<<ans<<endl;
	fill(dist,dist+n+1,INF);
   memset(visit,0,sizeof visit);
   dist[1]=0;
   pq.push({{dist[1],1},1});
	int cnt=0;
	while(true){
		long long int now=pq.top().first.second;
		long long int from=pq.top().second;
		pq.pop();
      if(visit[now]) continue;
      visit[now]=true;
		cnt++;
		if(cnt!=1)
			cout<<M[{from,now}]<<' ';
		if(cnt==ans+1)
			break;
      for(int i=0;i<edge[now].size();i++){
         int next=edge[now][i].first;
         long long int weight=edge[now][i].second;
         if(dist[next]>dist[now]+weight){
            dist[next]=dist[now]+weight;
            pq.push({{dist[next],next},now});
         }
      }
	}
	cout<<endl;
}