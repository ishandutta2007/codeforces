#include <cstdio>
const int N=2e5+10;
int T,n,a[N];
long long ans,d[N];
template<typename T>T abs(T x){return x>0?x:(-x);}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		for(int i=1;i<=n;++i)d[i]=a[i]-a[i-1];
		ans=0;
		for(int i=2;i<=n;++i){
			if(d[i]<0)d[1]+=d[i],ans-=d[i];
			else ans+=d[i];
		}
		printf("%lld\n",ans+abs(d[1]));
	}
	return 0;
}
/*
opt=1:--d[1],++d[i](i can be n+1)
opt=2:--d[i]
opt=3:++d[1]
Goal:all i in 1-n d[i]=0
*/