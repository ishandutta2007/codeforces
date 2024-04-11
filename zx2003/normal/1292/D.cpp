#include<bits/stdc++.h>
using namespace std;
const int U=5005;
int p[699],pcnt,mn[U],id[U];
int fa[U*2],dis[U*2],st[U*2],w,vcnt,a[U*2][699],sz[U*2],ww[U*2];
int n,k,i,j;
inline bool LE(int x,int y){for(j=1;j<=pcnt && a[x][j]<=a[y][j];++j);return j>pcnt;}
inline bool EQ(int x,int y){for(j=1;j<=pcnt && a[x][j]==a[y][j];++j);return j>pcnt;}
inline int jian(int x,int y){int ass=0;for(j=1;j<=pcnt;++j)ass+=a[x][j]-a[y][j];return ass;}
vector<int>e[U*2];
void getsz(int x){for(int y:e[x])getsz(y),sz[x]+=sz[y];}
vector<pair<int,int>>E[U*2];
long long ans;
void getans(int x,int fa,int d){
	ans+=1ll*ww[x]*d;
	for(auto u:E[x])if(u.second!=fa)getans(u.second,x,d+u.first);
}
int main(){
	for(i=2;i<U;++i)if(!mn[i])for(p[++pcnt]=i,id[i]=pcnt,j=i;j<U;j+=i)mn[j]=mn[j]?mn[j]:i;
	vcnt=5000;st[w=1]=1;
	for(i=2;i<=5000;++i){
		memcpy(a[i],a[i-1],sizeof a[i]);
		for(j=i;j>1;j/=mn[j])++a[i][id[mn[j]]];
		memset(a[0],0,sizeof a[0]);
		for(j=pcnt;j && a[i][j]==a[i-1][j];--j)a[0][j]=a[i][j];
		a[0][j]=min(a[i][j],a[i-1][j]);
		for(;w && LE(0,st[w]) && !EQ(0,st[w]);)--w;
		if(!EQ(0,st[w])){
			++vcnt,fa[vcnt]=st[w];fa[st[w+1]]=vcnt;st[++w]=vcnt;
			memcpy(a[vcnt],a[0],sizeof a[0]);
		}
		fa[i]=st[w];st[++w]=i;st[w+1]=0;
	}
	for(i=2;i<=vcnt;++i)dis[i]=jian(i,fa[i]),e[fa[i]].push_back(i);
	for(scanf("%d",&n),i=1;i<=n;++i){
		scanf("%d",&k);if(k==0)k=1;
		++sz[k],++ww[k];
	}
	getsz(1);
	for(i=1;;){
		int mx=0;
		for(int v:e[i])if(sz[v]>sz[mx])mx=v;
		if(sz[mx]*2<n)break;i=mx;
	}
	for(j=2;j<=vcnt;++j)E[j].push_back({dis[j],fa[j]}),E[fa[j]].push_back({dis[j],j});
	getans(i,0,0);
	printf("%lld\n",ans);
	return 0;
}