#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int T,n,a[N],i;
int main(){
	for(scanf("%d",&T);T--;){
		long long ans=0;
		for(scanf("%d",&n),i=1;i<=n;++i)scanf("%d",a+i);
		for(i=n;i>1;--i)if(a[i]<a[i-1])ans+=a[i-1]-a[i];
		printf("%lld\n",ans);
	}
}