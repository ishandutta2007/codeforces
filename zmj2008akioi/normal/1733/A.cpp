#include <cstdio>
typedef long long LL;
const int N=1e6+10;
int T,n,k,a[N];
template<typename T>void cmax(T &x,T y){if(x<y)x=y;}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&k);
		for(int i=0;i<k;++i)a[i]=0;
		for(int w,i=1;i<=n;++i)scanf("%d",&w),cmax(a[i%k],w);
		LL ans=0;for(int i=0;i<k;++i)ans+=a[i];
		printf("%lld\n",ans);
	}
	return 0;
}