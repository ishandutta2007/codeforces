#include <cstdio>
typedef long long LL;
const int N=2e5+10;
int T,n,a[N],b[N];LL ans;
template<typename T>void cmax(T &x,T y){if(x<y)x=y;}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),ans=0;int t=0;
		for(int i=1;i<=n;++i)scanf("%d",&a[i]),ans+=a[i];
		for(int i=1;i<=n;++i)scanf("%d",&b[i]),ans+=b[i],cmax(t,b[i]);
		printf("%lld\n",ans-t);
	}
	return 0;
}