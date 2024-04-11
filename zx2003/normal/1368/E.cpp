#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int T,n,m,i,j,e[N][2],x,y,deg[N],label[N],q[N],t,w;
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;++i)memset(e[i],0,8);
		for(i=1;i<=m;++i){
			scanf("%d%d",&x,&y),(e[x][0]?e[x][1]:e[x][0])=y;
			++deg[y];
		}
		t=w=0;for(i=1;i<=n;++i)if(!deg[i])q[++w]=i;
		memset(label+1,0,n<<2);
		for(;t<w;){
			x=q[++t];
			for(int y:e[x]){
				if(label[x]<2)label[y]=max(label[y],label[x]+1);
				if(y && !--deg[y])q[++w]=y;
			}
		}
		w=0;for(i=1;i<=n;++i)if(label[i]==2)q[++w]=i;
		printf("%d\n",w);for(i=1;i<=w;++i)printf("%d%c",q[i],i==w?'\n':' ');
	}
}