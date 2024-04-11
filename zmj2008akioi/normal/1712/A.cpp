#include <cstdio>
const int N=1e6+10;
int T,n,k,a[N];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&k);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		int ans=0;
		for(int i=1;i<=k;++i)ans+=a[i]>k;
		printf("%d\n",ans);
	}
	return 0;
}