#include <cstdio>
#include <algorithm>
int T,n,a[100010];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		std::sort(a+1,a+1+n);
		printf("%d\n",a[n]+a[n-1]);
	}
	return 0;
}