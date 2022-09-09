#include<bits/stdc++.h>
const int N=1000005;
int a[N],i,n;
long long ans;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n*2;++i)scanf("%d",a+i);
	std::sort(a+1,a+n*2+1);
	ans=1ll*(a[n]-a[1])*(a[n*2]-a[n+1]);
	for(i=2;i<=n;++i){
		ans=std::min(ans,1ll*(a[n*2]-a[1])*(a[i+n-1]-a[i]));
	}
	std::cout<<ans<<'\n';
	return 0;
}