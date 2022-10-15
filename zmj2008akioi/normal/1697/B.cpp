#include <cstdio>
#include <algorithm>
const int N=1e6+10;
int n,q,a[N];
long long sum[N];
int main(){
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	std::sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=q;++i){
		int x,y;
		scanf("%d %d",&x,&y);
		printf("%lld\n",sum[n-x+y]-sum[n-x]);
	}
	return 0;
}