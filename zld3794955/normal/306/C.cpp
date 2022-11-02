#include<bits/stdc++.h>
using namespace std;
const int N=4040,mod=1000000009;
int w,b,n,d[N+N]={1};
inline int rev(int x)
{
	int t=1;
	for(int y=mod-2; y; y>>=1,x=x*1ll*x%mod)
		if(y&1) t=t*1ll*x%mod;
	return t;
}
int main()
{
	cin>>n>>w>>b;
	for(int i=1;i<=b+w;++i)
		d[i]=d[i-1]*1ll*i%mod;
	cout<<d[w]*1ll*d[b]%mod*(w-1)%mod*d[b+w-3]%mod*rev(d[n-3])%mod*rev(d[b+w-n])%mod<<endl;
	return 0;
}