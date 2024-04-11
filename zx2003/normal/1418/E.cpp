#include<bits/stdc++.h>
using namespace std;
const int mo=998244353,N=2e5+5;
int n,m,i,d[N],a,b,inv[N],ps[N],ss[N];
int main(){
	for(i=1;i<N;++i)inv[i]=i==1?1:1ll*(mo-mo/i)*inv[mo%i]%mo;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)scanf("%d",d+i);sort(d+1,d+n+1);
	for(i=1;i<=n;++i)ps[i]=(ps[i-1]+d[i])%mo;for(i=n;i;--i)ss[i]=(ss[i+1]+d[i])%mo;
	for(;m--;){
		scanf("%d%d",&a,&b);
		b=d+n+1-lower_bound(d+1,d+n+1,b);
		a=a>b?0:(1ll*inv[b+1]*(b+1-a)%mo*ps[n-b]+1ll*inv[b]*(b-a)%mo*ss[n-b+1])%mo;
		printf("%d\n",a);
	}
}