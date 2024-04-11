#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

ll m,n,c[1010][1010],f[1010],b[1010],x,ans=1;
map<ll,ll>mp;

int main(){
	for (cin>>m>>n;n--;)
		for (int i=0;i<m;++i)
			scanf("%1lld",&x), b[i]|=x<<n;
	for (int i=0;i<m;++i) ++mp[b[i]];
	for (int i=0;i<=m;++i)
		for (int j=0;j<=i;++j)
			c[i][j]= j? (c[i-1][j-1]+c[i-1][j])%mod: 1;
	f[0]=f[1]=1;
	for (int i=2;i<=m;++i)
		for (int j=0;j<i;++j)
			f[i]=(f[i]+c[i-1][j]*f[j])%mod;
	for (auto o:mp) ans=(ans*f[o.second])%mod;
	cout<<ans;
}