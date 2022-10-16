#include <bits/stdc++.h>
using namespace std;
int n, m;
vector <int> g[40];
int color[40];
int r[40];
int minb[2];
int maxb[2];
int mask[1<<20];
int cnt[2][1<<20];
void check(int b, int key){
	for(int x=minb[b]; x<maxb[b]; x++) if(color[x]) for(auto y: g[x]) if(color[y]) return;
	cnt[b][key]++;
	if(b==0){
		int good=0;
		for(int x=minb[1]; x<maxb[1]; x++){
			good^=1<<(x-minb[1]);
			for(auto y: g[x]) if(y<maxb[0]) if(color[y]){
				good^=1<<(x-minb[1]);
				break;
			}
		}
		mask[key]=good;
	}
}
void backtrack(int b, int u, int key){
	if(u>=maxb[b]) check(b, key);
	else{
		backtrack(b, u+1, key);
		if(r[u]!=-1){
			color[u]=1;
			backtrack(b, u+1, key|(1<<(u-minb[b])));
			color[u]=0;
		}
	}
}
long long ans=0;
int root(int u){
	if(r[u]<0) return u;
	return r[u]=root(r[u]);
}
void unite(int u, int v){
	u=root(u);
	v=root(v);
	if(u==v) return;
	r[u]+=r[v];
	r[v]=u;
}
bool c[40];
bool done[40];
bool dfs(int u, bool cc){
	done[u]=1;
	c[u]=cc;
	for(int v: g[u]) if(!done[v]){
		if(dfs(v, !cc)==0) return 0;
	}
	else if(c[v]!=!cc) return 0;
	return 1;
}
int main(){
	cin>>n>>m;
	if(m<=3){
		cout<<0<<'\n';
		return 0;
	}
	for(int i=0; i<n; i++) r[i]=-1;
	for(int i=1; i<=m; i++){
		int u, v;
		cin>>u>>v;
		u--;
		v--;
		unite(u, v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	maxb[0]=min(20, n);
	minb[1]=20;
	maxb[1]=n;
	backtrack(0, minb[0], 0);
	backtrack(1, minb[1], 0);
	if(n<=20){
		for(int i=0; i<(1<<n); i++) ans+=cnt[0][i];
	}
	else{
		int lg=maxb[1]-minb[1];
		int maxm=1<<lg;
		for(int i=0; i<lg; i++)	for(int j=maxm-1; j>=0; j--) if((j>>i)&1) cnt[1][j]+=cnt[1][j^(1<<i)];
		for(int i=0; i<(1<<20); i++) if(cnt[0][i]) ans+=cnt[1][mask[i]];
	}
	ans*=2;
	///ans=number of (0, 1) only and (1, 2) only
	int cnt=0;
	int cnt2=0;
	for(int i=0; i<n; i++) if(r[i]!=-1){
		if(i==root(i)) cnt++;
	}
	else cnt2++;
	///(0, 2) only => only 1 or only 0 on each component
	ans+=(1LL<<cnt);
	ans-=2LL;///0 only and 2 only
	bool bi=1;
	for(int i=0; i<n; i++) if(r[i]!=-1) if(!done[i]) if(!dfs(i, 0)) bi=0;
	// cerr<<bi<<'\n';
	if(bi) ans-=(1LL<<cnt);///1 only
	ans<<=cnt2;
	ans=(1LL<<n)-ans;
	cout<<ans<<'\n';
	// cout<<(ans<<5)<<'\n';
}