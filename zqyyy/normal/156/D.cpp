#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=1e5+7;
int n,m,mod,pa[N],sz[N];
int find(int x){return pa[x]^x?pa[x]=find(pa[x]):x;}
int main(){
#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	n=read(),m=read(),mod=read(),iota(pa+1,pa+n+1,1);
	for(int i=1,x,y;i<=m;i++)x=read(),y=read(),pa[find(x)]=find(y);
	for(int i=1;i<=n;i++)sz[find(i)]++;
	int ans=1,cnt=0;
	for(int i=1;i<=n;i++)if(sz[i])cnt++,ans=1ll*ans*sz[i]%mod;
	if(cnt==1)ans=1%mod;
	else while(cnt>2)cnt--,ans=1ll*ans*n%mod;
	printf("%d\n",ans);
	return 0;
}