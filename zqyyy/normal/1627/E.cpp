
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
#define fi first
#define se second
const int N=1e5+7;
const ll INF=1e18;
struct Edge{int to,nxt,w;}e[N<<6];
int s_e,head[N<<3];
inline void add_e(int x,int y,int w){
	e[++s_e]={y,head[x],w},head[x]=s_e;	
}
ll dis[N<<3];
map<int,int>id[N];
int n,m,K,tot,x[N];
inline void clear(){
	for(int i=1;i<=tot;i++)head[i]=0;
	for(int i=1;i<=n;i++)id[i].clear();
	tot=s_e=0;
}
inline void work(){
	n=read(),m=read(),K=read();
	for(int i=1;i<=n;i++)x[i]=read();
	id[1][1]=++tot,id[n][m]=++tot;
	for(int i=1;i<=K;i++){
		int a=read(),b=read(),c=read(),d=read(),h=read();
		if(!id[a].count(b))id[a][b]=++tot;
		if(!id[c].count(d))id[c][d]=++tot;
		add_e(id[a][b],id[c][d],-h);
	}
	for(int i=1;i<=tot;i++)dis[i]=INF;
	dis[1]=0;
	for(int i=1;i<=n;i++){
		if((int)id[i].size()>1){
			for(auto it=id[i].begin(),it1=next(it);it1!=id[i].end();it=it1,it1=next(it1))
				dis[it1->se]=min(dis[it1->se],dis[it->se]+1ll*x[i]*(it1->fi-it->fi));
			for(auto it=--id[i].end(),it1=prev(it);;it=it1,it1=prev(it1)){
				dis[it1->se]=min(dis[it1->se],dis[it->se]+1ll*x[i]*(it->fi-it1->fi));
				if(it1==id[i].begin())break;
			}
		}
		for(auto it=id[i].begin();it!=id[i].end();it++){
			int x=it->se;
			for(int j=head[x];j;j=e[j].nxt){
				int y=e[j].to;
				if(dis[y]>dis[x]+e[j].w)dis[y]=dis[x]+e[j].w;
			}
		}
	}
	if(dis[2]<INF/2)printf("%lld\n",dis[2]);
	else puts("NO ESCAPE");
}
int main(){/*
#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif*/
	int test=read();
	while(test--)work(),clear();
    return 0;
}