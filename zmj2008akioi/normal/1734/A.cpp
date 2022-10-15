#include <cstdio>
#include <algorithm>
const int inf=2e9,N=310;
int T,n,a[N];
template<typename T>void cmin(T &x,T y){if(x>y)x=y;}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		std::sort(a+1,a+n+1);int ans=inf;
		for(int i=2;i<n;++i)cmin(ans,a[i+1]-a[i-1]);
		printf("%d\n",ans);
	}
	return 0;
}