#include<bits/stdc++.h>
#define mod 1000000007
#define maxn 100100
using namespace std;
typedef pair<int,int> par;
int f[maxn],n,pw[maxn*3]={1},X[maxn],Y[maxn],Z[maxn],bh[maxn],tg[maxn];
set<par>st[maxn];
int find(int x){
	return x==f[x]?x:f[x]=find(f[x]);
}
int cmp1(int a,int b){
	return X[a]==X[b]?Y[a]<Y[b]:X[a]<X[b];
}
int cmp2(int a,int b){
	return Y[a]==Y[b]?X[a]<X[b]:Y[a]<Y[b];
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n*3;++i)pw[i]=2ll*pw[i-1]%mod;
	for(int i=1;i<=n;++i)f[i]=i,bh[i]=i;
	for(int i=1;i<=n;++i)scanf("%d%d",&X[i],&Y[i]),Z[i]=i;
	sort(bh+1,bh+n+1,cmp1);
	for(int i=1;i<n;++i)
		if(X[bh[i]]==X[bh[i+1]]){
			int x=find(Z[bh[i]]),y=find(Z[bh[i+1]]);
			if(find(x)!=find(y))tg[y]|=tg[x],f[x]=y;
			else tg[x]=1;
		}
	sort(bh+1,bh+n+1,cmp2);
	for(int i=1;i<n;++i)
		if(Y[bh[i]]==Y[bh[i+1]]){
			int x=find(Z[bh[i]]),y=find(Z[bh[i+1]]);
			if(find(x)!=find(y))tg[y]|=tg[x],f[x]=y;
			else tg[x]=1;
		}
	for(int i=1;i<=n;++i){
		st[find(i)].insert(par(X[i],0));
		st[find(i)].insert(par(Y[i],1));
	}
	int ans=1;
	for(int i=1;i<=n;++i)if(find(i)==i)
		ans=1ll*ans*(tg[i]?pw[st[i].size()]:pw[st[i].size()]-1)%mod;
	printf("%d",ans);
}