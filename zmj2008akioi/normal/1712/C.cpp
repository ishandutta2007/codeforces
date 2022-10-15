#include <cstdio>
const int N=1e5+10;
int T,n,a[N],r[N];
bool vis[N];
void cmax(int &x,int y){if(x<y)x=y;}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]),r[a[i]]=i;
		int u=n,ans=0;
		while(u&&a[u]>=a[u-1])--u;
		for(int i=1;i<u;++i){
			ans+=!vis[a[i]],vis[a[i]]=true;
			cmax(u,r[a[i]]);
		}
		for(int i=1;i<u;++i)vis[a[i]]=false;
		printf("%d\n",ans);
	}
	return 0;
}