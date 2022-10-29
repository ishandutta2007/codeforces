#include<bits/stdc++.h>
using namespace std;
int n,m,f[1<<23],a[1<<22];
int v[1<<22],b[1<<22],tg[1<<22];
int find(int x){
	return x==f[x]?x:f[x]=find(f[x]);
}
int main(){
	int ans=0;
	scanf("%d%d",&n,&m);
	int S=(1<<n);
	for(int i=0;i<S*2;++i)f[i]=i>=S?i-S:i;
	for(int i=1,ai;i<=m;++i)
		scanf("%d",&a[i]),tg[(S-1)^a[i]]=1,f[find(((S-1)^a[i])+S)]=find(a[i]),b[a[i]]=1;
	for(int i=0;i<S;++i)b[i]|=b[i^(i&-i)];
	for(int i=S-1;i>=0;--i)if(tg[i])
		for(int j=0;j<n;++j)if(i>>j&1){
			int nxt=i^(1<<j);
			tg[nxt]|=1;
			if(!b[nxt])continue;
			f[find(nxt+S)]=find(i+S);
		}
	for(int i=1;i<=m;++i)
		if(!v[a[i]=find(a[i])])
			ans++,v[a[i]]=1;
	printf("%d",ans);
}