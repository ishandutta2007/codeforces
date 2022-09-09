#include<bits/stdc++.h>
const int N=1<<21;
int n,m,q,x,y,i,g[N],z;
int gfa(int x){
	return g[x]==x?x:g[x]=gfa(g[x]);
}
int main(){
	scanf("%d%d%d",&n,&m,&q);z=n+m;
	for(i=1;i<=n+m;++i)g[i]=i;
	while(q--){
		scanf("%d%d",&x,&y);y+=n;
		x=gfa(x);y=gfa(y);
		if(x!=y)--z,g[x]=y;
	}
	printf("%d\n",z-1);
	return 0;
}