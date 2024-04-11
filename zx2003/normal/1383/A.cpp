#include<bits/stdc++.h>
const int N=1e5+5;
int T,n,i,g[30];
char a[N],b[N];
int gfa(int x){return g[x]==x?x:g[x]=gfa(g[x]);}
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%d%s%s",&n,a+1,b+1);
		for(i=0;i<26;++i)g[i]=i;
		for(i=1;i<=n;++i){
			if(a[i]>b[i])break;
			g[gfa(a[i]-'a')]=gfa(b[i]-'a');
		}
		if(i<=n){puts("-1");continue;}
		int ans=26;for(i=0;i<26;++i)ans-=g[i]==i;printf("%d\n",ans);
	}
}