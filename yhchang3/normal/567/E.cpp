#include<bits/stdc++.h>
using namespace std;

int u[100010],v[100010],w[100010];
typedef pair<int,int> pii;
typedef pair<long long int,int> pli;
vector<pii> e[100010],re[100010];

long long int dist[100010],rdist[100010];
pair<long long int,long long int> from[100010],to[100010];
bool vis[100010];
const pii mod={1e9+7,998244353};
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m,s,t;
	cin>>n>>m>>s>>t;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		e[u[i]].emplace_back(w[i],v[i]);
		re[v[i]].emplace_back(w[i],u[i]);
	}
	priority_queue<pli,deque<pli>,greater<pli> > pq;
	for(int i=1;i<=n;i++)
		dist[i]=rdist[i]=1e18;
	dist[s]=0;
	pq.emplace(0,s);
	vector<int> seq;
	while(!pq.empty()){
		int x=pq.top().second;pq.pop();
		if(vis[x])	continue;
		vis[x]=true;
		seq.emplace_back(x);
		for(auto& it:e[x]){
			if(dist[it.second]>dist[x]+it.first){
				dist[it.second]=dist[x]+it.first;
				pq.emplace(dist[it.second],it.second);
			}
		}
	}
	from[s]={1,1};
	map<pair<int,int>,int> cnt;
	for(int x:seq)
		for(auto& it:e[x])
			if(dist[it.second]==dist[x]+it.first){
				cnt[make_pair(x,it.second)]++;
				(from[it.second].first+=from[x].first)%=mod.first;
				(from[it.second].second+=from[x].second)%=mod.second;
			}
	for(int i=1;i<=n;i++)
		vis[i]=false;
	rdist[t]=0;
	pq.emplace(0,t);
	vector<int> rseq;
	while(!pq.empty()){
		int x=pq.top().second;pq.pop();
		if(vis[x])	continue;
		vis[x]=true;
		rseq.emplace_back(x);
		for(auto& it:re[x])
			if(rdist[it.second]>it.first+rdist[x]){
				rdist[it.second]=it.first+rdist[x];
				pq.emplace(rdist[it.second],it.second);
			}
	}
	to[t]={1,1};
	for(int x:rseq)
		for(auto& it:re[x])
			if(rdist[it.second]==rdist[x]+it.first){
				(to[it.second].first+=to[x].first)%=mod.first;
				(to[it.second].second+=to[x].second)%=mod.second;
			}
	for(int i=1;i<=m;i++){
		pair<long long int,long long int> c={from[u[i]].first*to[v[i]].first%mod.first,from[u[i]].second*to[v[i]].second%mod.second};
		if(c==from[t]&&cnt[make_pair(u[i],v[i])]==1&&dist[u[i]]+rdist[v[i]]+w[i]==dist[t])
			cout<<"YES"<<'\n';
		else{
			long long int res=w[i]+dist[u[i]]+rdist[v[i]]-dist[t]+1;
			if(w[i]-res>=1)
				cout<<"CAN"<<' '<<res<<'\n';
			else
				cout<<"NO"<<'\n';
		}
	}
}