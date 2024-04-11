#include <cstdio>
typedef long long LL;
const int inf=1e9,N=110;
int T,n,a[N];
template<typename T>void cmin(T &x,T y){if(x>y)x=y;}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);int mn=inf;LL ans=0;
		for(int i=1;i<=n;++i)scanf("%d",&a[i]),cmin(mn,a[i]);
		mn=(mn<<1)-1;for(int i=1;i<=n;++i)ans+=(a[i]-1)/mn;
		printf("%lld\n",ans);
	}
	return 0;
}