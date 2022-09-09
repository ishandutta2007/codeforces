#include<bits/stdc++.h>
typedef long long ll;
ll n,ans,p,on;
int i,c,cc;
int main(){
	scanf("%lld",&n);on=n;
	for(i=2;1ll*i*i<=n;++i)if(n%i==0)for(++cc,p=i;n%i==0;n/=i,++c);
	if(n>1)++c,++cc,p=n;
	if(c<2)ans=on;
		else if(c>1 && cc==1)ans=p;
			else ans=1;
	printf("%lld\n",ans);
	return 0;
}