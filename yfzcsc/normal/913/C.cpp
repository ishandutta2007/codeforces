#include<bits/stdc++.h>
using namespace std;
int n,L,c[100];
long long ans,ans2;
int main(){
	scanf("%d%d",&n,&L);
	for(int i=0;i<n;++i)
		scanf("%d",&c[i]);
	for(int i=1;i<n;++i)
		c[i]=min(c[i],2*c[i-1]);
	ans2=LLONG_MAX;
	for(int i=n-1;i>=0;--i){
		int x=L>>i;
		ans+=1ll*c[i]*x;
		L&=(1<<i)-1;
		ans2=min(ans2,ans+(!!L)*c[i]);
	}
	printf("%lld",ans2);
}