#include<bits/stdc++.h>
using namespace std;
const int N=1010,mod=1000000007;
int n,p,t[3]={},a[N]={},tot=0,sg[N]={},f[N][4]={};
int main()
{
	cin>>n>>p;
	++tot,a[tot]=min(2,p),sg[tot]=0;
	int l=1,r=1;
	while(a[tot]<p)
	{
		int lp=min<long long>(a[l]*3ll+2,p),rp=min<long long>(a[r]*3ll/2,p);
		int v=sg[l] && sg[r] ? 0 : sg[l]+sg[r]==1 ? 2 : 1;
		if(v!=sg[tot])
			sg[++tot]=v;
		a[tot]=min(lp,rp);
		l+=(lp<=rp),r+=(rp<=lp);
	}
	a[tot]=p;
	for(int i=1;i<=tot;++i)
		t[sg[i]]=(t[sg[i]]+(p+p-a[i]-a[i-1]-1)*1ll*(a[i]-a[i-1])/2)%mod;
	f[0][0]=1;
	for(int i=1;i<=n;++i)
		for(int j=0;j<4;++j)
			for(int k=0;k<=2;++k)
				f[i][j]=(f[i][j]+f[i-1][j^k]*1ll*t[k])%mod;
	cout<<((f[n][1]+f[n][2])%mod+f[n][3])%mod<<endl; 
	return 0;
}