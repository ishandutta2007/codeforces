#include <cstdio>
#include <algorithm>
const int N=1e6+10;
int T,n,a[N];
long long ans;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		int p=1;ans=0;
		while(p<n&&!a[p])++p;
		int q=p;
		for(int i=p;i<n;++i){
			while(q<n){
				if(a[q])++q;
				else if(a[i])--a[i],++a[q++],++ans;
				else break;
			}
			ans+=a[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
5
10
0 0 0 0 0 1 0 0 0 0
*/