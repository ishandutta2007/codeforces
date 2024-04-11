#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int N=2e5+7;
int s_p,pr[N],v[N],mu[N];
inline void init(int n){
	mu[1]=1;
	for(int i=2;i<=n;i++){
		if(!v[i])v[i]=i,pr[++s_p]=i,mu[i]=-1;
		for(int j=1;j<=s_p && i*pr[j]<=n;j++){
			v[i*pr[j]]=pr[j];
			if(i%pr[j]==0){mu[i*pr[j]]=0;break;}
			mu[i*pr[j]]=-mu[i];
		}
	}
}
int pa[N],sz[N];
int find(int x){return pa[x]^x?pa[x]=find(pa[x]):x;}
inline void unin(int x,int y){
	x=find(x),y=find(y);
	if(sz[x]>sz[y])swap(x,y);
	if(x!=y)pa[x]=y,sz[y]+=sz[x];
}
int n,m,vis[N];
ll g[N];
vector<int>G[N],vec[N];
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		int x=read();
		for(int j=1;j*j<=x;j++)
			if(x%j==0){
				vec[j].push_back(i);
				if(j*j<x)vec[x/j].push_back(i);
			}
		m=max(m,x);
	}
	for(int i=1;i<n;i++){
		int x=read(),y=read();
		G[x].push_back(y),G[y].push_back(x);
	}
	init(m);
	for(int i=1;i<=m;i++){
		for(int x:vec[i])pa[x]=x,sz[x]=1,vis[x]=i;
		for(int x:vec[i])
			for(int y:G[x])
				if(vis[y]==i)unin(x,y);
		for(int x:vec[i])
			if(find(x)==x)g[i]+=1ll*sz[x]*(sz[x]+1)/2;
	}
	for(int i=1;i<=m;i++){
		ll f=0;
		for(int j=i;j<=m;j+=i)
			f+=mu[j/i]*g[j];
		if(f)printf("%d %lld\n",i,f);
	}
	return 0;
}