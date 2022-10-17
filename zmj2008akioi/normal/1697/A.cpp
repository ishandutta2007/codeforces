#include <cstdio>
const int N=1e6+10;
int T,n,m,ans,a[N];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&m),ans=-m;
		for(int i=1;i<=n;++i)scanf("%d",&a[i]),ans+=a[i];
		if(ans<0)ans=0;printf("%d\n",ans);
	}
	return 0;
}