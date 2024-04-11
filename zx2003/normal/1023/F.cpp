#include<bits/stdc++.h>
using namespace std;
char ibuf[1<<25],*ih=ibuf;
template<typename T>inline void read(T&x){
	int f=1;
	for(;!isdigit(*ih);++ih)if(*ih=='-')f=-1;
	for(x=0;isdigit(*ih);x=x*10+*ih++-48);x*=f;
}
const int N=500005;
int n,k,m,i,j,dad[N],dep[N],va[N],x,y,z,g[N],af[N],bf[N],wf[N];
vector<pair<int,int>>e[N];
void addedge(int x,int y,int tp){e[x].push_back({y,tp});e[y].push_back({x,tp});}
long long ans;
int gfa(int x){return g[x]==x?x:g[x]=gfa(g[x]);}
bool ont[N],mrk[N];
int main(){
	fread(ibuf,1,1<<25,stdin);
	read(n);read(k);read(m);
	for(i=1;i<=n;++i)g[i]=i;
	for(i=1;i<=k;++i)read(x),read(y),addedge(x,y,1),g[gfa(x)]=gfa(y);
	for(i=1;i<=m;++i){
		read(af[i]);read(bf[i]);read(wf[i]);
		x=gfa(af[i]);y=gfa(bf[i]);if(x!=y)g[x]=y,addedge(af[i],bf[i],0),ont[i]=1;
	}
	function<void(int,int)>dfs=[&](int x,int fa){
		dep[x]=dep[fa]+1;dad[x]=fa;
		for(auto y:e[x])if(y.first!=fa)dfs(y.first,x),mrk[y.first]=y.second;
	};
	dfs(1,0);
	for(i=1;i<=n;++i)g[i]=i;
	for(i=1;i<=m;++i)if(!ont[i]){
		for(x=af[i],y=bf[i],z=wf[i];x=gfa(x),y=gfa(y),x!=y;y=dad[y]){
			if(dep[x]>dep[y])swap(x,y);
			va[y]=z;g[y]=dad[y];
		}
	}
	for(i=1;i<=n;++i)if(mrk[i]){if(!va[i]){ans=-1;break;}ans+=va[i];}
	cout<<ans<<'\n';
	return 0;
}