#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>P;
const int N=1e6+5;
int n,m,k,c[N],x,y,i,tot;
int g[N],rk[N],stx[N],sty[N],stt[N],w,ow;
inline int gfa(int x){for(;g[x]!=x;x=g[x]);return x;}
inline void link(int x,int y){
	x=gfa(x);y=gfa(y);if(g[x]==g[y])return;
	if(rk[x]<rk[y])swap(x,y);
	stx[++w]=x;sty[w]=y;g[y]=x;rk[x]+=stt[w]=rk[x]==rk[y];
}
inline void goback(){
	for(;w>ow;)rk[stx[w]]-=stt[w],g[sty[w]]=sty[w],--w;
}
inline bool trylink(int x,int y){
	if(gfa(x)==gfa(y))return 0;
	link(x,y+n);link(x+n,y);return 1;
}
long long ans;
map<P,vector<P>>mp;
bool b[N];
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=n;++i)scanf("%d",c+i);
	for(i=1;i<=n*2;++i)g[i]=i;
	for(i=1;i<=m;++i){
		scanf("%d%d",&x,&y);
		if(c[x]>c[y])swap(x,y);
		if(c[x]==c[y])b[c[x]]|=!trylink(x,y);
			else mp[P{c[x],c[y]}].push_back({x,y});
	}
	for(i=1;i<=k;++i)tot+=!b[i];ans=1ll*tot*(tot-1)/2;
	ow=w;
	for(auto u:mp){
		tie(x,y)=u.first;if(b[x] || b[y])continue;
		for(auto uu:u.second){
			tie(x,y)=uu;
			if(!trylink(x,y)){--ans;break;}
		}
		goback();
	}
	printf("%lld\n",ans);
}