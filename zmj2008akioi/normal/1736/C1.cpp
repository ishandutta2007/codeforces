#include <cstdio>
typedef long long LL;
const int N=2e5+10;
int T,n,a[N];
template<typename T>T min(T x,T y){return x<y?x:y;}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);LL ans=0;
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		for(int p=1,i=1;i<=n;++i){
			while(p<n&&a[p+1]>=p+2-i)++p;
			ans+=p-i+1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}