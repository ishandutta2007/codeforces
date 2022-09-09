#include<cstdio>
#include<cctype>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=100005;
ll b[N],c[N],ans=-(1ll<<62);
int n,p,q,r,a[N],i;
int main(){
	scanf("%d%d%d%d",&n,&p,&q,&r);
	for(i=1;i<=n;++i)scanf("%d",a+i);
	for(b[1]=1ll*p*a[1],i=2;i<=n;++i)b[i]=max(b[i-1],1ll*p*a[i]);
	for(c[n]=1ll*r*a[n],i=n-1;i;--i)c[i]=max(c[i+1],1ll*r*a[i]);
	for(i=1;i<=n;++i)ans=max(ans,b[i]+c[i]+1ll*q*a[i]);
	cout<<ans<<endl;
	return 0;
}