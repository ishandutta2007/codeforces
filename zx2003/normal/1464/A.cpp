#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,m,i,j,x,y,p[N],ans;
bool vi[N];
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%d%d",&n,&m);memset(p+1,0,n<<2);memset(vi+1,0,n);ans=m;
		for(i=1;i<=m;++i)scanf("%d%d",&x,&y),p[x]=y;
		for(i=1;i<=n;++i)if(!vi[i] && p[i]){
			for(j=i;vi[j]=1,!vi[p[j]] && p[j];j=p[j]);
			if(p[j]==i)ans+=p[i]==i?-1:1;
		}
		printf("%d\n",ans);
	}
}