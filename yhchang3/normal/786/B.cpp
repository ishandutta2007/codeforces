#include<bits/stdc++.h>
using namespace std;

const int maxn = 400010;
int stp;
vector<pair<long long int,int> > e[maxn<<1];
struct SEG{
	int pos[maxn];
	bool dir;
	void build(int idx,int l,int r){
		pos[idx]=++stp;
		int u,v;
		if(l==r){
			u=stp,v=l;
			if(dir)	swap(u,v);
			e[u].emplace_back(0,v);
			return;
		}
		int mid=(l+r)>>1;
		build(idx<<1,l,mid);build(idx<<1|1,mid+1,r);
		u=pos[idx],v=pos[idx<<1];
		if(dir)	swap(u,v);
		e[u].emplace_back(0,v);
		u=pos[idx],v=pos[idx<<1|1];
		if(dir)	swap(u,v);
		e[u].emplace_back(0,v);
	}
	void addedge(int idx,int l,int r,int L,int R,int to,long long int w){
		int u,v;
		if(r<L||R<l)	return;
		if(L<=l&&r<=R){
			u=pos[idx],v=to;
			if(!dir)	swap(u,v);
			e[u].emplace_back(w,v);
			return;	
		}
		int mid=(l+r)>>1;
		addedge(idx<<1,l,mid,L,R,to,w);
		addedge(idx<<1|1,mid+1,r,L,R,to,w);
	}
}Up,Down;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m,s;
	cin>>n>>m>>s;
	stp=n;
	Up.dir=true;
	Down.dir=false;
	Up.build(1,1,n);Down.build(1,1,n);
	int type;
	while(m--){
		cin>>type;
		int u,l,r;
		long long int w;
		if(type==1){
			cin>>u>>l>>w;
			Down.addedge(1,1,n,l,l,u,w);
		}
		else if(type==2){
			cin>>u>>l>>r>>w;
			Down.addedge(1,1,n,l,r,u,w);
		}
		else{
			cin>>u>>l>>r>>w;
			Up.addedge(1,1,n,l,r,u,w);
		}
	}
	vector<long long int> dist(stp+1,1e18);
	vector<bool> vis(stp+1,false);
	dist[s]=0;
	typedef pair<long long int,int> pli;
	priority_queue<pli,deque<pli>,greater<pli> > pq;
	pq.emplace(0,s);
	while(!pq.empty()){
		int x=pq.top().second;pq.pop();
		if(vis[x])	continue;
		vis[x]=true;
		for(auto it:e[x])
			if(dist[it.second]>it.first+dist[x]){
				dist[it.second]=it.first+dist[x];
				pq.emplace(dist[it.second],it.second);
			}
	}
	for(int i=1;i<=n;i++)
		if(dist[i]==1e18)
			cout<<-1<<' ';
		else
			cout<<dist[i]<<' ';
	cout<<endl;
}