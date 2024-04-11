#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,tot,e[1000001],hd[1000001],nt[1000001],a[1000001],f[1000001][21];
ll ans;
void build(int t,int k){
	tot++;
	e[tot]=k;
	nt[tot]=hd[t];hd[t]=tot;
}
void dfs(int x,int fa){
	int i;
	f[x][0]=fa;
	for(i=1;i<=20;i++)
	 if(f[x][i-1]!=-1)f[x][i]=f[f[x][i-1]][i-1];
	ll mn=1ll<<60;
	for(i=0;i<=20&&f[x][i]!=-1;i++)mn=min(mn,(ll)(i+1)*a[f[x][i]]+a[x]);
	mn=min(mn,(ll)(i+1)*a[m]+a[x]);
	if(fa!=-1)ans+=mn;
	for(i=hd[x];i;i=nt[i])
	 if(e[i]!=fa)dfs(e[i],x);
}
int main(){
	int i,t,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(!m||a[m]>a[i])m=i;
	}
	for(i=1;i<n;i++){
		scanf("%d%d",&t,&k);
		build(t,k);build(k,t);
	}
	memset(f,-1,sizeof(f));
	dfs(m,-1);
	printf("%lld",ans);
}