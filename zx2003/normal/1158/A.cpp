#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,b[N],g[N],i,j,mb,mg=1<<30;
long long ans;
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)scanf("%d",b+i),ans+=1ll*b[i]*m;
	for(i=1;i<=m;++i)scanf("%d",g+i);
	sort(b+1,b+n+1);sort(g+1,g+m+1);
	for(i=1;i<=m;++i)ans+=g[i]-(i==m && g[1]>b[n]?b[n-1]:b[n]);
	if(b[n]>g[1])ans=-1;
	printf("%lld\n",ans);
	return 0;
}