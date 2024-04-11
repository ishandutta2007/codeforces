#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=5e6+1e3+7,P=1e9+7,M=5e6;

int T,n;

int c[N],f[N];

signed main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%lld",&x);
		c[x]++;
	}
	for(int i=1;i<=M;i++)
		for(int j=i*2;j<=M;j+=i)
			c[i]+=c[j];
	for(int i=M;i>=1;i--)
	{
		f[i]=i*c[i];
		for(int j=i*2;j<=M;j+=i)
			f[i]=max(f[i],f[j]+(c[i]-c[j])*i);
	}
	printf("%lld\n",*max_element(f+1,f+M+1));
}