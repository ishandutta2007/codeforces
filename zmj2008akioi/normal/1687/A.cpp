#include <cstdio>
const int N=2e5+10;
int T,n,k,a[N];
long long ans,sum[N];
template<typename T>void cmax(T &x,T y){if(x<y)x=y;}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&k);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		for(int i=1;i<=n;++i)sum[i]=sum[i-1]+a[i];
		if(n==1)printf("%d\n",a[1]+k-1);
		else if(k<=n){
			ans=0;
			for(int i=k;i<=n;++i)cmax(ans,sum[i]-sum[i-k]);
			printf("%lld\n",ans+(long long)k*(k-1)/2);
		}
		else printf("%lld\n",sum[n]+(long long)k*n-(long long)n*(n+1)/2);
	}
	return 0;
}