#include<bits/stdc++.h>
#define pa pair<int,int>
#define fi first
#define se second
#define N 300005
using namespace std;

vector<int> seq;
int mx[N],sz[N];
set<int> adj[N];

void dfs(int x,int fa=-1){
	seq.push_back(x);
	mx[x]=0; sz[x]=1;
	for (auto y:adj[x])
		if (y!=fa){
			dfs(y,x);
			sz[x]+=sz[y];
			mx[x]=max(mx[x],sz[y]);
		}
}

vector<int> wzp[N];
vector<int> walk[N];
vector<int> allq[N];
int fens[N],fenq[N];
int bel[N],first[N];
int cnt[N],ans[N];
pa dis[N];

void solve(int rt){
	seq.clear();
	dfs(rt);
	int x=-1;
	for (auto y:seq){
		mx[y]=max(mx[y],sz[rt]-sz[y]);
		if (x==-1||(mx[y]<mx[x])) x=y;
	}
	queue<int> q;
	for (auto u:seq)
		for (auto i:wzp[u])
			if (u==x){
				dis[i]=pa(0,i-bel[i]);
				q.push(i);
			}
			else dis[i]=pa(1e9,-1);
	while (!q.empty()){
		int u=q.front(); q.pop();
		for (auto v:walk[u]){
			pa newv(dis[u].fi+1,dis[u].se);
			if (newv<dis[v]){
				dis[v]=newv;
				q.push(v);
			}
		}
	}
	vector<pa> ins,Q;
	for (auto u:seq) for(auto i:wzp[u]){
		if (first[i]<1e9) ins.push_back(pa(first[i],i));
		for (auto qid:allq[i]) Q.push_back(pa(qid,i));
	}
	sort(ins.begin(),ins.end());
	sort(Q.begin(),Q.end());
	for (int i=0;i<=cnt[x];i++) fenq[i]=fens[i]=1e9;
	int tmp=0;
	for (auto u:Q){
		for (;tmp<ins.size()&&ins[tmp].fi<u.fi;++tmp){
			for (int i=dis[ins[tmp].se].se+1;i<=cnt[x];i+=i&(-i))
				fenq[i]=min(fenq[i],dis[ins[tmp].se].fi-dis[ins[tmp].se].se);
			for (int i=dis[ins[tmp].se].se+1;i>0;i-=i&(-i))
				fens[i]=min(fens[i],dis[ins[tmp].se].fi+dis[ins[tmp].se].se);
		}
		for (int i=dis[u.se].se+1;i>0;i-=i&(-i))
			if (fenq[i]<1e9) ans[u.fi]=min(ans[u.fi],fenq[i]+dis[u.se].fi+dis[u.se].se);
		for (int i=dis[u.se].se+1;i<=cnt[x];i+=i&(-i))
			if (fens[i]<1e9) ans[u.fi]=min(ans[u.fi],fens[i]+dis[u.se].fi-dis[u.se].se);
	}
	for (auto y:adj[x]) adj[y].erase(x);
	for (auto y:adj[x]) solve(y);
}

int n;
pa a[N];
map<pa,int> id;
bool isq[N];

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d%d",&a[i].fi,&a[i].se);
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++) id[a[i]]=i;
	bel[1]=1;
	for (int i=2;i<=n;i++){
		if (a[i].fi==a[i-1].fi&&a[i].se==a[i-1].se+1){
			walk[i].push_back(i-1);
			walk[i-1].push_back(i);
			bel[i]=bel[i-1];
		}
		else bel[i]=i;
		if (id.find(pa(a[i].fi-1,a[i].se))!=id.end()){
			int j=id[pa(a[i].fi-1,a[i].se)];
			walk[i].push_back(j);
			walk[j].push_back(i);
			adj[bel[i]].insert(bel[j]);
			adj[bel[j]].insert(bel[i]);
		}
	}
	for (int i=1;i<=n;i++)
		wzp[bel[i]].push_back(i);
	bel[n+1]=-1;
	for (int i=1;i<=n;i++)
		++cnt[bel[i]];
	int Q;
	scanf("%d",&Q);
	memset(first,63,sizeof(first));
	for (int i=1;i<=Q;i++){
		int tp,x,cx,cy;
		scanf("%d%d%d",&tp,&cx,&cy);
		x=id[pa(cx,cy)];
		if (tp==1) first[x]=min(first[x],i);
		else isq[i]=1,allq[x].push_back(i);
	}
	memset(ans,63,sizeof(ans));
	solve(1);
	for (int i=1;i<=Q;i++)
		if (isq[i])
			printf("%d\n",ans[i]>1e9?-1:ans[i]);
}